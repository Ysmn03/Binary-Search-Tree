#include<iostream>
#include"BST_Class.h"
using namespace std;

int main()
{
	int _nodes;
	cin >> _nodes;
	BST t;
	for (int i = 0; i < _nodes; ++i)
	{
		int node;
		cin >> node;
		t.add(node);
	}

	t.preorder();
	cout << "\nsize " << t.size() << endl;
	cout << "\nheight " << t.height() << endl;

	int s;
	cout << "Enter node to search for\n";
	cin >> s;
	cout << t.search(s) << endl;

	BST t2;
	t2.copy_bst(t);
	t2.preorder();
	cout << endl;
	t.preorder();
	t2.delete_bst();
}