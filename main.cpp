#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <locale.h>
#include <windows.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    std::locale::global(std::locale("ru_RU.UTF-8"));
    //qDebug() << "Begin";


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
