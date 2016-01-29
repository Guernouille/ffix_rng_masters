#include "mainwindow.h"

void MainWindow::display_gen_card(quint8 i){
    if(i<5 && i>0){
        switch(card_type){
            case 0:
                card_text = "P";
                break;
            case 1:
                card_text = "M";
                break;
            case 2:
                card_text = "X";
                break;
            case 3:
                card_text = "A";
                break;
            default :
                QMessageBox::warning(this, "Invalid Type", "One of the cards card has an invalid Type. Make sure your base_stats.bin file is not corrupted.");
                QApplication::quit();
        }
        card_text = QString::number(card_attack >> 4, 16) + card_text;
        card_text += QString::number(card_pdef >> 4, 16) + QString::number(card_mdef >> 4, 16);
        card_text = card_text.toUpper();

        switch(i){
            case 1:
                ui->label_genstats_1->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_gen_1->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_gen_1->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_gen_1->setText(card_text);
                break;
            case 2:
                ui->label_genstats_2->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_gen_2->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_gen_2->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_gen_2->setText(card_text);
                break;
            case 3:
                ui->label_genstats_3->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_gen_3->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_gen_3->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_gen_3->setText(card_text);
                break;
            case 4:
                ui->label_genstats_4->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_gen_4->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_gen_4->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_gen_4->setText(card_text);
                break;
            default:
                QMessageBox::critical(this, "Error", "Tried to load a card outside bounds. This should never happen, please report this bug to froggy25 / Mantidactyle.");
                QApplication::quit();
        }

        if(card_type == 2){
            if(i==1){
                ui->label_genstats_1->setAutoFillBackground(true);
                ui->label_genstats_1->setPalette(PowerCard);
             }
            if(i==2){
                ui->label_genstats_2->setAutoFillBackground(true);
                ui->label_genstats_2->setPalette(PowerCard);
             }
            if(i==3){
                ui->label_genstats_3->setAutoFillBackground(true);
                ui->label_genstats_3->setPalette(PowerCard);
             }
            if(i==4){
                ui->label_genstats_4->setAutoFillBackground(true);
                ui->label_genstats_4->setPalette(PowerCard);
             }
        }
        else if(card_selected != 57 && card_selected != 58 && card_selected != 59 && card_selected != 90 && card_selected != 91){
            if(i==1){
                ui->label_genstats_1->setAutoFillBackground(false);
                ui->label_genstats_1->setPalette(Neutral);
            }
            if(i==2){
                ui->label_genstats_2->setAutoFillBackground(false);
                ui->label_genstats_2->setPalette(Neutral);
            }
            if(i==3){
                ui->label_genstats_3->setAutoFillBackground(false);
                ui->label_genstats_3->setPalette(Neutral);
            }
            if(i==4){
                ui->label_genstats_4->setAutoFillBackground(false);
                ui->label_genstats_4->setPalette(Neutral);
            }
        }
        else{
            if(i==1){
                ui->label_genstats_1->setAutoFillBackground(false);
                ui->label_genstats_1->setPalette(Dark);
            }
            if(i==2){
                ui->label_genstats_2->setAutoFillBackground(false);
                ui->label_genstats_2->setPalette(Dark);
            }
            if(i==3){
                ui->label_genstats_3->setAutoFillBackground(false);
                ui->label_genstats_3->setPalette(Dark);
            }
            if(i==4){
                ui->label_genstats_4->setAutoFillBackground(false);
                ui->label_genstats_4->setPalette(Dark);
            }
        }
    }
    else{
        QMessageBox::critical(this, "Error", "Tried to load a card outside bounds. This should never happen, please report this bug to froggy25 / Mantidactyle.");
        QApplication::quit();
    }
}

void MainWindow::display_tot_card(quint8 i)
{
    if(i<16 && i>0){
        switch(card_type){
            case 0:
                card_text = "P";
                break;
            case 1:
                card_text = "M";
                break;
            case 2:
                card_text = "X";
                break;
            case 3:
                card_text = "A";
                break;
            default :
                card_text = " ";
                QMessageBox::warning(this, "Invalid Type", "One of the cards card has an invalid Type. Make sure your base_stats.bin file is not corrupted.");
                QApplication::quit();
        }
        card_text = QString::number(card_attack >> 4, 16) + card_text;
        card_text += QString::number(card_pdef >> 4, 16) + QString::number(card_mdef >> 4, 16);
        card_text = card_text.toUpper();

        switch(i){
            case 1:
                if(card_type == 2){
                    ui->label_totstats_1->setAutoFillBackground(true);
                    ui->label_totstats_1->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_1->setAutoFillBackground(false);
                    ui->label_totstats_1->setPalette(Neutral);
                }
                ui->label_totstats_1->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_1->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_1->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_1->setText(card_text);

                if(card_arrows & 0x01){
                    ui->img_genarrow_n_1->setPixmap(QPixmap(":/arrows/arrow_n"));
                    ui->img_totarrow_n_1->setPixmap(QPixmap(":/arrows/arrow_n"));
                }
                if(card_arrows & 0x02){
                    ui->img_genarrow_ne_1->setPixmap(QPixmap(":/arrows/arrow_ne"));
                    ui->img_totarrow_ne_1->setPixmap(QPixmap(":/arrows/arrow_ne"));
                }
                if(card_arrows & 0x04){
                    ui->img_genarrow_e_1->setPixmap(QPixmap(":/arrows/arrow_e"));
                    ui->img_totarrow_e_1->setPixmap(QPixmap(":/arrows/arrow_e"));
                }
                if(card_arrows & 0x08){
                    ui->img_genarrow_se_1->setPixmap(QPixmap(":/arrows/arrow_se"));
                    ui->img_totarrow_se_1->setPixmap(QPixmap(":/arrows/arrow_se"));
                }
                if(card_arrows & 0x10){
                    ui->img_genarrow_s_1->setPixmap(QPixmap(":/arrows/arrow_s"));
                    ui->img_totarrow_s_1->setPixmap(QPixmap(":/arrows/arrow_s"));
                }
                if(card_arrows & 0x20){
                    ui->img_genarrow_sw_1->setPixmap(QPixmap(":/arrows/arrow_sw"));
                    ui->img_totarrow_sw_1->setPixmap(QPixmap(":/arrows/arrow_sw"));
                }
                if(card_arrows & 0x40){
                    ui->img_genarrow_w_1->setPixmap(QPixmap(":/arrows/arrow_w"));
                    ui->img_totarrow_w_1->setPixmap(QPixmap(":/arrows/arrow_w"));
                }
                if(card_arrows & 0x80){
                    ui->img_genarrow_nw_1->setPixmap(QPixmap(":/arrows/arrow_nw"));
                    ui->img_totarrow_nw_1->setPixmap(QPixmap(":/arrows/arrow_nw"));
                }
                break;
            case 2:
                if(card_type == 2){
                    ui->label_totstats_2->setAutoFillBackground(true);
                    ui->label_totstats_2->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_2->setAutoFillBackground(false);
                    ui->label_totstats_2->setPalette(Neutral);
                }
                ui->label_totstats_2->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_2->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_2->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_2->setText(card_text);

                if(card_arrows & 0x01){
                    ui->img_genarrow_n_2->setPixmap(QPixmap(":/arrows/arrow_n"));
                    ui->img_totarrow_n_2->setPixmap(QPixmap(":/arrows/arrow_n"));
                }
                if(card_arrows & 0x02){
                    ui->img_genarrow_ne_2->setPixmap(QPixmap(":/arrows/arrow_ne"));
                    ui->img_totarrow_ne_2->setPixmap(QPixmap(":/arrows/arrow_ne"));
                }
                if(card_arrows & 0x04){
                    ui->img_genarrow_e_2->setPixmap(QPixmap(":/arrows/arrow_e"));
                    ui->img_totarrow_e_2->setPixmap(QPixmap(":/arrows/arrow_e"));
                }
                if(card_arrows & 0x08){
                    ui->img_genarrow_se_2->setPixmap(QPixmap(":/arrows/arrow_se"));
                    ui->img_totarrow_se_2->setPixmap(QPixmap(":/arrows/arrow_se"));
                }
                if(card_arrows & 0x10){
                    ui->img_genarrow_s_2->setPixmap(QPixmap(":/arrows/arrow_s"));
                    ui->img_totarrow_s_2->setPixmap(QPixmap(":/arrows/arrow_s"));
                }

                if(card_arrows & 0x20){
                    ui->img_genarrow_sw_2->setPixmap(QPixmap(":/arrows/arrow_sw"));
                    ui->img_totarrow_sw_2->setPixmap(QPixmap(":/arrows/arrow_sw"));
                }
                if(card_arrows & 0x40){
                    ui->img_genarrow_w_2->setPixmap(QPixmap(":/arrows/arrow_w"));
                    ui->img_totarrow_w_2->setPixmap(QPixmap(":/arrows/arrow_w"));
                }
                if(card_arrows & 0x80){
                    ui->img_genarrow_nw_2->setPixmap(QPixmap(":/arrows/arrow_nw"));
                    ui->img_totarrow_nw_2->setPixmap(QPixmap(":/arrows/arrow_nw"));
                }
                break;
            case 3:
                if(card_type == 2){
                    ui->label_totstats_3->setAutoFillBackground(true);
                    ui->label_totstats_3->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_3->setAutoFillBackground(false);
                    ui->label_totstats_3->setPalette(Neutral);
                }
                ui->label_totstats_3->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_3->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_3->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_3->setText(card_text);

                if(card_arrows & 0x01){
                    ui->img_genarrow_n_3->setPixmap(QPixmap(":/arrows/arrow_n"));
                    ui->img_totarrow_n_3->setPixmap(QPixmap(":/arrows/arrow_n"));
                }
                if(card_arrows & 0x02){
                    ui->img_genarrow_ne_3->setPixmap(QPixmap(":/arrows/arrow_ne"));
                    ui->img_totarrow_ne_3->setPixmap(QPixmap(":/arrows/arrow_ne"));
                }
                if(card_arrows & 0x04){
                    ui->img_genarrow_e_3->setPixmap(QPixmap(":/arrows/arrow_e"));
                    ui->img_totarrow_e_3->setPixmap(QPixmap(":/arrows/arrow_e"));
                }
                if(card_arrows & 0x08){
                    ui->img_genarrow_se_3->setPixmap(QPixmap(":/arrows/arrow_se"));
                    ui->img_totarrow_se_3->setPixmap(QPixmap(":/arrows/arrow_se"));
                }
                if(card_arrows & 0x10){
                    ui->img_genarrow_s_3->setPixmap(QPixmap(":/arrows/arrow_s"));
                    ui->img_totarrow_s_3->setPixmap(QPixmap(":/arrows/arrow_s"));
                }

                if(card_arrows & 0x20){
                    ui->img_genarrow_sw_3->setPixmap(QPixmap(":/arrows/arrow_sw"));
                    ui->img_totarrow_sw_3->setPixmap(QPixmap(":/arrows/arrow_sw"));
                }
                if(card_arrows & 0x40){
                    ui->img_genarrow_w_3->setPixmap(QPixmap(":/arrows/arrow_w"));
                    ui->img_totarrow_w_3->setPixmap(QPixmap(":/arrows/arrow_w"));
                }
                if(card_arrows & 0x80){
                    ui->img_genarrow_nw_3->setPixmap(QPixmap(":/arrows/arrow_nw"));
                    ui->img_totarrow_nw_3->setPixmap(QPixmap(":/arrows/arrow_nw"));
                }
                break;
            case 4:
                if(card_type == 2){
                    ui->label_totstats_4->setAutoFillBackground(true);
                    ui->label_totstats_4->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_4->setAutoFillBackground(false);
                    ui->label_totstats_4->setPalette(Neutral);
                }
                ui->label_totstats_4->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_4->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_4->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_4->setText(card_text);

                if(card_arrows & 0x01){
                    ui->img_genarrow_n_4->setPixmap(QPixmap(":/arrows/arrow_n"));
                    ui->img_totarrow_n_4->setPixmap(QPixmap(":/arrows/arrow_n"));
                }
                if(card_arrows & 0x02){
                    ui->img_genarrow_ne_4->setPixmap(QPixmap(":/arrows/arrow_ne"));
                    ui->img_totarrow_ne_4->setPixmap(QPixmap(":/arrows/arrow_ne"));
                }
                if(card_arrows & 0x04){
                    ui->img_genarrow_e_4->setPixmap(QPixmap(":/arrows/arrow_e"));
                    ui->img_totarrow_e_4->setPixmap(QPixmap(":/arrows/arrow_e"));
                }
                if(card_arrows & 0x08){
                    ui->img_genarrow_se_4->setPixmap(QPixmap(":/arrows/arrow_se"));
                    ui->img_totarrow_se_4->setPixmap(QPixmap(":/arrows/arrow_se"));
                }
                if(card_arrows & 0x10){
                    ui->img_genarrow_s_4->setPixmap(QPixmap(":/arrows/arrow_s"));
                    ui->img_totarrow_s_4->setPixmap(QPixmap(":/arrows/arrow_s"));
                }

                if(card_arrows & 0x20){
                    ui->img_genarrow_sw_4->setPixmap(QPixmap(":/arrows/arrow_sw"));
                    ui->img_totarrow_sw_4->setPixmap(QPixmap(":/arrows/arrow_sw"));
                }
                if(card_arrows & 0x40){
                    ui->img_genarrow_w_4->setPixmap(QPixmap(":/arrows/arrow_w"));
                    ui->img_totarrow_w_4->setPixmap(QPixmap(":/arrows/arrow_w"));
                }
                if(card_arrows & 0x80){
                    ui->img_genarrow_nw_4->setPixmap(QPixmap(":/arrows/arrow_nw"));
                    ui->img_totarrow_nw_4->setPixmap(QPixmap(":/arrows/arrow_nw"));
                }
                break;
            case 5:
                if(card_type == 2){
                    ui->label_totstats_5->setAutoFillBackground(true);
                    ui->label_totstats_5->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_5->setAutoFillBackground(false);
                    ui->label_totstats_5->setPalette(Neutral);
                }
                ui->label_totstats_5->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_5->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_5->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_5->setText(card_text);
                if(card_arrows & 0x01) ui->img_totarrow_n_5->setPixmap(QPixmap(":/arrows/arrow_n"));
                if(card_arrows & 0x02) ui->img_totarrow_ne_5->setPixmap(QPixmap(":/arrows/arrow_ne"));
                if(card_arrows & 0x04) ui->img_totarrow_e_5->setPixmap(QPixmap(":/arrows/arrow_e"));
                if(card_arrows & 0x08) ui->img_totarrow_se_5->setPixmap(QPixmap(":/arrows/arrow_se"));
                if(card_arrows & 0x10) ui->img_totarrow_s_5->setPixmap(QPixmap(":/arrows/arrow_s"));
                if(card_arrows & 0x20) ui->img_totarrow_sw_5->setPixmap(QPixmap(":/arrows/arrow_sw"));
                if(card_arrows & 0x40) ui->img_totarrow_w_5->setPixmap(QPixmap(":/arrows/arrow_w"));
                if(card_arrows & 0x80) ui->img_totarrow_nw_5->setPixmap(QPixmap(":/arrows/arrow_nw"));
                break;
            case 6:
                if(card_type == 2){
                    ui->label_totstats_6->setAutoFillBackground(true);
                    ui->label_totstats_6->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_6->setAutoFillBackground(false);
                    ui->label_totstats_6->setPalette(Neutral);
                }
                ui->label_totstats_6->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_6->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_6->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_6->setText(card_text);
                if(card_arrows & 0x01) ui->img_totarrow_n_6->setPixmap(QPixmap(":/arrows/arrow_n"));
                if(card_arrows & 0x02) ui->img_totarrow_ne_6->setPixmap(QPixmap(":/arrows/arrow_ne"));
                if(card_arrows & 0x04) ui->img_totarrow_e_6->setPixmap(QPixmap(":/arrows/arrow_e"));
                if(card_arrows & 0x08) ui->img_totarrow_se_6->setPixmap(QPixmap(":/arrows/arrow_se"));
                if(card_arrows & 0x10) ui->img_totarrow_s_6->setPixmap(QPixmap(":/arrows/arrow_s"));
                if(card_arrows & 0x20) ui->img_totarrow_sw_6->setPixmap(QPixmap(":/arrows/arrow_sw"));
                if(card_arrows & 0x40) ui->img_totarrow_w_6->setPixmap(QPixmap(":/arrows/arrow_w"));
                if(card_arrows & 0x80) ui->img_totarrow_nw_6->setPixmap(QPixmap(":/arrows/arrow_nw"));
                break;
            case 7:
                if(card_type == 2){
                    ui->label_totstats_7->setAutoFillBackground(true);
                    ui->label_totstats_7->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_7->setAutoFillBackground(false);
                    ui->label_totstats_7->setPalette(Neutral);
                }
                ui->label_totstats_7->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_7->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_7->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_7->setText(card_text);
                if(card_arrows & 0x01) ui->img_totarrow_n_7->setPixmap(QPixmap(":/arrows/arrow_n"));
                if(card_arrows & 0x02) ui->img_totarrow_ne_7->setPixmap(QPixmap(":/arrows/arrow_ne"));
                if(card_arrows & 0x04) ui->img_totarrow_e_7->setPixmap(QPixmap(":/arrows/arrow_e"));
                if(card_arrows & 0x08) ui->img_totarrow_se_7->setPixmap(QPixmap(":/arrows/arrow_se"));
                if(card_arrows & 0x10) ui->img_totarrow_s_7->setPixmap(QPixmap(":/arrows/arrow_s"));
                if(card_arrows & 0x20) ui->img_totarrow_sw_7->setPixmap(QPixmap(":/arrows/arrow_sw"));
                if(card_arrows & 0x40) ui->img_totarrow_w_7->setPixmap(QPixmap(":/arrows/arrow_w"));
                if(card_arrows & 0x80) ui->img_totarrow_nw_7->setPixmap(QPixmap(":/arrows/arrow_nw"));
                break;
            case 8:
                if(card_type == 2){
                    ui->label_totstats_8->setAutoFillBackground(true);
                    ui->label_totstats_8->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_8->setAutoFillBackground(false);
                    ui->label_totstats_8->setPalette(Neutral);
                }
                ui->label_totstats_8->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_8->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_8->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_8->setText(card_text);
                if(card_arrows & 0x01) ui->img_totarrow_n_8->setPixmap(QPixmap(":/arrows/arrow_n"));
                if(card_arrows & 0x02) ui->img_totarrow_ne_8->setPixmap(QPixmap(":/arrows/arrow_ne"));
                if(card_arrows & 0x04) ui->img_totarrow_e_8->setPixmap(QPixmap(":/arrows/arrow_e"));
                if(card_arrows & 0x08) ui->img_totarrow_se_8->setPixmap(QPixmap(":/arrows/arrow_se"));
                if(card_arrows & 0x10) ui->img_totarrow_s_8->setPixmap(QPixmap(":/arrows/arrow_s"));
                if(card_arrows & 0x20) ui->img_totarrow_sw_8->setPixmap(QPixmap(":/arrows/arrow_sw"));
                if(card_arrows & 0x40) ui->img_totarrow_w_8->setPixmap(QPixmap(":/arrows/arrow_w"));
                if(card_arrows & 0x80) ui->img_totarrow_nw_8->setPixmap(QPixmap(":/arrows/arrow_nw"));
                break;
            case 9:
                if(card_type == 2){
                    ui->label_totstats_9->setAutoFillBackground(true);
                    ui->label_totstats_9->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_9->setAutoFillBackground(false);
                    ui->label_totstats_9->setPalette(Neutral);
                }
                ui->label_totstats_9->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_9->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_9->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_9->setText(card_text);
                if(card_arrows & 0x01) ui->img_totarrow_n_9->setPixmap(QPixmap(":/arrows/arrow_n"));
                if(card_arrows & 0x02) ui->img_totarrow_ne_9->setPixmap(QPixmap(":/arrows/arrow_ne"));
                if(card_arrows & 0x04) ui->img_totarrow_e_9->setPixmap(QPixmap(":/arrows/arrow_e"));
                if(card_arrows & 0x08) ui->img_totarrow_se_9->setPixmap(QPixmap(":/arrows/arrow_se"));
                if(card_arrows & 0x10) ui->img_totarrow_s_9->setPixmap(QPixmap(":/arrows/arrow_s"));
                if(card_arrows & 0x20) ui->img_totarrow_sw_9->setPixmap(QPixmap(":/arrows/arrow_sw"));
                if(card_arrows & 0x40) ui->img_totarrow_w_9->setPixmap(QPixmap(":/arrows/arrow_w"));
                if(card_arrows & 0x80) ui->img_totarrow_nw_9->setPixmap(QPixmap(":/arrows/arrow_nw"));
                break;
            case 10:
                if(card_type == 2){
                    ui->label_totstats_10->setAutoFillBackground(true);
                    ui->label_totstats_10->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_10->setAutoFillBackground(false);
                    ui->label_totstats_10->setPalette(Neutral);
                }
                ui->label_totstats_10->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_10->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_10->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_10->setText(card_text);
                if(card_arrows & 0x01) ui->img_totarrow_n_10->setPixmap(QPixmap(":/arrows/arrow_n"));
                if(card_arrows & 0x02) ui->img_totarrow_ne_10->setPixmap(QPixmap(":/arrows/arrow_ne"));
                if(card_arrows & 0x04) ui->img_totarrow_e_10->setPixmap(QPixmap(":/arrows/arrow_e"));
                if(card_arrows & 0x08) ui->img_totarrow_se_10->setPixmap(QPixmap(":/arrows/arrow_se"));
                if(card_arrows & 0x10) ui->img_totarrow_s_10->setPixmap(QPixmap(":/arrows/arrow_s"));
                if(card_arrows & 0x20) ui->img_totarrow_sw_10->setPixmap(QPixmap(":/arrows/arrow_sw"));
                if(card_arrows & 0x40) ui->img_totarrow_w_10->setPixmap(QPixmap(":/arrows/arrow_w"));
                if(card_arrows & 0x80) ui->img_totarrow_nw_10->setPixmap(QPixmap(":/arrows/arrow_nw"));
                break;
                case 11:
                if(card_type == 2){
                    ui->label_totstats_11->setAutoFillBackground(true);
                    ui->label_totstats_11->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_11->setAutoFillBackground(false);
                    ui->label_totstats_11->setPalette(Neutral);
                }
                ui->label_totstats_11->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_11->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_11->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_11->setText(card_text);
                if(card_arrows & 0x01) ui->img_totarrow_n_11->setPixmap(QPixmap(":/arrows/arrow_n"));
                if(card_arrows & 0x02) ui->img_totarrow_ne_11->setPixmap(QPixmap(":/arrows/arrow_ne"));
                if(card_arrows & 0x04) ui->img_totarrow_e_11->setPixmap(QPixmap(":/arrows/arrow_e"));
                if(card_arrows & 0x08) ui->img_totarrow_se_11->setPixmap(QPixmap(":/arrows/arrow_se"));
                if(card_arrows & 0x10) ui->img_totarrow_s_11->setPixmap(QPixmap(":/arrows/arrow_s"));
                if(card_arrows & 0x20) ui->img_totarrow_sw_11->setPixmap(QPixmap(":/arrows/arrow_sw"));
                if(card_arrows & 0x40) ui->img_totarrow_w_11->setPixmap(QPixmap(":/arrows/arrow_w"));
                if(card_arrows & 0x80) ui->img_totarrow_nw_11->setPixmap(QPixmap(":/arrows/arrow_nw"));
                break;
            case 12:
                if(card_type == 2){
                    ui->label_totstats_12->setAutoFillBackground(true);
                    ui->label_totstats_12->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_12->setAutoFillBackground(false);
                    ui->label_totstats_12->setPalette(Neutral);
                }
                ui->label_totstats_12->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_12->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_12->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_12->setText(card_text);
                if(card_arrows & 0x01) ui->img_totarrow_n_12->setPixmap(QPixmap(":/arrows/arrow_n"));
                if(card_arrows & 0x02) ui->img_totarrow_ne_12->setPixmap(QPixmap(":/arrows/arrow_ne"));
                if(card_arrows & 0x04) ui->img_totarrow_e_12->setPixmap(QPixmap(":/arrows/arrow_e"));
                if(card_arrows & 0x08) ui->img_totarrow_se_12->setPixmap(QPixmap(":/arrows/arrow_se"));
                if(card_arrows & 0x10) ui->img_totarrow_s_12->setPixmap(QPixmap(":/arrows/arrow_s"));
                if(card_arrows & 0x20) ui->img_totarrow_sw_12->setPixmap(QPixmap(":/arrows/arrow_sw"));
                if(card_arrows & 0x40) ui->img_totarrow_w_12->setPixmap(QPixmap(":/arrows/arrow_w"));
                if(card_arrows & 0x80) ui->img_totarrow_nw_12->setPixmap(QPixmap(":/arrows/arrow_nw"));
                break;
            case 13:
                if(card_type == 2){
                    ui->label_totstats_13->setAutoFillBackground(true);
                    ui->label_totstats_13->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_13->setAutoFillBackground(false);
                    ui->label_totstats_13->setPalette(Neutral);
                }
                ui->label_totstats_13->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_13->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_13->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_13->setText(card_text);
                if(card_arrows & 0x01) ui->img_totarrow_n_13->setPixmap(QPixmap(":/arrows/arrow_n"));
                if(card_arrows & 0x02) ui->img_totarrow_ne_13->setPixmap(QPixmap(":/arrows/arrow_ne"));
                if(card_arrows & 0x04) ui->img_totarrow_e_13->setPixmap(QPixmap(":/arrows/arrow_e"));
                if(card_arrows & 0x08) ui->img_totarrow_se_13->setPixmap(QPixmap(":/arrows/arrow_se"));
                if(card_arrows & 0x10) ui->img_totarrow_s_13->setPixmap(QPixmap(":/arrows/arrow_s"));
                if(card_arrows & 0x20) ui->img_totarrow_sw_13->setPixmap(QPixmap(":/arrows/arrow_sw"));
                if(card_arrows & 0x40) ui->img_totarrow_w_13->setPixmap(QPixmap(":/arrows/arrow_w"));
                if(card_arrows & 0x80) ui->img_totarrow_nw_13->setPixmap(QPixmap(":/arrows/arrow_nw"));
                break;
            case 14:
                if(card_type == 2){
                    ui->label_totstats_14->setAutoFillBackground(true);
                    ui->label_totstats_14->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_14->setAutoFillBackground(false);
                    ui->label_totstats_14->setPalette(Neutral);
                }
                ui->label_totstats_14->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_14->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_14->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_14->setText(card_text);
                if(card_arrows & 0x01) ui->img_totarrow_n_14->setPixmap(QPixmap(":/arrows/arrow_n"));
                if(card_arrows & 0x02) ui->img_totarrow_ne_14->setPixmap(QPixmap(":/arrows/arrow_ne"));
                if(card_arrows & 0x04) ui->img_totarrow_e_14->setPixmap(QPixmap(":/arrows/arrow_e"));
                if(card_arrows & 0x08) ui->img_totarrow_se_14->setPixmap(QPixmap(":/arrows/arrow_se"));
                if(card_arrows & 0x10) ui->img_totarrow_s_14->setPixmap(QPixmap(":/arrows/arrow_s"));
                if(card_arrows & 0x20) ui->img_totarrow_sw_14->setPixmap(QPixmap(":/arrows/arrow_sw"));
                if(card_arrows & 0x40) ui->img_totarrow_w_14->setPixmap(QPixmap(":/arrows/arrow_w"));
                if(card_arrows & 0x80) ui->img_totarrow_nw_14->setPixmap(QPixmap(":/arrows/arrow_nw"));
                break;
            case 15:
                if(card_type == 2){
                    ui->label_totstats_15->setAutoFillBackground(true);
                    ui->label_totstats_15->setPalette(PowerCard);
                }
                else{
                    ui->label_totstats_15->setAutoFillBackground(false);
                    ui->label_totstats_15->setPalette(Neutral);
                }
                ui->label_totstats_15->setText(card_text);
                card_text = "ATK: " + QString::number(card_attack,10);
                ui->label_ATK_15->setText(card_text);
                card_text = "P. DEF: " + QString::number(card_pdef,10);
                ui->label_PDEF_15->setText(card_text);
                card_text = "M. DEF: " + QString::number(card_mdef,10);
                ui->label_MDEF_15->setText(card_text);
                if(card_arrows & 0x01) ui->img_totarrow_n_15->setPixmap(QPixmap(":/arrows/arrow_n"));
                if(card_arrows & 0x02) ui->img_totarrow_ne_15->setPixmap(QPixmap(":/arrows/arrow_ne"));
                if(card_arrows & 0x04) ui->img_totarrow_e_15->setPixmap(QPixmap(":/arrows/arrow_e"));
                if(card_arrows & 0x08) ui->img_totarrow_se_15->setPixmap(QPixmap(":/arrows/arrow_se"));
                if(card_arrows & 0x10) ui->img_totarrow_s_15->setPixmap(QPixmap(":/arrows/arrow_s"));
                if(card_arrows & 0x20) ui->img_totarrow_sw_15->setPixmap(QPixmap(":/arrows/arrow_sw"));
                if(card_arrows & 0x40) ui->img_totarrow_w_15->setPixmap(QPixmap(":/arrows/arrow_w"));
                if(card_arrows & 0x80) ui->img_totarrow_nw_15->setPixmap(QPixmap(":/arrows/arrow_nw"));
                break;
            default :
                QMessageBox::critical(this, "Error", "Tried to load a card outside bounds for Tot. This should never happen, please report this bug to froggy25 / Mantidactyle.");
                QApplication::quit();
        }
    }
    else{
        QMessageBox::critical(this, "Error", "Tried to load a card outside bounds for Tot. This should never happen, please report this bug to froggy25 / Mantidactyle.");
        QApplication::quit();
    }

}
