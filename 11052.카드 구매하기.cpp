#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[1001];
int P[1001];


int main(void)
{
	int N;
	cin >> N;

	for(int i=1; i<=N; i++)
	{
		int num;
		cin >> num;
		P[i] = num;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			d[i] = max(d[i], d[i - j] + P[j]);
		}
	}

	cout << d[N] << endl;


}