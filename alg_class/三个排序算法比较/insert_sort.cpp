#include <iostream>
#include <time.h>

void insertsort(int *arr, int len)
{
	for (int j = 1; j < len; j++)
	{
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
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
		arr[i] = Random(1, 100);
	}
	int len = sizeof(arr) / sizeof(arr[0]);
	clock_t start, finish;
	double duration;
	start = clock();
	insertsort(arr, len);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	printf("running time is: %f s\n", duration);
}

// 规模 10 100 1000 10000
int main()
{
	block(10);
	block(100);
	block(1000);
	block(10000);
	return 0;
}
