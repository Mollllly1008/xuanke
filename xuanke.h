//XuanKe.h
#ifndef XUANKE_H
#define XUANKE_H
#include "LinkList.h"
#include "Banking.h"
#include <iomanip>
using namespace std;
 
class student;//��ǰ����

class Student
{
public://������������
private:

};//Student�����ԣ�����AddressBook��Banking��class

class KeCheng
{
public:
    Kecheng(string name, string ID, string time, string teacher, string location, int cap)
    void sortStudents();//���ݼ�������ѧ��
    void deleteStudents();//�޳�����������ѧ��
    void printCourseMembers() const;//����γ̳�Ա

private:
    string courseName, courseNumber, courseTime, courseTeacher, courseLocation;
    vector<Student> students;
    int capacity, enrolled;
};

#endif

