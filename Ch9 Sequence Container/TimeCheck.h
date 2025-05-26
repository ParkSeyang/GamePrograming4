#pragma once

#include <iostream>
#include <chrono>  // 시간을 계산해주는 기능들이있는 헤더 or Clock 기능이 담겨있는 헤더

/*
*  vector와 list의 차이점
*
*  1. 임의의 데이터에 접근하는 시간을 비교한다.
* - 결과 : vector은 바로 임의의 데이터에 접근할 수 있다. 시간복잡도가 빠르다( O(1) ).  
*         list는 n번째 데이터에 접근하는데 길이에 비례해서 시간이 걸린다. (linear Time O(n))
* 
*  2. 첫번째와 끝의 데이터가 아닌 데이터를 삭제 또는 수정하는데 걸리는 시간.
* - 많은 데이터를 자주 삭제 또는 수정하는 경우 Vector의 시간이 비효율적이다.
* - 1~N 데이터 -> 1~N-1 개 데이터를 옮기는 작업
* - 데이터를 지우거나, 변강하는 작업이 많으면 많을수록 vector 가 시간이 비효율적이다.
* 
*/

/*
* (번외) 어떠한 자료구조를 써야할 지 잘 모르겠으면 Vector로 만들어보세요.
* vector은 무엇을 했을때 시간이 오래걸릴까?
*/

void TimeCheckTest()
{
	std::cout << "특정 기능이 얼마나 시간이 걸리는지 측정하는 코드 입니다." << std::endl;

	auto Start = std::chrono::high_resolution_clock::now();

	std::vector<int> nums;

	for (int i = 0; i < 1000000; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 10000; i++)
	{
		auto it = nums.begin() + 5;
		nums.erase(it);
	}
	

	auto End = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << "ms" << std::endl;
}



void TimeCheckTest2()
{
	std::cout << "STL list 의 시간을 측정합니다. " << std::endl;

	auto Start = std::chrono::high_resolution_clock::now();

	std::list<int> nums;

	for (int i = 0; i < 1000000; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 10000; i++)
	{
		auto it = std::next(nums.begin(), 5);
		nums.erase(it);
	}
	

	auto End = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << "ms" << std::endl;
}