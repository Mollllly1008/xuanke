//XuanKe(kecheng).cpp
#include "Banking.h"
#include <iomanip>

KeCheng::KeCheng(string name, string ID, string time, string teacher, string location, int cap) : courseName(name), courseID(ID), courseTime(time), courseTeacher(teacher), courseLocation(location), capacity(cap), enrolled(0)
{
}

// ���ݼ�������ѧ��
void sortStudents() 
{
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) 
        {
        return a.gpa > b.gpa;
        });
}

// �޳�����������ѧ��
void deleteStudents()
{
    if (students.size() > capacity) 
    {
        students.resize(capacity);
        enrolled = capacity;
    }
}

// ����γ̳�Ա
void printCourseMembers() const 
{
    cout << "Course: " << courseName << " (" << courseNumber << ")" << endl;
    cout << "Time: " << courseTime << ", Teacher: " << courseTeacher << ", Location: " << courseLocation << endl;
    cout << "Enrolled Students: " << std::endl;
    for (const auto& student : students) {
        cout << "  " << student.name << " (GPA: " << student.gpa << ")" << endl;
    }
}
};
