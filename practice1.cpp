#include <iostream>
#include <cstdlib>
#include <ctime>
int main(void)
{
	srand(time(0));
	int secret = rand() % 100 + 1;
	int guess;
	int count = 0;
	while (true)
	{
		std::cin >> guess;
		if (!std::cin)break;
		count++;
		if (guess == secret)
		{
			std::cout << "猜对了" << "\n";
			break;
		}
		else if (guess < secret)
		{
			std::cout << "太小" << "\n";
		}
		else
		{
			std::cout << "太大" << "\n";
		}
		std::cout << std::endl;
	}
	std::cout << "共猜了" << count << "次" << std::endl;
	return 0;
}