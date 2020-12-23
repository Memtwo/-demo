#include <iostream>
#include <string>
using namespace std;

#define MAX 1000
//联系人结构体
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//通讯录结构体
struct AddressBook {
	Person personArray[MAX];
	int m_Size;
};

//菜单界面
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(AddressBook * abs) {
	//判断联系薄是否已满
	if (abs->m_Size == MAX) {
		cout << "联系薄已满" << endl;
		return;
	}
	else {
		//输入用户名
		cout << "请输入用户名：" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//输入性别
		cout << "请输入性别：" << endl;
		cout << "1---男 2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//输入年龄
		cout << "请输入年龄：" << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//输入电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//输入住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(AddressBook * abs) {
	if (abs->m_Size == 0) {
		cout << "记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
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
	cout << "请输入要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBook * abs) {
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBook * abs) {
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//输入用户名
		cout << "请输入用户名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//输入性别
		cout << "请输入性别：" << endl;
		cout << "1---男 2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//输入年龄
		cout << "请输入年龄：" << endl;
		int age;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150) {
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//输入电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//输入住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void clearAll(AddressBook * abs) {
	abs->m_Size = 0;
	cout << "清空成功" << endl;
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
		case 1: //1、添加联系人
			addPerson(&abs);
			break;
		case 2: //2、显示联系人
			showPerson(&abs);
			break;
		case 3: // 3、删除联系人
			deletePerson(&abs);
			break;
		case 4: //4、查找联系人
			findPerson(&abs);
			break;
		case 5: //5、修改联系人
			modifyPerson(&abs);
			break;
		case 6: //6、清空联系人
			clearAll(&abs);
			break;
		case 0: //0、退出通讯录
			cout << "退出成功，欢迎再次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}

	system("pause");
	return 0;
}