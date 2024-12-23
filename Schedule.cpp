#include "Schedule.h"
#include <iostream>

Schedule::Schedule(int groups) {
    timetable.resize(groups); // ���-�� �����
    for (int t = 0; t < groups; t++)
    {
        timetable[t].resize(6); // 6 ���� � ������
        for (int i = 0; i < 6; ++i) {
            timetable[t][i].resize(8); // 8 ��������� ������ � ����
        }
    }
}

Schedule::Schedule() {}