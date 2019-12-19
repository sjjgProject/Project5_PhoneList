#pragma once
#pragma once

#include<iostream>
#include<string>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<cstdlib>
#include<string>
using namespace std;

struct birthday {
	int year;
	int month;
	int day;
};
struct node {
	string phone_number;
	string name;
	string sex;
	string catagory;//类别
	string QQ;
	string WeChat;
	birthday day;//生日
	string address;
	string email;
	string mail;

	node* leftchild;
	node* rightchild;
	node()
	{
		this->name = "0";
		this->phone_number = "0";
		this->sex = "0";
		this->catagory = "0";
		this->QQ = "0";
		this->WeChat = "0";
		this->day.year = this->day.month = this->day.year = 0;
		this->address = "0";
		this->email = "0";
		this->mail = "0";
	}
	node(string phone_number, string name, string sex, string catagory,
		string QQ, string WeChat, birthday day, string address, string email, string mail)
	{
		this->name = name;
		this->phone_number = phone_number;
		this->sex = sex;
		this->catagory = catagory;
		this->QQ = QQ;
		this->WeChat = WeChat;
		this->day = day;
		this->address = address;
		this->email = email;
		this->mail = mail;
	}
	void displayNode()
	{
		cout << "________________________________________" << endl;
		cout << "姓名："<<name << endl;
		cout << "   电话：" << phone_number << endl;
		cout << "   性别：" << sex << endl;
		cout << "   分类：" << catagory << endl;
		cout << "   QQ：" << QQ << endl;
		cout << "   微信：" << WeChat << endl;
		cout << "   生日：" << day.year <<" "<<day.month<<" "<<day.day<< endl;
		cout << "   地址：" << address << endl;
		cout << "   电子邮箱：" << email << endl;
		cout << "   邮编：" << mail << endl;
		cout<<"___________________________________________"<< endl;
		
	}
};

class PhoneList {
public:
	node* root;
	PhoneList() {
		root = NULL;

	}
	
	bool creatListFromFile()//从txt写入树，成功返回1
	{
		ifstream fin;
		fin.open("Phone.txt", ios::in);//读取形式打开文件

		if (!fin.is_open())//打开失败
		{
			cout << "文件不能打开" << endl;
			return false;
		}
		else//打开成功
		{
			string sexName;
			char buffer[200];

			//fin.getline(buffer, 190);

			while (!fin.eof())//循环建树
			{
				node* newMember = new node;
				
				//用输入参数构建节点
				fin >> newMember->phone_number >> newMember->name >> newMember->sex >> newMember->catagory >> newMember->QQ;
				fin >> newMember->WeChat >> newMember->day.year >> newMember->day.month >> newMember->day.year;
				fin >> newMember->address >> newMember->email>>newMember->mail;

				
				newMember->leftchild = NULL;
				newMember->rightchild = NULL;

				insert(root,newMember);//插入构建好的节点
			}


			fin.close();//关闭文件
			return true;
		}
	}
	
	bool creatListFromExcel()//从excel表格创建树
	{
		ifstream fin;
		fin.open("Phone.csv", ios::in);//读取形式打开文件

		if (!fin.is_open())//打开失败
		{
			cout << "文件不能打开" << endl;
			return false;
		}
		else//打开成功
		{
			string temp;
			//getline(fin, temp);

			//while (!fin.eof())//循环建树
			while(1)
			{
				getline(fin, temp);
				if (temp[0]==',')
				{
					break;
				}
				node* newMember = new node;

				//用输入参数构建节点
				//getline(fin, temp);
				char* token;
				char s[2] = ",";
				string information[12];
				int count = 0;
				char* buf;
				/* 获取第一个子字符串 */
				token = strtok_s((char*)temp.c_str(), s,&buf);

				/* 继续获取其他的子字符串 */
				while (token != NULL)
				{
					//cout << token << endl;
					information[count++] = token;
					token = strtok_s(NULL, s,&buf);
				}
				
					newMember->phone_number = information[0];
					newMember->name = information[1];
					newMember->sex = information[2];
					newMember->catagory = information[3];
					newMember->QQ = information[4];
					newMember->WeChat = information[5];
					newMember->day.year = stoi(information[6]);
					newMember->day.month = stoi(information[7]);
					newMember->day.day = stoi(information[8]);
					newMember->address = information[9];
					newMember->email = information[10];
					newMember->mail = information[11];

					newMember->leftchild = NULL;
					newMember->rightchild = NULL;

					insert(root, newMember);//插入构建好的节点
				
			}
				


			fin.close();//关闭文件
			return true;
		}
	}

	void display() {
		display_the_tree(root);
	}

	void display_the_tree(node*root) {//展示功能的递归函数
		if (root == NULL) {
			return;
		}
		else {
			display_the_tree(root->leftchild);
			//cout << root->name << ":" << root->phone_number << endl;
			root->displayNode();
			display_the_tree(root->rightchild);
		}
	}

	void insert_new_node() {

		string phone_number;
		string name;
		string sex;
		string catagory;//类别
		string QQ;
		string WeChat;
		birthday day;//生日
		string address;
		string email;
		string mail;
		cout << "______________________________________" << endl;
		cout << "输入联系人信息,按照提示顺序:"<<endl;

		cout << "手机：" << endl;
		cin >> phone_number ;

		cout << "姓名：" << endl;
		cin >> name;

		cout << "性别(男或女)：" << endl;
		cin >> sex;

		cout << "类别（家人，朋友，同事）：" << endl;
		cin >>catagory;

		cout << "QQ：" << endl;
		cin >> QQ;

		cout << "微信：" << endl;
		cin >> WeChat;

		cout << "生日（年月日顺序 中间有换行 eg: 1999 12 8：" << endl;
		cin >> day.year>>day.month>>day.year;

		cout << "地址：" << endl;
		cin >> address;

		cout << "邮箱：" << endl;
		cin >> email;

		cout << "邮编：" << endl;
		cin >> mail;

		node* temp = new node(phone_number,name,sex,catagory,QQ,WeChat,day,address,email,mail);
		temp->leftchild = temp->rightchild = NULL;
		
		insert(root, temp);
	}

	void insert(node* &myroot, node* &toadd) {//插入的递归函数
		if (myroot == NULL) {
			myroot = toadd;
		}
		else {
			if (toadd->name < myroot->name) {
				insert(myroot->leftchild, toadd);
			}
			else {
				insert(myroot->rightchild, toadd);
			}
		}
	}

	void get_info() {//输入姓名，获取其相关信息
		cout << "请输入要查找的姓名" << endl;
		string name;
		cin >> name;
		
		node* result = searchNodeName( name);
		cout << "姓名：" << root->name;
		cout << "手机号码：" << root->phone_number;
	}


	void searchTreeName(node* root, node*& member, string name)//递归搜索成员
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			if (root->name == name)
			{
				member = root;
				return;
			}
			else
			{
				searchTreeName(root->leftchild, member, name);
				searchTreeName(root->rightchild, member, name);
			}
		}
	}

	node* searchNodeName(string name)//查找并返回节点,找不到返回NULL
	{
		node* member = NULL;
		searchTreeName(root, member, name);
		return member;
	}

	void searchAssignName(string name, node*& member)//查找并把结果付给节点参数
	{
		member = NULL;
		searchTreeName(root, member, name);
	}

	void searchTreePhone(node* root, node*& member, string phone)//递归搜索成员,按电话号码
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			if (root->phone_number == phone)
			{
				member = root;
				return;
			}
			else
			{
				searchTreePhone(root->leftchild, member, phone);
				searchTreePhone(root->rightchild, member, phone);
			}
		}
	}

	node* searchNodePhone(string phone)//查找并返回节点,找不到返回NULL
	{
		node* member = NULL;
		searchTreePhone(root, member, phone);
		return member;
	}

	void searchAssignPhone(string phone, node*& member)//查找并把结果付给节点参数
	{
		member = NULL;
		searchTreePhone(root, member, phone);
	}

	void deleteBFS(string name) {
		if (delete_node(root, name) == false)
		{
			cout << "删除失败!" << endl;
		}
		else
		{
			cout << "删除成功！" << endl;
		}
		
	}

	void swapall(node*a, node*b) {
		swap(a->name, b->name);
		swap(a->phone_number, b->phone_number);
		swap(a->sex, b->sex);
		swap(a->catagory, b->catagory);
		swap(a->QQ, b->QQ);
		swap(a->WeChat, b->WeChat);
		swap(a->day, b->day);
		swap(a->address, b->address);
		swap(a->email, b->email);
		swap(a->mail, b->mail);
	}

	bool delete_node(node* &myroot, string name)
	{
		//根节点为空
		if (myroot == NULL)
		{
			cout << "通讯录为空！";
			return false;
		}
		//只有一个节点,直接删掉
		if (myroot->leftchild == NULL && myroot->rightchild == NULL)
		{
			delete myroot;
			myroot = NULL;
			return true;
		}

		node* parent = NULL;//指向被删除节点的父母节点
		node* del = myroot;//指向要删除的节点，初始化为根节点

		while (del)//循环找到要删除的节点
		{
			if (name > del->name)
			{
				parent = del;
				del = del->rightchild;
			}
			else if (name < del->name)
			{
				parent = del;
				del = del->leftchild;
			}
			else
			{
				break;
			}
		}
		cout << "父母： "<<parent->name << "要删除：" << del->name;

		if (del)//不是空树
		{
			if (name != del->name)//找不到该名字
			{
				cout << "ERROR:您输入的名字有误！将回到主菜单。" << endl;
				return false;
			}
			else if (del->leftchild == NULL)//要删除的节点没有左子树
			{
				if (del == myroot)//根节点
				{
					myroot = del->rightchild;
				}
				else//非根
				{
					if (del == parent->leftchild)//是某节点左子树
					{
						parent->leftchild = del->rightchild;
					}
					else//是某节点右子树
					{
						parent->rightchild = del->rightchild;
					}
				}
			}
			else if (del->rightchild == NULL)//没有右子树
			{
				if (del == myroot)//是根
				{
					myroot = del->leftchild;
				}
				else//不是根
				{
					if (del == parent->leftchild)
					{
						parent->leftchild = del->leftchild;
					}
					else
					{
						parent->rightchild = del->rightchild;
					}
				}
			}
			else//有左右有
			{
				node* parent = del;
				node* firstInorder = del->rightchild;

				if (firstInorder->leftchild == NULL) 
				{//只有右子树，则直接换信息
					
					swapall(del, firstInorder);//交换信息
					del->rightchild = firstInorder->rightchild;
					delete firstInorder;
					firstInorder = NULL;
					return true;
				}
				else
				{
					while (firstInorder->leftchild)//否则找右子树最左
					{
						parent = firstInorder;
						firstInorder = firstInorder->leftchild;
					}

					swapall(del, firstInorder);//交换信息
					parent->leftchild = firstInorder->leftchild;
					delete del;
					del = NULL;
					return true;
				}
				
			}
		}
	}

};