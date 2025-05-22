#pragma once

#include <iostream>
#include <vector>

/* 도전과제
*  1. DropItem 생성자를 만들어 보세요.
*  2. Monster이 데이터를 받아올 수 있게 Private 필드를 선언한다.
*  3. Pubilc 레이블에 생성자, vector의 DropItem을 추가해보세요.
*  4. 자료구조를 사용하는 함수를 만들어보세요.
*/

struct DropItem
{
	int index;
	int exp;
	int money;
	DropItem() = default;
	DropItem(int index, int exp, int money) : index(index), exp(exp), money(money) {}

};

class Monster
{
private:
	// 2
	int exp;
	int money;
	std::vector<DropItem> DropTable;
	DropItem currentDropItem;
public:

	Monster(int exp, int money) : exp(exp), money(money)
	{
		// 3. 자료 구조를 생성하여 만들어보세요.
		DropTable.emplace_back(1,5,20);
		DropTable.emplace_back(2,10,10);
		DropTable.emplace_back(3,2,5);
		DropTable.emplace_back(4,3,5);
		DropTable.emplace_back(5,80,100);

		// 내가 어떤 경험치 테이블을 선택했는가?
		SetDropItem();
	}

	void SetDropItem()
	{
		// int index =
		// 	currentDropItem = drop[index];
	}

	void GetDropPoint()
	{

	}

};