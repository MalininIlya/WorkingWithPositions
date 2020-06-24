#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <Windows.h>

using namespace std;

class Element {

public:
	Element(const string &data) {
		this->data = data;												// ��������� ������ ������ � ������ ������ 
	}

	friend ostream& operator<< (ostream &os, const Element& element) {  // ���������� ��������� ��� ������ ������ �� ������� 
		os << element.data;
		return os;
	}

private:
	string data;
};

int workingFile() {

	string choice;

	cout << "������� 1 ��� ���������� �������" << endl;
	cout << "������� 2 ��� ������ ������ �������" << endl;
	cout << "������� 3 ��� �������� �������" << endl;
	cout << "������� 4 ��� ���������� ������ �������" << endl;
	cout << "������� 5 ��� ������ �� ��������� � ����������� ������" << endl << endl;

	getline(cin,choice);
	cout << endl;

	if (choice == "1")												 // �������� ���������� �������� �� ������������
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
		cout << "�������� ���� �� ���������" << endl << endl;
		return 0;
	}
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fstream file;
	file.open("data.txt", fstream::in | fstream::out | fstream::app); // �������� ����� � ����������� �����, ������ ������, � ����� 
																	  // ���������� � ������� ������, �� ������� ����������

	if (!file.is_open())											
		cout << "������ �������� �����!"<<endl;
	else {

		string data;
		list<Element> positions;									 // �������� ���������� ��� ������ � ������ ��������� �������� �����
		string getData;

		while (!file.eof()) {										 // ���� ����� �������� ���� �� ������ ����� ������������ �����

			getline(file, getData);
		
			if (getData == "")										 // ���� ���� ������ ������, �� ������� ��������� ������ ��� ��
				continue;

			positions.push_back(getData);
		}

		int esc = 0;

		while (!(esc == 5)) {									      // ���� ������������ �� ������� ������� "5", ��������� ��������

			switch (workingFile())									  // ������� workingFile() ������������ ������������� ��������
			{														  // ��� ����������� ��������� ���������� �������� 
			case 1:
				cout << "������� ������" << endl;
				getline(cin, data);

				file << data + "\n";								  // ���������� ������ � ���� ����� ��������� ����� ������ �� ���������
				positions.push_back(data);

				cout << "������ ���������" << endl << endl;
				break;

			case 2:
				for (auto elem : positions) 				          // ����� ���� ��������� ���������� �� ������ ������				
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