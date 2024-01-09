#include "Header.h"

bool IsItInt(std::string check) {
	for (size_t i = 0; i < check.size(); i++) {
		if (check[i] < '0' || check[i] > '9') {
			std::cout << "������! ������ ���� �����!";
			return false;
		}
	}
	return true;
}

bool IsIntCorrect(std::string check, int MaxInt) {
	if (IsItInt(check)) {
		if (stoi(check) > MaxInt) {
			std::cout << "\n�������� ��������! �������� �� ������ ��������� " << MaxInt;
			return false;
		}
		else if (stoi(check) < 0) {
			std::cout << "\n�������� ��������! �������� �� ������ ���� ������ 0!";
			return false;
		}
		return true;
	}
	else return false;
	
}

std::string GradeCorrecting(std::string grade) {
	std::string ourGrade;

	double dgrade = stod(grade);
	std::cout << dgrade;
	dgrade = round(dgrade * 100) / 100;
	ourGrade = std::to_string(dgrade);
	ourGrade = ourGrade.substr(0, 4);

	return ourGrade;
}

Review MakeReview(Customer Customer) {

	std::string Grade;
	std::string TextOfRev;
	Review NewRev;

	
	do {
		std::cout << "\n������� ���-�� ������ (�� 5-���������� �����): ";
		std::cin >> Grade;
	} while (!IsIntCorrect(Grade, 5));
	while (getchar() != '\n');
	std::cout << "\n��� �����: ";
	std::getline(std::cin, TextOfRev);
	
	NewRev.Customer = Customer;
	NewRev.Grade = Grade;
	NewRev.TextOfR = TextOfRev;

	return NewRev;
	
}

void NewReview(ListOfReview *ReviewList, Customer Customer) {
	(*ReviewList).push_back(MakeReview(Customer));
}

void AddReview(std::string ProdID, ListOfProduct* ProdList, Customer* Customer) {
	for (size_t i = 0; i != (*ProdList).size(); i++) {
		if ((*ProdList)[i].ProductID == ProdID) {
			(*ProdList)[i].Reviews.push_back(MakeReview(*Customer));
			int SumRate = 0;
			for (size_t k = 0; k != (*ProdList)[i].Reviews.size(); k++) {
				SumRate += stoi((*ProdList)[i].Reviews[k].Grade);

			}
			double Rate = SumRate / (*ProdList)[i].Reviews.size();
			(*ProdList)[i].Rating = GradeCorrecting(std::to_string(Rate));
			(*Customer).PurchasedProduct.push_back((*ProdList)[i]);
		}
	}
}

Product MakeProduct(){
	std::string NameOfProd;
	std::string Price;
	std::string ProdID;
	Product NewProd;

	std::getline(std::cin, NameOfProd);
	std::cin >> Price;
	std::cin >> ProdID;
	while (getchar() != '\n');

	NewProd.ProdName = NameOfProd;
	NewProd.Price = Price;
	NewProd.ProductID = ProdID;

	return NewProd;

}

void NewProduct(ListOfProduct *ProductList) {
	(*ProductList).push_back(MakeProduct());
}

Customer CustomerLogin() {
	Customer MrCustomer;
	std::cout << "������� �����: ";
	getline(std::cin, MrCustomer.CustomerName);

	return MrCustomer;
}

bool PasswordCheck(std::string FilePath) {
	std::ifstream file(FilePath);
}

Seller SellerLogin(std::string FilePath) {
	Seller MrSeller;
	std::string password;

	std::cout << "\n������� �����: ";
	getline(std::cin, MrSeller.SellerName);
	std::cout << "\n������� ������: ";
	getline(std::cin, password);
}