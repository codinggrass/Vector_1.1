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

	//����xԪ���Ƿ񱻰���������
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
	//�������е������Сֵ,���ص��ǽڵ��ָ��
	//���ַ�����һ�ֵݹ飬һ�ַǵݹ�
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
	//insert�����������x���뵽�ڵ�����t��
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
	//ɾ������
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
	//����
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
	//��¡
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

