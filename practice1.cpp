#include <iostream>
int main()
	{
	int n;
	int a, b;
	std::cin >> n;
	int arr[100];
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n -1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		std::cout << arr[n-1-i] << " ";
	}
		return 0;
	}
