#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QLabel>

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    QString getName() const;
    QString getType() const;
    int getWeight() const;
    void setName(const QString& name);
    void setType(const QString& type);
    void setWeight(int weight);


private:
    QComboBox *classComboBox;
    QLineEdit *nameEdit;
    QLineEdit *weightEdit;
    QDialogButtonBox *buttonBox;

private slots:
    void onAccept();


};

#endif // ADDDIALOG_H
