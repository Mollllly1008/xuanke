//XuanKe.cpp
#include "LinkList.h"
#include "Banking.h"
#include <conio.h>

class Student
{
public://声明函数即可
private:

};//Student的属性，参照AddressBook与Banking的class

Student::Student()//在外面定义刚声明的函数
{
}

class KeCheng
{
public://声明函数即可
private:

};

KeCheng::KeCheng()//在外面定义刚声明的函数
{
}
//记得定义四个成员函数
template <typename T>
void XuanKeTest()
{
	LinkList<Student> Student;
	LinkList<KeCheng> KeCheng;
	char key;
	while (true)
	{
		cout << "\n\n========= 选课系统 =========" << endl;
		cout << "  a ---- 登录学生账号 (P)" << endl;
		cout << "  b ---- 选择    课程 (I)" << endl;
		cout << "  c ---- 查询选课排名 (A)" << endl;
		cout << "  d ---- 退        课 (S)" << endl;
		cout << "  e ---- 输出    课表 (E)" << endl;
		cout << "  f ---- 退出学生账号 (V)" << endl;
		cout << "  g ---- 登录老师账号 (O)" << endl;
		cout << "  h ---- 绩点    排序 (W)" << endl;
		cout << "  i ---- 踢        课 (R)" << endl;
		cout << "  j ---- 输出课程成员 (F)" << endl;
		cout << "  k ---- 退出老师账号 (Q)" << endl;
		cout << "  l ---- 退出    网站(ESC)" << endl;
		cout << "==========================" << endl;
		key = Choice("请选择", "abcdefghijkl\x1bpPiIaAsSvVoOwWrRfF");
		cout << "\n\n";
		if (key == 27 || key == 'l')		// '\x1b'等于27，指ESC键
			break;
		switch (key)
		{
		case 'a':
		case 'P':	//登陆学生账号（Banking与BankingTest有）
		case 'b':
		case 'I':	//选择课程（先输入课程号，后输出课程的各内容，再输出是否选该课程，输入yes后课程的学生数据多一个该生，该生的课程数据多一个该课程）cout << "插入一个结点到链表首结点前。" << endl;
		case 'c':
		case 'A':	//查询课程排名（输出一张表，有课程号，课程名称，容量，排名等，参照上海大学的选课网站的选课排名情况）cout << "追加一个结点(至尾结点后)。";
			
		case 'd':
		case 'S':	//退课(输入课程号，输出是否退课，输入yes，课程删掉这个结点，学生的课程数据删掉这个课程)cout << "根据数据域数据查询。可根据如下三种方式查询。" << endl;
		case 'e':
		case 'E'://输出课表（输出一张表，包含课程的所有信息）
		case 'f':
		case 'V':	//退出学生账号（参考Banking与BankingTest)
		case 'g':
		case 'O':	//登陆老师账号
		case 'h':
		case 'W':  //绩点排序（运用排序函数，将浮点数的绩点排序，并输出，课程模板中需包含学生绩点排名）
		case 'i':
		case 'R':	//踢课（以容量为依据，将排名在容量外的课程学生数据删除，学生的该课程数据也删除）
		case 'j':
		case 'F':	//输出课程成员（将课程的学生数据输出）
		case 'k':
		case 'Q':  //退出老师账号
		}
	}

}