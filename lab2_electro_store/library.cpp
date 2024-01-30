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

void InputLogin(std::string* login) {
	std::cout << "������� �����: ";
	std::cin >> *login;
}

void InputPassword(std::string* password) {
	std::cout << "������� ������:  ";
	std::cin >>*password;
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
		std::cout << "\n���� ������ (�� 5-���������� �����): ";
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

void NewReview(ListOfReview *ReviewList, Customer* Customer) {
	(*ReviewList).push_back(MakeReview(*Customer));
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



Product NewProduct(std::string NameOfProd, std::string Price, std::string ProdID, std::string Descript) {
	Product nProduct;
	nProduct.ProdName = NameOfProd;
	nProduct.Price = Price;
	nProduct.ProductID = ProdID;
	nProduct.Description = Descript;

	return nProduct;
}

void MakeNewProduct(ListOfProduct *ProductList, Seller* seller) {
	std::string NameOfProd;
	std::string Price;
	std::string ProdID;
	std::string Descript;

	std::cout << "������� �������� ������: ";
	std::cin >> NameOfProd;
	std::cout << "������� ID ������: ";
	std::cin >> ProdID;
	std::cout << "������� �������� ������: ";
	std::getline(std::cin, Descript);
	do {
		std::cout << "������� ����: ";
		std::cin >> Price;
	} while (!IsItInt(Price));
	Product nProduct = NewProduct(NameOfProd, Price, ProdID);
	(*ProductList).push_back(nProduct);
	seller->ProdOnSale.push_back(nProduct);
}

Customer NewCustomer(std::string name, std::string password, std::string mail) {
	Customer nCustomer;
	nCustomer.CustomerName = name;
	nCustomer.Password = password;
	nCustomer.CustomerMail = mail;
	return nCustomer;
}
void CustomerRegistr(ListOfCustomer* customers) {
	std::string name;
	std::string password;
	std::string mail;

	std::cout << "������� ���: ";
	std::cin >> name;
	std::cout << "������� ����� ����������� �����: ";
	std::cin >> mail;
	std::cout << "������� ������: ";
	std::cin >> password;

	bool IsExist = false;

	for (int i = 0; i < (*customers).size(); i++) {
		if ((*customers)[i].CustomerName == name || (*customers)[i].CustomerMail == mail) IsExist = true;
	}
	if (IsExist == false) {
		(*customers).push_back(NewCustomer(name, password, mail));
	}
	else {
		std::cout << "������� � ����� ������ ��� ������ ��� ����������!";
	}

}

bool LoginOnSite(ListOfCustomer customers, Customer* customer) { //������� ����� ��� ����������
	std::string login;
	std::string password;
	InputLogin(&login);
	InputPassword(&password);
	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].CustomerName == login && customers[i].Password == password) {
			*customer = customers[i];
			return true;
		}
	}
	std::cout << "�������� ����� ��� ������!\n";
	return false;
	
}
bool LoginOnSite(ListOfSeller sellers, Seller* seller) { //���������� ������� ����� ��� ��������
	std::string login;
	std::string password;
	InputLogin(&login);
	InputPassword(&password);
	for (int i = 0; i < sellers.size(); i++) {
		if (sellers[i].SellerName == login && sellers[i].Password == password) {
			*seller = sellers[i];
			return true;
		}
	}
	std::cout << "�������� ����� ��� ������!\n";
	return false;
}

ParamForSearch NewParam(std::string MinPrice, std::string MaxPrice, std::string MinRating, bool WithReview) {
	ParamForSearch nParam;

	nParam.MinPrice = MinPrice;
	nParam.MaxPrice = MaxPrice;
	nParam.MinRating = MinRating;
	nParam.WithReview = WithReview;

	return nParam;
}

ParamForSearch MakeNewParam() {
	std::string MinPrice, MaxPrice, MinRating;
	bool WithReview;
	int check;
	do {
		std::cout << "������� ����������� ���� ������: ";
		std::cin >> MinPrice;
	} while (!IsItInt(MinPrice));
	do {
		std::cout << "������� ������������ ���� ������: ";
		std::cin >> MaxPrice;
	} while (!IsItInt(MaxPrice));
	
	
	if (check == 1) {
		do {
			std::cout << "������� ����������� ������� ������: ";
			std::cin >> MinRating;
		} while (!IsItInt(MinRating));
		WithReview = true;
	}
	else {
		WithReview = false;
	}
	return (NewParam(MinPrice, MaxPrice, MinRating, WithReview));
}

ListWithSortedP SearchProduct(ListOfProduct products, ParamForSearch params) {
	int countOf� = 3;
	int curCount = 0;
	ListWithSortedP sortedlist;
	for (int i = 0; i < products.size(); i++) {
		if (stoi(products[i].Price) >= stoi(params.MinPrice)) curCount++;
		if (stoi(products[i].Price) <= stoi(params.MaxPrice)) curCount++;
		if (products[i].Reviews.size() == 0 && params.WithReview == false) {
			curCount++;
		}
		if (products[i].Reviews.size() > 0 && params.WithReview == true) {
			curCount++;
		}
		if (curCount == countOf�) sortedlist.push_back(products[i]);
	}
}