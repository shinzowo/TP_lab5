#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include "adddialog.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    QWidget *central = new QWidget(this);
    this->setCentralWidget(central);
    // Кнопки
    addButton = new QPushButton("Add");
    editButton = new QPushButton("Edit");
    deleteButton = new QPushButton("Delete");

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(deleteButton);

    // Список и метка
    listWidget = new QListWidget;
    totalWeightLabel = new QLabel("TotalWeight: 0");

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(listWidget);
    rightLayout->addWidget(totalWeightLabel);

    // Общий layout
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(rightLayout);

    central->setLayout(mainLayout);

    setWindowTitle("Candies");
    resize(500, 300);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addCandy);
    connect(editButton, &QPushButton::clicked, this, &MainWindow::editSelectedCandy);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteSelectedCandy);

}

void MainWindow::addCandy()
{
    AddDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();
        QString type = dialog.getType();
        int weight = dialog.getWeight();
        if(type=="Chocolate"){
            box.addSweet(chocolateFactory.FactoryMethod(name.toStdString(), weight));
        }
        else if(type=="Caramel"){
            box.addSweet(caramelFactory.FactoryMethod(name.toStdString(), weight));
        }
        else if(type=="Chocolate Bars"){
            box.addSweet(barsFactory.FactoryMethod(name.toStdString(), weight));
        }
        else if(type=="Gum"){
            box.addSweet(gumFactory.FactoryMethod(name.toStdString(), weight));
        }
        listWidget->addItem(name + " " + QString::number(weight) + "g.");
        totalWeightLabel->setText("TotalWeight: " + QString::number(box.GetTotalWeight()));
    }
}
void MainWindow::editSelectedCandy(){
    QListWidgetItem *item = listWidget->currentItem();
    if (!item) return;
    int row = listWidget->row(item);

    auto oldSweet = box.getSweet(row);

    // Открываем диалог с начальными значениями
    AddDialog dialog(this);
    dialog.setName(QString::fromStdString(oldSweet->getName()));

    dialog.setWeight(oldSweet->getWeight());

    if (dialog.exec() == QDialog::Accepted) {
        // Создаём новый объект вместо старого
        std::string name = dialog.getName().toStdString();
        std::string type = dialog.getType().toStdString();
        int weight = dialog.getWeight();

        std::shared_ptr<Sweet> newSweet;
        if(type=="Chocolate"){
            newSweet = chocolateFactory.FactoryMethod(name, weight);
        }
        else if(type=="Caramel"){
            newSweet = caramelFactory.FactoryMethod(name, weight);
        }
        else if(type=="Chocolate Bars"){
            newSweet = barsFactory.FactoryMethod(name, weight);
        }
        else if(type=="Gum"){
            newSweet = gumFactory.FactoryMethod(name, weight);
        }

        // Заменяем в векторе box
        box.replaceSweetAt(row, newSweet);

        // Обновляем виджет
        item->setText(QString("%1 %2 g")
                      .arg(dialog.getName())
                      .arg(dialog.getWeight()));

        totalWeightLabel->setText("TotalWeight: " + QString::number(box.GetTotalWeight()));
    }

}
void MainWindow::deleteSelectedCandy()
{
    QListWidgetItem *item = listWidget->currentItem();
    if (!item) return; // ничего не выбрано

    int row = listWidget->row(item);
    delete listWidget->takeItem(row);  // удаление из интерфейса


    box.removeSweet(row);
    totalWeightLabel->setText("TotalWeight: " + QString::number(box.GetTotalWeight()));
}

MainWindow::~MainWindow()
{
}
