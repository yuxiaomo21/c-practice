#include<iostream>
#include<string>
#include<cctype>
int main()
{
	std::string s;//初始化字符串
	std::getline(std::cin, s);
	int total = (int)s.length();//获取字符串长度
	int alpha = 0, digit = 0, space = 0, other = 0;
	for (int i = 0; i < (int)s.length(); i++)
	{
		char c = s[i];
		if (std::isalpha(c))
		{
			alpha++;
		}
		else if (std::isdigit(c))
		{
			digit++;
		}
		else if (std::isspace(c))
		{
			space++;
		}
		else
		{
			other++;
		}
	}
	std::cout << total << "\n";
	std::cout << alpha << "\n";
	std::cout << digit << "\n";
	std::cout << space << "\n";
	std::cout << other << "\n";
	return 0;
}
