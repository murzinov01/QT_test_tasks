#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_increase_brightness_clicked();
    void on_decrease_brightness_clicked();
    void on_add_blur_clicked();
    void on_set_default_clicked();

private:
    Ui::MainWindow *ui;
    QImage image, initial_image;
    int brightnessDelta = 5;

    QImage change_brightness(QImage& image, int brightness);
    QImage applyEffectToImage(QImage src, QGraphicsEffect *effect, int extent = 0);

};
#endif // MAINWINDOW_H
