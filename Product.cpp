#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Product.h"
using namespace std;

 void Product::setDescription(const string & description){
	description_ = description;
 };

 void Product::setSKU(const string & sku){
	sku_ = sku;
 };

 void Product::setQuantity(int quantity){
	quantity_ = quantity;
 };

 void Product::setTargetQuantity(int quantity){
	targetQuantity_ = quantity;
 };


 void Product::setPrice(float price){
	price_ = price;
 };

 void Product::setSize(float size){
	size_ = size;
 };


 void Product::setUnits(const string & units){
	units_ = units;
 };

 const string & Product::getDescription() const {
	return description_;
 };

 const string & Product::getSKU() const {
	return sku_;
 };

 float Product::getPrice() const {
	return price_;
 };

 int Product::getQuantity() const {
	return quantity_;
 };

 int Product::getTargetQuantity() const {
	return targetQuantity_;
 };

 const string & Product::getUnits() const {
	return units_;
 };

 float Product::getSize() const {
	return size_;
 };
 
 void Product::getInfo() {
	string desc;
 	string sku;
	int quant;
	float pric;
	float siz;
	string unts;
	
	cout << "Description:"; cin >> desc; 
	setDescription(desc);

	cout << "SKU:"; cin >> sku; 
	setSKU(sku);

	cout << "Quantity:"; cin >> quant; 
	setQuantity(quant);

	cout << "Price:"; cin >> pric; 
	setPrice(pric);

	cout << "Size:"; cin >> siz; 
	setSize(siz);

	cout << "Units:"; cin >> unts; 
	setUnits(unts);
	
	cout << listItem() << endl << endl;
 }

 string Product::listItem() const {
	ostringstream returnString;
	returnString << setw(4) << getQuantity() 
                     << " of " << left << setw(20) << getDescription();
	ostringstream amountString;
	amountString << " (" << setw(4) << getSize() << " " << setw(6) << getUnits() << ")";
	returnString << setw(8) << amountString.str() 
		     << " at $";
	returnString << fixed << setprecision(2);
	returnString << setiosflags(ios::right|ios::fixed) << setw(6) << getPrice() 
		     << "    (" << setw(5) << getSKU() << ")"; 
	return returnString.str();
 };
 



