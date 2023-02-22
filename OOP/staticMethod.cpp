#include<iostream>
using namespace std;

class A{
    int nonStatic;
    static int stat;

    public:
        static void setValues(int i, int j){
            //Error for this statment : nonStatic = i;
            //Error for this statement : stat = j;
            cout<<i<<" "<<j<<endl;
        }
};

int main()
{
    A obj;
    obj.setValues(5, 10);

    //Also we can do like this.
    A :: setValues(0, 10);

    return 0;
}