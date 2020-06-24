#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

class Element {

public:
	Element(const string &data) {
		this->data = data;												// введенные данные вносим в объект класса 
	}

	friend ostream& operator<< (ostream &os, const Element& element) {  // перегрузка оператора для вывода данных на консоль 
		os << element.data;
		return os;
	}

private:
	string data;
};


int workingFile() {

	string choice;

	cout << "Нажмите 1 для добавление позиции" << endl;
	cout << "Нажмите 2 для вывода списка позиций" << endl;
	cout << "Нажмите 3 для удаление позиции" << endl;
	cout << "Нажмите 4 для текстового поиска позиции" << endl;
	cout << "Нажмите 5 для выхода из программы с сохранением данных" << endl << endl;

	cin >> choice;

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

int main() {

	setlocale(LC_ALL, "Russian");

	fstream file;
	file.open("data.txt", fstream::in | fstream::out | fstream::app); // открытие файла с параметрами ввода, вывода данных, а также 
																	  // добавление в текущие данные, не затирая предыдущие

	if (!file.is_open())											
		cout << "Ошибка открытие файла!"<<endl;
	else {

		list<Element> positions;										  // создание контейнера для данных в случае успешного открытия файла
		string data;
		int esc = 0;

		while (!(esc == 5)) {									      // пока пользователь не выберет вариант "5", программа работает

			switch (workingFile())									  // функция workingFile() возвращается целочисленное значение
			{														  // для последующей обработки введенного значения 
			case 1:
				cout << "Введите данные" << endl;
				cin >> data;
				file << data + "\n";								  // сохранение данных в файл будет выполнено после выхода из программы
				positions.push_back(data);
				cout << "Данные добавлены" << endl << endl;
				break;

			case 2:
				cout << endl;
				for (auto elem : positions) 				          // вывод всех елементов контейнера на данный момент				
					cout << elem << endl;
				cout << endl;
				break;

			case 3:
				cout << "3" << endl;
				break;

			case 4:
				cout << "4" << endl;
				break;

			case 5:
				esc = 5;
				break;
			}
		}
	}

	file.close();

	return 0;
}