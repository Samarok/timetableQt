#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <vector>
#include <QString>
#include <QTableWidgetItem>
#include <locale.h>
#include <windows.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    connect(ui->groupComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::updateSchedule);
    ui->groupComboBox->addItem(QString::fromStdWString(L"Пусто"));
}

MainWindow::~MainWindow() {
    delete ui; //возможно убрать
}

void MainWindow::on_updateDataButton_clicked() {
    teachers.clear();
    groups.clear();
    DataLoader::loadTeachers(L"teachers.txt", teachers);
    DataLoader::loadGroups(L"groups.txt", groups);

    main_table = Schedule(groups.size());
    
    if (!groups.empty()) {
            //ui->groupComboBox->clear();
        //if (ui->groupComboBox->isEnabled())
            //ui->groupComboBox->clear();

        while (ui->groupComboBox->count() > 1) {
            ui->groupComboBox->removeItem(1);
        }
        for(auto iter: groups)
            ui->groupComboBox->addItem(QString::fromStdWString(iter.name));
    }
    //updateSchedule();
}

void MainWindow::on_enumerationButton_clicked() {
    main_table.timetable.clear();
    //main_table.timetable.resize(0);
    main_table = Schedule(groups.size());

    for (int t = 0; t < groups.size(); t++)
    {
        for (int j = 0; j < groups[t].courses.size(); j++)
        {
            bool check = 0;
            for(int i=0; i<48; i++)
            if (main_table.timetable[t][(i) % 6][(i) / 6].first.empty())
            {
                for (int q = 0; q < teachers.size(); q++)
                {
                    for (int w = 0; w < teachers[q].courses.size(); w++)
                    {
                        if (teachers[q].courses[w] == groups[t].courses[j])
                        {
                            for (int r = 0; r <= t /*groups.size()*/; r++)
                            {
                                if (teachers[q].name == main_table.timetable[r][(i) % 6][(i) / 6].second)
                                {
                                    check = 0;
                                    break;
                                }
                                else check = 1;
                            }
                            break;
                        }
                    }
                    if (check)
                    {
                        main_table.timetable[t][(i) % 6][(i) / 6].second = teachers[q].name;
                        main_table.timetable[t][(i) % 6][(i) / 6].first = groups[t].courses[j];
                        break;
                    }
                }
                if (check) break;
            }
        }
    }
}

void MainWindow::updateSchedule() {
    int currentGroup = ui->groupComboBox->currentIndex(); // Получаем индекс выбранной группы
    if (currentGroup == 0) return;
    const auto& timetable = main_table.timetable[currentGroup-1]; // Получаем расписание для выбранной группы

    ui->scheduleTable->clear(); // Очищаем таблицу
    ui->scheduleTable->setRowCount(8); // Устанавливаем количество строк (временных слотов)
    ui->scheduleTable->setColumnCount(6); // Устанавливаем количество столбцов (дней)

    // Устанавливаем режим изменения размера для всех столбцов
    for (int i = 0; i < ui->scheduleTable->columnCount(); ++i) {
        ui->scheduleTable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
    // Устанавливаем режим изменения размера для всех строк по содержимому
    for (int i = 0; i < ui->scheduleTable->rowCount(); ++i) {
        ui->scheduleTable->verticalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }
    // Растягиваем последний столбец на всё доступное пространство
    ui->scheduleTable->horizontalHeader()->setStretchLastSection(true);
    // Заголовки столбцов (временные слоты)
    QStringList headers;
    headers << "Понедельник" << "Вторник" << "Среда" << "Четверг" << "Пятница" << "Суббота";
    ui->scheduleTable->setHorizontalHeaderLabels(headers);

    // Заполняем таблицу данными
    for (int day = 0; day < 6; ++day) { // 6 дней
        for (int time = 0; time < 8; ++time) { // 8 временных слотов
            const auto& entry = timetable[day][time];
            QString discipline = QString::fromStdWString(entry.first); // Дисциплина
            QString teacher = QString::fromStdWString(entry.second); // Преподаватель

            if (!discipline.isEmpty()) {
                ui->scheduleTable->setItem(time, day,  new QTableWidgetItem(discipline + "\n" + teacher));
            }
            else {
                ui->scheduleTable->setItem(time, day,  new QTableWidgetItem("-------"));
            }
        }
    }
}

void MainWindow::on_geneticAlgorithmButton_clicked() {

}
