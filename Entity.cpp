/*
 *@file entity.cpp
 *  base class, abstract class
 *
 */

#include <string>
#include <iostream>
#include <array>
#include "Entity.h"

using namespace std;

Entity::Entity(const std::string &n, const std::string &i, double bal):
	name(n),
	id(i),
	balance(bal){};

Entity::~Entity(){ std::cout << "Deleting " << getName() << std::endl;}

/*GETTERS*/
const string & Entity::getName() const{
	return name;
} 
const string & Entity::getID() const{
	return id;
}
double Entity::getBalance() const{
	return balance;
}

/*SETTERS*/
void Entity::setName(const string & n){
	name=n;
}
void Entity::setID(const string & i){
	id=i;
}
void Entity::setBalance(double bal){
	balance=bal;
}

/*
 *@func list()
 *  list all of an entity's attributes in cout object
 */
void Entity::list(){
	std::cout << getName() << " : " << getID() << " has $ " << getBalance() << std::endl;
}
//virtual void step();


