/* Singleton is a creational pattern in which the classes are designed with regards 
* to the class instantiation or object creations.
* Singleton class is created with the reason of restricting it to only one object of the class
*  The objective of Singleton class is to instantiate the class only once throughout the lifetime
* the program
* Also, The only object created should be globally accessible
*/

/* Singleton design pattern will have a structure like below
* Instance declaration,  private constructor, getInstance() method 
*/

#include<stdio.h>
using namespace std;

class Singleton{
    public:
    static Singleton *Instance;
    
    private:
    // Private constuctor
    Singleton();
    public:
    static Singleton *getInstance();
};
