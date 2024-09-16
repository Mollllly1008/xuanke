//XuanKe(kecheng).cpp
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

//课程函数定义
KeCheng::KeCheng(string name, string ID, string time, string teacher, string location, int cap) :courseName(name),courseID(ID), courseTime(time),courseTeacher(teacher),courseLocation(location),capacity(cap),enrolled(0)
{  
}

// 根据绩点排序学生
void KeCheng::sortStudents() 
{
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b)
        {
        return a.gpa > b.gpa;
        });

}

// 剔除超出容量的学生
void KeCheng::deleteStudents()
{
    if (students.size() > capacity) 
    {
        students.resize(capacity);
        enrolled = capacity;
    }
}

// 输出课程成员
void KeCheng::printCourseMembers() const
{
    cout << "Course: " << courseName << " (" << courseNumber << ")" << endl;
    cout << "Time: " << courseTime << ", Teacher: " << courseTeacher << ", Location: " << courseLocation << endl;
    cout << "Enrolled Students: " << std::endl;
    for (const auto& student : students) 
    {
        cout << "  " << student.name << " (GPA: " << student.gpa << ")" << endl;
    }
}
