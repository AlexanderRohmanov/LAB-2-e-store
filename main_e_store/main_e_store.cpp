#include <iostream>
#include <Windows.h>
#include "..\lab2_electro_store\Header.h";

void Dynamic() { //������ � ������������  ����������
	Product* productONE = new Product;
	Product productTWO = NewProduct("NVIDIA GTX 1650", "20000", "100", "�������� �� ���� ��������� ���������.");

	*productONE = productTWO;

	std::cout << productONE->ProdName;
	delete productONE;
}

int main() {
	
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	std::cout << "������ � �����.\n\n";
	Dynamic();
	std::cout << "\n\n\n������  �� ����.\n";

	ListOfReview ReviewList;
	ListOfSeller SellerList;
	ListOfProduct ProductList;
	ListOfCustomer CustomersList;

	CustomersList.push_back(NewCustomer("Alex", "12345", "sasha@mail.ru"));
	std::cout << CustomersList[0].CustomerName << "\n";
	CustomerRegistr(&CustomersList);

	std::cout << CustomersList[1].CustomerName;

	

	
}