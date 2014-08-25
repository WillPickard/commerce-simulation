#include <iostream>
#include "Seller.h"
#include "Buyer.h"
#include "Inventory.h"
using namespace std;

Inventory * stockInventory(int type);

int main()
{
 Seller *seller1 = new Seller("Seller1", "0001", 100000);
 Buyer *buyer1 = new Buyer("Buyer1", "0001", 100000);
 seller1->addBuyer(buyer1);
 seller1->setInventory(stockInventory(1));

 cout << "Initial seller contents: " << endl;
 seller1->list();
 cout << endl;

 seller1->step();
 cout << "After taking a step : " << endl;
 seller1->list();
 cout << endl;

 Buyer *buyer2 = new Buyer("Buyer2", "0002", 200000);
 seller1->addBuyer(buyer2);
 cout << "After adding a Buyer : " << endl;
 seller1->list();
 cout << endl;

}




