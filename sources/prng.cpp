#include "mainwindow.h"
#include "prng.h"

void MainWindow::prng_call()
{
    /* Perform a complete PRNG cycle, and updates seed to its next value.
    The formula, seed * 0x41C64E6D + 0x3039, is executed 5 to 13 times.  */
    seed = prng_tetra_master(seed);
    seed = prng_tetra_master(seed);
    seed = prng_tetra_master(seed);
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

    if(prn_16<1) arrow_amount = 0;
    else if(prn_16<9) arrow_amount = 1;
    else if(prn_16<0x22) arrow_amount = 2;
    else if(prn_16<0x41) arrow_amount = 3;
    else if(prn_16<0x53) arrow_amount = 4;
    else if(prn_16<0x5C) arrow_amount = 5;
    else if(prn_16<0x61) arrow_amount = 6;
    else if(prn_16<0x63) arrow_amount = 7;
    else arrow_amount = 8;

    card_arrows = 0;
    while(arrow_amount>0){
        arrow_new = 0;
        seed = prng_tetra_master(seed);
        prn_16 = (seed >> 16) & 0x7;
        arrow_new |= 1 << prn_16;
        lo = card_arrows & arrow_new;

        if(lo == 0){
            arrow_amount--;
            card_arrows |= arrow_new;
        }
    }

    seed = prng_tetra_master(seed);
}


void MainWindow::prng_seed_update()
{
    seed = 0x24040001;

    prng_calls_iterations = ui->spinBox_Cards_1->value();
    while(prng_calls_iterations>0){
        prng_call();
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_WMap_1->value() * 30;
    while(prng_calls_iterations>0){
        seed = prng_tetra_master(seed);
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_Cards_2->value();
    while(prng_calls_iterations>0){
        prng_call();
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_WMap_2->value() * 30;
    while(prng_calls_iterations>0){
        seed = prng_tetra_master(seed);
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_Cards_3->value();
    while(prng_calls_iterations>0){
        prng_call();
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_WMap_3->value() * 30;
    while(prng_calls_iterations>0){
        seed = prng_tetra_master(seed);
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_Cards_4->value();
    while(prng_calls_iterations>0){
        prng_call();
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_WMap_4->value() * 30;
    while(prng_calls_iterations>0){
        seed = prng_tetra_master(seed);
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_Cards_5->value();
    while(prng_calls_iterations>0){
        prng_call();
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_WMap_5->value() * 30;
    while(prng_calls_iterations>0){
        seed = prng_tetra_master(seed);
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_Cards_6->value();
    while(prng_calls_iterations>0){
        prng_call();
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_WMap_6->value() * 30;
    while(prng_calls_iterations>0){
        seed = prng_tetra_master(seed);
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_Cards_7->value();
    while(prng_calls_iterations>0){
        prng_call();
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_WMap_7->value() * 30;
    while(prng_calls_iterations>0){
        seed = prng_tetra_master(seed);
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_Cards_8->value();
    while(prng_calls_iterations>0){
        prng_call();
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_WMap_8->value() * 30;
    while(prng_calls_iterations>0){
        seed = prng_tetra_master(seed);
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_Cards_9->value();
    while(prng_calls_iterations>0){
        prng_call();
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_WMap_9->value() * 30;
    while(prng_calls_iterations>0){
        seed = prng_tetra_master(seed);
        prng_calls_iterations--;
    }
    prng_calls_iterations = ui->spinBox_Cards_10->value();
    while(prng_calls_iterations>0){
        prng_call();
        prng_calls_iterations--;
    }

    //Display current seed
    prng_display = "";
    prn_16 = seed >> 16;
    if(prn_16<0x1000) prng_display += "0";
    if(prn_16<0x100) prng_display += "0";
    if(prn_16<0x10) prng_display += "0";
    prng_display += QString::number(prn_16, 16);
    ui->LCD_Seed1->display(prng_display);

    prng_display = "";
    prn_16 = seed << 16 >> 16;
    if(prn_16<0x1000) prng_display += "0";
    if(prn_16<0x100) prng_display += "0";
    if(prn_16<0x10) prng_display += "0";
    prng_display += QString::number(prn_16, 16);
    ui->LCD_Seed2->display(prng_display);
}


void MainWindow::prng_start_duel()
{
    for(lo=0;lo<60;lo++){
        seed = prng_tetra_master(seed);
    }
}

