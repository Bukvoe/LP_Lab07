#pragma once
#include <cstring>
#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30
#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышен максимальной емкости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование индетификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "UpdEntry: не найден элемент"
#define THROW07 "DelEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование индетификатора"

namespace Dictionary
{
	struct Entry
	{
		int id;
		char name[ENTRYNAMEMAXSIZE];
	};
	struct Instance
	{
		char name[DICTNAMEMAXSIZE];
		int maxsize;
		int size;
		Entry* Dictinary;
	};

	Instance Create(char name[DICTNAMEMAXSIZE], int size);
	void AddEntry(Instance& inst, Entry ed);
	void DelEntry(Instance& inst, int id);
	Entry GetEntry(Instance& inst, int id);
	void UpdateEntry(Instance& inst, int id, Entry new_entry);
	void Print(Instance& inst);
	void Delete(Instance& inst);
}