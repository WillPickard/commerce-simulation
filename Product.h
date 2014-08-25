#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product{

public:
 Product(){};
 Product( 
	const std::string & description, 
	const std::string & sku, 
	int quantity,
	float price, 
	float size, 
	const std::string & units): 
	description_(description), 
	sku_(sku), 
	quantity_(quantity),
	price_(price), 
	size_(size), 
	units_(units){};

 void setDescription(const std::string & description);
 void setSKU(const std::string & sku);
 void setQuantity(int quantity);
 void setTargetQuantity(int quantity);
 void setPrice(float price);
 void setSize(float size);
 void setUnits(const std::string & units);
 
 const std::string & getDescription() const;
 const std::string & getSKU() const;
 int getQuantity() const;
 int getTargetQuantity() const;
 float getPrice() const;
 float getSize() const;
 const std::string & getUnits() const;

 void getInfo();
 std::string listItem() const;
 
private:
 std::string description_;
 std::string sku_;
 int quantity_;
 int targetQuantity_;
 float price_;
 float size_;
 std::string units_;

};
#endif
