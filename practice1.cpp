#include <iostream>
int factorial(int n)
{
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}

int fibonacci(int n)
{
	if (n <= 1) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int hanoiSteps = 0;

void hanoi(int n, char  from, char to, char via)
{
	if (n == 0) return;
	hanoi(n - 1, from, via, to);
	std::cout << from <<" -> " << to << "\n";
	hanoiSteps++;
	hanoi(n - 1, via, to, from);
}
int main()
{
	int n = 0;
	std::cin >> n;

	std::cout << "阶乘: " << factorial(n) << "\n";
	std::cout << "斐波那契: " << fibonacci(n) << "\n";
	std::cout << "汉诺塔:\n";
	hanoi(n, 'A', 'C', 'B');
	std::cout << "共 " << hanoiSteps << " 步\n";
	return 0;
}

