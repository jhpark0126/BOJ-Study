#include <iostream>

using namespace std;

typedef struct tree {
	char left;
	char right;
}Tree;

Tree T[27];

void preorder(char root)
{
	cout << root;
	if (T[root - 'A'].left != 0)
		preorder(T[root - 'A'].left);
	if (T[root - 'A'].right !=0)
		preorder(T[root - 'A'].right);
}

void inorder(char root)
{
	if (T[root - 'A'].left != 0)
		inorder(T[root - 'A'].left);
	cout << root;
	if (T[root - 'A'].right != 0)
		inorder(T[root - 'A'].right);
}

void postorder(char root)
{

	if (T[root - 'A'].left != 0)
		postorder(T[root - 'A'].left);
	if (T[root - 'A'].right != 0)
		postorder(T[root - 'A'].right);
	cout << root;
}

int main(void)
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char root, L, R;
		cin >> root >> L >> R;
		if (L != '.')
			T[root - 'A'].left = L;
		if (R != '.')
			T[root - 'A'].right = R;
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';

	return 0;
}