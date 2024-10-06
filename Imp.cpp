#include "BST_Class.h"
#include<cmath>
#include<iostream>
using namespace std;
BST::BST()
{
	root = 0;
}

bool BST::add(int el)
{
	return add(el, root);
}
bool BST::add(int el, node*& r)
{
	if (r == 0)
	{
		r = new node(el);
		return true;
	}
	else
	{
		if (el < r->data)
			return add(el, r->left);
		else if (el > r->data)
			return add(el, r->right);
		else
			return false;
	}
}

void BST::preorder()
{
	pre(root);
}
void BST::pre(node* r)
{
	if (r != 0)
	{
		cout << r->data << " ";
		pre(r->left);
		pre(r->right);
	}
}

void BST::postorder()
{
	post(root);
}
void BST::post(node* r)
{
	if (r != 0)
	{
		post(r->left);
		post(r->right);
		cout << r->data << " ";
	}
}

void BST::inorder()
{
	in(root);
}
void BST::in(node* r)
{
	if (r != 0)
	{
		in(r->left);
		cout << r->data << " ";
		in(r->right);
	}
}

int BST::size()
{
	return size(root);
}
int BST::size(node* r)
{
	if (r == 0)
		return 0;
	return 1 + size(r->left) + size(r->right);
}

int BST::height()
{
	return height(root);
}
int BST::height(node* r)
{
	if (r == 0)
		return -1;
	int hl = height(r->left);
	int hr = height(r->right);
	return (max(hl, hr) + 1);
}

bool BST::search(int el)
{
	return search(el, root);
}
bool BST::search(int el, node* r)

{
	if (r == 0)
		return false;
	if (r->data == el)
		return true;
	if (el < r->data)
		search(el, r->left);
	if (el > r->data)
		search(el, r->right);
}

void BST::delete_bst()
{
	del(root);
}
void BST::del(node*& r)
{
	if (r != 0)
	{
		del(r->left);
		del(r->right);
		delete r;
		r = 0;
	}
}

void BST::copy_bst(BST& o)
{
	if (o.root == 0)
		root = 0;
	else
		copy(o.root, root);
} //because copy constructor exists we remove by reference
void BST::copy(node* ro, node*& r)
{
	if (ro != 0)
	{
		r = new node(ro->data);
		copy(ro->left, r->left);
		copy(ro->right, r->right);
	}
}

BST::~BST()
{
	delete_bst();
}

BST::BST(BST& o)
{
	if (o.root == 0)
		root = 0;
	else
		BST(o.root, root);
}
BST::BST(node* ro, node* r)
{
	if (ro != 0)
	{
		r = new node(ro->data);
		BST(ro->left, r->left);
		BST(ro->right, r->right);
	}
}