#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QGridLayout>
#include <QMessageBox>
#include <QSound>
#include <QSpacerItem>
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString card_text;
    QString error_message;
    QString img_path;
    QString prng_display;

    QPalette Dark;
    QPalette Neutral;
    QPalette PowerCard;

    quint32 debug;
    quint32 plouf;

    quint32 seed;
    quint32 seed_initial;
    quint32 seed_next;
    quint16 prn_16;
    quint32 prn_32;
    //quint64 prn_64;
    quint32 hi;
    quint32 lo;
    quint8 byte_storage;
    quint16 prng_calls_iterations;

    quint8 arrow_amount;
    quint8 arrow_new;

    quint8 base_attack;
    quint8 base_pdef;
    quint8 base_mdef;
    quint8 base_type;
    quint16 block_current;
    quint16 blocks;
    quint8 blocks_amount;
    quint8 blocks_placed;

    quint8 card_attack;
    quint8 card_pdef;
    quint8 card_mdef;
    quint8 card_arrows;
    quint8 card_type;
    quint16 card_offset;
    quint8 card_selected;
    QByteArray card_data;

    quint8 column;
    quint8 row;

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionAbout_triggered();
    void on_actionHelp_triggered();
    void on_actionKupo_triggered();
    void on_comboBox_Cards_currentIndexChanged(int);
    void on_spinBox_Cards_1_valueChanged(int);
    void on_spinBox_Cards_2_valueChanged(int);
    void on_spinBox_Cards_3_valueChanged(int);
    void on_spinBox_Cards_4_valueChanged(int);
    void on_spinBox_Cards_5_valueChanged(int);
    void on_spinBox_Cards_6_valueChanged(int);
    void on_spinBox_Cards_7_valueChanged(int);
    void on_spinBox_Cards_8_valueChanged(int);
    void on_spinBox_Cards_9_valueChanged(int);
    void on_spinBox_Cards_10_valueChanged(int);
    void on_spinBox_WMap_1_valueChanged(int);
    void on_spinBox_WMap_2_valueChanged(int);
    void on_spinBox_WMap_3_valueChanged(int);
    void on_spinBox_WMap_4_valueChanged(int);
    void on_spinBox_WMap_5_valueChanged(int);
    void on_spinBox_WMap_6_valueChanged(int);
    void on_spinBox_WMap_7_valueChanged(int);
    void on_spinBox_WMap_8_valueChanged(int);
    void on_spinBox_WMap_9_valueChanged(int);

    void display_board(quint8);
    void display_gen_card(quint8);
    void display_tot_card(quint8);
    void generate_board();
    void generate_boards();
    void generate_card(quint8);
    void generate_gen_cards();
    void generate_tot_cards();
    void initialize_display();
    void initialize_labels();
    void initialize_variables();
    void prng_call();
    void prng_seed_update();
    void prng_start_duel();
    void read_card(quint8);
    void read_card_data();
    void set_palettes();
};

#endif // MAINWINDOW_H
