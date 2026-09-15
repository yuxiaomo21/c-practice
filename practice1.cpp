#include <iostream>
int main()
	{
		int n;
		std::cin >> n;
		double a = 0, b = 0;
		double temps[100];
		for (int i = 0; i < n; i++)
		{
			std::cin >> temps[i];
			a += temps[i];
		}
		double c = temps[0], d = temps[0];
		for (int j = 0; j < n; j++)
		{
			if (c < temps[j])
			{
				c = temps[j];
			}
			if (d > temps[j])
			{
				d = temps[j];
			}
		}
		b = a / n;

		// ① 读入 n 个气温

		// ② 算总和、平均、最高、最低

		// ③ 输出四行
		std::cout << a << std::endl;// 总和
		std::cout << b << std::endl;// 平均
		std::cout << c << std::endl;// 最高
		std::cout << d << std::endl;// 最低
		return 0;
	}
