#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include "Algo.h"


// int 타입의 데이터를 저장하는 vector 클래스를 만들어서
// 1,2,3,4,5 를 저장하세요

// Iterator (반복기)
// 포인터의 역할을 하는 클래스.
// 자료구조::iterator

// iterator을 사용해서 자료구조의 element를 출력할 수 있다.
// begin() -> 데이터의 맨처음,     cbegin() -> 변경하지못하는 데이터의맨처음, rbegin() -> 맨처음의 역순, crbegin() -> 데이터를변경하지못하고 맨처음의 역순.
//   end() -> 데이터의 맨마지막,     cend() -> 변경하지못하는 데이터 맨마지막,  rend() -> 맨마지막의 역순, crend() -> 데이터를 변경하지못하고 맨마지막의 역순.

// auto it = 변수이름.실행할함수

// iterator 의 기본 사용법
void test1()
{
	std::vector<int> nums = { 1,2,3,4,5 };
	std::list<int> intlist = { 2,4,6,8,10 };
	std::vector<int>::iterator it = nums.begin();

	std::cout << "iterator를 활용한 자료구조 전체 데이터 출력" << std::endl;
	while (it != nums.end()) // vector.end
	{
		std::cout << *it << " ";  // iterator 저장된 주소의 값을 역참조해서 출력
		it++;
	}

	std::cout << std::endl;
	std::cout << "for반복문을 활용한 자료구조 전체 데이터 출력" << std::endl;
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}

	// vector가 아닌 다른 자료구조에서 데이터를 순회, 사용

	std::list<int>::iterator it2 = intlist.begin();
	std::cout << "\n============================================================" << std::endl;
	std::cout << "list 자료구조를 전체 출력한 코드" << std::endl;
	while (it2 != intlist.end())
	{
		std::cout << *it2 << " ";
		it2++;
	}
}

// 역순으로 출력하는 방법
void test2()
{
	std::cout << "\n===================================" << std::endl;
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9};
	auto it = vec.rbegin();
	
	while (it != vec.rend())
	{
		std::cout << *it << " ";
		it++;
	}

	std::cout << std::endl;
	std::cout << "list를 역순으로 출력" << std::endl;
	std::list<int> lis = { 2,4,5,6,7,8,9, };
	std::list<int>::reverse_iterator it2 = lis.rbegin();

	while (it2 != lis.rend())
	{
		std::cout << *it2 << " ";
		it2++;
	}

}

// auto 키워드
void test3()
{
	std::cout << "\n===================================" << std::endl;

	// 예시 1
	auto x = 5;

	// 예시 2. 언제 사용하면 좋은가? 타입이름이 매우 긴 예제들이 있다.
	std::vector<int> nums = { 1,2,3,4,5 };
	auto it = nums.rbegin();

	
	// 주의할 사항 : 대입 연산자 오른쪽에 오는 value 불특정한 데이터일때 사용 X
	// auto score = 1.1 * 10 + 1.23 * 200;

	// 예시 3.

	// 1. 데이터를 복사해서 사용하고싶을때 (데이터의 자료형이 매우 작을때)
	// 
	// auto        : int, double, primitive type 사용 할 때 편하게 사용 (복사해서 만들어 진다.)
	// auto&       : 메모리에 접근해서 데이터를 변경할 수 있다.
	// const auto& : 메모리에 데이터를 문법적으로 변경하지 못하게 한다.
	


	for (auto& num : nums)
	{
		num = 0;
	}

	for (auto num : nums)
	{
		std::cout << num << " ";
	}

}

// 상수 iterator
void test4()
{
	std::cout << "\n===================================" << std::endl;
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };

	auto it = vec.cbegin();

	while (it != vec.cend())
	{
		std::cout << *it << " ";
		it++;
	}

}

// iterator 응용
void test5()
{
	std::cout << "\n===================================" << std::endl;
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };

	auto start = vec.begin() + 2;  // 가리키고 있다. 3번째 element 가리키고있다.
	auto finish = vec.end() - 3;

	while (start != finish)
	{
		std::cout << *start << " ";
		start++;
	}

}

int main()
{
	// test()
	// test2();
	// test3();
	// test4();
	// test5();
	// find_test();
	find_test2();
	// all_of_test();
	// for_each_test();
}
