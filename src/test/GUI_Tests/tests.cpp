#include <QtWidgets>
#include <QtTest/QtTest>

class TestGui: public QObject
{
    Q_OBJECT

private slots:
    void test_lineEdit();
    void test_plainTextEdit();
    void test_comboBox();
    void test_pushButton();
    void test_label();
};

void TestGui::test_lineEdit()
{
    QLineEdit lineEdit;

    QTest::keyClicks(&lineEdit, "hello world");

    QCOMPARE(lineEdit.text(), QString("hello world"));
}

void TestGui::test_plainTextEdit()
{
    QPlainTextEdit plainTextEdit;

    QTest::keyClicks(&plainTextEdit, "hello world");

    QCOMPARE(plainTextEdit.toPlainText(), QString("hello world"));
    QCOMPARE(plainTextEdit.toPlainText().isEmpty(), false);
    while(!plainTextEdit.toPlainText().isEmpty())
        QTest::keyClick(&plainTextEdit, Qt::Key_Backspace);
    QCOMPARE(plainTextEdit.toPlainText().isEmpty(), true);
}

void TestGui::test_comboBox()
{
    QComboBox *comboBox=new QComboBox;
    comboBox->addItem("item1");
    comboBox->setCurrentText(QString("item1"));
    comboBox->addItem("item2");
    comboBox->setCurrentText(QString("item2"));
    comboBox->addItem("item3");
    comboBox->setCurrentText(QString("item3"));
    comboBox->setCurrentIndex(0);
    QCOMPARE(comboBox->currentIndex(),0);
    QCOMPARE(comboBox->currentText(),QString("item1"));
    comboBox->setCurrentIndex(2);
    QCOMPARE(comboBox->currentIndex(),2);
    QCOMPARE(comboBox->currentText(),QString("item3"));
    comboBox->setCurrentIndex(1);
    QCOMPARE(comboBox->currentIndex(),1);
    QCOMPARE(comboBox->currentText(),QString("item2"));
}

void TestGui::test_pushButton()
{
    QPushButton *pushButton=new QPushButton;
    pushButton->setEnabled(false);
    QCOMPARE(pushButton->isEnabled(),false);
    pushButton->setEnabled(true);
    QCOMPARE(pushButton->isEnabled(),true);
}

void TestGui::test_label()
{
    QLabel *label=new QLabel;
    label->setText(QString("label text"));
    QCOMPARE(label->text(),QString("label text"));
    QTestEventList list1;
    list1.addKeyClick(Qt::Key_Backspace);
    list1.simulate(label);
    list1.addKeyClicks("asdlkqwe1");
    list1.simulate(label);
    QCOMPARE(label->text(),QString("label text"));
}

QTEST_MAIN(TestGui)
#include "tests.moc"
