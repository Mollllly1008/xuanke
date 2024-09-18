/*//XuanKe.cpp
#include "LinkList.h"
#include "Banking.h"
#include<vector>
#include <conio.h>

LinkList<KeCheng>g_allCourses;
class Student {
public:
    Student(const char* ID, const char* Name , double GPA);
    Student(const Student& other);
    ~Student();
    Student& operator=(const Student& other);
    bool Login(const char* ID, const char* Password);//��½�˺�
    void QueryCourses();//��ѯ�γ�
    bool SelectCourse(KeCheng& const course);//ѡ��
    void QuerySelectedCourses();//��ѯѡ�����
    bool DropCourse(const std::string& courseID);//�˿�
    void Logout();//�˳��˺�

private:
    string id, name;
    double GPA;
    LinkList<KeCheng> selectedCourses;
    friend class KeCheng;
};

Student::Student(const char* ID = "00000000", const char* Name = "NoName", double GPA = 0.0)//�����涨��������ĺ���
{
}

Student::Student(const Student& other)
    : id(other.id), name(other.name), GPA(other.GPA), selectedCourses(other.selectedCourses) {}

Student::~Student() {}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        GPA = other.GPA;
        selectedCourses = other.selectedCourses;
    }
    return *this;
}

bool Student::Login(const char* ID, const char* Password) {
    if (this->id == ID && Password == "password") {
        cout << " logged in successfully." << endl;
        return true;
    }
    else {
        cout << "Login failed. Incorrect ID or password." << endl;
        return false;
    }
}//��½�˺�

void Student::QueryCourses() {
    cout << "�γ�:" << endl;
    g_allCourses.ShowList();
}

bool Student::SelectCourse(KeCheng& course) {
    if (course.addStudent(*this)) {
        selectedCourses.Append(course); // ���γ���ӵ�ѧ����ѡ��������
        return true;
    }
    return false;
}//ѡ��

void Student::QuerySelectedCourses() {
    cout << "��ѡ�γ�:" << endl;
    selectedCourses.ShowList();
}//��ѯѡ�����

bool Student::DropCourse(const std::string& courseID) {
    for (auto it = selectedCourses.GoTop(); it != nullptr; it = selectedCourses.Skip(1)) {
        if (it->data.courseNumber == courseID) {
            if (it->data.removeStudent(id)) {
                selectedCourses.DeleteCurNode(); // ��������ɾ���γ�
                return true;
            }
            break; // �ҵ��γ̺���Ҫ��������
        }
    }
    return false;
}//�˿�

void Student::Logout() {
    cout << "�˳���½" << endl;
}//�˳���½


class KeCheng
{
public:
    KeCheng(string name, string ID, string time, string teacher, string location, int cap);
    KeCheng(const KeCheng& other);
    ~KeCheng();
    KeCheng& operator=(const KeCheng& other);
    //void sortStudents();//���ݼ�������ѧ��
    void deleteStudents();//�޳�����������ѧ��
    void printCourseMembers() const;//����γ̳�Ա

private:
    string courseName, courseNumber, courseTime, courseTeacher, courseLocation;
    vector<Student> students;
    int capacity, enrolled;
};

//�γ̺�������
KeCheng::KeCheng(string name, string ID, string time, string teacher, string location, int cap) :courseName(name), courseNumber(ID), courseTime(time), courseTeacher(teacher), courseLocation(location), capacity(cap), enrolled(0)
{
}

// ���ݼ�������ѧ��
/*void KeCheng::sortStudents()
{
    sort(students.begin(), students.end(), [](const Student& a, const Student& b)
        {
            return a.GPA > b.GPA;
        });

}
*/

// �޳�����������ѧ��
void KeCheng::deleteStudents()
{
    if (students.size() > capacity)
    {
        students.resize(capacity);
        enrolled = capacity;
    }
}

// ����γ̳�Ա
void KeCheng::printCourseMembers() const
{
    cout << "Course: " << courseName << " (" << courseNumber << ")" << endl;
    cout << "Time: " << courseTime << ", Teacher: " << courseTeacher << ", Location: " << courseLocation << endl;
    cout << "Enrolled Students: " << std::endl;
    for (const auto&  student : students)
    {
        cout << "  " << student.name << " (GPA: " << student.gpa << ")" << endl;
    }
}


//�ǵö����ĸ���Ա����
template <typename T>
void XuanKeTest()
{
    Student student;
    LinkList<KeCheng*> courses;
    char key;
    while (true)
    {
        cout << "\n\n========= ѡ��ϵͳ =========" << endl;
        cout << "  a ---- ��¼ѧ���˺� (P)" << endl;
        cout << "  b ---- ѡ��    �γ� (I)" << endl;
        cout << "  c ---- ��ѯѡ������ (A)" << endl;
        cout << "  d ---- ��        �� (S)" << endl;
        cout << "  f ---- �˳�ѧ���˺� (V)" << endl;
        cout << "  h ---- ����    ���� (W)" << endl;
        cout << "  i ---- ��        �� (R)" << endl;
        cout << "  j ---- ����γ̳�Ա (F)" << endl;
        cout << "  l ---- �˳�    ��վ(ESC)" << endl;
        cout << "==========================" << endl;
        key = Choice("��ѡ��", "abcdefghijkl\x1bpPiIaAsSvVoOwWrRfF");
        cout << "\n\n";
        if (key == 27 || key == 'l')		// '\x1b'����27��ָESC��
            break;
        switch (key)
        {
        case 'a':
        case 'P':	Student.Login(); break; //��½ѧ���˺ţ�Banking��BankingTest�У�
        case 'b':
        case 'I':	Student.SelectCourse(); break;//ѡ��γ̣�������γ̺ţ�������γ̵ĸ����ݣ�������Ƿ�ѡ�ÿγ̣�����yes��γ̵�ѧ�����ݶ�һ�������������Ŀγ����ݶ�һ���ÿγ̣�cout << "����һ����㵽�����׽��ǰ��" << endl;
        case 'c':
        case 'A':	Student.QuerySelectedCourses(); break;//��ѯ�γ����������һ�ű��пγ̺ţ��γ����ƣ������������ȣ������Ϻ���ѧ��ѡ����վ��ѡ�����������cout << "׷��һ�����(��β����)��";
        case 'd':
        case 'S':	Student.DropCourse(); break;//�˿�(����γ̺ţ�����Ƿ��˿Σ�����yes���γ�ɾ�������㣬ѧ���Ŀγ�����ɾ������γ�)cout << "�������������ݲ�ѯ���ɸ����������ַ�ʽ��ѯ��" << endl;
        case 'f':
        case 'V':	Student.Logout(); break;//�˳�ѧ���˺ţ��ο�Banking��BankingTest)
        case 'h':
        case 'W':  cout << "������ݼ��� ";
                   KeCheng.Sort(int(0));					// ��һ���������ݵ���ֵ����Ҫ����Ҫ������������
                   cout << "\n����ţ�����������\n" << link << endl;
                   KeCheng.Sort(int(0), false);
                   break;
        case 'i':
        case 'R':	KeCheng.DeleteStudents(); break;//�߿Σ�������Ϊ���ݣ���������������Ŀγ�ѧ������ɾ����ѧ���ĸÿγ�����Ҳɾ����
        case 'j':
        case 'F':	KeCheng.printCourseMembers(); break;//����γ̳�Ա�����γ̵�ѧ�����������
        }
    }

}
*/