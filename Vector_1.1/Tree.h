#ifndef TREE_H
#define TREE_H
template <typename Comparable>
class BinarySearchTree
{
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

