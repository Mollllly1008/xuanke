//XuanKe.h
#ifndef XUANKE_H
#define XUANKE_H
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
 
class Student
{
public://声明函数即可
private:

};//Student的属性，参照AddressBook与Banking的class

class KeCheng
{
public:
    KeCheng(string name, string ID, string time, string teacher, string location, int cap);
    void sortStudents();//根据绩点排序学生
    void deleteStudents();//剔除超出容量的学生
    void printCourseMembers() const;//输出课程成员

private:
    string courseName, courseNumber, courseTime, courseTeacher, courseLocation;
    vector<Student> students;
    int capacity, enrolled;
};

#endif

