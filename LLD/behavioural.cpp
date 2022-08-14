/* Behavioural Design pattern : Command pattern */
/* It's a type of pattern designed to have loose coupling between classes. 
*  This pattern gives the knowledge of how classes and objects are intereacting with each other 
*  There are 3 actors (classes) in this design pattern 
*   1. Client class  2. Invoker class  3. Executer class
*   Invoker class calls the callable object's method but the required action is taken by executer class
*/
#include <iostream>
using namespace std;
class Chef
{
    string food;
    public:

    void takeFood(string food){ this->food = food;}
    void cook()
    {
        cout<<"Cooking "<<this->food<<endl;
    }
};

/* Interface for command (Abstract class)*/
class Command
{
    public:
    // Pure virtual function
    virtual void execute() = 0;
};

/* Client makes order using command interface (Concrete command )*/
class Order : public Command
{
    Chef *chef_;
    public:
    Order(){}

    Order(Chef *chef,string food) : chef_(chef)
    {
        this->chef_->takeFood(food);
    }

    void execute()
    {
        this->chef_->cook();
    }
};
 /* Invoker class which hand over the Order to the Chef who takes the action
 *  which in turns calls cook method*/
class Waiter : public Order
{
    Order *order_;
    public:
    Waiter(){}

    Waiter(Order *order): order_(order)
    {}

    void execute()
    {
        this->order_->execute();
    }

}; 

int main(){
    Chef *chef = new Chef();
    Order *order = new Order(chef,"Pizza");
    Waiter *waiter = new Waiter(order);

    waiter->execute();
    return 0;
}