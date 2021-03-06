﻿#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <Windows.h>

using namespace std;

class Element {

public:
	Element(const string &data) {
		this -> data = data;												// введенные данные вносим в объект класса
		
	}

	friend ostream& operator<< (ostream &os, const Element &element) {  // перегрузка оператора для вывода данных на консоль 
		os << element.data;
		return os;
	}

	friend bool operator== (Element& element, const string& data) {  // перегрузка оператора для сравнение объекта класса и вводимых данных 
		if(element.data == data)
		return true;
	}

private:
	string data;
};

list<Element>& reading(list<Element>& positions, int &esc){

	fstream fileRead;

	fileRead.open("data.txt", fstream::in);							  //считывание предыдущих данных
	if (!fileRead.is_open()) {
		cout << "Ошибка открытие файла!" << endl;
		esc = 5;
	}
	else {
		string getData;

		while (!fileRead.eof()) {										  // цикл будет работать пока не найдет конец считываемого файла
			getline(fileRead, getData);

			if (getData == "")									      // если есть пустая строка, не создает отдельный объект под неё
				continue;

			positions.push_back(getData);
		}
	}
	fileRead.close();
	return positions;
}

int choiceUser() {

	string choice;

	cout << "Нажмите 1 для добавление позиции" << endl;
	cout << "Нажмите 2 для вывода списка позиций" << endl;
	cout << "Нажмите 3 для удаление позиции" << endl;
	cout << "Нажмите 4 для текстового поиска позиции" << endl;
	cout << "Нажмите 5 для выхода из программы" << endl << endl;

	getline(cin, choice);
	cout << endl;

	if (choice == "1")												 // проверка введенного значения на корректность
		return 1;	
	else if (choice == "2")
		return 2;
	else if (choice == "3")
		return 3;
	else if (choice == "4")
		return 4;
	else if (choice == "5")
		return 5;
	else{
		cout << "Выберите один из вариантов" << endl << endl;
		return 0;
	}
}

void workingFile(list<Element>& positions, int &esc) {

	fstream file;

	string data;
	bool point = false;                                        // переменая для проверки элемента в списке
	int index = 1;                                             

	while (!(esc == 5)) {									      // пока пользователь не выберет вариант "5", программа работает

	switch (choiceUser())									  // функция choiceUser() возвращается целочисленное значение
	{														  // для последующей обработки введенного значения 
	case 1:

		cout << "Введите данные" << endl;
		getline(cin, data);

		file.open("data.txt", fstream::out | fstream::app);			// открытие файла с параметрами ввода и
																	 // добавление в текущие данные, не затирая предыдущие
			file << data + "\n";									//запись данных в файл
			positions.push_back(data);								// добавление нового объекта в list
			file.close();
			cout << "Данные добавлены" << endl << endl;
		break;

	case 2:
		cout << "Список позиций" << endl;
		for (auto elem : positions)			          // вывод всех элементов контейнера на данный момент				
			cout << index++ <<". "<< elem << endl;

		cout << endl;
		index = 1;
		break;

	case 3:
		cout << "Напишите элемент или его номер для удаления" << endl;
		getline(cin, data);

		file.open("data.txt", fstream::out);

		for (auto it = positions.begin(); it != positions.end(); it++) {

			string strIndex = to_string(index);										// преобразование int в string 
			pair<string, Element> pos(strIndex, *it);                               // создание контейнера с преобразованной строкой и элементом коллекции
			
			if ((*it) == data || pos.first == data) {                   // проверка преобразованной строки со строкой, введенной пользователем или с данными из коллекции

				positions.erase(it);
				cout << "Элемент " << data << " удален" << endl << endl;

				break;
			}
			else if (it == (--(positions.end())) && point == false) {  // Если it == последнему элементу list и до этого не нашли необходимый элемент
				cout << "Элемент " << data << " не найден в списке" << endl << endl;
			}
			index++;                                                  // увеличение index для проверки следующего элемента в коллекции
		}

		for (auto elem : positions)                          // после удаления записываем новые данные в файл
			file << elem << endl;

		file.close();
		index = 1;                                                   // после выполнения возвращаем index в начальное состояние
		point = false;
		break;

	case 4:
		cout << "Напишите элемент для поиска" << endl;   // поиск по полному тексту позиции
		getline(cin, data);

		for (auto it = positions.begin(); it != positions.end(); it++) {

			if ((*it) == data) {
				cout << "Элемент " << data << " найден в списке" << endl << endl;
				point = true;
			}
			else if (it == (--(positions.end())) && point == false) {  // Если it == последнему элементу list и до этого не нашли необходимый элемент
				cout << "Элемент " << data << " не найден в списке" << endl << endl;
			}
		}
		point = false;
		break;

	case 5:
		esc = 5;
		break;
		}
	}
}


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int esc = 0;
	list<Element> positions;
	reading(positions, esc);
	workingFile(positions, esc);

	return 0;
}