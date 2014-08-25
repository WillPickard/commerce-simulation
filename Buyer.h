/**
 *@file Buyer.h
 *   header file for buyer class inherited from Entity base class
 */

#ifndef BUYER_H
#define BUYER_H
#include <string>
#include <queue>
#include "Entity.h"
#include "Seller.h"
#include "Order.h"

class Buyer : public virtual  Entity{
  private: 
    std::queue<Order *> orderQueue;
    std::queue<Seller *> sellerQueue; 
  public:
    Buyer(){};
    Buyer(const std::string &, const std::string &, double);
    virtual ~Buyer();
    virtual Buyer* clone() const; 

    void addSeller(Seller *);
    std::queue<Seller *> getSellers() const;
    
    void addOrder(Order *);
    std::queue<Order *> getOrders() const;   
    
    void list();
    void step();
};
#endif
