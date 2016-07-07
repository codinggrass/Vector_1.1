#ifndef MY_VECTOR_H
#define MY_VECTOR_H
template <typename Object>
class Vector
{
private:
	int theSize;
	int theCapacity;
	Object *objects;
public:
	explicit Vector(int initSize = 0)
		:theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
	{
		objects = new Object[theCapacity];
	}
	Vector(const Vector &rhs) :objects(NULL)//���������ָ�ʽ��
	{
		operator=(rhs);
	}
	//�������� 
	~Vector()
	{
		delete[] objects;
	}
	//���Ʋ���
	const Vector&operator=(const Vector &rhs)
	{
		if (this != rhs)
		{
			delete[] objects;
			theSize = rhs.theSize();
			theCapasity = rhs.theCapacity();

			objects = new Object[theCapacity];//
			int k = 0;
			for (auto a : rhs.objects)
				objects[k++] = a;
		}
		return *this;
	}
	//Ԫ�ظ����趨����
	void resize(int theNewsize)
	{
		if (theNewsize > theCapacity)
			reserve(theNewsize * 2 + 1);//Ϊʲô+1
		theSize = theNewsize;
	}
	//�ռ����亯��
	void reserve(int newCapacity)
	{
		if (newCapacity < theCapacity)
			return;
		Object *oldArray = objects;

		objects = new Object[newCapacity];
		for (int k = 0; k < theSize; k++)
			objects[k] = oldArray[k];
		theCapacity = newCapacity;
		delete[] oldArray;
	}
	int size() const
	{
		return theSize;
	}
	int capacity() const
	{
		return theCapacity;
	}
	//�ṩ[]����
	Object &operator[](int index)
	{
		return objects[index];
	}
	const Object &operator[](int index) const
	{
		return objects[index];
	}
	//�Ƿ�Ϊ��
	bool empty() const
	{
		return size() == 0;
	}
	//��β������һ��Ԫ��
	void push_back(const Object &x)
	{
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		objects[theSize++] = x;
	}
	//ɾ�����һ��Ԫ��
	void pop_back()
	{
		theSize--;
	}
	const Object & back() const
	{
		return objects[theSize - 1];
	}
	typedef Object * iterator;
	typedef const Object * const_iterator;
	iterator begin()
	{
		return &objects[0];
	}
	//����ָ�����һ��Ԫ�أ��������һ��Ԫ�ص���һ��Ԫ��
	iterator end()
	{
		return &objects[theSize];
	}
	const_iterator begin() const
	{
		return &objects[0];
	}
	//����ָ�����һ��Ԫ�أ��������һ��Ԫ�ص���һ��Ԫ��
	const_iterator end() const
	{
		return &objects[theSize];
	}
	enum MyEnum
	{
		SPARE_CAPACITY = 16
	};
};

#endif // MY_VECTOR_H

