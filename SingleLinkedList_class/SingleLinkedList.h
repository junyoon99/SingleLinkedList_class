#pragma once
#include <iostream>
#include "Monster.h"

class SingleLinkedList
{
private:
	Monster* pHead;
	Monster* pTail;
	int size;

public:
	void CreateMonster(const char* name, int hp, int mp);
	int GetMonsterCount() const;
	void PrintMonsters() const;
	bool FindMonster(const char* name) const;
	void DeleteList();
	void DeleteMonster(const char* name);
};