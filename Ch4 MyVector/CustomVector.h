#pragma once

/* ����(���� �迭)�� Ư¡
*  - ���̰� ���� �� �ִ�. ���� ũ�� ��ȯ�� �����ϴ�.
*  - �ڵ����� ũ�Ⱑ ���� �ȴ�.
*  - 
* 
*/

/*
*  int size ũ��;
*  int capacity ���뷮;
* 
* int arr = new int[5]; -> size(0) capacity(5)
* 
* size 6 = int[6]
* arr = new int[10];
* 
* resize();
* int size, capacity
*/
// value�� �ش��ϴ� Ÿ���� T�� ��ȯ�ϼ���.
#include <iostream>
template<typename T>  // int, double, string
class MyVector
{
private:
	int size;
	int capacity;
	T* vec;


public:
	// ������
	MyVector() = default;
	MyVector(int startSize)
	{
		vec = new T[startSize];
		size = 0;
		capacity = startSize;
	}
	// �Ҹ���
	~MyVector()
	{
		delete[] vec;
	}

	

	T& operator[](int idx)
	{
		return vec[idx];
	}
	void resize(int nsize)
	{
		// size : ���� �迭�� ����ִ� ������ ����
		// nsize : �����Ϸ��� �������� ũ��

		// ������ ������ ������
		if (size < nsize)
		{
			size = size;
		}
		else
		{
			size = nsize;
		}

		// capacity ��� �����ұ�?
		
		capacity = nsize;

		T* arr = new T[nsize];

		//vec[0], vec[1].... size ��ŭ
		for (int i = 0; i < size; i++)
		{
			arr[i] = vec[i];
		}
		delete[] vec;  // ������ vec�� ����Ű�� �ִ� ������ �޸� �����Ѵ�.

		vec = arr;     // vec�� ���ο� ������ �ٽ� �����Ѷ�.

		// delete[] arr;
 
	}
	void push_back(const T& element)
	{
		// capacity <= size
		if (capacity <= size)
		{
			capacity = capacity * 2; 
			resize(capacity);
		}

		vec[size] = element;

		size++;

	}
	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;

		// if (size > 0)
		// {
		// 	size = size - 1;
		// }
		// else if (size == 0)
		// {
		// 	size = 0;
		// }
	}

	int Size() { return size; }

};
void test1()
{
	while (true)
	{
		MyVector<int>* myVec = new MyVector<int>(10);
		delete myVec;
	}
}

void test2()
{
	MyVector<int> vec(5);

	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);

		std::cout << vec[i] << " ";
	}

	vec.push_back(6);
	std::cout << std::endl;

	for (int i = 0; i < vec.Size(); i++)
	{
		std::cout << vec[i] << " ";
	}


	MyVector<double> vec2(5);
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		vec2.push_back(i + 0.1);
		
		std::cout << vec2[i] << " ";
	}
}