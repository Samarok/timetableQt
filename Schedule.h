#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <string>


class Schedule {
public:
    Schedule();
    Schedule(int groups);
    std::vector <std::vector<std::vector<std::pair<std::wstring, std::wstring>>>> timetable;
    // Расписание timetable[group][day][time].first=дисциплина/second=преподователь

};
#endif // TEACHER_H