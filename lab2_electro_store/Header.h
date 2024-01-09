#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>


struct Review;
struct Seller;
struct Product;

typedef std::vector<Review> ListOfReview;
typedef std::vector<Seller> ListOfSeller;
typedef std::vector<Product> ListOfProduct;
typedef std::vector<Product> ProdWithRating;



struct Customer {
	std::string CustomerName;
	std::string CustomerID;
	std::vector<Product> PurchasedProduct;
	
};

struct Seller {
	std::string SellerName;
	std::string SellerMail;
	std::string Rating = "-";
	std::vector<Product> ProdOnSale;
};

struct Product {
	std::string ProdName;
	std::string Price;
	Seller SellerMan;
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

Review MakeReview(Customer Customer);
void NewReview(ListOfReview* ReviewList, Customer);
Product MakeProduct();
void NewProduct(ListOfProduct* ProductList);
void AddReview(std::string ProdID, ListOfProduct* ProdList, Customer* Customer);
Customer CustomerLogin();