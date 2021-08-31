#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Documents/Test_task_image/image.jpg");
    int w = ui->label_image->width();
    int h = ui->label_image->height();
    pix = pix.scaled(w, h, Qt::KeepAspectRatio);
    ui->label_image->setPixmap(pix);
    image = pix.toImage();
    initial_image = pix.toImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_increase_brightness_clicked()
{
    image = change_brightness(image, brightnessDelta);
    ui->label_image->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_decrease_brightness_clicked()
{
    image = change_brightness(image, -brightnessDelta);
    ui->label_image->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_add_blur_clicked()
{
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(8);
    image = applyEffectToImage(image, blur);
    ui->label_image->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_set_default_clicked()
{
    ui->label_image->setPixmap(QPixmap::fromImage(initial_image));
    image = initial_image;
}


QImage MainWindow::applyEffectToImage(QImage src, QGraphicsEffect *effect, int extent)
{
    if(src.isNull())
    {
        return QImage();
    }
    if(!effect)
    {
        return src;
    }
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(src));
    item.setGraphicsEffect(effect);
    scene.addItem(&item);
    QImage res(src.size()+QSize(extent*2, extent*2), QImage::Format_ARGB32);
    res.fill(Qt::transparent);
    QPainter ptr(&res);
    scene.render(&ptr, QRectF(), QRectF( -extent, -extent, src.width()+extent*2, src.height()+extent*2 ) );
    return res;
}

QImage MainWindow::change_brightness(QImage& image, int brightness)
{
    uchar* line = image.scanLine(0);
    uchar* pixel;

    for (int y = 0; y < image.height(); ++y)
    {
        pixel = line;
        for (int x = 0; x < image.width(); ++x)
        {
            *pixel = qBound(0, *pixel + brightness, 255);
            *(pixel + 1) = qBound(0, *(pixel + 1) + brightness, 255);
            *(pixel + 2) = qBound(0, *(pixel + 2) + brightness, 255);
            pixel += 4;
        }

        line += image.bytesPerLine();
    }
    return image;
}
