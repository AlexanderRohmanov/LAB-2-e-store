#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>



class Revieww;
class Sellerr;
class Productt;
class CustomerCL;

typedef std::vector<Revieww> ListOfRevieww;
typedef std::vector<Sellerr> ListOfSellerr;
//typedef std::vector<Productt> ListOfProductt;
typedef std::vector<CustomerCL> ListOfCustomerr;
typedef std::vector<Productt> ListWithSortedPP;

class CustomerCL {
private:
	std::string CustomerName;
	std::string Password;
	std::string CustomerMail;
	std::vector<Productt> _PurchasedProduct;

public:
	CustomerCL(std::string custname, std::string passw, std::string mail);

	CustomerCL(std::string custname);

	CustomerCL();

	std::string GetCustomerName();
	std::string GetCustomerPassword();
	std::string GetCustomerMail();
	//ListOfProductt GetPurchasedProduct();

};

//class Sellerr {
//private:
//	std::string SellerName;
//	std::string SellerMail;
//	std::string Rating = "-";
//	ListOfProductt ProdOnSale;
//	std::string Password;
//public:
//	Sellerr(std::string sellname, std::string sellmail, std::string rating, ListOfProductt prodonsal, std::string passw);
//
//	Sellerr(std::string sellname);
//
//	Sellerr();
//
//	std::string GetSellerName();
//	std::string GetSellerMail();
//	std::string GetRating();
//	ListOfProductt GetProdOnSale();
//	std::string GetPassword();
//};



///

struct Review;
struct Seller;
struct Product;
struct Customer;

typedef std::vector<Review> ListOfReview;
typedef std::vector<Seller> ListOfSeller;
typedef std::vector<Product> ListOfProduct;
typedef std::vector<Customer> ListOfCustomer;
typedef std::vector<Product> ListWithSortedP;


struct Customer {
	std::string CustomerName;
	std::vector<Product> PurchasedProduct;
	std::string Password;
	std::string CustomerMail;
	
};

struct Seller {
	std::string SellerName;
	std::string SellerMail;
	std::string Rating = "-";
	std::vector<Product> ProdOnSale;
	std::string Password;
};

struct Product {
	std::string ProdName;
	std::string Price;
	Seller SellerMan;
	std::string Description;
	std::vector<Review> Reviews;
	std::string ProductID;
	std::string Rating;
};

struct Review {
	Customer Customer;
	std::string TextOfR;
	std::string Grade;
	std::string ProdID;
};

struct ParamForSearch {
	std::string MinPrice;
	std::string MaxPrice;
	std::string MinRating;
	bool WithReview;
};

Review MakeReview(Customer Customer);
void NewReview(ListOfReview* ReviewList, Customer* Customer);
void AddReview(std::string ProdID, ListOfProduct* ProdList, Customer* Customer);
bool LoginOnSite(ListOfCustomer customers, Customer* customer);
bool LoginOnSite(ListOfSeller sellers, Seller* seller);
Customer NewCustomer(std::string name, std::string password, std::string mail);
void CustomerRegistr(ListOfCustomer* customers);
Product NewProduct(std::string NameOfProd, std::string Price, std::string ProdID, std::string Descript);
void MakeNewProduct(ListOfProduct* ProductList, Seller* seller);
ParamForSearch NewParam(std::string MinPrice, std::string MaxPrice, std::string MinRating, bool WithReview);
ParamForSearch MakeNewParam();
void OutputProductInformation(Product prod);