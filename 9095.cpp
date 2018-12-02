#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int d[11];

int DP(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return 4;
	return d[n] = DP(n - 1) + DP(n - 2) + DP(n - 3);

}
int main(void)
{
	int n;
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n; // n < 11인 양수
		cout << DP(n) << '\n';
	}

	return 0;
}
