//XuanKe.h
#ifndef XUANKE_H
#define XUANKE_H
#include "LinkList.h"
#include "Banking.h"
#include <iomanip>
using namespace std;
 
class student;//提前声明

class Student
{
public://声明函数即可
private:

};//Student的属性，参照AddressBook与Banking的class

class KeCheng
{
public:
    Kecheng(string name, string ID, string time, string teacher, string location, int cap)
    void sortStudents();//根据绩点排序学生
    void deleteStudents();//剔除超出容量的学生
    void printCourseMembers() const;//输出课程成员

private:
    string courseName, courseNumber, courseTime, courseTeacher, courseLocation;
    vector<Student> students;
    int capacity, enrolled;
};

#endif

