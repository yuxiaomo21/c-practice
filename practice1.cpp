#include <iostream>

// 函数定义要写在 main 上面（否则 main 里"看不到"它们）

int calcSum(int arr[], int n)
{
	int a=0;
	for (int i = 0; i < n; i++)
	{
		a += arr[i];
	}
	return a;
	// 累加求和，return 结果
}

int findMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
	// 找最大值，return 结果
	// 提示：还记得第六题的套路吗？
}

void reverseArray(int arr[], int n)
{
	for (int i = 0, j = n - 1; i < j; i++, j--)//我理解的是i为最小值，j为里面的最大值，i和j相互交换，直到i=j为止
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		// 交换 arr[i] 和 arr[j]
		// 提示：还记得第七题的交换三步骤吗？
	}
}

int main()
{
	int n;
	std::cin >> n;
	int arr[100];
	for (int i = 0; i < n; i++) std::cin >> arr[i];

	std::cout << calcSum(arr, n) << "\n";
	std::cout << findMax(arr, n) << "\n";

	reverseArray(arr, n);
	for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
	std::cout << "\n";
	return 0;
}
