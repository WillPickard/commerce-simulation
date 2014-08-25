#include <iostream>
#include <set>
#include "Seller.h"
#include "Buyer.h"
#include "Retailer.h"
#include "Inventory.h"
using namespace std;

Inventory * stockInventory(int type)
{
 if (type == 1){
   Inventory * inv1 = new Inventory();
   Product *nerds_wholesale =
        new Product("Nerds", "0001", 5, 12.00, 1, "dozen");
   Product *laffy_wholesale =
        new Product("Laffy Taffy", "0002", 5, 144.00, 1, "gross");
   Product *wonkaBar_wholesale =
        new Product("Wonka Bars", "0003", 5,  48.00, 1, "case");
   Product *gobstopper_wholesale =
        new Product("Gobstoppers ", "0004", 5, 77.00, 1, "gross");
   Product *kazoozles_wholesale =
        new Product("Kazoozles", "0005", 5, 77.00, 1, "gross");

   /* set target quantities for stock levels */
   	nerds_wholesale->setTargetQuantity(6);
   	laffy_wholesale->setTargetQuantity(6);
   	wonkaBar_wholesale->setTargetQuantity(6);
   	gobstopper_wholesale->setTargetQuantity(6);
   	kazoozles_wholesale->setTargetQuantity(6);

   /* add products to inventory and set stock levels */
   inv1->addProduct(nerds_wholesale); 
   inv1->addProduct(laffy_wholesale); 
   inv1->addProduct(wonkaBar_wholesale); 
   inv1->addProduct(gobstopper_wholesale); 
   inv1->addProduct(kazoozles_wholesale); 
   return inv1;
  };

 if (type == 2){
   Inventory *inv2 = new Inventory();
   Product *nerds_one = 
	new Product("Nerds", "0001", 10, 1.25, 5, "oz");
   Product *laffy_one = 
	new Product("Laffy Taffy", "0002", 2, 1.25, 1, "pkg");
   Product *wonkaBar_one = 
	new Product("Wonka Bars", "0003", 10, 2.50, 7, "oz.");
   Product *gobstopper_one = 
	new Product("Gobstoppers ", "0004", 2, 0.75, 100, "g");
   Product *kazoozles_one = 
	new Product("Kazoozles", "0005", 10, 0.75, 1.8, "oz");

   /* set target quantities for stock levels */
   	nerds_one->setTargetQuantity(5);
   	laffy_one->setTargetQuantity(5);
   	wonkaBar_one->setTargetQuantity(5);
   	gobstopper_one->setTargetQuantity(5);
   	kazoozles_one->setTargetQuantity(5);
 
  /* add products to inventory */
  inv2->addProduct(nerds_one); 
  inv2->addProduct(laffy_one); 
  inv2->addProduct(wonkaBar_one); 
  inv2->addProduct(gobstopper_one); 
  inv2->addProduct(kazoozles_one); 
  return inv2;
 };

 if (type == 3){
   Inventory *inv3 = new Inventory();
   Product *nerds_two = 
	new Product("Nerds", "0001", 2, 1.25, 5, "oz");
   Product *laffy_two = 
	new Product("Laffy Taffy", "0002", 10, 1.25, 1, "pkg");
   Product *wonkaBar_two = 
	new Product("Wonka Bars", "0003", 2, 2.50, 7, "oz."); 
   Product *gobstopper_two = 
	new Product("Gobstoppers ", "0004", 10, 0.75, 100, "g");
   Product *kazoozles_two = 
	new Product("Kazoozles", "0005", 2, 0.75, 1.8, "oz");
   
   /* set target quantities for stock levels */
   	nerds_two->setTargetQuantity(5);
   	laffy_two->setTargetQuantity(5);
   	wonkaBar_two->setTargetQuantity(5);
   	gobstopper_two->setTargetQuantity(5);
   	kazoozles_two->setTargetQuantity(5);
 
  /* add products to inventory */
  inv3->addProduct(nerds_two); 
  inv3->addProduct(laffy_two); 
  inv3->addProduct(wonkaBar_two); 
  inv3->addProduct(gobstopper_two); 
  inv3->addProduct(kazoozles_two); 
  return inv3;
 };
 
 Inventory * dummy = nullptr;
 return dummy;

}

 
