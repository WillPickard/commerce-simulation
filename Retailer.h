//@file retailer.h
#ifndef RETAILER_H
#define RETAILER_H
#include <string>
#include "Seller.h"
#include "Buyer.h"
#include "Inventory.h"
#include "Entity.h"
#include "Product.h"

class Retailer : public Seller, public Buyer{
  
public:
  Retailer(){};
  Retailer(const std::string &, const std::string &, double);

  virtual ~Retailer();
  virtual Retailer* clone() const; 
  void list();
  void step();
};
#endif
