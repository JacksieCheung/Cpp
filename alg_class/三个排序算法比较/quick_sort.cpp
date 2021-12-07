#include <iostream>

// 交换函数
void swap(int *m, int *n)
{
	int tmp = *m;
	*m = *n;
	*n = tmp;
}

// 默认以最后一个元素作为中枢
// 比中枢大的放右边，比中枢小的放左边。一直递归求解即可。
int partition(int *arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	// 采用了双指针比较，一遍循环结束
	// i+1 给 pivot 预留位置，移动过程中，指向的值大于 pivot
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[j], &arr[i]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quicksort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

int Random(int a, int b)
{
	return (rand() % (b - a) + a);
}

void block(int num)
{
	std::cout << "new block: " << num << std::endl;
	int arr[num];
	for (int i = 0; i < num; i++)
	{
		arr[i] = Random(1, num);
	}
	int len = sizeof(arr) / sizeof(arr[0]);
	clock_t start, finish;
	double duration;
	start = clock();
	quicksort(arr, 0, len - 1);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	printf("running time is: %f s\n", duration);
}

int main()
{
	block(10);
	block(100);
	block(1000);
	block(10000);
	return 0;
}
