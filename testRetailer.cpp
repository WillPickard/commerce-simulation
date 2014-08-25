#include "Retailer.h"
#include "Buyer.h"
#include "Seller.h"
#include "Product.h"
#include "Inventory.h"
#include "Order.h"
#include <set>
#include <iostream>

using namespace std;

int main(void){

Seller *microsoft = new Seller("Microsoft", "000001", 1000.00);
Seller *apple = new Seller("Apple", "00002", 1000.00);

Buyer *bob = new Buyer("Bob the buyer", "00003", 10.00);
Buyer *boe = new Buyer("Boe the buyer", "00004", 15.00);

Retailer *walmart = new Retailer("Walmart", "00005", 100000);

microsoft -> addBuyer(bob);
microsoft -> addBuyer(boe);
microsoft -> addBuyer(walmart);

apple -> addBuyer(bob);
apple -> addBuyer(boe);
apple -> addBuyer(walmart);

bob -> addSeller(microsoft);
bob -> addSeller(apple);
bob -> addSeller(walmart);

boe -> addSeller(microsoft);
boe -> addSeller(apple);
boe -> addSeller(walmart);

std::set<Entity *> entSet;//to hold all above inits
std::set<Entity *>::iterator iter;//iterator for entSet

entSet.insert(microsoft);
entSet.insert(apple);
entSet.insert(bob);
entSet.insert(boe);
entSet.insert(walmart);

/*for(iter=entSet.begin(); iter!=entSet.end(); ++iter){
  std::cout << iter->list() << endl;
}*/
walmart -> list();
for(auto iter : entSet){

  iter->list();
}

return 0;
}
