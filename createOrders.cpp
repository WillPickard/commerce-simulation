#include <iostream>
#include <set>
#include "Seller.h"
#include "Buyer.h"
#include "Inventory.h"
using namespace std;

Order * createOrder(int type)
{
 if (type == 1){
 Order  *order1 = new Order();
 Product *nerds_retail =
        new Product("Nerds", "0001", 0, 1.25, 5, "oz");
 Product *laffy_retail =
        new Product("Laffy Taffy", "0002", 0, 1.25, 1, "pkg");
 Product *wonkaBar_retail =
        new Product("Wonka Bars", "0003", 0, 2.50, 1, "oz");
 Product *gobstopper_retail =
        new Product("Gobstoppers ", "0004", 0, 0.75, 100, "g");
 Product *kazoozles_retail =
        new Product("Kazoozles", "0005", 0, 0.75, 1.8, "oz");

 /* set target quantities */
	nerds_retail->setTargetQuantity(2);
        laffy_retail->setTargetQuantity(3);
        wonkaBar_retail->setTargetQuantity(2);
        gobstopper_retail->setTargetQuantity(3);
        kazoozles_retail->setTargetQuantity(2);

 /* add products to inventory */
 order1->addItem(nerds_retail);
 order1->addItem(laffy_retail);
 order1->addItem(wonkaBar_retail);
 order1->addItem(gobstopper_retail);
 order1->addItem(kazoozles_retail);
 return order1;
 }
 
 if (type == 2){
 Order  *order2 = new Order();
 Product *nerds_two =
        new Product("Nerds", "0001", 0, 1.25, 5, "oz");
 Product *laffy_two =
        new Product("Laffy Taffy", "0002", 0, 1.25, 1, "pkg");
 Product *wonkaBar_two =
        new Product("Wonka Bars", "0003", 0, 2.50, 1, "oz");
 Product *gobstopper_two =
        new Product("Gobstoppers ", "0004", 0, 0.75, 100, "g");
 Product *kazoozles_two =
        new Product("Kazoozles", "0005", 0, 0.75, 1.8, "oz");

 /* set target quantities */
	nerds_two->setTargetQuantity(1);
        laffy_two->setTargetQuantity(2);
        wonkaBar_two->setTargetQuantity(1);
        gobstopper_two->setTargetQuantity(2);
        kazoozles_two->setTargetQuantity(1);

 /* add products to inventory */
 order2->addItem(nerds_two);
 order2->addItem(laffy_two);
 order2->addItem(wonkaBar_two);
 order2->addItem(gobstopper_two);
 order2->addItem(kazoozles_two);
 return order2;
 }
 
 if (type == 3){
 Order  *order3 = new Order();
 Product *nerds_three =
        new Product("Nerds", "0001", 0, 1.25, 5, "oz");
 Product *laffy_three =
        new Product("Laffy Taffy", "0002", 0, 1.25, 1, "pkg");
 Product *wonkaBar_three =
        new Product("Wonka Bars", "0003", 0, 2.50, 1, "oz");
 Product *gobstopper_three =
        new Product("Gobstoppers ", "0004", 0, 0.75, 100, "g");
 Product *kazoozles_three =
        new Product("Kazoozles", "0005", 0, 0.75, 1.8, "oz");

 /* set target quantities */
	nerds_three->setTargetQuantity(0);
        laffy_three->setTargetQuantity(3);
        wonkaBar_three->setTargetQuantity(0);
        gobstopper_three->setTargetQuantity(3);
        kazoozles_three->setTargetQuantity(0);

 /* add products to inventory */
 order3->addItem(nerds_three);
 order3->addItem(laffy_three);
 order3->addItem(wonkaBar_three);
 order3->addItem(gobstopper_three);
 order3->addItem(kazoozles_three);
 return order3;
 }
 
 if (type == 4){
 Order  *order4 = new Order();
 Product *nerds_four =
        new Product("Nerds", "0001", 0, 1.25, 5, "oz");
 Product *laffy_four =
        new Product("Laffy Taffy", "0002", 0, 1.25, 1, "pkg");
 Product *wonkaBar_four =
        new Product("Wonka Bars", "0003", 0, 2.50, 1, "oz");
 Product *gobstopper_four =
        new Product("Gobstoppers ", "0004", 0, 0.75, 100, "g");
 Product *kazoozles_four =
        new Product("Kazoozles", "0005", 0, 0.75, 1.8, "oz");

 /* set target quantities */
	nerds_four->setTargetQuantity(1);
        laffy_four->setTargetQuantity(2);
        wonkaBar_four->setTargetQuantity(3);
        gobstopper_four->setTargetQuantity(4);
        kazoozles_four->setTargetQuantity(5);

 /* add products to inventory */
 order4->addItem(nerds_four);
 order4->addItem(laffy_four);
 order4->addItem(wonkaBar_four);
 order4->addItem(gobstopper_four);
 order4->addItem(kazoozles_four);
 return order4;
 }
 Order *o = nullptr;
 return o; 
};

 
