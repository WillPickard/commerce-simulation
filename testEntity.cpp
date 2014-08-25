#include <iostream>
#include "Entity.h"
using namespace std;

int main()
{
 Entity *entity1 = new Entity("Entity1", "0001", 25.00);

 cout << "name is " << entity1->getName() << endl;
 cout << "id is " << entity1->getID() << endl;
 cout << "balance is " << entity1->getBalance() << endl;
 entity1->list();
 
}




