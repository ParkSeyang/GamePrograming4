#pragma once

// 1. vector <������ ������Ÿ��> �������̸�;

// 2. template ������ �ڵ�� �����غ� ��

// ���ΰ���
// vector< > �����е��� ���� ������ Ŭ������ �ѹ� �����ϰ�, �����ϰ�, ����ϴ� ������ �ѹ� ��������.
// ���� ���� 
// ���ӿ� �����͸� Ŭ������ ǥ��
// vector <> 

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class PocketMonster
{
private:
	int _number;
	string _name;
public:
	PocketMonster(int number, string name) : _number(number), _name(name) {}

	int Get_Number() const
	{
		return _number;
	}

	string Get_Name()
	{
		return _name;
	}

	bool operator<(const PocketMonster& other)
	{
		// this->_number : �ڽ��� ���� ��ȣ
		// other.Get_Number() : �� ����� ���� ��ȣ

		return this->_number < other.Get_Number();
	}
	bool operator>(const PocketMonster& other)
	{
		return this->_number > other.Get_Number();
	}



};



void Example1()
{
	PocketMonster pica(25, "��ī��");
	PocketMonster gugu(1, "����");
	PocketMonster firemon(4, "���̸�");
	PocketMonster pizion(33, "����");
	PocketMonster Bulbasaur(17, "�̻��ؾ�");

	// cout << "No." << pica.Get_Number() << " " << pica.Get_Name() << endl;

	bool result = pica < gugu;
	cout << "������ ��ī�� ���� ���� ��ȣ�� ū����?" << endl;
	if (pica < gugu)
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "�ƴϿ�" << endl;
	}

	vector<PocketMonster> pocketDatabase;

	pocketDatabase.push_back(pica);
	pocketDatabase.push_back(gugu);
	pocketDatabase.push_back(firemon);
	pocketDatabase.push_back(pizion);
	pocketDatabase.push_back(Bulbasaur);

	// ������ �˰���(����)

	sort(pocketDatabase.begin(), pocketDatabase.end());

	// ������ ���
	for (auto&pocketmon : pocketDatabase )
	{
		cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}
	// ������ ã��(�˻�) 
	for (auto& pocketmon : pocketDatabase)
	{
		if(pocketmon.Get_Number() == 1)
		{
			cout << pocketmon.Get_Number()<< "�� ���͸� ã�Ҵ�";
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
		}
		else
		{
			cout << "��ã�Ҵ�.";
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
		}
	}


}