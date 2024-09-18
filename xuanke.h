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
 
class Student {
public:
	Student(const char* ID = "00000000", const char* Name = "NoName", double GPA = 0.0);
	Student(const Student& other);
        ~Student();
	Student& operator=(const Student& other);
	bool Login(const char* ID, const char* Password);//登陆账号
	void QueryCourses();//查询课程
	bool SelectCourse(KeCheng& const course);//选课
	void QuerySelectedCourses();//查询选课情况
	bool DropCourse(const std::string& courseID);//退课
	void Logout();//退出账号

private:
	string id, name;
	double GPA;
	LinkList<KeCheng> selectedCourses;
	friend class KeCheng;
};

class KeCheng
{
public:
    KeCheng(string name, string ID, string time, string teacher, string location, int cap);
    KeCheng(const KeCheng& other);
    ~KeCheng();
    KeCheng& operator=(const KeCheng& other);
    void sortStudents();//根据绩点排序学生
    void deleteStudents();//剔除超出容量的学生
    void printCourseMembers() const;//输出课程成员
    bool removeStudent(const std::string& studentId)；//移除学生方法
    bool addStudent(const Student& student);//添加学生方法

private:
    string courseName, courseNumber, courseTime, courseTeacher, courseLocation;
    vector<Student> students;
    int capacity, enrolled;
    friend class Student;
};

#endif

