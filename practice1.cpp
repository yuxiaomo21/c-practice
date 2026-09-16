#include <iostream>
#include <string>
struct Student
{
	std::string name;
	int score;
};//定义一个学生结构体，包含姓名和成绩两个成员变量
int main()
{
	int n;
	std::cin >> n;
	Student list[100];
	for (int i = 0; i < n; i++)
	{
		std::cin >> list[i].name >> list[i].score;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (list[j].score < list[j + 1].score)
			{
				Student  temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << list[i].name << " " << list[i].score << "\n";
	}
	return 0;
}
