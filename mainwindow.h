#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include "SweetLibrary.h"
#include "PresentBox.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QListWidget *listWidget;
    QLabel *totalWeightLabel;

    //SweetLibrary
    FactoryChocolateCandy chocolateFactory;
    FactoryCaramelCandy caramelFactory;
    FactoryChocolateBars barsFactory;
    FactoryGum gumFactory;
    PresentBox box;

private slots:
    void addCandy();
    void editSelectedCandy();
    void deleteSelectedCandy();

};

#endif // MAINWINDOW_H
