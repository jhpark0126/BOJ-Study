#include <iostream>

using namespace std;

bool map[1001][1001];
bool visited1[1001];
bool visited2[1001];
int queue[10001];
int rear = 0;
int front = 0;
int N;

void DFS(int n)
{
	visited1[n] = true;
	cout << n << ' ';
	for (int i = 1; i <= N; i++)
	{
		if (map[n][i] == 1 && visited1[i] == 0)
		{
			DFS(i);
		}
	}

}

int _size()
{
	return rear - front;
}

void BFS(int n)
{
	queue[rear++] = n;
	visited2[n] = true;
	while (_size() != 0)
	{
		cout << queue[front]<<' ';
		int k = queue[front++];
		for (int i = 1; i <= N; i++)
		{
			if (map[k][i] == 1 && visited2[i] == 0)
			{
				queue[rear++] = i;
				visited2[i] = true;
			}
		}
	}

}

int main(void)
{
	int M, V;
	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	DFS(V);
	cout << '\n';
	BFS(V);
	cout << '\n';

	return 0;
}
/*
6 5 1
1 2
2 3
1 4
3 6
3 5
*/