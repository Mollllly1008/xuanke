//XuanKe.cpp
#include "LinkList.h"
#include "Banking.h"
#include <conio.h>

class Student
{
public://������������
private:

};//Student�����ԣ�����AddressBook��Banking��class

Student::Student()//�����涨��������ĺ���
{
}

class KeCheng
{
public://������������
private:

};

KeCheng::KeCheng()//�����涨��������ĺ���
{
}
//�ǵö����ĸ���Ա����
template <typename T>
void XuanKeTest()
{
	LinkList<Student> Student;
	LinkList<KeCheng> KeCheng;
	char key;
	while (true)
	{
		cout << "\n\n========= ѡ��ϵͳ =========" << endl;
		cout << "  a ---- ��¼ѧ���˺� (P)" << endl;
		cout << "  b ---- ѡ��    �γ� (I)" << endl;
		cout << "  c ---- ��ѯѡ������ (A)" << endl;
		cout << "  d ---- ��        �� (S)" << endl;
		cout << "  e ---- ���    �α� (E)" << endl;
		cout << "  f ---- �˳�ѧ���˺� (V)" << endl;
		cout << "  g ---- ��¼��ʦ�˺� (O)" << endl;
		cout << "  h ---- ����    ���� (W)" << endl;
		cout << "  i ---- ��        �� (R)" << endl;
		cout << "  j ---- ����γ̳�Ա (F)" << endl;
		cout << "  k ---- �˳���ʦ�˺� (Q)" << endl;
		cout << "  l ---- �˳�    ��վ(ESC)" << endl;
		cout << "==========================" << endl;
		key = Choice("��ѡ��", "abcdefghijkl\x1bpPiIaAsSvVoOwWrRfF");
		cout << "\n\n";
		if (key == 27 || key == 'l')		// '\x1b'����27��ָESC��
			break;
		switch (key)
		{
		case 'a':
		case 'P':	//��½ѧ���˺ţ�Banking��BankingTest�У�
		case 'b':
		case 'I':	//ѡ��γ̣�������γ̺ţ�������γ̵ĸ����ݣ�������Ƿ�ѡ�ÿγ̣�����yes��γ̵�ѧ�����ݶ�һ�������������Ŀγ����ݶ�һ���ÿγ̣�cout << "����һ����㵽�����׽��ǰ��" << endl;
		case 'c':
		case 'A':	//��ѯ�γ����������һ�ű��пγ̺ţ��γ����ƣ������������ȣ������Ϻ���ѧ��ѡ����վ��ѡ�����������cout << "׷��һ�����(��β����)��";
			
		case 'd':
		case 'S':	//�˿�(����γ̺ţ�����Ƿ��˿Σ�����yes���γ�ɾ�������㣬ѧ���Ŀγ�����ɾ������γ�)cout << "�������������ݲ�ѯ���ɸ����������ַ�ʽ��ѯ��" << endl;
		case 'e':
		case 'E'://����α����һ�ű������γ̵�������Ϣ��
		case 'f':
		case 'V':	//�˳�ѧ���˺ţ��ο�Banking��BankingTest)
		case 'g':
		case 'O':	//��½��ʦ�˺�
		case 'h':
		case 'W':  //�����������������������������ļ������򣬲�������γ�ģ���������ѧ������������
		case 'i':
		case 'R':	//�߿Σ�������Ϊ���ݣ���������������Ŀγ�ѧ������ɾ����ѧ���ĸÿγ�����Ҳɾ����
		case 'j':
		case 'F':	//����γ̳�Ա�����γ̵�ѧ�����������
		case 'k':
		case 'Q':  //�˳���ʦ�˺�
		}
	}

}