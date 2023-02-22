#include<iostream>
using namespace std;

class car{
    protected:
        string breakType;
        int fuelEfficiency;
        int noOfWheels;

    public:
        void getBreakType(){
            cout<<"Enter the break type"<<endl;
            cin>>breakType;
        }

        void getFuelEfficiency(){
            cout<<"Enter the fuel efficiency"<<endl;
            cin>>fuelEfficiency;
        }

        void getNoOfWheels(){
            cout<<"Enter the number of wheels"<<endl;
            cin>>noOfWheels;
        }

        void display(){
            cout<<"Break type is : "<<breakType<<endl;
            cout<<"Fuel efficiency is : "<<fuelEfficiency<<endl;
            cout<<"Number of wheels is : "<<noOfWheels<<endl;
        }
};

class mercedes : public car{
    public:
        string model;

    virtual void display(){
        cout<<"Model name is : "<<endl;
    }
};

int main()
{
    /* car c1;
    c1.getFuelEfficiency();
    c1.getNoOfWheels();
    c1.getBreakType();

    c1.display();

    car *c2;
    mercedes m1;
    c2 = &m1;
    m1.getFuelEfficiency();
    m1.getNoOfWheels();
    m1.getBreakType();

    c2->display(); */

    mercedes m[5];
    car *c3;
    c3 = m;

    for(int i=0; i<5; i++){
        cout<<"Enter the details"<<endl;
        m[i].getFuelEfficiency();
    }

    for(int i=0; i<5; i++){
        c3[i].display();
    }


    return 0;
}