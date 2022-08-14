/* Decorator is designed depending on the class structure
*  It consists of Abstract and concrete classes, This design pattern allows the objects to behave differently 
*  by placing these objects into special types of wrapper objects which contains these kind of behaviours 
 */
#include <iostream>
using namespace std;

/* Abstract component of Coffee */
class Coffee{
    // Type of coffee
    public:
    string type;

    public:
    Coffee(){}

    virtual string getType() = 0;
    virtual double cost() = 0;
};

/* Concrete componenent */
class CoffeeBlend: public Coffee
{
    public:
    /* Initializer list which calls parent class constructor */
    CoffeeBlend(){
        this->type = "CoffeeBlend";
    }

    string getType(){ return this->type; }
    
    double cost(){ return 20;}

};

/* Concrete Compoenent*/
class CoffeeRoast : public Coffee
{
    public:
    /* Initializer list which calls parent class constructor first */
    CoffeeRoast(){}

    double cost(){ return 25; }
};

/* Abstract Decorator class which is special type of abstract class which adds the diffent behaviours to its objects
using the its Abstract parent class objects which have multiple behaviours in its Concrete classes */
class AddOn : public Coffee
{
    /* The class which is having a member of the class type same as its Parent class, It can be identified as 
    Abstract decorator class*/
    public:
    Coffee *coffee_;

    public:
    AddOn(){}

    AddOn(Coffee *coffee){
        this->coffee_ = coffee;
    }

    virtual string getType() = 0;

    // string getType(){
    //     return this->coffee_->getType();
    // }
};

class Sugar : public AddOn
{
    public:
    Sugar(Coffee *coffee): AddOn(coffee)
    {}

    double cost(){ 
        return (this->coffee_->cost() + 3);
    }

    string getType(){ return "Sugar in " + this->coffee_->getType();}
};

class Milk : public AddOn
{
    public:
    Milk(Coffee *coffee): AddOn(coffee)
    {}

    double cost(){
        return (this->coffee_->cost() + 5);
    }

    string getType(){ return "Milk in" + this->coffee_->getType();}

};

class Ginger : public AddOn
{
    public:
    Ginger(Coffee *coffee): AddOn(coffee)
    {}

    double cost(){ return this->coffee_->cost() + 2;}

    string getType(){ return "Ginger in " + this->coffee_->getType();}

};
int main(){
    /* Instantiation of Concrete component */ 
    Coffee *coffee = new CoffeeBlend();
    cout<<coffee->getType()<<" : "<<coffee->cost()<<endl;
    Coffee *addOn = new Milk(coffee);
    cout<<addOn->getType()<<" : "<<addOn->cost()<<endl;
    Coffee *sugarOn = new Sugar(addOn);
    cout<<sugarOn->getType()<<" : "<<sugarOn->cost()<<endl;
    return 0;
}