#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <string>


class Schedule {
public:
    Schedule();
    Schedule(int groups);
    std::vector <std::vector<std::vector<std::pair<std::wstring, std::wstring>>>> timetable;
    // ���������� timetable[group][day][time].first=����������/second=�������������

};
#endif // TEACHER_H