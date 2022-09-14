﻿// Лабораторная работа №6. Вариант 3

#include <iostream>
#include <string.h>     // Библиотека для работы со строками.
#include <windows.h>    // Библиотека для русской локализации

void Print(char* text)		// Передаем динамический массив, т.к мы не знаем конкретно сколько слов ввел пользователь
{
	char* begin = text;     // Начало текущего слова, кладем в динамический массив, т.к. не знаем сколько букв в слове
	int letter = 0;         // Счетчик гласных
	char vowels[] = { 'а', 'е', 'ё', 'и', 'о', 'у', 'ы', 'э', 'ю', 'я' }; // Все гласные буквы

	while (true) 
	{
		//текущий символ - гласная
		for (int i = 0; i < 10; i++)
		{
			if (*text == vowels[i]) // Проверяю каждую букву на массив гласных
			{
				letter++;			// Ловим гласные, если поймали счетчик увеличился 
				text++;				// Переход к следующему символу
			}
		}

		if (*text == ' ' || *text == '\0')	// Текущий символ - конец слова
		{
			if (letter == 0)				// Проверяем Если в слове нет гласных букв, то выводим
			{
				while (begin < text)		// Вывод слова в консоль
				{
					std::cout << *begin;
					begin++;
				}
				std::cout << std::endl;    // Заканчиваем строку
			}
			if (*text == '\0')			// Если конец строки - завершить поиcк
			{
				break;					// Выходим из цикла while
			}
			else Print(++text);			// Переходим к СЛУДЮЩЕМУ слову пропуская пробел инкрементно букве Рекурсивно
			
			return;						// Выходим из функции
		}

		text++;							// Переход к следующему символу
	}
}

int main()
{
	SetConsoleCP(1251);         // Ввод с консоли в кодировке 1251 для русской локализации.
	SetConsoleOutputCP(1251);   // Вывод на консоль в кодировке 1251 для русской локализации.

	char text[255];				// Массив символов = строки.

	std::cout << "Вводите текст: \n";

	gets_s(text, 255);			// Считываем текст и добавляем в массив

	Print(text);				// Отправляем массив к функции
}
