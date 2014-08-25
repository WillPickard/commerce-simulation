#include <string>
#include <array>
#include <iostream>
#include "Product.h"
#include "Seller.h"
#include "Order.h"
using namespace std;

 Order::Order(){};

 void Order::addItem(Product *prod){
	productList_.push_back(prod);
 };

 void Order::removeItem(const std::string &sku){};

 double Order::getTotal() const{
 Product *p;
 double total = 0.0;
 for (auto it = productList_.cbegin(); it != productList_.cend(); ++it){ 
	p = *it;
	total += p->getQuantity() * p->getPrice();
 }
 return total;
 };


 void Order::display() const{
 Product *p;
 cout << "Order contains: " << endl;
 for (auto it = productList_.cbegin(); it != productList_.cend(); ++it){ 
	p = *it;
	cout << p->listItem() << endl;
 }

 };

 std::vector<Product *> Order::getProductList(){
	return productList_;
 };
	





