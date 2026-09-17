#include <iostream>
#include <string>
struct Student
{
	std::string name;
	int score;
};
void showMenu()
{
    std::cout << "\n===== 学生成绩管理系统 =====\n";
    std::cout << "1. 添加学生\n";
    std::cout << "2. 显示全部\n";
    std::cout << "3. 按成绩降序排序\n";
    std::cout << "4. 统计信息\n";
    std::cout << "0. 退出\n";
    std::cout << "请选择: ";
}
void addStudent(Student list[], int& count)
{
	std::cin >> list[count].name;
	std::cin >> list[count].score;
	count++;
	std::cout << "已添加\n";
}
void showAll(Student list[], int count)
{
    for (int i = 0; i < count; i++)
    {
		std::cout << list[i].name << " " << list[i].score <<"\n";
    }
}
void sortByScore(Student list[], int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (list[j].score < list[j+1].score)
            {
				Student temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
            }
        }
    }
	std:: cout << "排序完成\n";
}
void showStats(Student list[], int count)
{
	double avg =0 , mx =0, mn =0,sum=0;
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
    
        mx = list[0].score;
        mn = list[count -1].score;
    }
    for (int i = 0; i < count; i++)
    {
		sum += list[i].score;
    }
    avg = sum / count;
    std::cout << "人数: " << count << "\n";
	std::cout << "平均分: " << avg << "\n";
    std::cout << "最高分: " << mx << "\n";
    std::cout << "最低分: " << mn << "\n";
}
int main() 
{
    Student list[100];
	int count = 0,choice=0;
    while (true)
    {
        showMenu();
		std::cin >> choice;
        if (!std::cin)break;
        if (choice == 0)break;
        switch (choice)
        {
        case 1:addStudent(list, count); break;
        case 2: showAll(list, count);      break;
        case 3: sortByScore(list, count);  break;
        case 4: showStats(list, count);    break;
        default: std::cout << "无效选择\n";
        }
    }

	return 0;
}

