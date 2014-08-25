/*
 *
 *@file Entity.h
 *	header for Entity base class
 */

#ifndef ENTITY_H
#define ENTITY_H
#include <string>

class Entity{
  protected:
    std::string name;
    std::string id;
    double balance;
  public:
    Entity(){};
    Entity(std::string &, std::string &, double);
    
    const std::string & getName() const;
    const std::string &  getID() const;
    double getBalance() const;

    void setName(const std::string &);
    void setID(const std:: string &);
    void setBalance(double);

    void list() const;
   // virtual void step()=0;//virtual, must be implemented by inheriting classes 
}
#endif 
