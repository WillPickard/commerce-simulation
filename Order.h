#ifndef ORDER_H 
#define ORDER_H
#include <string>
#include <array>
#include "Product.h"
#include "Seller.h"

class Seller;

class Order{

public:
 Order();
 void removeItem(const std::string &sku);
 void addItem(Product *prod);
 double getTotal() const;
 void display() const;
 std::vector<Product *> getProductList();

private:
 std::vector<Product *> productList_;
};
#endif

