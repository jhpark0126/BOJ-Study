#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int d[1001];

int DP(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;

	if (d[n] != 0)
		return d[n];

	return d[n] = (DP(n - 1) + DP(n - 2))%10007;
}
int main(void)
{
	int n;
	cin >> n;

	cout << DP(n) << endl;
	

	return 0;
}
