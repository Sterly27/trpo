#include "crypt.h"
#include "ui_crypt.h"
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>

Crypt::Crypt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Crypt)
{
    ui->setupUi(this);
}

int vsnCrypt=0, check,check1=0, check2=0, check3=0,transformer=0,keyc;
char str[4096], str2[100], *strm;
QString st,st2,k;

Crypt::~Crypt()
{
    delete ui;
}

void Crypt::on_plainTextEdit_textChanged()
{
    if(!ui->plainTextEdit->toPlainText().isEmpty()) check1=1;
    else check1=0;
    if(transformer&&check1==1&&check2==1&&check3==1||transformer&&vsnCrypt==2&&check1==1&&check2==1) ui->ok->setEnabled(true);
    else ui->ok->setEnabled(false);

}

void Crypt::on_comboBox_2_activated(int index)
{
   if(index==0){transformer=0; ui->ok->setEnabled(false);}
   if(index==1){transformer=1;}
   if(index==2){transformer=2;}
   if(transformer&&check1==1&&check2==1&&check3==1||transformer&&vsnCrypt==2&&check1==1&&check2==1) ui->ok->setEnabled(true);
   else ui->ok->setEnabled(false);
}

void Crypt::on_comboBox_activated(int index)
{
    if(index==0){check2=0;ui->action->setEnabled(false);}
    if(index==1){vsnCrypt=1; ui->lineEdit->setMaxLength(100); check2=1; ui->action->setEnabled(true);}
    if(index==2){vsnCrypt=2; check2=1; ui->lineEdit->setMaxLength(0);}
    if(index==3){vsnCrypt=3; ui->lineEdit->setMaxLength(3); check2=1;ui->action->setEnabled(true);}
    if(index==1||index==3) ui->lineEdit->setEnabled(true);
    else{ui->lineEdit->setEnabled(false); ui->action->setEnabled(false);}
    if(transformer&&check1==1&&check2==1&&check3==1||transformer&&vsnCrypt==2&&check1==1&&check2==1) ui->ok->setEnabled(true);
    else ui->ok->setEnabled(false);
}

void Crypt::on_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()) check3=1;
    else check3=0;
    if(transformer&&check1==1&&check2==1&&check3==1||transformer&&vsnCrypt==2&&check1==1&&check2==1) ui->ok->setEnabled(true);
    else ui->ok->setEnabled(false);
}

void Crypt::on_action_5_triggered()
{
  QString filename = QFileDialog::getOpenFileName(0, "Открытие файла","..\\","*.crpt *.txt");
  QFile file(filename);
  file.open(QIODevice::ReadOnly);
  QTextStream text(&file);
  st=text.readAll();
  ui->plainTextEdit->setPlainText(st);
  file.close();
}

void Crypt::on_action_triggered()
{
    QString filenamekey = QFileDialog::getOpenFileName(0, "Открытие файла","..\\","*.key *.txt");
    QFile key(filenamekey);
    key.open(QIODevice::ReadOnly);
    QTextStream inkey(&key);
    k=inkey.readAll();
    ui->lineEdit->setText(k);
    key.close();
}

void Crypt::on_ok_clicked()
{
    QFile file(".\\text.crpt");
    file.open(QIODevice::WriteOnly);
    QTextStream outtext(&file);
        outtext << ui->plainTextEdit->toPlainText();
        file.flush();
        file.close();

        file.open(QFile::ReadOnly);
        file.readLine(str, sizeof(str));
        file.flush();
        file.close();

        QFile key(".\\key.key");
        key.open(QIODevice::WriteOnly);
        QTextStream outkey(&key);
            outkey << ui->lineEdit->text();
            key.flush();
            key.close();

    if(vsnCrypt==1){
            key.open(QFile::ReadOnly);
            key.readLine(str2, sizeof(str2));
            key.flush();
            key.close();
        if(transformer==1){
            check=vig(str,str2);
            if(check < 0){
                QMessageBox *msg=new QMessageBox;
                msg->setObjectName("error1");
                msg->setWindowTitle("Error: string/key is empty.");
                msg->setText("You have not entered text or key");
                msg->setButtonText(1,"Cancel");
                msg->exec();
           }
           if(check > 0){
               QMessageBox *msg=new QMessageBox;
               msg->setObjectName("error2");
               msg->setWindowTitle("Error: invalid characters.");
               msg->setText("You entered invalid characters");
               msg->setButtonText(1,"Cancel");
               msg->exec();
         }
        else ui->plainTextEdit_2->setPlainText(str);
        }
    }

    if(vsnCrypt==2){
        if(transformer==1){
        strm=new char [strlen(str)*10];
        morze(str,strm);
        if(!strcmp(strm,"ERROR")){
            QMessageBox *msg=new QMessageBox;
            msg->setObjectName("error2");
            msg->setWindowTitle("Error: invalid characters.");
            msg->setText("You entered invalid characters");
            msg->setButtonText(1,"Cancel");
            msg->exec();
           }
        else ui->plainTextEdit_2->setPlainText(strm);
        }
    }

   if(vsnCrypt==3){
          keyc=ui->lineEdit->text().toInt();
     if(transformer==1){
         check=crpt(str,keyc);
             if(check < 0){
                 QMessageBox *msg=new QMessageBox;
                 msg->setObjectName("error1");
                 msg->setWindowTitle("Error: string/key is empty.");
                 msg->setText("You have not entered text or key");
                 msg->setButtonText(1,"Cancel");
                 msg->exec();
            }
            if(check > 0){
                QMessageBox *msg=new QMessageBox;
                msg->setObjectName("error2");
                msg->setWindowTitle("Error: invalid characters.");
                msg->setText("You entered invalid characters");
                msg->setButtonText(1,"Cancel");
                msg->exec();
          }
          else ui->plainTextEdit_2->setPlainText(str);
        }
    }
}

void Crypt::on_Close_clicked()
{
    close();
}

