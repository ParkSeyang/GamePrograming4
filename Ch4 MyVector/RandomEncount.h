#pragma once

#include"ConsoleUtility.h"
#include <vector>
#include <iostream>


class Monster
{
public:
	std::string name;
	int hp;
	int atk;
public:
	Monster() = default;
	~Monster() = default;

	Monster(std::string name, int hp, int atk)
		: name(name), hp(hp), atk(atk) {}

	void ShowInfo() const
	{
		std::cout << "몬스터 이름 : " << name << std::endl;
	}

	void takeDamage(int dmg)
	{
		hp -= dmg;
		if (hp <= 0)
		{
			std::cout <<name<<"이 사망했습니다." << std::endl;
		}
		else
		{
			std::cout << name << "의 남은 체력 : " << hp << std::endl;
		}

	}
};

class Player
{
private:
	std::vector<Monster> huntedMonster;
public:
	void huntMonster(const Monster& monster)
	{
		huntedMonster.push_back(monster);
	}

	void display() const
	{
		std::cout << "사냥한 몬스터 목록" << std::endl;
		int i = 1;
		for (const auto& monster : huntedMonster)
		{
			std::cout << i << "번째 사냥한 몬스터 : " << monster.name << std::endl;
			i++;
		}
	}


};

void Battle(Player& player)
{
	std::vector<Monster> monster =
	{
		Monster("Goblin", 30, 5),
		Monster("Orc", 50, 10),
		Monster("Dragon", 100, 20),
		Monster("Zombie", 20, 3),
		Monster("Vampire", 40, 8)
	};

	int randIndex = ConsoleUtil::GetRandomInt(monster.size() - 1);

	Monster& selectMonster = monster[randIndex];

	int playerAttackDMG = 10;

	while (selectMonster.hp > 0)
	{
		// std::cout << "몬스터에게 " << playerAttackDMG << "만큼 공격을 했습니다.";
		selectMonster.takeDamage(playerAttackDMG);
	}

	player.huntMonster(selectMonster);
}