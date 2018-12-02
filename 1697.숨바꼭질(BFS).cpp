#include <iostream>

using namespace std;

int map[100001];
bool visited[100001];
int queue[100001];
int front = 0;
int rear = 0;
int cnt = 0;

int _size() {
	return rear - front;
}

int BFS(int N, int K)
{
	if (N == K)
		return 0;
	else
	{
		queue[rear++] = N;
		visited[N] = true;
		while (front < rear)
		{
			int size = _size();

			for (int i = 0; i < size; i++)
			{
				int temp = queue[front++]; //pop

				if (temp == K)
					return cnt;

				if (temp - 1 >= 0 && visited[temp - 1] == 0)
				{
					queue[rear++] = temp - 1;
					visited[temp - 1] = true;
				}
				if (temp + 1 <= 100000 && visited[temp + 1] == 0)
				{
					queue[rear++] = temp + 1;
					visited[temp + 1] = true;
				}
				if (temp * 2 <= 100000 && visited[temp * 2] == 0)
				{
					queue[rear++] = temp * 2;
					visited[temp * 2] = true;
				}
				 
			}
			cnt++;
		}
	}
	return 0;
}



int main(void)
{

	int N, K;
	cin >> N >> K;



	cout << BFS(N,K) << '\n';
	return 0;
}