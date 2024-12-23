#pragma once

#include <iostream>
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QMainWindow>
#include <vector>
#include "Schedule.h"
#include "Teacher.h"
#include "Group.h"
#include "DataLoader.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindowClass; // ќбъ€вл€ем указатель на класс MainWindowClass
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_updateDataButton_clicked();
    void on_enumerationButton_clicked();
    void on_geneticAlgorithmButton_clicked();
    void updateSchedule();
    //void mutation(Schedule& main_table);
    //void modification(Schedule& main_table);
    //int estimation(Schedule& main_table);

private:
//public:
    Ui::MainWindowClass *ui;
    std::vector<Teacher> teachers;
    std::vector<Group> groups;
    Schedule main_table;
};
