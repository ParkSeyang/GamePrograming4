#pragma once

#include <iostream>
#include <vector>

/* ��������
*  1. DropItem �����ڸ� ����� ������.
*  2. Monster�� �����͸� �޾ƿ� �� �ְ� Private �ʵ带 �����Ѵ�.
*  3. Pubilc ���̺� ������, vector�� DropItem�� �߰��غ�����.
*  4. �ڷᱸ���� ����ϴ� �Լ��� ��������.
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
		// 3. �ڷ� ������ �����Ͽ� ��������.
		DropTable.emplace_back(1,5,20);
		DropTable.emplace_back(2,10,10);
		DropTable.emplace_back(3,2,5);
		DropTable.emplace_back(4,3,5);
		DropTable.emplace_back(5,80,100);

		// ���� � ����ġ ���̺��� �����ߴ°�?
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