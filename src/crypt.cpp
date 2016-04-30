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
#include <QByteArray>
#include <string.h>

Crypt::Crypt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Crypt)
{
    ui->setupUi(this);
}

int vsnCrypt=0, check=0, check1=0, check2=0, check3=0, transformer=0, keyc;
char *str, *str_key, *str_morze;
QString st,st2,k;
QByteArray result;

Crypt::~Crypt()
{
    delete ui;
}

void Crypt::on_plainTextEdit_textChanged()
{
    if(!ui->plainTextEdit->toPlainText().isEmpty()) check1=1;
    else check1=0;

    if(transformer && check1 && check2 && check3 || transformer && vsnCrypt==2 && check1 && check2) ui->enter->setEnabled(true);
    else ui->enter->setEnabled(false);
}

void Crypt::on_comboBox_1_activated(int index)
{
   if(index==0){transformer=0;}

   if(index==1){transformer=1;}

   if(index==2){transformer=2;}

   if(transformer && check1 && check2 && check3 || transformer && vsnCrypt==2 && check1 && check2) ui->enter->setEnabled(true);
   else ui->enter->setEnabled(false);
}

void Crypt::on_comboBox_2_activated(int index)
{
     ui->lineEdit->clear();

    if(index==0){check2=0; ui->openKey->setEnabled(false);}

    if(index==1){vsnCrypt=1; ui->lineEdit->setEnabled(true); ui->lineEdit->setMaxLength(100); check2=1; ui->openKey->setEnabled(true);}

    if(index==2){vsnCrypt=2; ui->lineEdit->setEnabled(false); check2=1; ui->openKey->setEnabled(false);}

    if(index==3){vsnCrypt=3; ui->lineEdit->setEnabled(true); ui->lineEdit->setMaxLength(3); check2=1; ui->openKey->setEnabled(true);}

    if(transformer && check1 && check2 && check3 || transformer && vsnCrypt==2 && check1 && check2) ui->enter->setEnabled(true);
    else ui->enter->setEnabled(false);
}

void Crypt::on_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()) check3=1;
    else check3=0;

    if(transformer && check1 && check2 && check3 || transformer && vsnCrypt==2 && check1 && check2) ui->enter->setEnabled(true);
    else ui->enter->setEnabled(false);
}

void Crypt::on_openText_triggered()
{
    QString filename = QFileDialog::getOpenFileName(0, "Открытие файла","..\\","*.crpt *.txt");
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream text(&file);
    st=text.readAll();
    ui->plainTextEdit->setPlainText(st);
    file.close();
}

void Crypt::on_openKey_triggered()
{
    QString filenamekey = QFileDialog::getOpenFileName(0, "Открытие файла","..\\","*.key *.txt");
    QFile key(filenamekey);
    key.open(QIODevice::ReadOnly);
    QTextStream inKey(&key);
    k=inKey.readAll();
    ui->lineEdit->setText(k);
    key.close();
}

void Crypt::on_saveResult_triggered()
{
    QString savefile = QFileDialog::getSaveFileName(this,tr("Сохранить итоговый текст"),"",tr("Текстовый файл (*.txt)"));
    QFile save(savefile);
    save.open(QIODevice::WriteOnly);
    QTextStream outText(&save);
    outText << ui->plainTextEdit_2->toPlainText();
    save.flush();
    save.close();
}

void Crypt::on_enter_clicked()
{    
    st=ui->plainTextEdit->toPlainText();

    if(st.size()>4096){
        QMessageBox *msg=new QMessageBox;
        msg->setObjectName("error1");
        msg->setWindowTitle("Error: invalid number of characters!");
        msg->setText("The maximum string length ten thousand characters.");
        msg->setButtonText(1,"Cancel");
        msg->exec();
    }
    else{
        result=st.toLocal8Bit();
        str = new char[result.size()];
        strcpy(str, result.data());

        if(vsnCrypt==1){
            k=ui->lineEdit->text();
            result=k.toLocal8Bit();
            str_key = new char[result.size()];
            strcpy(str_key, result.data());

            if(transformer==1){

                check=vig(str,str_key);

                if(check < 0){
                    QMessageBox *msg=new QMessageBox;
                    msg->setObjectName("error2");
                    msg->setWindowTitle("Error: string/key is empty!");
                    msg->setText("You have not entered text or key.");
                    msg->setButtonText(1,"Cancel");
                    msg->exec();
                }

                if(check > 0){
                    QMessageBox *msg=new QMessageBox;
                    msg->setObjectName("error3");
                    msg->setWindowTitle("Error: invalid characters!");
                    msg->setText("You entered invalid characters.");
                    msg->setButtonText(1,"Cancel");
                    msg->exec();
                }
                if(check == 0) ui->plainTextEdit_2->setPlainText(str);

            }
            delete(str);
            delete(str_key);
        }

        if(vsnCrypt==2){

            if(transformer==1){

                str_morze=new char [strlen(str)*10];
                morze(str,str_morze);

                if(!strcmp(str_morze,"ERROR")){
                    QMessageBox *msg=new QMessageBox;
                    msg->setObjectName("error4");
                    msg->setWindowTitle("Error: invalid characters!");
                    msg->setText("You entered invalid characters.");
                    msg->setButtonText(1,"Cancel");
                    msg->exec();
                }
                else ui->plainTextEdit_2->setPlainText(str_morze);
            }
            delete(str);
            delete(str_morze);
        }

        if(vsnCrypt==3){
            keyc=ui->lineEdit->text().toInt();

            if(transformer==1){

                check=crpt(str,keyc);

                if(check < 0){
                    QMessageBox *msg=new QMessageBox;
                    msg->setObjectName("error5");
                    msg->setWindowTitle("Error: string/key is empty!");
                    msg->setText("You have not entered text or key.");
                    msg->setButtonText(1,"Cancel");
                    msg->exec();
                }

                if(check > 0){
                    QMessageBox *msg=new QMessageBox;
                    msg->setObjectName("error6");
                    msg->setWindowTitle("Error: invalid characters!");
                    msg->setText("You entered invalid characters.");
                    msg->setButtonText(1,"Cancel");
                    msg->exec();
                }
                if(check == 0) ui->plainTextEdit_2->setPlainText(str);
            }
            delete(str);
        }
    }
}

void Crypt::on_clear_clicked()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit_2->clear();
    ui->lineEdit->clear();
}

void Crypt::on_close_clicked()
{
    close();
}
