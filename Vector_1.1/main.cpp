#include<iostream>
#include<vector>
#include<string>
#include"my_vector.h"
#include"Tree.h"
using namespace std;
int main()
{
	vector<int> vv;
	vv = { 1,2,3 };
	Vector<int> v1;
	cout << v1.size() << endl;

	cout << v1.capacity() << endl;
	v1.reserve(100);
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.push_back(0);
	v1.push_back(1);
	cout << v1.size() << endl;

	cout << v1[0] << ' ' << v1[1] << ' ';
	cout << *v1.begin() << endl;

	BinaryNode root,home,local;
	root.element = 0;
	root.left = &home;
	root.right = &local;
	home.element = 1;
	local.element = 2;
	cout << root.left->element << endl;
	while (getchar() != 'q');




	return 0;
}

//
