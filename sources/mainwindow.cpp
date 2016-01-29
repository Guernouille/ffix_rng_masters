#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_palettes();
    read_card_data();
    initialize_display();
    initialize_variables();
}

MainWindow::~MainWindow()
{
    delete ui;
}
