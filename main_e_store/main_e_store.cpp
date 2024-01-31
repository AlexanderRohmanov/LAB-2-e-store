#include <iostream>
#include <Windows.h>
#include "..\lab2_electro_store\Header.h";


void DynamicArray() {
	Customerr* customers = new Customerr[3]{ Customerr("���������", "123321", "sasha@mail.ru"), Customerr("�������", "9999", "nikolay@mail.ru"), Customerr("ϸ��", "2023", "peter@mail.ru") };

	for (int i = 0; i < 3; i++) {
		std::cout << i + 1 << ". ";
		customers[i].OutputCustomerName();
		std::cout << "\n";
	}

	delete[] customers;


}

void DynamicObjectsArray() {
	Customerr* custONE = new Customerr("���������", "123321", "sasha@mail.ru");
	Customerr* custTWO = new Customerr("�������", "9999", "nikolay@mail.ru");
	Customerr* custTHREE = new Customerr("ϸ��", "2023", "peter@mail.ru");
	
	Customerr CustomersList[3] = { *custONE, *custTWO, *custTHREE };
	
	int count = 0;
	for (Customerr customer : CustomersList) {
		count += 1;
		std::cout << count << ". ";
		customer.OutputCustomerName();
		std::cout << "\n";
	}


}


int main() {
	
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "������������ ������ � ���������:\n";
	DynamicArray();

	std::cout << "\n";

	std::cout << "������  � ������������� ���������:\n";
	DynamicObjectsArray();
}