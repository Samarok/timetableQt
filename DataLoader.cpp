#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <codecvt>
#include <stdio.h>


// Загрузка преподавателей из файла
void DataLoader::loadTeachers(const std::wstring& filename, std::vector<Teacher>& teachers) {
    //std::ifstream file(filename);
    std::wifstream file(filename);
    //file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));
    if (!file.is_open()) {
        std::wcerr <<  L"Ошибка открытия файла: " << filename << std::endl;
        return;
    }
    
    std::wstring line;
    while (std::getline(file, line)) {
        Teacher teacher;
        size_t pos = line.find(',');
        if (pos != std::wstring::npos) {
            teacher.name = line.substr(0, pos);
            std::wistringstream ss(line.substr(pos + 1));
            std::wstring course;

            while (std::getline(ss, course, L',')) {
                teacher.courses.push_back(course);
            }
            teachers.push_back(teacher);
        }
    }
    file.close();
}

// Загрузка групп из файла
void DataLoader::loadGroups(const std::wstring& filename, std::vector<Group>& groups) {
    std::wifstream file(filename);
    if (!file.is_open()) {
        std::wcerr << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    std::wstring line;
    while (std::getline(file, line)) {
        Group group;
        size_t pos = line.find(',');
        if (pos != std::wstring::npos) {
            group.name = line.substr(0, pos);

            std::wistringstream ss(line.substr(pos + 1));
            std::wstring course;
            while (std::getline(ss, course, L',')) {
                group.courses.push_back(course);
            }
            groups.push_back(group);
        }
    }
    file.close();
}
