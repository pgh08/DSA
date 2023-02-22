#include<bits/stdc++.h>
using namespace std;

float celtofahren(float celvalue)
{
    return ((celvalue*9/5)+32);
}

float fahrentocel(float fahrenvalue)
{
    return ((fahrenvalue-32)*5/9);
}

int main()
{
    char input;
    float celin,fhin;
    cout<<"Enter from which unit to which unit :"<<endl;
    cout<<"For Celsius press 'c' and for Fahrenheit press 'f'"<<endl;
    cin>>input;
    switch (input)
    {
    case 'c':
        cout<<"Enter the value of celsius"<<endl;
        cin>>celin;
        cout<<celtofahren(celin)<<endl;
        break;
    case 'f':
        cout<<"Enter the value of Fahrenheit"<<endl;
        cin>>fhin;
        cout<<fahrentocel(fhin)<<endl;
        break;
    default:
        return 0;
    }
    return 0;
}
