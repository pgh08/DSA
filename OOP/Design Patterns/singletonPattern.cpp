/* Singleton (class) Design Pattern : A singleton class is a special type of class in object-oriented programming which can have only one object or instance at a time. 
                                      In other words, we can instantiate only one instance of the singleton class. 
                                      The new variable also points to the initial instance created if we attempt to instantiate the Singleton class after the first time. 
                                      This is implemented by using the core concepts of object-oriented programming namely access modifiers, constructors & static methods.*/

/* Steps to Implement Singleton Class :

    --> Make all the constructors of the class private.
    --> Delete the copy constructor of the class.
    --> Make a private static pointer that can point to the same class object (singleton class).
    --> Make a public static method that returns the pointer to the same class object (singleton class). */

#include<iostream>
using namespace std;

class Singleton{
    private:
        string name, loves;

        static Singleton* instancePtr;

        Singleton(){}
    
    public:
        //Deleting copy constructor.
        Singleton(const Singleton &obj) = delete;

        static Singleton* getInstance(){
            if(instancePtr == NULL){
                instancePtr = new Singleton();
                return instancePtr;
            }
            else{
                return instancePtr;
            }
        }

        void setValues(string n, string l){
            this->name = n;
            this->loves = l;
        }

        void print(){
            cout<<name<<" Loves "<<loves<<endl;
        }
};

Singleton* Singleton :: instancePtr = NULL;

int main()
{
    Singleton* pgh = Singleton :: getInstance();

    pgh->setValues("Prajwal", "Sahana");
    pgh->print();
    cout<<"Address of pgh is : "<<pgh<<endl;

    Singleton* s = Singleton :: getInstance();
    s->setValues("Sahana", "Prajwal");
    s->print();
    cout<<"Address of s is : "<<s<<endl;

    return 0;
}