#include "Header.h"

Customerr::Customerr(std::string custname, std::string passw, std::string mail) {
	CustomerName = custname;
	Password = passw;
	CustomerMail = mail;
}

Customerr::Customerr(std::string custname) {
	CustomerName = custname;
	
}
Customerr::Customerr() {
	
}


std::string Customerr::GetCustomerName() {
	return CustomerName;
}

std::string Customerr::GetCustomerPassword() {
	return Password;
}

std::string Customerr::GetCustomerMail() {
	return CustomerMail;
}

ListOfProductt Customerr::GetPurchProd() {
	return PurchasedProduct;
}



Sellerr::Sellerr(std::string sellname, std::string sellmail, std::string rating, std::vector<Productt> prodonsal, std::string passw) {
	SellerName = sellname;
	SellerMail = sellmail;
	Rating = rating;
	ProdOnSale = prodonsal;
	Password = passw;

}

Sellerr::Sellerr(std::string sellname) {
	SellerName = sellname;
}

Sellerr::Sellerr() {
}

std::string Sellerr::GetSellerName() {
	return SellerName;
}

std::string Sellerr::GetSellerMail() {
	return SellerMail;
}

std::string Sellerr::GetRating() {
	return Rating;
}

std::vector<Productt> Sellerr::GetProdOnSale() {
	return ProdOnSale;
}

std::string Sellerr::GetPassword() {
	return Password;
}


Productt::Productt(std::string prodname, std::string price, std::string descript, std::string ProdID, std::string rating, std::vector<Revieww> review, Sellerr selMan) {
	ProdName = prodname;
	Price = price;
	Description = descript;
	ProductID = ProdID;
	Rating = rating;
	Reviews = review;
	SellerMan = selMan;
	
}

Productt::Productt(std::string prodname, std::string price, std::string descript, std::string ProdID, Sellerr selMan) {
	ProdName = prodname;
	Price = price;
	Description = descript;
	ProductID = ProdID;
	SellerMan = selMan;

}

Productt::Productt(std::string prodname) {
	ProdName = prodname;
}

Productt::Productt() {

}

std::string Productt::GetProdName() {
	return ProdName;
}

std::string Productt::GetPrice() {
	return Price;
}

std::string Productt::GetDescript() {
	return Description;
}

std::string Productt::GetProdID() {
	return ProductID;
}

std::string Productt::GetRating() {
	return Rating;
}

Sellerr Productt::GetSeller() {
	return SellerMan;
}

std::vector<Revieww> Productt::GetReviews() {
	return Reviews;
}


Revieww::Revieww(std::string textOfRev, std::string grade, std::string productID, Customerr customer) {
	TextOfR = textOfRev;
	Grade = grade;
	ProdID = productID;
	Customer = customer;
}
Revieww::Revieww(std::string textOfRev) {
	TextOfR = textOfRev;
}
Revieww::Revieww() {

}

std::string Revieww::GetTextOfR() {
	return TextOfR;
}
std::string Revieww::GetGrade() {
	return Grade;
}
std::string Revieww::GetProdID() {
	return ProdID;
}
Customerr Revieww::GetCustomer() {
	return Customer;
}


ParamOfSearchh::ParamOfSearchh(std::string minPr, std::string maxPr, std::string minrating, bool withreview) {
	MinPrice = minPr;
	MaxPrice = maxPr;
	MinRating = minrating;
	WithReview = withreview;
}

ParamOfSearchh::ParamOfSearchh(std::string minPr) {
	MinPrice = minPr;
}

ParamOfSearchh::ParamOfSearchh() {
}

std::string ParamOfSearchh::GetMaxPrice() {
	return MaxPrice;
}
std::string ParamOfSearchh::GetMinPrice() {
	return MinPrice;
}
std::string ParamOfSearchh::GetMinRating() {
	return MinRating;
}
bool ParamOfSearchh::GetWithReview() {
	return WithReview;
}

bool IsItInt(std::string check) {
	for (size_t i = 0; i < check.size(); i++) {
		if (check[i] < '0' || check[i] > '9') {
			std::cout << "Ошибка! Должно быть число!";
			return false;
		}
	}
	return true;
}

bool IsIntCorrect(std::string check, int MaxInt) {
	if (IsItInt(check)) {
		if (stoi(check) > MaxInt) {
			std::cout << "\nНеверное значение! Значение не должно превышать " << MaxInt;
			return false;
		}
		else if (stoi(check) < 0) {
			std::cout << "\nНеверное значение! Значение не должно быть меньше 0!";
			return false;
		}
		return true;
	}
	else return false;
	
}

void InputLogin(std::string* login) {
	std::cout << "Введите логин: ";
	std::cin >> *login;
}

void InputPassword(std::string* password) {
	std::cout << "Введите пароль:  ";
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

Revieww MakeReview(Customerr Customer, std::string prodID) {

	std::string Grade;
	std::string TextOfRev;

	
	do {
		std::cout << "\nВаша оценка (по 5-тибалльной шкале): ";
		std::cin >> Grade;
	} while (!IsIntCorrect(Grade, 5));
	while (getchar() != '\n');
	std::cout << "\nВаш отзыв: ";
	std::getline(std::cin, TextOfRev);

	return Revieww(TextOfRev, Grade, prodID ,Customer);
	
}

void NewReview(ListOfRevieww *ReviewList, Customerr* Customer, std::string prodID) {
	(*ReviewList).push_back(MakeReview(*Customer, prodID));
}

void AddReview(std::string ProdID, ListOfProductt* ProdList, Customerr* Customer) { //добавление отзыва на товар
	for (size_t i = 0; i != (*ProdList).size(); i++) {
		if ((*ProdList)[i].GetProdID() == ProdID) {
			(*ProdList)[i].GetReviews().push_back(MakeReview(*Customer, (*ProdList)[i].GetProdID()));
			int SumRate = 0;
			for (size_t k = 0; k != (*ProdList)[i].GetReviews().size(); k++) {
				SumRate += stoi((*ProdList)[i].GetReviews()[k].GetGrade());

			}
			double Rate = SumRate / (*ProdList)[i].GetReviews().size();
			(*ProdList)[i].GetRating() = GradeCorrecting(std::to_string(Rate));
			(*Customer).GetPurchProd().push_back((*ProdList)[i]);
		}
	}
}





void MakeNewProduct(ListOfProductt *ProductList, Sellerr* seller) { //создание нового продукта
	std::string NameOfProd;
	std::string Price;
	std::string ProdID;
	std::string Descript;

	std::cout << "Введите название товара: ";
	std::cin >> NameOfProd;
	std::cout << "Введите ID товара: ";
	std::cin >> ProdID;
	std::cout << "Введите описание товара: ";
	std::getline(std::cin, Descript);
	do {
		std::cout << "Введите цену: ";
		std::cin >> Price;
	} while (!IsItInt(Price));
	
	ProductList->push_back(Productt(NameOfProd, Price,Descript, ProdID, *seller));
	seller->GetProdOnSale().push_back(Productt(NameOfProd, Price, Descript, ProdID, *seller));
}

void OutputProductInformation(Productt prod) {
	std::cout << "---- Информация о товаре ----\n\n";
	std::cout << prod.GetProdName() << "\n";
	std::cout << "Цена " << prod.GetPrice() << "\n";
	std::cout << "Оценка: " << prod.GetRating() << " / 5.0\n";
	std::cout << "Описание:\n" << prod.GetDescript() << "\n";
	std::cout << "Продавец: " << prod.GetSeller().GetSellerName();
}

void Customerr::OutputCustomerName() {
	std::cout << CustomerName;
}

void CustomerRegistr(ListOfCustomerr* customers) {  //функция для создания нового аккаунта для покупателя
	std::string name;
	std::string password;
	std::string mail;
	std::cout << "---- Регистрация покупателя ----\n\n";
	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << "Введите адрес электронной почты: ";
	std::cin >> mail;
	std::cout << "Введите пароль: ";
	std::cin >> password;

	bool IsExist = false;

	for (int i = 0; i < (*customers).size(); i++) {
		if ((*customers)[i].GetCustomerName() == name || (*customers)[i].GetCustomerMail() == mail) IsExist = true;
	}
	if (IsExist == false) {
		customers->push_back(Customerr(name, password, mail));
	}
	else {
		std::cout << "Аккаунт с таким именем или почтой уже существует!";
	}

}

bool LoginOnSite(ListOfCustomerr customers, Customerr* customer) { //функция входа для покупателя
	std::cout << "------ Вход на сайт (если вы покупатель)------\n";
	std::string login;
	std::string password;
	InputLogin(&login);
	InputPassword(&password);
	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].GetCustomerName() == login && customers[i].GetCustomerPassword() == password) {
			*customer = customers[i];
			return true;
		}
	}
	std::cout << "Неверный логин или пароль!\n";
	return false;
	
}
bool LoginOnSite(ListOfSellerr sellers, Sellerr* seller) { //перегрузка функции входа для продавца
	std::cout << "------ Вход на сайт (если вы продавец)------\n";
	std::string login;
	std::string password;
	InputLogin(&login);
	InputPassword(&password);
	for (int i = 0; i < sellers.size(); i++) {
		if (sellers[i].GetSellerName() == login && sellers[i].GetPassword() == password) {
			*seller = sellers[i];
			return true;
		}
	}
	std::cout << "Неверный логин или пароль!\n";
	return false;
}


ParamOfSearchh MakeNewParam() {
	std::string MinPrice, MaxPrice, MinRating;
	bool WithReview;
	int check;
	do {
		std::cout << "Введите МИНИМАЛЬНУЮ цену товара: ";
		std::cin >> MinPrice;
	} while (!IsItInt(MinPrice));
	do {
		std::cout << "Введите МАКСИМАЛЬНУЮ цену товара: ";
		std::cin >> MaxPrice;
	} while (!IsItInt(MaxPrice));
	
	std::cout << "Обязательно ли у товара наличие хотя бы дного отзыва?\n1 - ДА\n0 - НЕТ\n";
	std::cin >> check;
	if (check == 1) {
		do {
			std::cout << "Введите МИНИМАЛЬНЫЙ рейтинг товара: ";
			std::cin >> MinRating;
		} while (!IsItInt(MinRating));
		WithReview = true;
	}
	else {
		WithReview = false;
	}
	return (ParamOfSearchh(MinPrice, MaxPrice, MinRating, WithReview));
}

ListWithSortedPP SearchProduct(ListOfProductt products, ParamOfSearchh params) {
	int countOfС = 3;
	int curCount = 0;
	ListWithSortedPP sortedlist;
	for (int i = 0; i < products.size(); i++) {
		if (stoi(products[i].GetPrice()) >= stoi(params.GetMinPrice())) curCount++;
		if (stoi(products[i].GetPrice()) <= stoi(params.GetMaxPrice())) curCount++;
		if (products[i].GetReviews().size() == 0 && params.GetWithReview() == false) {
			curCount++;
		}
		if (products[i].GetReviews().size() > 0 && params.GetWithReview() == true) {
			curCount++;
		}
		if (curCount == countOfС) sortedlist.push_back(products[i]);
	}
	return sortedlist;
}