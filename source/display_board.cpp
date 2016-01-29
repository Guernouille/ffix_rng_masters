#include "mainwindow.h"

void MainWindow::display_board(quint8 i){
    switch(i){
        case 1:
            if(blocks & 0x0001) ui->img_block_1_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0002) ui->img_block_2_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0004) ui->img_block_3_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0008) ui->img_block_4_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0010) ui->img_block_5_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0020) ui->img_block_6_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0040) ui->img_block_7_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0080) ui->img_block_8_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0100) ui->img_block_9_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0200) ui->img_block_10_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0400) ui->img_block_11_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0800) ui->img_block_12_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x1000) ui->img_block_13_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x2000) ui->img_block_14_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x4000) ui->img_block_15_1->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x8000) ui->img_block_16_1->setPixmap(QPixmap(":/board/block"));
            break;
        case 2:
            if(blocks & 0x0001) ui->img_block_1_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0002) ui->img_block_2_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0004) ui->img_block_3_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0008) ui->img_block_4_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0010) ui->img_block_5_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0020) ui->img_block_6_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0040) ui->img_block_7_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0080) ui->img_block_8_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0100) ui->img_block_9_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0200) ui->img_block_10_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0400) ui->img_block_11_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0800) ui->img_block_12_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x1000) ui->img_block_13_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x2000) ui->img_block_14_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x4000) ui->img_block_15_2->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x8000) ui->img_block_16_2->setPixmap(QPixmap(":/board/block"));
            break;
        case 3:
            if(blocks & 0x0001) ui->img_block_1_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0002) ui->img_block_2_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0004) ui->img_block_3_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0008) ui->img_block_4_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0010) ui->img_block_5_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0020) ui->img_block_6_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0040) ui->img_block_7_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0080) ui->img_block_8_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0100) ui->img_block_9_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0200) ui->img_block_10_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0400) ui->img_block_11_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x0800) ui->img_block_12_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x1000) ui->img_block_13_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x2000) ui->img_block_14_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x4000) ui->img_block_15_3->setPixmap(QPixmap(":/board/block"));
            if(blocks & 0x8000) ui->img_block_16_3->setPixmap(QPixmap(":/board/block"));
            break;
        default:
            QMessageBox::critical(this, "Error", "Tried to load a board outside bounds. This should never happen, please report this bug to froggy25 / Mantidactyle.");
            QApplication::quit();
    }
}
