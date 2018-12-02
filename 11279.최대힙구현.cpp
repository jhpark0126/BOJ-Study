#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int heap[100001];
int heapsize = 0;

void push(int n)
{
	heap[++heapsize] = n;
	for (int i = heapsize; i > 1; i /= 2)
	{
		if (heap[i] > heap[i / 2])
		{
			swap(heap[i], heap[i / 2]);
		}
		else
			break;
	}
}

int pop()
{
	int ans = heap[1];
	heap[1] = heap[heapsize];
	heap[heapsize--] = 0;
	for (int i = 1; 2 * i <= heapsize;)
	{
		if (heap[i] >= heap[2 * i] && heap[i] >= heap[2 * i + 1])
			break;
		if (heap[2 * i] > heap[2 * i + 1])
		{
			swap(heap[2 * i], heap[i]);
			i = i * 2;
		}
		else
		{
			swap(heap[2 * i + 1], heap[i]);
			i = 2 * i + 1;
		}
	}
	return ans;
}

int main(void)
{
	//최대힙 구현
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		if (n > 0)
		{
			push(n);
		}
		else if (n == 0)
		{
			if (heapsize == 0)
				cout << 0 << '\n';
			else
				cout << pop() << '\n';
		}

	}





	return 0;
}