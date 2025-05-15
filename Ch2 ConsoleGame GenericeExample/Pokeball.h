#pragma once
#include<iostream>
#include<string>

class PokeMon
{
private:
	int number;
	std::string name;

public:
	PokeMon() = default;
	~PokeMon() = default;

	PokeMon(int number, std::string name)
		: number(number), name(name) 
	{}

	int get_number() const
	{
		return number;
	}
	std::string get_name() const
	{
		return name;
	}


};

