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

Student::Student(const char* ID = "00000000", const char* Name = "NoName", double GPA = 0.0)//在外面定义刚声明的函数
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
}//登陆账号

void Student::QueryCourses() {
    cout << "课程:" << endl;
    g_allCourses.ShowList();
}

bool Student::SelectCourse(KeCheng& course) {
    if (course.addStudent(*this)) {
        selectedCourses.Append(course); // 将课程添加到学生的选课链表中
        return true;
    }
    return false;
}//选课

void Student::QuerySelectedCourses() {
    cout << "已选课程:" << endl;
    selectedCourses.ShowList();
}//查询选课情况

bool Student::DropCourse(const std::string& courseID) {
    for (auto it = selectedCourses.GoTop(); it != nullptr; it = selectedCourses.Skip(1)) {
        if (it->data.courseNumber == courseID) {
            if (it->data.removeStudent(id)) {
                selectedCourses.DeleteCurNode(); // 从链表中删除课程
                return true;
            }
            break; // 找到课程后不需要继续搜索
        }
    }
    return false;
}//退课

void Student::Logout() {
    cout << "退出登陆" << endl;
}//退出登陆


class KeCheng
{
public:
    KeCheng(string name, string ID, string time, string teacher, string location, int cap);
    KeCheng(const KeCheng& other);
    ~KeCheng();
    KeCheng& operator=(const KeCheng& other);
    //void sortStudents();//根据绩点排序学生
    void deleteStudents();//剔除超出容量的学生
    void printCourseMembers() const;//输出课程成员

private:
    string courseName, courseNumber, courseTime, courseTeacher, courseLocation;
    vector<Student> students;
    int capacity, enrolled;
};

//课程函数定义
KeCheng::KeCheng(string name, string ID, string time, string teacher, string location, int cap) :courseName(name), courseNumber(ID), courseTime(time), courseTeacher(teacher), courseLocation(location), capacity(cap), enrolled(0)
{
}

// 根据绩点排序学生
/*void KeCheng::sortStudents()
{
    sort(students.begin(), students.end(), [](const Student& a, const Student& b)
        {
            return a.GPA > b.GPA;
        });

}
*/

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
    for (const auto&  student : students)
    {
        cout << "  " << student.name << " (GPA: " << student.gpa << ")" << endl;
    }
}


//记得定义四个成员函数
template <typename T>
void XuanKeTest()
{
    Student student;
    LinkList<KeCheng*> courses;
    char key;
    while (true)
    {
        cout << "\n\n========= 选课系统 =========" << endl;
        cout << "  a ---- 登录学生账号 (P)" << endl;
        cout << "  b ---- 选择    课程 (I)" << endl;
        cout << "  c ---- 查询选课排名 (A)" << endl;
        cout << "  d ---- 退        课 (S)" << endl;
        cout << "  f ---- 退出学生账号 (V)" << endl;
        cout << "  h ---- 绩点    排序 (W)" << endl;
        cout << "  i ---- 踢        课 (R)" << endl;
        cout << "  j ---- 输出课程成员 (F)" << endl;
        cout << "  l ---- 退出    网站(ESC)" << endl;
        cout << "==========================" << endl;
        key = Choice("请选择", "abcdefghijkl\x1bpPiIaAsSvVoOwWrRfF");
        cout << "\n\n";
        if (key == 27 || key == 'l')		// '\x1b'等于27，指ESC键
            break;
        switch (key)
        {
        case 'a':
        case 'P':	Student.Login(); break; //登陆学生账号（Banking与BankingTest有）
        case 'b':
        case 'I':	Student.SelectCourse(); break;//选择课程（先输入课程号，后输出课程的各内容，再输出是否选该课程，输入yes后课程的学生数据多一个该生，该生的课程数据多一个该课程）cout << "插入一个结点到链表首结点前。" << endl;
        case 'c':
        case 'A':	Student.QuerySelectedCourses(); break;//查询课程排名（输出一张表，有课程号，课程名称，容量，排名等，参照上海大学的选课网站的选课排名情况）cout << "追加一个结点(至尾结点后)。";
        case 'd':
        case 'S':	Student.DropCourse(); break;//退课(输入课程号，输出是否退课，输入yes，课程删掉这个结点，学生的课程数据删掉这个课程)cout << "根据数据域数据查询。可根据如下三种方式查询。" << endl;
        case 'f':
        case 'V':	Student.Logout(); break;//退出学生账号（参考Banking与BankingTest)
        case 'h':
        case 'W':  cout << "排序根据绩点 ";
                   KeCheng.Sort(int(0));					// 第一个参数传递的数值不重要，重要的是数据类型
                   cout << "\n按序号（升序）排序结果\n" << link << endl;
                   KeCheng.Sort(int(0), false);
                   break;
        case 'i':
        case 'R':	KeCheng.DeleteStudents(); break;//踢课（以容量为依据，将排名在容量外的课程学生数据删除，学生的该课程数据也删除）
        case 'j':
        case 'F':	KeCheng.printCourseMembers(); break;//输出课程成员（将课程的学生数据输出）
        }
    }

}
*/