#include <iostream>
#include <array>
#include <typeinfo>
#include <set>
#include "Seller.h"
#include "Buyer.h"
#include "Retailer.h"
#include "Inventory.h"
using namespace std;

Inventory * stockInventory(int type);
Order * createOrder(int type);
void simulationStats();
std::set<Entity *> saveState(std::set<Entity *>);
int main()
{

 Seller *willieWonka;
 Retailer *momAndPop;
 Retailer *jackNjill;
 Buyer *cust1, *cust2, *cust3, *cust4;

 /* create a Supplier (i.e., Seller, Manufacturer)  */
 willieWonka = new Seller("Willie Wonka", "001", 1000000);

 /* create some Retailers */
 momAndPop = new Retailer("Mom's candy shop","002", 10000);
 jackNjill = new Retailer("J&J Sweets ", "003", 20000);

 /* create some Buyers (Customer) */
 cust1 = new Buyer("Charlie","004", 25.00);
 cust2 = new Buyer("Sally","005", 26.000);
 cust3 = new Buyer("Mary","006", 27.00);
 cust4 = new Buyer("Bob","007", 28.00);

 /* hook them up */

 willieWonka->addBuyer(momAndPop);
 willieWonka->addBuyer(jackNjill);
 momAndPop->addSeller(willieWonka);
 jackNjill->addSeller(willieWonka);

 momAndPop->addBuyer(cust1);
 cust1->addSeller(momAndPop);

 momAndPop->addBuyer(cust2);
 cust2->addSeller(momAndPop);

 jackNjill->addBuyer(cust3);
 cust3->addSeller(jackNjill);

 jackNjill->addBuyer(cust4);
 cust4->addSeller(jackNjill);

 /* provision the supplier and the retailers*/
 willieWonka->setInventory(stockInventory(1)); 
 momAndPop->setInventory(stockInventory(2)); 
 jackNjill->setInventory(stockInventory(3)); 

 /* demonstrate initial inventories */
 cout << endl;

 cout << momAndPop->getName() << " is starting the simulation with: " << endl;
 momAndPop->getInventory()->showInventory();
 cout << endl;

 cout << jackNjill->getName() << " is starting the simulation with: " << endl;
 jackNjill->getInventory()->showInventory();
 cout << endl;

 /* initialize customer orders */
 cust1->addOrder(createOrder(1));
 cust2->addOrder(createOrder(2));
 cust3->addOrder(createOrder(3));
 cust4->addOrder(createOrder(4));
 
/* Place all entitities into a set of simulation objects 
    Use the set template for c++11
    Items are of type Entity * 
  */
//create a set of entity objects called simset, the iterator for that set it called iter
std::set<Entity *> simSet;
std::set<Entity *>::iterator iter;

//the array init below is an array of 100 cells, each containing a set of entity objects, each cell correponds with a step in the sim for loop, and is used to generate stats at the end
std::array< std::set<Entity *>, 100> simMemory;

simSet.insert(willieWonka);

simSet.insert(momAndPop);
simSet.insert(jackNjill);

simSet.insert(cust1);
simSet.insert(cust2);
simSet.insert(cust3);
simSet.insert(cust4);
  
 /* Run the simulation for 100 steps */
 /* iterate through your set of entity objects
    Invoke "step()" on each one.  
    Each type of entity should update appropriately.
    Each type of entity should display appropriately, once every 10 steps.
  */

cout << "******************** BEGIN SIMULATION *********************" << endl <<endl; 
for(int i=0;i<100;i++){
  simMemory[i]=saveState(simSet);
  if(i%10==0){  cout << "******************************* STEP " << i << " ******************************" <<endl; }
  for(iter=simSet.begin(); iter!=simSet.end(); iter++){
    (*iter) -> step();
    if(i%10==0){//display state of objects once every 10 steps
      (*iter) -> list(); 
    }
  }
}
cout << "******************** SIMULATION OVER! ********************" << endl;

cout << endl << endl <<  "The simulation has now ended. " << endl;
//at the end of the simulation the user will be prompted to quit by pressing 0 or following a list of options to view some sim stats that utilize the simMemory array
int choice=0;
while( cout << endl << endl <<  "You can press: " << endl << "0 to quit, " << endl << "1 to view the total changes in each step" << endl << "or 2 to view the state of the simulation at a specific step(you will be prompted for the step after you press 2)" << endl , cin >> choice){
  switch(choice){
     case 0:
	{
        cout << "Terminating" << endl; 
	for(iter=simSet.begin();iter!=simSet.end();iter++){
          delete (*iter);
        }
        for(int i=0; i<100; i++){
          for(iter=simMemory[i].begin(); iter!=simMemory[i].end(); iter++){  
            delete (*iter);
          }
        }
        exit(0);
        }
      case 1:
        { 
        std::vector<double> beginningValues;
        std::vector<double> endValues;
	std::vector<double> differenceValues;
        cout << "At the beginning of the simulation, each entity had this much in their bank: " << endl;
        std::set<Entity *>::iterator iter;
        for(iter=simMemory[0].begin(); iter!=simMemory[0].end(); iter++){
          (*iter) -> Entity::list();
          beginningValues.push_back((*iter)->getBalance());
        }
        cout << endl << "And at the end: " << endl;
        for(iter=simMemory[99].begin(); iter!=simMemory[99].end(); iter++){
          (*iter) -> Entity::list();
          endValues.push_back((*iter)->getBalance());
        }
        cout << endl << "Here are the total changes by name: " << endl;
        int vectorSize = endValues.size();
        for(int i=0; i<vectorSize; i++){
           double val = (endValues.at(i) - beginningValues.at(i));
           differenceValues.push_back(val);
        }
        int i=0;
        for(iter=simMemory[99].begin(); iter!=simMemory[99].end(); iter++){
           string name = (*iter) -> getName();
           double difference = differenceValues.at(i);
           if(difference<0){ cout << name << " lost " << difference << endl; }
           else{ cout << name << " gained " << difference << endl; }
           i++;
        }
        break;
        }
      case 2:
         {
         int valid = 0;
         int step=-1;
         while(!valid){
            cout << "Please enter a step number between 0 (for the first step) and 99 (for the last): ";
            cin >> step; if(step>=0 && step <100){ valid =1; } 
         }
         std::set<Entity *>::iterator iter1;
         for(iter1 = simMemory[step].begin(); iter1!=simMemory[step].end(); iter1++){
           (*iter1) -> list();
         }
         break;
         }
  }//end switch
}//end while

};//end main

std::set<Entity *>  saveState(std::set<Entity *> simSet){
  std::set<Entity *> returnSet;
  std::set<Entity *>::iterator iter;
  for(iter=simSet.begin(); iter!=simSet.end(); iter++){
//    cout << typeid(*iter).name() << endl;
     Entity *temp = (*iter) -> clone();
     returnSet.insert(temp);
   }
   return returnSet;
}

 
