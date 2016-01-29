#include "mainwindow.h"
#include "prng.h"

void MainWindow::generate_card(quint8 card_ID)
{
    if(card_ID < 101 && card_ID > 0){
        read_card(card_ID);

       /*********** Attack ***********/
        card_attack = base_attack >> 1;
        if(card_attack > 0){
            seed = prng_tetra_master(seed);
            prn_16 = (seed >> 16) & 0x7FFF;
            card_attack += prn_16 % card_attack;
        }

       /****** Physical Defense ******/
        card_pdef = base_pdef >> 1;
        if(card_pdef > 0){
            seed = prng_tetra_master(seed);
            prn_16 = (seed >> 16) & 0x7FFF;
            card_pdef += prn_16 % card_pdef;
        }

       /****** Magical Defense ******/
        card_mdef = base_mdef >> 1;
        if(card_mdef > 0){
            seed = prng_tetra_master(seed);
            prn_16 = (seed >> 16) & 0x7FFF;
            card_mdef += prn_16 % card_mdef;
        }

       /********** Arrows **********/
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
        else if(prn_16<34) arrow_amount = 2;
        else if(prn_16<65) arrow_amount = 3;
        else if(prn_16<83) arrow_amount = 4;
        else if(prn_16<92) arrow_amount = 5;
        else if(prn_16<97) arrow_amount = 6;
        else if(prn_16<99) arrow_amount = 7;
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

       /*********** Type ***********/
        seed = prng_tetra_master(seed);
        prn_16 = (seed >> 16) & 0x7F;
        if(prn_16 == 0) card_type = 2;
        else card_type = base_type;
    }
    else{
        QMessageBox::critical(this, "Invalid Card ID", "The Card ID must be between 1 and 100!");
        QApplication::quit();
    }
}


void MainWindow::generate_gen_cards()
{
    seed_initial = seed;
    card_selected = ui->comboBox_Cards->currentIndex() +1;

    ui->img_gencard_1->clear();
    ui->img_gencard_2->clear();
    ui->img_gencard_3->clear();
    ui->img_gencard_4->clear();

    generate_card(card_selected);
    display_gen_card(1);
    generate_card(card_selected);
    display_gen_card(2);
    generate_card(card_selected);
    display_gen_card(3);
    generate_card(card_selected);
    display_gen_card(4);
    seed = seed_initial;

    img_path = ":/cards/";
    if(card_selected<100) img_path += "0";
    if(card_selected<10) img_path += "0";
    img_path += QString::number(card_selected);
    ui->img_gencard_1->setPixmap(QPixmap(img_path));
    ui->img_gencard_2->setPixmap(QPixmap(img_path));
    ui->img_gencard_3->setPixmap(QPixmap(img_path));
    ui->img_gencard_4->setPixmap(QPixmap(img_path));
}


void MainWindow::generate_tot_cards()
{
    seed_initial = seed;

    generate_card(20);
    display_tot_card(1);
    seed_next = seed;
    generate_card(22);
    display_tot_card(2);
    generate_card(24);
    display_tot_card(3);
    generate_card(29);
    display_tot_card(4);
    generate_card(78);
    display_tot_card(5);

    seed = seed_next;
    generate_card(20);
    display_tot_card(6);
    seed_next = seed;
    generate_card(22);
    display_tot_card(7);
    generate_card(24);
    display_tot_card(8);
    generate_card(29);
    display_tot_card(9);
    generate_card(78);
    display_tot_card(10);

    seed = seed_next;
    generate_card(20);
    display_tot_card(11);
    generate_card(22);
    display_tot_card(12);
    generate_card(24);
    display_tot_card(13);
    generate_card(29);
    display_tot_card(14);
    generate_card(78);
    display_tot_card(15);

    seed = seed_initial;
}
