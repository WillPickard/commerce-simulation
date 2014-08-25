//@file Retailer.cpp

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include "Retailer.h"
#include "Order.h"
#include "Seller.h"
#include "Buyer.h"
#include "Inventory.h"
#include "Product.h"

using namespace std;

Retailer::Retailer(const std::string &n, const std::string &i, double bal):
  Entity(n,i,bal)
{}

Retailer::~Retailer(){ std::cout << "Deleting " << getName() << std::endl; }

Retailer* Retailer::clone() const{
  return new Retailer(*this);
}

void Retailer::list(){
  Entity::list();
  Seller::list();
  Buyer::list();  
}

void Retailer::step(){
  Seller::step();
  Buyer::step();

}



