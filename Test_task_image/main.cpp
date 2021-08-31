#include "mainwindow.h"
#include <QApplication>


void showImage(QString file_name)
{
    QImage myImage;
    myImage.load(file_name);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
