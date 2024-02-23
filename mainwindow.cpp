#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttons[0][0] = ui->pushButton1;
    buttons[0][1] = ui->pushButton2;
    buttons[0][2] = ui->pushButton3;
    buttons[1][0] = ui->pushButton4;
    buttons[1][1] = ui->pushButton5;
    buttons[1][2] = ui->pushButton6;
    buttons[2][0] = ui->pushButton7;
    buttons[2][1] = ui->pushButton8;
    buttons[2][2] = ui->pushButton9;

}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::check_win()
{
    /*
     1 - перемога людини
     2 - перемога програми
     0 - нічия
     -1- продовження гри
    */
    if (counter>4 && counter<=9)
    {
        for (int i=0; i<3; i++)
        {
            if (board[i][0]==comp && board[i][1]==comp && board[i][2]==comp)
            {
                return 2;
            }
            if (board[0][i]==comp && board[1][i]==comp && board[2][i]==comp)
            {
                return 2;
            }
            // Перевірка перемоги людини
            if (board[i][0]==human && board[i][1]==human && board[i][2]==human)
            {
                return 1;
            }
            if (board[0][i]==human && board[1][i]==human && board[2][i]==human)
            {
                return 1;
            }
        }
        if (board[0][0]==comp && board[1][1]==comp && board[2][2]==comp)
        {
            return 2;
        }
        if (board[0][2]==comp && board[1][1]==comp && board[2][0]==comp)
        {
            return 2;
        }
        if (board[0][0]==human && board[1][1]==human && board[2][2]==human)
        {
            return 1;
        }
        if (board[0][2]==human && board[1][1]==human && board[2][0]==human)
        {
            return 1;
        }
        if (counter==9)
        {
            //display();
            return 0;
        }
        else
        {
            return -1; //гра триває далі
        }
    }
    else
    {
        return -1; //гра триває далі
    }
}
void MainWindow::game_play()
{
    choose();
}
void MainWindow::move_human(QChar human)
{
    if     (check_win()==-1)
    {
        move_comp(comp);
        return;
    }
    else if(check_win()==0)
    {
        QMessageBox::about(this, QString("Нічия"), QString("Переможця не виявлено"));
        return;
    }
    else if(check_win()==1)
    {
        QMessageBox::about(this, QString("Перемога"), QString("Перемогла людина"));
        return;
    }
}
void MainWindow::move_comp(QChar comp)
{

    bool moved=false;
    // 1) якщо є два своїх в ряд, то доповнюємо третім
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (board[i][j]==comp && board[i][(j+1)%3]==comp && board[i][(j+2)%3]==_)
            {
                board  [i][(j+2)%3]=comp;
                buttons[i][(j+2)%3]->setText(comp);
                buttons[i][(j+2)%3]->setEnabled(false);
                moved=true;
                break;
            }
            if (board[i][j]==comp && board[(i+1)%3][j]==comp && board[(i+2)%3][j]==_)
            {
                board  [(i+2)%3][j]=comp;
                buttons[(i+2)%3][j]->setText(comp);
                buttons[(i+2)%3][j]->setEnabled(false);
                moved=true;
                break;
            }
        }
        break;
    }
    if (board[0][0]==comp && board[1][1]==comp && board[2][2]==_)
    {
        board  [2][2]=comp;
        buttons[2][2]->setText(comp);
        buttons[2][2]->setEnabled(false);
        moved=true;
    }
    else if (board[0][0]==comp && board[2][2]==comp && board[1][1]==_)
    {
        board  [1][1]=comp;
        buttons[1][1]->setText(comp);
        buttons[1][1]->setEnabled(false);
        moved=true;
    }
    else if (board[1][1]==comp && board[2][2]==comp && board[0][0]==_)
    {
        board  [0][0]=comp;
        buttons[0][0]->setText(comp);
        buttons[0][0]->setEnabled(false);
        moved=true;
    }
    else if (board[0][2]==comp && board[1][1]==comp && board[2][0]==_)
    {
        board  [2][0]=comp;
        buttons[2][0]->setText(comp);
        buttons[2][0]->setEnabled(false);
        moved=true;
    }
    else if (board[1][1]==comp && board[2][0]==comp && board[0][2]==_)
    {
        board  [0][2]=comp;
        buttons[0][2]->setText(comp);
        buttons[0][2]->setEnabled(false);
        moved=true;
    }
    else if (board[0][2]==comp && board[2][0]==comp && board[1][1]==_)
    {
        board  [1][1]=comp;
        buttons[1][1]->setText(comp);
        buttons[1][1]->setEnabled(false);
        moved=true;
    }
    // 2) коли два в ряд у суперника, то блокуємо
    if(!moved)
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                if (board[i][j]==human && board[i][(j+1)%3]==human && board[i][(j+2)%3]==_)
                {
                    board  [i][(j+2)%3]=comp;
                    buttons[i][(j+2)%3]->setText(comp);
                    buttons[i][(j+2)%3]->setEnabled(false);
                    moved=true;
                    break;
                }
                if (board[i][j]==human && board[(i+1)%3][j]==human && board[(i+2)%3][j]==_)
                {
                    board  [(i+2)%3][j]=comp;
                    buttons[(i+2)%3][j]->setText(comp);
                    buttons[(i+2)%3][j]->setEnabled(false);
                    moved=true;
                    break;
                }
                if (board[0][0]==human && board[1][1]==human && board[2][2]==_)
                {
                    board  [2][2]=comp;
                    buttons[2][2]->setText(comp);
                    buttons[2][2]->setEnabled(false);
                    moved=true;
                    break;
                }
                if (board[0][0]==human && board[2][2]==human && board[1][1]==_)
                {
                    board  [1][1]=comp;
                    buttons[1][1]->setText(comp);
                    buttons[1][1]->setEnabled(false);
                    moved=true;
                    break;
                }
                if (board[1][1]==human && board[2][2]==human && board[0][0]==_)
                {
                    board  [0][0]=comp;
                    buttons[0][0]->setText(comp);
                    buttons[0][0]->setEnabled(false);
                    moved=true;
                    break;
                }
                if (board[0][2]==human && board[1][1]==human && board[2][0]==_)
                {
                    board  [2][0]=comp;
                    buttons[2][0]->setText(comp);
                    buttons[2][0]->setEnabled(false);
                    moved=true;
                    break;
                }
                if (board[1][1]==human && board[2][0]==human && board[0][2]==_)
                {
                    board  [0][2]=comp;
                    buttons[0][2]->setText(comp);
                    buttons[0][2]->setEnabled(false);
                    moved=true;
                    break;
                }
                if (board[0][2]==human && board[2][0]==human && board[1][1]==_)
                {
                    board  [1][1]=comp;
                    buttons[1][1]->setText(comp);
                    buttons[1][1]->setEnabled(false);
                    moved=true;
                    break;
                }
            }
            break;
        }    // 3)
    while (!moved) {
        int r = rand() % 3;
        int s = rand() % 3;
        if (board[r][s] == _)
        {
            board[r][s] = comp;
            buttons[r][s]->setText(comp);
            buttons[r][s]->setEnabled(false);
            moved = true;
            break;
        }
    }

    counter++;
    display();
    int result = check_win();
    if (result == 2)
        QMessageBox::about(this, QString("Перемога"), QString("Перемогла програма"));
    else if (result == 0)
        QMessageBox::about(this, QString("Нічия"), QString("Переможця не виявлено"));

    if(check_win()==2)
    {
        QMessageBox::about(this, QString("Перемога"), QString("Перемогла програма"));
        return;
    }
    else if(check_win()==0)
    {
        QMessageBox::about(this, QString("Нічия"), QString("Переможця не виявлено"));
        return;
    }
    else if(check_win()==1)
    {
        QMessageBox::about(this, QString("Перемога"), QString("Перемогла людина"));
        return;
    }
    else
    {
        return;
    }
}
void MainWindow::display()
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            buttons[i][j]->setText(board[i][j]);
            // треба додати блокування кнопок
            if (board[i][j] != _)
                buttons[i][j]->setEnabled(false);
            else
                buttons[i][j]->setEnabled(true);
        }
    }
    ui->Movenum->setNum(counter);
}

void MainWindow::on_pushButton1_clicked()
{
    counter++;
    ui->pushButton1->setText(human);
    board[0][0]=human;
    ui->pushButton1->setEnabled(false);
    display();
    move_human(human);
}


void MainWindow::on_pushButton2_clicked()
{
    counter++;
    ui->pushButton2->setText(QString(human));
    board[0][1] = human;
    ui->pushButton2->setEnabled(false);
    display();
    move_human(human);
}



void MainWindow::on_pushButton3_clicked()
{
    counter++;
    ui->pushButton1->setText(human);
    board[0][2]=human;
    ui->pushButton1->setEnabled(false);
    display();
    move_human(human);
}


void MainWindow::on_pushButton4_clicked()
{
    counter++;
    ui->pushButton1->setText(human);
    board[1][0]=human;
    ui->pushButton1->setEnabled(false);
    display();
    move_human(human);
}


void MainWindow::on_pushButton5_clicked()
{
    counter++;
    ui->pushButton1->setText(human);
    board[1][1]=human;
    ui->pushButton1->setEnabled(false);
    display();
    move_human(human);
}


void MainWindow::on_pushButton6_clicked()
{
    counter++;
    ui->pushButton1->setText(human);
    board[1][2]=human;
    ui->pushButton1->setEnabled(false);
    display();
    move_human(human);
}


void MainWindow::on_pushButton7_clicked()
{
    counter++;
    ui->pushButton1->setText(human);
    board[2][0]=human;
    ui->pushButton1->setEnabled(false);
    display();
    move_human(human);
}


void MainWindow::on_pushButton8_clicked()
{
    counter++;
    ui->pushButton1->setText(human);
    board[2][1]=human;
    ui->pushButton1->setEnabled(false);
    display();
    move_human(human);
}


void MainWindow::on_pushButton9_clicked()
{
    counter++;
    ui->pushButton1->setText(human);
    board[2][2]=human;
    ui->pushButton1->setEnabled(false);
    display();
    move_human(human);
}


void MainWindow::on_Start_clicked()
{
   game_play();
}

void MainWindow::choose()
{
    gameover = false;
    counter=0;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            board[i][j]=' ';
            buttons[i][j]->setEnabled(true);
        }
    }
    if (ui->radioButton_X->isChecked()==true)
    {
        human=X;
        comp =O;
    }
    else
    {
        human=O;
        comp =X;
        move_comp(comp);
    }
    display();
}
