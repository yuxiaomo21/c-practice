#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include<algorithm>
struct Student
{
	std::string name;
	int score;
};
bool compraeByScore(const Student& a, const Student& b)
{
	return a.score > b.score;//如果a大于b则返回的为ture，所以能够降序排序
}
class StudentList
{
public:
	void add(); void show(); void sort();
	void stats(); void save(); void load();
private:
	std::vector<Student>list;
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
	Student s;
	std::cin >> s.name;
	std::cin >> s.score;
	list.push_back(s);
	std::cout << "已添加\n";
}
void StudentList::show()
{
	for (const Student& s : list)
	{
		std::cout << s.name << " " << s.score << "\n";
	}
}
void StudentList::sort()
{
	std::sort(list.begin(), list.end(), compraeByScore);
	std::cout << "排序完成\n";
}
void StudentList::stats()
{
	double  sum = 0;
	int mx = list[0].score, mn = list[0].score;
	if (list.empty()) { std::cout << "暂无学生\n"; return; }
	for (Student& s : list)//遍历list，其实约等于之前的const
	{
		if (s.score > mx) mx = s.score;
		if (s.score < mn) mn = s.score;
		sum += s.score;
	}
	std::cout << "人数: " << list.size() << "\n";
	std::cout << "平均分: " << sum / list.size() << "\n";
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
	for (Student& s : list)
	{
		fout << s.name << " " << s.score << "\n";
	}
	fout.close();
	std::cout << "已保存\n";
}
void StudentList::load()
{
	std::ifstream fin("students.txt");
	if (!fin)
	{
		std::cout << "文件不存在或无法打开\n";
		return;
	}
	list.clear();
	Student s;
	while (fin >> s.name >> s.score)//不断读取，直到文件结束或数组满
	{
		list.push_back(s);
	}
	fin.close();
	std::cout << "已读取" << list.size() << "条\n";
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

