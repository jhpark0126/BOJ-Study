#include <iostream>

using namespace std;

typedef struct node {
	int data;
	struct node *left, *right;
}TNode;

TNode *root = NULL;
int C = 0;


TNode *createNode(int X)
{
	TNode *node = new TNode;
	node->data = X;
	node->left = node->right = NULL;
	return node;
}

void insert(int X, TNode *N)
{
	C++;
	if (X < N->data)
	{
		if (N->left == NULL)
			N->left = createNode(X);
		else
			insert(X, N->left);
	}
	else if(X > N->data)
	{
		if (N->right == NULL)
			N->right = createNode(X);
		else
			insert(X, N->right);
	}
}
int main(void)
{
	int N;
	cin >> N;

	while (N--)
	{
		int num;
		cin >> num;
		if (root == NULL)
		{
			root = createNode(num);
			cout << C << endl;
			continue;
		}
		insert(num, root);
		cout << C << endl;
	}
	return 0;
}