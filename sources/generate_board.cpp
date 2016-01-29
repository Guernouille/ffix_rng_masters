#include "mainwindow.h"
#include "prng.h"

void MainWindow::generate_board()
{
    seed_next = seed;

   //Block amount
    prng_start_duel();
    seed = prng_tetra_master(seed);
    prn_16 = (seed >> 16) & 0x7FFF;

    //x86 CPU
    hi = prn_16 * 0x51EB;
    lo = (prn_16 * 0x851F) >> 16;
    prn_32 = hi >> 16;
    hi = hi & 0xFFFF;
    if(hi + lo > 0xFFFF) prn_32++;
    lo = prn_32 >> 5;
    hi = lo * 100;
    prn_16 = prn_16 - hi;

    //x64 CPU, ppc64 CPU
    //prn_64 = prn_16 * 0x51EB851F;
    //prn_64 = prn_64 >> 37;
    //prn_16 = prn_16 - (prn_64 * 100);

    if(prn_16<3) blocks_amount = 0;
    else if(prn_16<7) blocks_amount = 1;
    else if(prn_16<12) blocks_amount = 2;
    else if(prn_16<17) blocks_amount = 3;
    else if(prn_16<27) blocks_amount = 4;
    else if(prn_16<97) blocks_amount = 5;
    else blocks_amount = 6;

   //Block placement
    blocks = 0;
    blocks_placed = 0;

    while(blocks_placed < blocks_amount){
        seed = prng_tetra_master(seed);
        column = (seed >> 16) & 0x3;
        seed = prng_tetra_master(seed);
        row = (seed >> 16) & 0x3;
        block_current = (row * 4) + column;
        block_current = 1 << block_current;

        if(blocks_placed==0){
            blocks = block_current;
            blocks_placed++;
            seed = prng_tetra_master(seed);
        }
        else{
            if((block_current & blocks) == 0){
                blocks |= block_current;
                blocks_placed++;
                seed = prng_tetra_master(seed);
            }
        }
    }
    seed = seed_next;
}

void MainWindow::generate_boards()
{
    seed_initial = seed;
    generate_board();
    display_board(1);
    prng_call();
    generate_board();
    display_board(2);
    prng_call();
    generate_board();
    display_board(3);
    seed = seed_initial;
}
