#include "stdafx.h"
#include <tchar.h>
#include <iostream>
#include "Dictionary.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// через функцию, буллев переменная будет проверять на кол-во макросов
	setlocale(LC_ALL, "rus");
#if (defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_CREATE_03) + defined(TEST_CREATE_04) + defined(TEST_CREATE_05) + defined(TEST_CREATE_06) + defined(TEST_CREATE_07) + defined(TEST_CREATE_08) + defined(TEST_DICTIONARY) > 1)
#error DEFINITELY MORE THAN ONE MACRO COMMAND
#endif
	try
	{
#ifdef TEST_CREATE_01
		Dictionary::Create("this_argument_is_too_long_for_the_function", 10);
#elif defined TEST_CREATE_02
		Dictionary::Create("this_argument_is_too_long_for_the_function", 200);
#elif defined TEST_ADDENTRY_03
		Dictionary::Instance temp = Dictionary::Create("Студенты", 3);
		Dictionary::AddEntry(temp, { 1, "Орлов" });
		Dictionary::AddEntry(temp, { 2, "Андреев" });
		Dictionary::AddEntry(temp, { 3, "Соколов" });
		Dictionary::AddEntry(temp, { 4, "Иванов" });
#elif defined TEST_ADDENTRY_04
		Dictionary::Instance temp = Dictionary::Create("Студенты", 3);
		Dictionary::AddEntry(temp, { 1, "Орлов" });
		Dictionary::AddEntry(temp, { 1, "Андреев" });
#elif defined TEST_GETENTRY_05
		Dictionary::Instance temp = Dictionary::Create("Студенты", 3);
		Dictionary::AddEntry(temp, { 1, "Орлов" });
		Dictionary::GetEntry(temp, 2);
#elif defined TEST_GETENTRY_06
		Dictionary::Instance temp = Dictionary::Create("Студенты", 3);
		Dictionary::AddEntry(temp, { 1, "Орлов" });
		Dictionary::DelEntry(temp, 2);
#elif defined TEST_UPDENTRY_07
		Dictionary::Instance temp = Dictionary::Create("Студенты", 3);
		Dictionary::AddEntry(temp, { 1, "Орлов" });
		Dictionary::UpdateEntry(temp, 10, { 1, "Орлов" });
#elif defined TEST_UPDENTRY_08
		Dictionary::Instance temp = Dictionary::Create("Студенты", 3);
		Dictionary::AddEntry(temp, { 1, "Орлов" });
		Dictionary::UpdateEntry(temp, 1, { 1, "Орлов" });
#elif defined TEST_DICTIONARY
		Dictionary::Instance d1 = Dictionary::Create((char*)"Студенты", 9);

		Dictionary::Entry e1 = { 1, "Орлов" }, e2 = { 2, "Андреев" }, e3 = { 3, "Соколов" }, e4 = { 4, "Иванов" }, e5 = { 5, "Смирнов" }, e6 = { 6, "Васильев" }, e7 = { 7, "Петров" },
			e8 = { 8, "Соколов" }, e9 = { 9, "Федоров" };
		Dictionary::AddEntry(d1, e1);
		Dictionary::AddEntry(d1, e2);
		Dictionary::AddEntry(d1, e3);
		Dictionary::AddEntry(d1, e4);
		Dictionary::AddEntry(d1, e5);
		Dictionary::AddEntry(d1, e6);
		Dictionary::AddEntry(d1, e7);
		Dictionary::AddEntry(d1, e8);

		Dictionary::Instance d2 = Dictionary::Create((char*)"Преподаватели", 10);
		Dictionary::Entry t1 = { 1, "Орлов" }, t2 = { 2, "Андреев" }, t3 = { 3, "Соколов" }, t4 = { 4, "Иванов" }, t5 = { 5, "Смирнов" }, t6 = { 6, "Иванов" }, t7 = { 7, "Смирнов" };
		Dictionary::AddEntry(d2, t1);
		Dictionary::AddEntry(d2, t2);
		Dictionary::AddEntry(d2, t3);
		Dictionary::AddEntry(d2, t4);
		Dictionary::AddEntry(d2, t5);
		Dictionary::AddEntry(d2, t6);
		Dictionary::AddEntry(d2, t7);
		Dictionary::GetEntry(d1, 4);
		Dictionary::GetEntry(d2, 3);
		Dictionary::DelEntry(d1, 4);
		Dictionary::DelEntry(d2, 5);
		Dictionary::UpdateEntry(d1, 2, { 1, "Петров" });
		Dictionary::UpdateEntry(d2, 1, { 2, "Новиков" });
		std::cout << "-------- Преподавтели --------" << std::endl;
		Dictionary::Print(d2);
		std::cout << "-------- Студенты --------" << std::endl;
		Dictionary::Print(d1);
		Dictionary::Delete(d1);
		Dictionary::Delete(d2);
#endif
	}
	catch (char* e)
	{
		std::cout << e << std::endl;
	}
	system("pause");
	return 0;
}