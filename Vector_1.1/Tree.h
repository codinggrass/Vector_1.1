#ifndef TREE_H
#define TREE_H
template <typename Comparable>
class BinarySearchTree
{
public:
	~BinarySearchTree()
	{
		makeEmpty();
	}
	BinarySearchTree & operator=(BinarySearchTree &ths)
	{
		if (this != &ths)
		{
			makeEmpty();
			root = clone(ths.root);
		}
		return *this;
	}
	bool contains(Comparable &x)
	{
		return contains(x, root);
	}

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode * left;
		BinaryNode * right;

		BinaryNode(const Comparable & theElement, BinaryNode *lt, BinaryNode *rt)
			:element(theElement), left(lt), right(rt) {};
	};
	BinaryNode *root;

	//查找x元素是否被包含在树中
	bool contains(Comparable & x, BinaryNode *t) const
	{
		if (t == NULL)
			return false;
		else if (x<t->element)
			return contains(x, t->left)
		else if (x>t->element)
			return constains(x, t->right)
		else 
			return true;
	}
	//查找树中的最大最小值,返回的是节点的指针
	//两种方法，一种递归，一种非递归
	BinaryNode *findMin(BinaryNode *t)
	{
		if (t == NULL)
			return NULL;
		else if (t->left == NULL)
			return t;
		else
			return findMin(t->left);
	}
	BinaryNode * findMax(BinaryNode *t)
	{
		if (t == NULL)
			return NULL;
		while (t->right != NULL)
			t = t->right;
		return t;
	}
	//insert插入操作，将x插入到节点引用t中
	void insert(Comparable &x, BinaryNode * & t)const
	{
		if (t == NULL)
			t = new BinaryNode(x, NULL, NULL);
		else if (x < t->element)
			return insert(x, t->left);
		else if (x > t->right)
			return insert(x, t->right);
		else
			;
	}
	//删除操作
	void remove(Comparable &x, BinaryNode *&t)
	{
		if (t == NULL)
			return;
		if (x < t->element)
			return remove(x, t->left);
		else if (x>t->element)
			return remove(x, t->right);
		else if (t->left != NULL&&t->right != NULL)
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		}
		else
		{
			BinaryNode *oldNode = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete oldNode;
		}			
	}
	//析构
	void makeEmpty(BinaryNode *&t)
	{
		if (t != NULL)
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = NULL;
	}
	//克隆
	BinaryNode *clone(BinaryNode*t) const
	{
		if (t == NULL)
			return NULL;
		return new BinaryNode(t->element, clone(t->left), clone(t->right));
	}
};

class BinaryNode
{
public:
	int element;
	BinaryNode * left;
	BinaryNode * right;

    BinaryNode()
		:element(0), left(NULL), right(NULL) {};
};
#endif // !TREE_H

