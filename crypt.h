#ifndef CRYPT_H
#define CRYPT_H
#include <QMainWindow>

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

    void on_close_clicked();

    void on_comboBox_1_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_openText_triggered();

    void on_enter_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_openKey_triggered();

    void on_clear_clicked();

private:
    Ui::Crypt *ui;
};

#endif // CRYPT_H
