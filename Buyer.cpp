/*
 *@file Buyer.cpp
 *
 */
#include <stdlib.h>
#include <string>
#include <queue>
#include <iostream>
#include "Buyer.h"
#include "Entity.h"
#include "Seller.h"
#include "Product.h"
#include "Order.h"

using namespace std;

Buyer::Buyer(const string &n, const string &i, double bal):
	Entity(n,i,bal)
{}

Buyer::~Buyer(){ std::cout << "Deleting " << getName() << std::endl; }

Buyer* Buyer::clone() const{
  return new Buyer(*this);
}

void Buyer::addSeller(Seller * s){
  sellerQueue.push(s);
}

std::queue<Seller *> Buyer::getSellers() const{
  return sellerQueue;
}

void Buyer::addOrder(Order * order){
  orderQueue.push(order);
}

std::queue<Order *> Buyer::getOrders() const{
   return orderQueue;
}

void Buyer::list(){
  Entity::list();

//create copies of queues to retain their contents after exec of func  
  //std::queue<Order *> tempOrderQueue;
  //tempOrderQueue = getOrders();

  //std::queue<Seller *> tempSellerQueue;
  //tempSellerQueue = getSellers();
 
  unsigned int oQueueSize=getOrders().size();  
  unsigned int sQueueSize=sellerQueue.size();  
  std::cout << "Orders: " << endl;
  //iterate through order queue calling display each time
  for(unsigned int i=0;i<oQueueSize;i++){
    Order * currentOrder =orderQueue.front();
    orderQueue.pop();
    currentOrder->display();
    orderQueue.push(currentOrder);
  }
  std::cout << "Sellers: " << endl;
  //iterate through seller queue, displaying name each time
  for(unsigned int i=0;i<sQueueSize;i++){
    Seller * currentSeller = sellerQueue.front();
    sellerQueue.pop();
    std::cout << currentSeller->getName() << endl;
    sellerQueue.push(currentSeller);
  }

  std::cout << std::endl;
}//end list()

void Buyer::step(){
  double expense=0;
  if(orderQueue.size()){//are there any orders for thjis buyer?
    unsigned int size = orderQueue.size();
    for(unsigned int i=0; i<size; i++){//there are otders for the buyer, so lets go through each one in the queue
      Order * currentOrder=orderQueue.front();
      orderQueue.pop();
      if(sellerQueue.size()){//does this buyer know about any sellers?
        unsigned int size0 = sellerQueue.size();
        for(unsigned int j=0;j<size0;j++){
	  Seller * tempSeller = sellerQueue.front();
          sellerQueue.pop();
          expense+=(tempSeller->fillOrder(currentOrder));
          sellerQueue.push(tempSeller); 
        }
      }
     orderQueue.push(currentOrder);
    }
  }
  //below handles updating values and updating new order list
  double currentBalance = getBalance();
  setBalance(currentBalance - expense);
  unsigned int size=orderQueue.size();
  for(unsigned int i=0;i<size;i++){//iterate through each order in the orderqueue
    Order * currentOrder = orderQueue.front();
    orderQueue.pop();
    std::vector<Product *> productList = currentOrder->getProductList();
    unsigned int size0=productList.size();
    for(unsigned int j=0;j<size0;j++){//iterate through each product in the currentorder
      int quant = rand() % 10; //generate random # 1-9 inclusive
      cout << "Generated random number " << quant << endl;
      Product *currentProduct = productList.at(j);
      int currentQuantity= currentProduct->getQuantity();
      currentProduct -> setQuantity(currentQuantity+quant);
    }
    orderQueue.push(currentOrder);
  } 
}








