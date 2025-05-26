#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "TimeCheck.h"
#include "FunctionPointer.h"
#include "ConsoleUtility.h"

/* 컨테이너의 종류
* Sequence Container 
* Vector
* Deque
* List
*/

/*
* 오늘의 목표 : Vector 와 List의 차이점을 직접 비교해보세요. 
* 
* 1. vector push_back 추가, List push_back 추가한 시간을 비교해보세요. : 결과 <> 누가 더 빨랐다  그이유를.
* 2. 임의의 데이터에 접근하는데 걸리는 시간 : vector가 더 빠르다 . list 개수가 많을수록 더 시간이 걸린다.
* 3. 임의의 데이터를 지우는데 걸리는 시간 : list가 더빠르다.
* 
* 데이터가 삭제는 적은데, 접근은 많은 경우 vector이 유리
* 데이터의 삭제가 빈번한 경우 : list 유리
* (★★★★★) 데이터 삭제도 많고 접근도 많은 경우 : ?? unordered_map
* 
* vector
* unordered_map
* 
*/

/* Vector 과 List의 차이점.
* Vector, List 크게 차이점이 없다.
* Vector [] 인덱스로 데이터로 출력할 수 있다.
* List   [] 인덱스로 접근할 수 없다. // 배열이 아니면 어떻게 자료를 표현할 수 있을까?
* 
* 차이점을 눈으로 확인하기 위해서 환경 설정을 진행한다.
*/


void Test1_Vector()
{
    std::vector<int> nums;
    for (int i = 0; i < 1000; i++)
    {
        nums.push_back(i);
    }

    std::cout << nums[500] << std::endl;


}

void Test2_List()
{
    std::list<int> nums;

    nums.push_back(3);
    nums.push_front(2);
    nums.push_back(1);

    for (const auto& num : nums )
    {
        std::cout << num << " ";
    }
}

void VectorExample()
{
    std::vector<int> nums;
    for (int i = 0; i < 1000; i++)
    {
        nums.push_back(i);
    }
    std::cout << "임의의 데이터 접근 시간" << std::endl;
    std::cout << nums[900] << std::endl;

    // erase 함수를 n번 사용하는 예제를 만들어보세요.
}

void ListExample()
{
    std::list<int> nums;
    for (int i = 0; i < 1000; i++)
    {
        nums.push_back(i);
    }

    std::cout << "임의의 데이터 접근 시간" << std::endl;
    auto it = std::next(nums.begin(), 900);
   std::cout << *it << std::endl;

   // erase 함수를 n번 사용하는 예제를 만들어보세요.
}

int main()
{
   // Test1_Vector();
   // Test2_List();
  
   // 자료구조 시간 테스트
   // TimeCheckTest();
   // TimeCheckTest2();

   // 함수 포인터 예제
   // Test();

   // ConsoleUtil::TimeCheck(); 실행하기.

    ConsoleUtil::TimeCheck(VectorExample);
    ConsoleUtil::TimeCheck(ListExample);

}

