#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>


class Revieww;
class Sellerr;
class Productt;
class Customerr;

typedef std::vector<Revieww> ListOfRevieww;
typedef std::vector<Sellerr> ListOfSellerr;
typedef std::vector<Productt> ListOfProductt;
typedef std::vector<Customerr> ListOfCustomerr;
typedef std::vector<Productt> ListWithSortedPP;


class Customerr {
private:
	std::string CustomerName;
	std::string Password;
	std::string CustomerMail;

	ListOfProductt PurchasedProduct;

public:
	Customerr(std::string custname, std::string passw, std::string mail);
	Customerr(std::string custname);
	Customerr();

	std::string GetCustomerName();
	std::string GetCustomerPassword();
	std::string GetCustomerMail();
	ListOfProductt GetPurchProd();
	void OutputCustomerName();

};

class Sellerr {
private:
	std::string SellerName;
	std::string SellerMail;
	std::string Rating = "-";
	ListOfProductt ProdOnSale;
	std::string Password;
public:
	Sellerr(std::string sellname, std::string sellmail, std::string rating, ListOfProductt prodonsal, std::string passw);

	Sellerr(std::string sellname);

	Sellerr();

	std::string GetSellerName();
	std::string GetSellerMail();
	std::string GetRating();
	ListOfProductt GetProdOnSale();
	std::string GetPassword();
};

class Productt {
private:
	std::string ProdName;
	std::string Price;
	std::string Description;
	std::string ProductID;
	std::string Rating = "-";
	std::vector<Revieww> Reviews;
	Sellerr SellerMan;

public:
	Productt(std::string prodname, std::string price, std::string descript, std::string ProdID, std::string rating, std::vector<Revieww> Reviews, Sellerr SellerMan);
	Productt(std::string prodname, std::string price, std::string descript, std::string ProdID, Sellerr SellerMan);
	Productt(std::string prodname);
	Productt();

	std::string GetProdName();
	std::string GetPrice();
	Sellerr GetSeller();
	std::string GetDescript();
	std::vector<Revieww> GetReviews();
	std::string GetProdID();
	std::string GetRating();
};

class Revieww {
private:
	std::string TextOfR;
	std::string Grade;
	std::string ProdID;
	Customerr Customer;

public:
	Revieww(std::string TextOfR, std::string Grade, std::string ProdID, Customerr Customer);
	Revieww(std::string TextOfR);
	Revieww();

	std::string GetTextOfR();
	std::string GetGrade();
	std::string GetProdID();
	Customerr GetCustomer();
};

class ParamOfSearchh {
private:
	std::string MinPrice;
	std::string MaxPrice;
	std::string MinRating;
	bool WithReview;
public:
	ParamOfSearchh(std::string minPr, std::string maxPr, std::string minrating, bool withreview);
	ParamOfSearchh(std::string minPr);
	ParamOfSearchh();

	std::string GetMinPrice();
	std::string GetMaxPrice();
	std::string GetMinRating();
	bool GetWithReview();
};



Revieww MakeReview(Customerr Customer, std::string prodID);
void NewReview(ListOfRevieww* ReviewList, Customerr* Customer);
void AddReview(std::string ProdID, ListOfProductt* ProdList, Customerr* Customer);
bool LoginOnSite(ListOfCustomerr customers, Customerr* customer);
bool LoginOnSite(ListOfSellerr sellers, Sellerr* seller);

void CustomerRegistr(ListOfCustomerr* customers);

void MakeNewProduct(ListOfProductt* ProductList, Sellerr* seller);

ParamOfSearchh MakeNewParam();
void OutputProductInformation(Productt prod);