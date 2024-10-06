struct node
{
	int data;
	node* right, * left;
	node(int d, node* r = 0, node* l = 0)
	{
		data = d;
		right = r;
		left = l;
	}
};
class BST
{
	node* root;

	bool add(int el, node*& r);
	void pre(node* r);
	void post(node* r);
	void in(node* r);
	int size(node* r);
	int height(node* r);
	bool search(int el, node* r);
	void del(node*& r);
	void copy(node* ro, node*& r);
	BST(node* ro, node* r);
public:
	BST();
	bool add(int el);
	void preorder();//root left right
	void postorder();//left right root
	void inorder();//left root right
	int size();
	int height();
	bool search(int el);
	void delete_bst();
	void copy_bst(BST& o);
	~BST();
	BST(BST& o);
	//void operator=(BST& o);
};