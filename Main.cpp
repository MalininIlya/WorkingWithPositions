#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int workingFile() {

	string choice;

	cout << "Нажмите 1 для добавление позиции" << endl;
	cout << "Нажмите 2 для вывода списка позиций" << endl;
	cout << "Нажмите 3 для удаление позиции" << endl;
	cout << "Нажмите 4 для поиска позиции" << endl;
	cout << "Нажмите 5 для выхода из программы" << endl << endl;

	cin >> choice;
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
		cout << "Выберите один из вариантов" << endl;
		workingFile();												// повторный вызов функции при некоретном значения
	}
}

int main() {

	setlocale(LC_ALL, "ru");
	
	fstream data;
	data.open("data.txt", fstream::in | fstream::out | fstream::app); // открытие файла с параметрами ввода, вывода данных, а также 
																	  // добавление в текущие данные, не затирая предыдущие

	if (!data.is_open())											
		cout << "Ошибка открытие файла!"<<endl;
	else {

		switch (workingFile())										  // функция workingFile() возвращается целочисленное значение
		{															  // для последующей обработке введенного значения 
		case 1:
			cout << "1" << endl;
			break;
		case 2:
			cout << "2" << endl;
			break;
		case 3:
			cout << "3" << endl;
			break;
		case 4:
			cout << "4" << endl;
			break;
		case 5:
			cout << "5" << endl;
			break;
		}
		
	}

}