#ifndef DATALOADER_H
#define DATALOADER_H

#include <vector>
#include <string>
#include "teacher.h"
#include "group.h"

class DataLoader {
public:
    static void loadTeachers(const std::wstring& filename, std::vector<Teacher>& teachers);
    static void loadGroups(const std::wstring& filename, std::vector<Group>& groups);
};

#endif // TEACHER_H