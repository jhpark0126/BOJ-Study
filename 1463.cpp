#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int d[1000001];

int DP(int n)
{
	if (n == 1)
		return 0;
	if (d[n] != 0)
		return d[n];

	d[n] = DP(n - 1) + 1;
	if (n % 2 == 0)
	{
		int temp = DP(n / 2) + 1;
		if (d[n] > temp)
			d[n] = temp;
	}
	if (n % 3 == 0)
	{
		int temp = DP(n / 3) + 1;
		if (d[n] > temp)
			d[n] = temp;
	}
	return d[n];
}

int DP_botup(int n)
{
	d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
			d[i] = d[i / 2] + 1;
		if (i % 3 == 0 && d[i] > d[i / 3] + 1)
			d[i] = d[i / 3] + 1;
	}
	return d[n];
}
int main(void)
{
	int N;
	cin >> N;

	cout << DP(N) << endl;
	//cout << DP_botup(N) << endl;

	return 0;
}
