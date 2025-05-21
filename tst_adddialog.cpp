#include <QtTest/QtTest>
#include "adddialog.h"

class AddDialogTest : public QObject
{
    Q_OBJECT

private slots:
    void testPositiveWeight();
    void testZeroWeight();
    void testNegativeWeight();
    void testInvalidWeight();  // буквы и символы
};

void AddDialogTest::testPositiveWeight()
{
    AddDialog dialog;
    dialog.setWeight(100);
    QCOMPARE(dialog.getWeight(), 100);
}

void AddDialogTest::testZeroWeight()
{
    AddDialog dialog;
    dialog.setWeight(0);
    QCOMPARE(dialog.getWeight(), 0);
}

void AddDialogTest::testNegativeWeight()
{
    AddDialog dialog;
    dialog.setWeight(-50);
    QCOMPARE(dialog.getWeight(), 0);
}

void AddDialogTest::testInvalidWeight()
{
    AddDialog dialog;
    dialog.setWeight(0);

    dialog.findChild<QLineEdit *>("")->setText("abc"); //вручную
    QCOMPARE(dialog.getWeight(), 0);
}
QTEST_MAIN(AddDialogTest)
#include "tst_adddialog.moc"
