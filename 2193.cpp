#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long d[91][2];

int main(void)
{
	int N;
	cin >> N;
	long long sum = 0;
	d[1][0] = 0;
	d[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		d[i][1] = d[i-1][0];
		d[i][0] = d[i - 1][0] + d[i - 1][1];
	}

	sum = d[N][0] + d[N][1];

	cout << sum << endl;

	return 0;
}