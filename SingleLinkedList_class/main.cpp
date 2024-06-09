#include<iostream>
#include "SingleLinkedList.h"

int main() 
{
	SingleLinkedList list{};

	list.CreateMonster("Wolf", 100, 0);
	list.CreateMonster("Demon", 200, 100);

	std::cout << list.GetMonsterCount() << std::endl;
	list.PrintMonsters();

	list.DeleteMonster("Wolf");
	std::cout << list.FindMonster("Wolf") << std::endl;

	list.DeleteList();
}