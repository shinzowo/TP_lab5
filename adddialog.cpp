#include "adddialog.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QStringList>

AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Add Candy");

    // Поля ввода
    classComboBox = new QComboBox;
    classComboBox->addItems(QStringList() << "Chocolate" << "Caramel" << "Chocolate Bars" << "Gum");

    nameEdit = new QLineEdit;
    weightEdit = new QLineEdit;


    // Кнопки OK / Cancel
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    // Макет формы
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Class:", classComboBox);
    formLayout->addRow("Name:", nameEdit);
    formLayout->addRow("Weight (g):", weightEdit);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    // Закрытие по кнопкам (без логики работы с данными)
    connect(buttonBox, &QDialogButtonBox::accepted, this, &AddDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &AddDialog::reject);
}
QString AddDialog::getName() const{
    return nameEdit->text();
}
QString AddDialog::getType() const{
    return classComboBox->currentText();
}
int AddDialog::getWeight() const{
    return weightEdit->text().toInt();
}
void AddDialog::setName(const QString& name) {
    nameEdit->setText(name);
}

void AddDialog::setType(const QString& type) {
    int index = classComboBox->findText(type);
    if (index >= 0)
        classComboBox->setCurrentIndex(index);
}

void AddDialog::setWeight(int weight) {
    weightEdit->setText(QString::number(weight));
}
