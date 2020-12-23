#include <iostream>
#include <string>
using namespace std;

#define MAX 1000
//��ϵ�˽ṹ��
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//ͨѶ¼�ṹ��
struct AddressBook {
	Person personArray[MAX];
	int m_Size;
};

//�˵�����
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(AddressBook * abs) {
	//�ж���ϵ���Ƿ�����
	if (abs->m_Size == MAX) {
		cout << "��ϵ������" << endl;
		return;
	}
	else {
		//�����û���
		cout << "�������û�����" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�����Ա�
		cout << "�������Ա�" << endl;
		cout << "1---�� 2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//��������
		cout << "���������䣺" << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "������������������" << endl;
		}

		//����绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//����סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(AddressBook * abs) {
	if (abs->m_Size == 0) {
		cout << "��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(AddressBook * abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(AddressBook * abs) {
	cout << "������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBook * abs) {
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBook * abs) {
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//�����û���
		cout << "�������û�����" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�����Ա�
		cout << "�������Ա�" << endl;
		cout << "1---�� 2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//��������
		cout << "���������䣺" << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150) {
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "������������������" << endl;
		}

		//����绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//����סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void clearAll(AddressBook * abs) {
	abs->m_Size = 0;
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

int main() {
	AddressBook abs;
	abs.m_Size = 0;
	while (true)
	{
		showMenu();
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1: //1�������ϵ��
			addPerson(&abs);
			break;
		case 2: //2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: // 3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4: //4��������ϵ��
			findPerson(&abs);
			break;
		case 5: //5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: //6�������ϵ��
			clearAll(&abs);
			break;
		case 0: //0���˳�ͨѶ¼
			cout << "�˳��ɹ�����ӭ�ٴ�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}

	system("pause");
	return 0;
}