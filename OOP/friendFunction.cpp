#include<iostream>
using namespace std;
class two;
class one{
    private:
        int x;
    
    public:
        void setValue(int i){
            this->x = i;
        }
        friend void max(one, two);
};

class two{
    private:
        int y;
    
    public:
        void setValue(int j){
            this->y = j;
        }
        friend void max(one, two);
};

void max(one o, two t){
    if(o.x > t.y){
        cout<<"Class one"<<endl;
    }
    else{
        cout<<"Class two"<<endl;
    }
}

int main()
{
    one o;
    o.setValue(10);

    two t;
    t.setValue(5);

    max(o, t);

    return 0;
}