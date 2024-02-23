#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //move buttons
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();
    void on_pushButton6_clicked();
    void on_pushButton7_clicked();
    void on_pushButton8_clicked();
    void on_pushButton9_clicked();
    //start button
    void on_Start_clicked();

private:
    Ui::MainWindow *ui;
    QChar board[3][3];
    const QChar X='X';
    const QChar O='O';
    const QChar _=' ';
    QChar human, comp;
    bool  gameover;
    int counter;
    QPushButton* buttons[3][3];
    void display();
    void move_human(QChar);
    void move_comp(QChar);
    void game_play();
    void choose();
    int check_win();
};
#endif // MAINWINDOW_H
