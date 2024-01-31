#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>


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
void NewReview(ListOfReview* ReviewList, Customer);
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