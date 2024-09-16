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
public:
Student(const char* ID = "00000000", const char* Name = "NoName", double GPA = 0.0);
Student(const Student& other);
~Student();
Student& operator=(const Student& other);
bool Login(const char* ID, const char* Password);//登陆账号
void QueryCourses();//查询课程
bool SelectCourse(const string& courseID);//选课
void QuerySelectedCourses();//查询选课情况
bool DropCourse(const string& courseID);//退课
void Logout();//退出账号
private:
string id, name;
double GPA;
LinkList<KeCheng> selectedCourses;
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

