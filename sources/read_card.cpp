#include "mainwindow.h"

void MainWindow::read_card(quint8 i)
{
    if(i<101 && i>0){
        card_offset = i*5;
        card_offset -= 5;
        base_attack = card_data[card_offset];
        card_offset++;
        base_type = card_data[card_offset];
        card_offset++;
        base_pdef = card_data[card_offset];
        card_offset++;
        base_mdef = card_data[card_offset];
    }
    else{
        QMessageBox::critical(this, "Invalid Card ID", "The submitted card ID is either over 100 or under 1!");
        QApplication::quit();
    }
}

void MainWindow::read_card_data()
{
    QString filename = ":/data/base_stats.bin";
    QFile basestats_file(filename);
    basestats_file.open(QIODevice::ReadOnly);
    QDataStream read(&basestats_file);
    read.setByteOrder(QDataStream::LittleEndian);

    if(basestats_file.size() == 500) {
        for(lo=0;lo<500;lo++){
            basestats_file.seek(lo);
            read>>byte_storage;
            card_data[lo]=byte_storage;
        }
    }
    else {
        basestats_file.close();
        QMessageBox::critical(this, "Invalid File", "The Base Stats file is not valid!");
        QApplication::quit();
    }
}
