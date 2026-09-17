#include <iostream>
#include <string>
#include <fstream>
struct Student
{
	std::string name;
	int score;
};
class StudentList
{
public:
	void add();
	void show();
	void sort();
	void stats();
	void save();
	void load();
private:
	Student list[100];
	int count = 0;
};
void showMenu()
{
	std::cout << "\n===== 学生成绩管理系统 =====\n";
	std::cout << "1. 添加学生\n";
	std::cout << "2. 显示全部\n";
	std::cout << "3. 按成绩降序排序\n";
	std::cout << "4. 统计信息\n";
	std::cout << "5.保存到文件\n";
	std::cout << "6.从文件读取\n";
	std::cout << "0. 退出\n";
	std::cout << "请选择: ";
}
void StudentList::add()
{
	std::cin >> list[count].name;
	std::cin >> list[count].score;
	count++;
	std::cout << "已添加\n";
}
void StudentList::show()
{
	for (int i = 0; i < count; i++)
	{
		std::cout << list[i].name << " " << list[i].score << "\n";
	}
}
void StudentList::sort()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (list[j].score < list[j + 1].score)
			{
				Student temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	std::cout << "排序完成\n";
}
void StudentList::stats ()
{
	double avg = 2, mn = list[0].score, sum = 0;
	double mx = list[0].score;
	for (int i = 0; i < count; i++)
	{
		if (list[i].score > mx) mx = list[i].score;
		if (list[i].score < mn) mn = list[i].score;
	}
	for (int i = 0; i < count; i++)
	{
		sum += list[i].score;
	}
	if (count == 0) { std::cout << "暂无学生\n"; return; }
	avg = sum / count;
	std::cout << "人数: " << count << "\n";
	std::cout << "平均分: " << avg << "\n";
	std::cout << "最高分: " << mx << "\n";
	std::cout << "最低分: " << mn << "\n";
}
void StudentList::save()
{
	std::ofstream fout("students.txt");
	if (!fout)
	{
		std::cout << "无法写入文件\n";
		return;
	}
	for (int i = 0; i < count; i++)
	{
		fout << list[i].name << " " << list[i].score << "\n";
	}
	fout.close();
	std::cout << "已保存/n";
}
void StudentList::load()
{
	std::ifstream fin("students.txt");
	if (!fin)
	{
		std::cout << "文件不存在或无法打开\n";
		return;
	}
	count = 0;
	while (count<100 && fin >> list[count].name >> list[count].score)//不断读取，直到文件结束或数组满
	{
		count++;
	}
	fin.close();
	std::cout << "已读取" << count << "条\n";
}
int main()
{
	StudentList s1;
	int choice = 0;
	while (true)
	{
		showMenu();
		std::cin >> choice;
		if (!std::cin)break;
		if (choice == 0)break;
		switch (choice)
		{
		case 1: s1.add();   break;
		case 2: s1.show();  break;
		case 3: s1.sort();  break;
		case 4: s1.stats(); break;
		case 5: s1.save();  break;
		case 6: s1.load();  break;
		default: std::cout << "无效选择\n";
		}
	}

	return 0;
}

