#pragma once

#include <vector>

class Monsters
{
private:

public:
	Monsters();
	~Monsters();


};
class MonsterDatabase
{
private:
	std::vector<Monsters> monsters;
	std::vector<int> nums;

public:

	void FindMonsterById(int id)
	{

	}

	void FindNumInDatabase()
	{

	}
	MonsterDatabase();
	~MonsterDatabase();


};
