#ifndef CRYPT_H
#define CRYPT_H
#include <QMainWindow>

int crpt(char* string,int key);

int decrpt(char* string,int key);

int vig(char a[],char b[]);

int devig(char a[],char b[]);

void morze(char* str, char* total);

void demorze(char* str);

namespace Ui {
class Crypt;
}

class Crypt : public QMainWindow
{
    Q_OBJECT

public:   
    explicit Crypt(QWidget *parent = 0);
    ~Crypt();

private slots:
    void on_plainTextEdit_textChanged();

    void on_close_clicked();

    void on_comboBox_1_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_openText_triggered();

    void on_enter_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_openKey_triggered();

    void on_clear_clicked();

    void on_saveResult_triggered();

	void on_fontComboBox_currentFontChanged(const QFont &f);

	void on_action_15_triggered();

private:
    int vsnCrypt=0, check=0, check1=0, check2=0, check3=0, transformer=0, keyc;
    char *str, *str_key, *str_morze;
    QString st,st2,k;
    QByteArray result;

    Ui::Crypt *ui;
};

#endif // CRYPT_H
