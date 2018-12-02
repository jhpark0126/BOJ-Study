#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[100001][2];
int d[100001][2];

int main(void)
{
	int T;
	cin >> T;
	
	while (T--)
	{
		int n;
		cin >> n;
		for (int j = 0; j < 2; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				cin >> arr[i][j];
			}
		}
		d[1][0] = arr[1][0];
		d[1][1] = arr[1][1];
		d[2][0] = max(d[1][0], d[1][1] + arr[2][0]);
		d[2][1] = max(d[1][1], d[1][0] + arr[2][1]);
		for (int i = 3; i <= n; i++)
		{
			d[i][0] = max(d[i - 1][0], max(d[i - 2][1] + arr[i][0], d[i-1][1]+arr[i][0]));
			d[i][1] = max(d[i - 1][0] + arr[i][1], max(d[i - 2][0] + arr[i][1], d[i - 1][1]));
		}
		
		int result = max(d[n][0], d[n][1]);
		cout << result << '\n';
	}

	return 0;
}