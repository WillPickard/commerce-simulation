#include <iostream>
#include "Buyer.h"
#include "Seller.h"
#include "Order.h"
using namespace std;

Order *createOrder(int type);
Inventory * stockInventory(int type);

int main()
{
 Buyer *buyer1 = new Buyer("Buyer1", "0001", 100000);
 Seller *seller1 = new Seller("Seller1", "0002", 200000);

 seller1->setInventory(stockInventory(1));
 buyer1->addOrder(createOrder(1));
 buyer1->addSeller(seller1);
 cout << "Initial buyer contents: " << endl;
 buyer1->list();
 cout << endl;

//for(int i=0;i<100;i++){
 buyer1->step();
 cout << "After taking a step : " << endl;
 buyer1->list();
 cout << endl;
//printf("\t\t\t\t %d", i);
//}
 Seller *seller2 = new Seller("Seller2", "0003", 30000);
 buyer1->addSeller(seller2);
 cout << "After adding a Seller : " << endl;
 buyer1->list();
 cout << endl;

}





