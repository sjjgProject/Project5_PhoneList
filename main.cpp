#include"Phone_List.h"
#include<iostream>
#include<Windows.h>
using namespace std;
void correct(node*& temp)
{
	int tocorrect;
			cin >> tocorrect;

			switch (tocorrect)
			{
			case 1:
			{
				cout << "输入新的电话：" << endl;
				string s;
				cin >> s;
				temp->phone_number = s;

				break;
			}
			case 2:
			{
				cout << "输入新的名字：" << endl;
				string s;
				cin >> s;
				temp->name = s;
				break;
			}
			case 3:
			{
				cout << "输入新的性别：" << endl;
				string s;
				cin >> s;
				temp->sex = s;
				break;
			}
			case 4:
			{
				cout << "输入新的分类：" << endl;
				string s;
				cin >> s;
				temp->catagory = s;
				break;
			}
			case 5:
			{
				cout << "输入新的QQ：" << endl;
				string s;
				cin >> s;
				temp->QQ = s;
				break;
			}
			case 6:
			{
				cout << "输入新的微信：" << endl;
				string s;
				cin >> s;
				temp->WeChat = s;
				break;
			}
			case 7:
			{
				cout << "输入新的生日：" << endl;
				cout << "年份：";
				int y;
				cin >> y;
				cout << "月份:";
				int m;
				cin >> m;
				cout << "日期：";
				int d;
				cin >> d;
				temp->day.year = y;
				temp->day.month = m;
				temp->day.day = d;
				break;
			}
			case 8:
			{
				cout << "输入新的地址：" << endl;
				string s;
				cin >> s;
				temp->address = s;
				break;
			}
			case 9:
			{
				cout << "输入新的邮箱：" << endl;
				string s;
				cin >> s;
				temp->email = s;
				break;
			}
			case 10:
			{
				cout << "输入新的邮编：" << endl;
				string s;
				cin >> s;
				temp->mail = s;
				break;
			}
			default:
				cout << "输入错误！返回主菜单！" << endl;
				break;
		}
}
void displayInfoMenu()
{
	cout << "______________输入修改信息的序号_________________" << endl;
	cout << "1.电话               2.姓名                 3.性别" << endl;
	cout << "4.分类               5.QQ                   6.微信" << endl;
	cout << "7.生日               8.地址                 9.邮箱" << endl;
	cout << "10.邮编                                           " << endl;

}
void Menu()
{
	cout << "*******************菜单********************" << endl;
	cout << "   1.导入通讯录       2.展示联系人信息" << endl;
	cout << "   3.新建联系人       4.删除联系人" << endl;
	cout << "   5.修改联系人信息   6.查看通讯录" << endl;
	cout << "   7.退出程序" << endl;

	cout << "请输入您的选项：" << endl;
}

int main()
{

	cout << "***********************************" << endl;
	cout << "            欢迎使用通讯录           " << endl;
	cout << "***********************************" << endl;

	bool flag = 1;
	PhoneList myList;

	while (flag)
	{
		Menu();
		int choice;
		cin >> choice;

		switch (choice)
		{

		case 1://导入
		{
			cout << "************创建通讯录***************" << endl;
			cout << "输入1从txt文档导入；输入2从excel文件导入：";
			int mod;
			cin >> mod;
			if (mod == 1)
			{
				cout << "正在导入......." << endl;
				Sleep(3000);
				if (myList.creatListFromFile())
				{
					cout << "导入成功！" << endl;
				}
				else
				{
					cout << "导入失败！" << endl;
				}
			}
			else if (mod == 2)
			{
				cout << "正在导入......." << endl;
				Sleep(3000);
				if (myList.creatListFromExcel())
				{
					cout << "导入成功！" << endl;
				}
				else
				{
					cout << "导入失败！" << endl;
				}
			}
			else
			{
				cout << "没有此模式，返回主菜单！" << endl;
			}
			break;
		}
		case 2://2.展示联系人信息
		{
			cout << "检索名字请按1； 检索电话号码请按2: " << endl;
			int mod;
			cin >> mod;

			node* temp;
			if (mod == 1)//名字检索
			{
				string name;
				cin >> name;
				myList.searchAssignName(name, temp);
				if (temp != NULL)
				{
					temp->displayNode();
				}
				else
				{
					cout << "查无此人！返回主菜单。" << endl;
				}
			}
			else if (mod == 2)
			{
				string phone;
				cin >> phone;
				myList.searchAssignPhone(phone, temp);
				if (temp != NULL)
				{
					temp->displayNode();
				}
				else
				{
					cout << "查无此人！返回主菜单。" << endl;
				}

			}
			else
			{
				cout << "没有此模式，返回主菜单！" << endl;
			}
			break;
		}
		case 3:// 3.新建联系人
		{
			cout << "_________________新建联系人____________________" << endl;
			myList.insert_new_node();
			cout << "插入成功！" << endl;
			break;
		}
		case 4:// 4.删除联系人
		{
			cout << "_________________删除联系人____________________" << endl;
			cout << "输入要删除联系人的姓名：" << endl;
			string name;
			cin >> name;
			myList.deleteBFS(name);

			break;
		}
		case 5://5.修改联系人信息
		{
			cout << "_________________修改联系人____________________" << endl;
			cout << "从姓名检索联系人请按1；从电话号码检索联系人请按2" << endl;
			int mod;
			cin >> mod;

			node* temp;
			bool success=1;
			if (mod == 1)
			{
				cout << "请输入要修改的联系人的名字：" << endl;
				string name;
				cin >> name;
				myList.searchAssignName(name, temp);
				if (temp == NULL)
				{
					success = 0;
				}
				
			}
			else if (mod == 2)
			{
				cout << "请输入要修改的联系人的电话号码：" << endl;
				string phone;
				cin >> phone;
				myList.searchAssignPhone(phone, temp);
				if (temp == NULL)
				{
					success = 0;
				}
			}
			else
			{
				cout << "没有此模式，返回主菜单！" << endl;
				break;
			}
			if (success == 1)
			{
				displayInfoMenu();
				correct(temp);
			}
			else
			{
				cout << "查无此联系人，返回主菜单！" << endl;
			}
			
			
			break;
		}
		case 6:// 6.查看通讯录
		{
			myList.display();
			break;
		}

		case 7://exit
		{
			flag = 0;
			cout << "       感谢使用！常联系！         " << endl;
			cout << "_________________________________________" << endl;
			break;
		}

		default:
		{
			cout << "输入错误选项！返回主菜单！" << endl;
			break;
		}

		}
	}
	return 0;
}


