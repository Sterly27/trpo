#include "crypt.h"
#include "ui_crypt.h"
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QRgb>
#include <QWidget>
#include <QApplication>
#include <QByteArray>
#include <string.h>

Crypt::Crypt ( QWidget *parent ) :
	QMainWindow(parent),
	ui(new Ui::Crypt)
{
	ui->setupUi(this);
}

Crypt::~Crypt()
{
	delete ui;
}

void Crypt::on_plainTextEdit_textChanged()
{
	if ( !ui->plainTextEdit->toPlainText().isEmpty() ) check1 = 1;
	else check1 = 0;

	if ( transformer && check1 && check2 && check3 || transformer && vsnCrypt == 2 && check1 && check2 ) ui->enter->setEnabled(true);
	else ui->enter->setEnabled(false);
}

void Crypt::on_comboBox_1_activated ( int index )
{
	if ( index == 0 ){transformer = 0;}

	if ( index == 1 ){transformer = 1;}

	if ( index == 2 ){transformer = 2;}

	if ( transformer && check1 && check2 && check3 || transformer && vsnCrypt == 2 && check1 && check2 ) ui->enter->setEnabled(true);
	else ui->enter->setEnabled(false);


	if ( !check2 && transformer )
		ui->plainTextEdit_2->setPlainText("Выберите алгоритм шифрования");
	if ( check2 && transformer )
		ui->plainTextEdit_2->clear();
	if ( check2 && !transformer )
		ui->plainTextEdit_2->setPlainText("Выберите тип преобразования");
	if ( !check2 && !transformer )
		ui->plainTextEdit_2->setPlainText("Выберите тип преобразования и алгоритм шифрования");
}


void Crypt::on_comboBox_2_activated ( int index )
{
	ui->lineEdit->clear();

	if ( index == 0 ) {check2 = 0; ui->openKey->setEnabled(false);}

	if ( index == 1 ){vsnCrypt = 1; ui->lineEdit->setEnabled(true); ui->lineEdit->setMaxLength(100); check2 = 1; ui->openKey->setEnabled(true);}

	if ( index == 2 ){vsnCrypt = 2; ui->lineEdit->setEnabled(false); check2 = 1; ui->openKey->setEnabled(false);}

	if ( index == 3 ){vsnCrypt = 3; ui->lineEdit->setEnabled(true); ui->lineEdit->setMaxLength(3); check2 = 1; ui->openKey->setEnabled(true);}

	if ( transformer && check1 && check2 && check3 || transformer && vsnCrypt == 2 && check1 && check2 ) ui->enter->setEnabled(true);
	else ui->enter->setEnabled(false);


	if ( !check2 && transformer )
		ui->plainTextEdit_2->setPlainText("Выберите алгоритм шифрования");
	if ( check2 && transformer )
		ui->plainTextEdit_2->clear();
	if ( check2 && !transformer )
		ui->plainTextEdit_2->setPlainText("Выберите тип преобразования");
	if ( !check2 && !transformer )
		ui->plainTextEdit_2->setPlainText("Выберите тип преобразования и алгоритм шифрования");
}

void Crypt::on_lineEdit_textChanged ( const QString &arg1 )
{
	if ( !arg1.isEmpty() ) check3 = 1;
	else check3 = 0;

	if ( transformer && check1 && check2 && check3 || transformer && vsnCrypt == 2 && check1 && check2 ) ui->enter->setEnabled(true);
	else ui->enter->setEnabled(false);
}

void Crypt::on_openText_triggered()
{
	QString filename = QFileDialog::getOpenFileName(0, "Открытие файла","..\\","*.crpt *.txt");
	QFile file(filename);
	file.open(QIODevice::ReadOnly);
	QTextStream text(&file);
	st = text.readAll();
	ui->plainTextEdit->setPlainText(st);
	file.close();
}

void Crypt::on_openKey_triggered()
{
	QString filenamekey = QFileDialog::getOpenFileName(0, "Открытие файла","..\\","*.key *.txt");
	QFile key(filenamekey);
	key.open(QIODevice::ReadOnly);
	QTextStream inKey(&key);
	k = inKey.readAll();
	ui->lineEdit->setText(k);
	key.close();
}

void Crypt::on_saveResult_triggered()
{
	if ( !ui->plainTextEdit_2->toPlainText().isEmpty() && check2 && transformer ){
	QString savefile = QFileDialog::getSaveFileName(this, tr("Сохранить итоговый текст"),"*.txt", tr("Текстовый файл (*.txt)"));
	QFile save(savefile);
	save.open(QIODevice::WriteOnly);
	QTextStream outText(&save);
	outText << ui->plainTextEdit_2->toPlainText();
	save.flush();
	save.close();
	}
	else{
		QMessageBox *msg = new QMessageBox;
		msg->setObjectName("error_rezult");
		msg->setWindowTitle("Error: string is empty!");
		msg->setText("Encrypted/decrypted text is absent");
		msg->setButtonText(1, "Cancel");
		msg->exec();
	}
}

void Crypt::on_enter_clicked()
{
	st = ui->plainTextEdit->toPlainText();

	if ( st.size() > 4096 ){
		QMessageBox *msg = new QMessageBox;
		msg->setObjectName("error1");
		msg->setWindowTitle("Error: invalid number of characters!");
		msg->setText("The maximum string length 4096 characters.");
		msg->setButtonText(1, "Cancel");
		msg->exec();
	}
	else{
		result = st.toLocal8Bit();
		str = new char[result.size()];
		strcpy(str, result.data());

		if ( vsnCrypt == 1 ){
			k = ui->lineEdit->text();
			result = k.toLocal8Bit();
			str_key = new char[result.size()];
			strcpy(str_key, result.data());

			if ( transformer == 1 ){

				check = vig(str,str_key);

				if ( check < 0 ){
					QMessageBox *msg = new QMessageBox;
					msg->setObjectName("error2");
					msg->setWindowTitle("Error: string/key is empty!");
					msg->setText("You have not entered text or key.");
					msg->setButtonText(1, "Cancel");
					msg->exec();
				}

				if ( check > 0 ){
					QMessageBox *msg=new QMessageBox;
					msg->setObjectName("error3");
					msg->setWindowTitle("Error: invalid characters!");
					msg->setText("You entered invalid characters.");
					msg->setButtonText(1, "Cancel");
					msg->exec();
				}
				if ( check == 0 ) ui->plainTextEdit_2->setPlainText(str);

			}

			if ( transformer == 2 ){

				check = devig(str, str_key);

				if ( check < 0 ){
					QMessageBox *msg = new QMessageBox;
					msg->setObjectName("error4");
					msg->setWindowTitle("Error: string/key is empty!");
					msg->setText("You have not entered text or key.");
					msg->setButtonText(1, "Cancel");
					msg->exec();
				}

				if ( check > 0 ){
					QMessageBox *msg=new QMessageBox;
					msg->setObjectName("error5");
					msg->setWindowTitle("Error: invalid characters!");
					msg->setText("You entered invalid characters.");
					msg->setButtonText(1, "Cancel");
					msg->exec();
				}
				if ( check == 0 ) ui->plainTextEdit_2->setPlainText(str);

			}
			delete(str);
			delete(str_key);
		}

		if ( vsnCrypt == 2 ){

			if ( transformer == 1 ){

				str_morze = new char [strlen(str)*10];
				morze(str, str_morze);

				if ( !strcmp(str_morze, "ERROR") ){
					QMessageBox *msg = new QMessageBox;
					msg->setObjectName("error6");
					msg->setWindowTitle("Error: invalid characters!");
					msg->setText("You entered invalid characters.");
					msg->setButtonText(1, "Cancel");
					msg->exec();
				}
				else ui->plainTextEdit_2->setPlainText(str_morze);

				delete(str_morze);
			}

			if ( transformer == 2 ){

				demorze(str);

				if ( str[0] == 0 ){
					QMessageBox *msg = new QMessageBox;
					msg->setObjectName("error7");
					msg->setWindowTitle("Error: invalid characters!");
					msg->setText("You entered invalid characters.");
					msg->setButtonText(1, "Cancel");
					msg->exec();
				}
				else ui->plainTextEdit_2->setPlainText(str);
			}
			delete(str);
		}

		if ( vsnCrypt == 3 ){
			keyc = ui->lineEdit->text().toInt();

			if ( transformer == 1 ){

				check = crpt(str, keyc);

				if ( check < 0 ){
					QMessageBox *msg = new QMessageBox;
					msg->setObjectName("error8");
					msg->setWindowTitle("Error: string/key is empty!");
					msg->setText("You have not entered text or key.");
					msg->setButtonText(1, "Cancel");
					msg->exec();
				}

				if ( check > 0 ){
					QMessageBox *msg = new QMessageBox;
					msg->setObjectName("error9");
					msg->setWindowTitle("Error: invalid characters!");
					msg->setText("You entered invalid characters.");
					msg->setButtonText(1, "Cancel");
					msg->exec();
				}
				if ( check == 0 ) ui->plainTextEdit_2->setPlainText(str);
			}

			if ( transformer == 2 ){

				check = decrpt(str, keyc);

				if ( check < 0 ){
					QMessageBox *msg = new QMessageBox;
					msg->setObjectName("error10");
					msg->setWindowTitle("Error: string/key is empty!");
					msg->setText("You have not entered text or key.");
					msg->setButtonText(1, "Cancel");
					msg->exec();
				}

				if ( check > 0 ){
					QMessageBox *msg = new QMessageBox;
					msg->setObjectName("error11");
					msg->setWindowTitle("Error: invalid characters!");
					msg->setText("You entered invalid characters.");
					msg->setButtonText(1, "Cancel");
					msg->exec();
				}
				if ( check == 0 ) ui->plainTextEdit_2->setPlainText(str);
			}
			delete(str);
		}
	}
}

void Crypt::on_fontComboBox_currentFontChanged ( const QFont &f )
{
	ui->plainTextEdit->setFont(f);
	ui->plainTextEdit_2->setFont(f);
	ui->lineEdit->setFont(f);
}

void Crypt::on_action_15_triggered()
{
	QMessageBox* authors = new QMessageBox;
	authors->setButtonText(1, "Молодцы!");
    authors->setSizeIncrement(250, 200);

    authors->setWindowTitle("O Crypt VCM");
    authors->setText("<center><h1>Crypt VCM 1.0</h1></center>"
                     "Это приложение создано для шифровки и дешифровки текста<br>одним из трёх видов шифра: Вижинер, Морзе или Цезарь.<br>"
                     "<td width=200 valign=top>"
                     "<strong>Над проектом работали:</strong><br>"
                     "Глава по "
						"<font color = red>д"
					 "<font color = orange>и"
					 "<font color = yellow>з"
					  "<font color = green>а"
					   "<font color = cyan>й"
					   "<font color = blue>н"
					 "<font color = purple>у"
					 "</font></font></font></font></font></font></font> "
                     " и оформлению:"
					 "<br>Автор шифра Цезаря:"
					 "<br>Автор шифра Вижинера:"
                     "<br>Автор шифра Морзе:<br>"
                     "<a href=https://github.com/BjornSodenberg/TRPO>"
                     "<center><strong>Вы можете посетить наш репозиторий на GitHub.com</strong></center></a></td>"

                     "<td valign=top><b><br>"
					 "Федотов Павел<br>"
					 "Огнев Юрий<br>"
					 "Санин Иван<br>"
                     "Силкин Михаил</b>"
					 );
	authors->show();
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
