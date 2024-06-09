#pragma once
#include <iostream>

const int Name_Length{ 16 };

struct  Monster
{
	char name[Name_Length];
	int hp;
	int mp;

	Monster* pNext;
};