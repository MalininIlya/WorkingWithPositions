#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int workingFile() {

	string choice;

	cout << "������� 1 ��� ���������� �������" << endl;
	cout << "������� 2 ��� ������ ������ �������" << endl;
	cout << "������� 3 ��� �������� �������" << endl;
	cout << "������� 4 ��� ������ �������" << endl;
	cout << "������� 5 ��� ������ �� ���������" << endl << endl;

	cin >> choice;
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
		cout << "�������� ���� �� ���������" << endl;
		workingFile();												// ��������� ����� ������� ��� ���������� ��������
	}
}

int main() {

	setlocale(LC_ALL, "ru");
	
	fstream data;
	data.open("data.txt", fstream::in | fstream::out | fstream::app); // �������� ����� � ����������� �����, ������ ������, � ����� 
																	  // ���������� � ������� ������, �� ������� ����������

	if (!data.is_open())											
		cout << "������ �������� �����!"<<endl;
	else {

		switch (workingFile())										  // ������� workingFile() ������������ ������������� ��������
		{															  // ��� ����������� ��������� ���������� �������� 
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