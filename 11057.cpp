#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long int d[101][10];

int main(void)
{
	int N;
	cin >> N;
	long long int sum = 0;
	for (int i = 1; i < 10; i++)
		d[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				d[i][j] = d[i - 1][j + 1];
			else if (j == 9)
				d[i][j] = d[i - 1][j - 1];
			else
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1])% 1000000000;
			
		}
	}
	for (int j = 0; j < 10; j++)
		sum += d[N][j] % 1000000000;

	cout << sum% 1000000000 << endl;

	return 0;
}