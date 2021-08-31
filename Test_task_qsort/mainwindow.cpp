#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qsort.h"
#include <QString>
#include <string>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString input = ui->input_text->toPlainText();
    QString output = "";
    QStringList numbers = input.split(" ");
    std::vector<int> data{};

    for (auto num_str : numbers)
    {
        data.push_back(num_str.toInt());
    }

    quick_sort(data.data(), 0, data.size() - 1);

    for (auto el : data)
    {
        std::string s = std::to_string(el) + " ";
        output.insert(output.length(), QString::fromStdString(s));
    }

    ui->output_text->setText(output);
}

