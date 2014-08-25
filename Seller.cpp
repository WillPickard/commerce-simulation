//@file seller.cpp

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "Seller.h"
#include "Order.h"
using namespace std;

Seller::Seller(const string &n, const string &i, double bal):
  Entity::Entity(n,i,bal)
{}

Seller* Seller::clone() const{
  return new Seller(*this);
}

Seller::~Seller(){ std::cout << "Deleting " << getName() << std::endl;}
void Seller::addBuyer(Buyer * buyer){
  buyers.push_back(buyer);
};

std::vector<Buyer *> Seller::getBuyers() const{
  return buyers;
};

void Seller::setInventory(Inventory * inv){
  inventory = inv;
};

Inventory * Seller::getInventory() const{
  return inventory;
};

void Seller::list(){
  Entity::list();
  std::cout << "Inventory: " << endl;
  inventory->showInventory();
  
  std::cout << "and the following buyers: " << endl;

  for(unsigned int i=0;i<buyers.size();i++){
    Buyer * buyer=buyers.at(i);
    std::cout << buyer->getName() << endl;
  }

  std::cout << std::endl;
};

void Seller::step(){
  set<Product *> inventorySet=inventory->Inventory::getInventory();
  //create iterator to iterate though contents of inventory's set
  //for(set<Product *>::iterator iter=inventorySet.begin(); iter!=inventorySet.end(); ++iter){
   for(auto iter : inventorySet){
      unsigned int targetQuantity = iter->getTargetQuantity();
      unsigned int currentQuantity = iter->getQuantity();
     if(currentQuantity < targetQuantity){//we do not have enough of the product, buy some if you have enough dough
        double currentBalance = getBalance();
        double costOfProduct  = iter->getPrice();
        unsigned int numToBuy = (targetQuantity-currentQuantity); //this is the number of produts we need to buy to reach the target quantity
       double expectedCost = numToBuy*costOfProduct;
       if(currentBalance >= expectedCost){//check to see if the seller has enough cash money to buy up to target cost, if he does, let him, else we are going to allow him to buy as close to target amt as he can 
          double newBalance=(currentBalance-expectedCost);
          inventory->incrementStock(iter->getSKU(), numToBuy);
          setBalance(newBalance);
       }
       else{//seller does not have enough money to bring to ideal amount, so we calc the max amt they can buy w/o entering red
          unsigned int toBuy= (getBalance()/iter->getPrice());
         std::cout << "Seller wants to buy " << numToBuy << " of " << iter->getDescription() << " at " << iter->getPrice() << " each. For a total of " << expectedCost << endl;
         std::cout << "But the seller only has " << getBalance() << ". It is going to instead buy " << toBuy << endl;
         if(toBuy>=0){
	   inventory->incrementStock(iter->getSKU(),toBuy);
           double expense = toBuy*(iter->getPrice());
  	   double newBalance=(getBalance()-expense);
           setBalance(newBalance);
         }
       }
     }
  }
};

double Seller::fillOrder(Order * order){
  double revenue=0.0;
  std::vector<Product *> productList = order->getProductList();//take the passed order and get its list of products
  int sizeOfOrder=productList.size();
  for(unsigned int i=0; i<sizeOfOrder; i++){
   Product *orderProduct = productList.at(i);
   const string tempSKU= orderProduct->getSKU();
   Product *sellerProduct = inventory->getProductBySku(tempSKU);
    if(sellerProduct != NULL){//the seller's inventory has the product
     int numDesired = orderProduct->getQuantity();
     int numHave = sellerProduct->getQuantity();
     if(numHave>=numDesired){//does this seller have enough stuff to fill the order?
       int numSold=numDesired;
       revenue += (numSold * sellerProduct->getPrice());
       orderProduct->setQuantity(0);
       inventory->incrementStock(sellerProduct->getSKU(), -numSold);
     }
     else{//this is the case when the order wants more than we can currently fill
       int numSold=numHave;
       orderProduct->setQuantity(numDesired-numSold);
       revenue += (numSold * sellerProduct->getPrice());
       inventory->incrementStock(sellerProduct->getSKU(), 0);
     }
   }
 }
  setBalance(getBalance()+revenue);
  return revenue;
};
