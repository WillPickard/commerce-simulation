//@file seller.h

#ifndef SELLER_H
#define SELLER_H

#include <string>
#include <vector>
#include "Inventory.h"
#include "Buyer.h"
#include "Order.h"
class Buyer;
class Inventory;

class Seller : public virtual  Entity{
  private:
    Inventory* inventory;
    std::vector<Buyer *> buyers;
  public:
     Seller(){};
     virtual  ~Seller();
     virtual Seller* clone() const;
     Seller(const std::string &, const std::string &, double);
     
     void addBuyer(Buyer *);
     std::vector<Buyer *> getBuyers() const;
     
     void setInventory(Inventory *);
     Inventory * getInventory() const;

     void list();
     void step();

     double fillOrder(Order *);
};
#endif
