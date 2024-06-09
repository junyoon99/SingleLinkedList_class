#include "SingleLinkedList.h"

void SingleLinkedList::CreateMonster(const char* name, int hp, int mp)
{
	Monster* m = new Monster;

	m->hp = hp;
	m->mp = mp;

	strcpy_s(m->name, Name_Length, name);

	m->pNext = nullptr;

	if (pHead == nullptr && pTail == nullptr)
	{
		pHead = m;
		pTail = m;
	}
	else
	{
		pTail->pNext = m;
		pTail = m;
	}
	size++;
}

int SingleLinkedList::GetMonsterCount() const
{
	return size;
}

void SingleLinkedList::PrintMonsters() const
{
	Monster* m = pHead;

	while (m != nullptr)
	{
		std::cout << m->name << "," << m->hp << "," << m->mp << std::endl;
		m = m->pNext;
	}
}

bool SingleLinkedList::FindMonster(const char* name) const
{
	Monster* m = pHead;
	while (m != nullptr)
	{
		if (strcmp(m->name, name) == 0)
		{
			return true;
		}
		m = m->pNext;
	}
	return false;
}

void SingleLinkedList::DeleteList()
{
	Monster* m = pHead;
	Monster* next;

	while (m != nullptr)
	{
		next = m->pNext;
		delete m;

		m = next;
	}

	pHead = pTail = nullptr;
	size = 0;
}

void SingleLinkedList::DeleteMonster(const char* name)
{
	Monster* m = pHead;
	Monster* previous = nullptr;

	while (m != nullptr)
	{
		if (strcmp(m->name, name) == 0)
		{
			break;
		}

		previous = m;
		m = m->pNext;
	}

	if (m != nullptr)
	{
		if (pHead == pTail)
		{
			pHead = pTail = nullptr;
		}
		else if (previous == nullptr)
		{
			pHead = m->pNext;
		}
		else if (m == pTail)
		{
			previous->pNext = nullptr;
			pTail = previous;
		}
		else
		{
			previous->pNext = m->pNext;
		}
	}
	size--;
}
