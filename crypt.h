#ifndef CRYPT_H
#define CRYPT_H
#include <QMainWindow>

void print(char* fileName,char* str);

void scan(char* fileName,char* str,int n);

int crpt(char* string,int key);

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

    void on_Close_clicked();

    void on_comboBox_activated(int index);

    void on_action_5_triggered();

    void on_ok_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_action_triggered();

    void on_comboBox_2_activated(int index);

private:
    Ui::Crypt *ui;
};

#endif // CRYPT_H
