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
    Entity(const std::string &, const std::string &, double);
   
    virtual ~Entity();
    virtual Entity* clone() const =0;
    
    const std::string & getName() const;
    const std::string &  getID() const;
    double getBalance() const;

    void setName(const std::string &);
    void setID(const std:: string &);
    void setBalance(double);

    virtual void list();
    virtual void step()=0;//pure virtual, making Entity class a virtual/abstract class
};
#endif 
