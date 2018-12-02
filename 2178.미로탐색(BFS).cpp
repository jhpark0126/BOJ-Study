#include <iostream>

using namespace std;

typedef struct {
	int x;
	int y;
}axis;

int map[101][101];
int visited[101][101];
axis queue[10001];
int front = 0;
int rear = 0;



int _size()
{
	return rear - front;
}

int BFS(int N, int M)
{
	int cnt =1;
	queue[rear++] = axis{1,1};
	visited[1][1] = true;

	while (front < rear)
	{
		int size = _size();

		for (int k = 0; k < size; k++)
		{
			axis T = queue[front++];

			if (T.x == M && T.y == N)
				return cnt;

			if (map[T.y][T.x - 1] == 1 && visited[T.y][T.x - 1] == 0)
			{
				queue[rear++] = axis{ T.x-1,T.y };
				visited[T.y][T.x - 1] = true;
			}
			if (map[T.y][T.x + 1] == 1 && visited[T.y][T.x + 1] == 0)
			{
				queue[rear++] = axis{ T.x+1,T.y };
				visited[T.y][T.x + 1] = true;
			}
			if (map[T.y - 1][T.x] == 1 && visited[T.y - 1][T.x] == 0)
			{
				queue[rear++] = axis{ T.x,T.y-1 };
				visited[T.y - 1][T.x] = true;
			}
			if (map[T.y + 1][T.x] == 1 && visited[T.y + 1][T.x] == 0)
			{
				queue[rear++] = axis{ T.x,T.y+1 };
				visited[T.y + 1][T.x] = true;
			}
		}
		cnt++;
	}
}


int main(void)
{

	int N, M;
	cin >> N >> M;
	// M : x좌표, N : y좌표
	for (int i = 1; i <= N; i++)
	{
		char num[101];
		cin >> num;
		for (int j = 1; j <= M; j++)
			map[i][j] = num[j - 1] - '0';

	}

	cout << BFS(N, M) << endl;

	return 0;
}