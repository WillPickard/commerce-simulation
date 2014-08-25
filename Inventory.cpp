#include <iostream>
#include <set>
#include <stdexcept>
#include "Inventory.h"
using namespace std;

 void Inventory::addProduct(Product *p){
 inventory_.insert(p); 
 };	

std::set<Product *> Inventory::getInventory() const{
  return inventory_;
}
 // Add a product from inventory
 void Inventory::removeProduct(Product *p){
  std::set<Product *>:: iterator it;
  it = inventory_.find(p); 
  inventory_.erase(it);
 };	

 Product * Inventory::getProductBySku(const std::string & sku){
  std::set<Product *>:: iterator it;
  std::set<Product *>:: iterator found_it;
  Product *p;
  for (it=inventory_.begin(); it!=inventory_.end(); it++){
    p = *it;
    if (p->getSKU() == sku) {
	return *it;
    }
  }
  throw invalid_argument( "SKU not found" );
 }

 void Inventory::showInventory() const {
  std::set<Product *>:: iterator it;
  Product *p;

  for (it=inventory_.begin(); it!=inventory_.end(); ++it){
    p = *it;
    cout << p->listItem() << endl;
  }
 }


 // Find product by Description
 Product * Inventory::getProductByDescription(const std::string & description){
  std::set<Product *>:: iterator it;
  std::set<Product *>:: iterator found_it;
  Product *p;

  for (it=inventory_.begin(); it!=inventory_.end(); ++it){
    p = *it;
    if (p->getDescription() == description)
	return *it;
  };

  throw invalid_argument( "SKU not found" );
 };

 
 double Inventory::getValue(){
  std::set<Product *>:: iterator it;
  Product *p;
  double balance = 0.0;

  for (it=inventory_.begin(); it!=inventory_.end(); ++it){
    p = *it;
    balance += (p->getQuantity() * p->getPrice());
  }
 
  return balance;
 };

 
 void Inventory::incrementStock(const std::string & sku, int val){
  Product *p;
  p = getProductBySku(sku);
  p->setQuantity(p->getQuantity() + val);
 };




