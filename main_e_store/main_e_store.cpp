#include <iostream>
#include <Windows.h>
#include "..\lab2_electro_store\Header.h";


void DynamicArray() {
	Customerr* customers = new Customerr[3]{ Customerr("Александр", "123321", "sasha@mail.ru"), Customerr("Николай", "9999", "nikolay@mail.ru"), Customerr("Пётр", "2023", "peter@mail.ru") };

	for (int i = 0; i < 3; i++) {
		std::cout << i + 1 << ". ";
		customers[i].OutputCustomerName();
		std::cout << "\n";
	}

	delete[] customers;


}

void DynamicObjectsArray() {
	Customerr* custONE = new Customerr("Александр", "123321", "sasha@mail.ru");
	Customerr* custTWO = new Customerr("Николай", "9999", "nikolay@mail.ru");
	Customerr* custTHREE = new Customerr("Пётр", "2023", "peter@mail.ru");
	
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

	Productt prodONE = Productt("RTX 3060", "10000", "Отличная видеокарта...");
	Productt prodTWO = Productt("RTX 3060 ti", "15000", "Отличная видеокарта...");

	Productt prodTHREE = prodONE + prodTWO;
	std::cout << "Цена prodTHREE: " << prodTHREE.GetPrice();
}