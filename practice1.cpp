#include <iostream>
void swapValues(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int* findMax(int* arr, int n)
{
	int* best = arr;
	for (int i = 1; i < n; i++)
	{
		if (*best < arr[i])
		{
			best = &arr[i];
		}
	}
	return best;
}
int main()
{
	int n;
	std::cin >> n;
	int arr[100];
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	int* maxPtr = findMax(arr, n);
	std::cout << "最大值：" << *maxPtr << "\n";
	std::cout << "下标：" << (maxPtr - arr) << "\n";//相减为指针的偏移量，这两个指针指向同一个数组
	swapValues(&arr[0], maxPtr);
	for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
	std::cout << "\n";
	return 0;
}

