#include <iostream>
#include <Windows.h>
#include "..\lab2_electro_store\Header.h";


int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ListOfReview ReviewList;
	ListOfSeller SellerList;
	ListOfProduct ProductList;
	
	Customer MrCustomer = CustomerLogin();

	
	NewProduct(&ProductList);
	

	for (int i = 0; i < ProductList.size(); i++) {
		std::cout << ProductList[i].ProdName << "  |   ID: " << ProductList[i].ProductID << "\n";
	}
	std::string ID;
	std::cin >> ID;
	while (getchar() != '\n');
	AddReview(ID, &ProductList, &MrCustomer);
	Seller NewSel = { "МистерКрабс", "mrcrabs@gmail.com" };
	SellerList.push_back(NewSel);
	std::cout << "\n" << ProductList[0].Reviews[0].TextOfR;
	std::cout << " - " <<ProductList[0].Rating;

	std::cout << MrCustomer.PurchasedProduct[0].ProdName;
}