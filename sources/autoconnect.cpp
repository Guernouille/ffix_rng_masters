#include "mainwindow.h"

void MainWindow::on_actionAbout_triggered()
{
    QSound::play(":/sound/moogle.wav");
    QMessageBox messageBox;
    QSpacerItem* horizontalSpacer = new QSpacerItem(300, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    messageBox.setIconPixmap(QPixmap(":/icon/mog"));
    messageBox.setTextFormat(Qt::RichText);
    messageBox.setText("RNG Masters, a RNG manipulation tool for Tetra Masters in Final Fantasy IX.\nCoded in C++ with Qt. Hope you enjoy this program !\nYou can contact me on <a href='http://forums.qhimm.com/index.php?action=profile;u=25024'>forums.qhimm.com</a> (froggy25) or on <a href='http://datacrystal.romhacking.net/wiki/User_talk:Mantidactyle'>datacrystal.romhacking.net</a> (Mantidactyle).\nShout out to the FFIX speedrunning community, you guys rock !");
    messageBox.setWindowTitle("About");
    QGridLayout* layout = (QGridLayout*)messageBox.layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
    messageBox.exec();
}

void MainWindow::on_actionHelp_triggered()
{
    QSound::play(":/sound/moogle.wav");
    QMessageBox messageBox;
    QSpacerItem* horizontalSpacer = new QSpacerItem(300, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    messageBox.setIconPixmap(QPixmap(":/icon/mog"));
    messageBox.setText("Input the number of cards you obtained since your last reset, and the number of times you've loaded the World Map since your last reset, in order.\nFor example, if you just started the game, obtained the 3 cards from Ticketmaster, went once on the World Map, obtained one card from a random encounter in the Ice Cavern, and went one more time on the World Map before reaching Dali, you would input 3 / 1 / 1 / 1 in this order.\nIf you need help on a specific part of the window, simply hover your mouse on it, a tooltip should appear.");
    messageBox.setWindowTitle("Help meeeeeee, kupo...");
    QGridLayout* layout = (QGridLayout*)messageBox.layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
    messageBox.exec();
}

void MainWindow::on_actionKupo_triggered()
{
    QSound::play(":/sound/moogle.wav");
    QMessageBox messageBox;
    QSpacerItem* horizontalSpacer = new QSpacerItem(200, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    messageBox.setIconPixmap(QPixmap(":/icon/mog"));
    messageBox.setText("Kupo !");
    messageBox.setWindowTitle("Kupo ?");
    QGridLayout* layout = (QGridLayout*)messageBox.layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
    messageBox.exec();
}


void MainWindow::on_comboBox_Cards_currentIndexChanged(int)
{
    generate_gen_cards();
}


void MainWindow::on_spinBox_Cards_1_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_Cards_2_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_Cards_3_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_Cards_4_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_Cards_5_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_Cards_6_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_Cards_7_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_Cards_8_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_Cards_9_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_Cards_10_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_WMap_1_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_WMap_2_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_WMap_3_valueChanged(int){
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_WMap_4_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_WMap_5_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_WMap_6_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_WMap_7_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_WMap_8_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}

void MainWindow::on_spinBox_WMap_9_valueChanged(int)
{
    prng_seed_update();
    initialize_labels();
    generate_tot_cards();
    generate_gen_cards();
    generate_boards();
}
