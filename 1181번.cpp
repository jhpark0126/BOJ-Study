#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string word[20000];

bool compare(string a, string b)
{
	if (a.length() < b.length())
		return true;
	else if(a.length() > b.length())
		return false;
	else
		return a < b;
}

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> word[i];
	}
	
	sort(word, word + N, compare);

	for (int i = 0; i < N; i++)
	{
		if (i < N - 1)
		{
			if (word[i] == word[i + 1])
				continue;
		}
		cout << word[i] << endl;
	}
	return 0;
}

