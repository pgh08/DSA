#include<iostream>
using namespace std;

void reverse(string &str, int i, int j){
//    cout<<"Call received for "<<str<<endl;
//  Base case.
    if(i > j){
        return;
    }
    swap(str[i], str[j]);
    i++;
    j--;
    reverse(str, i, j);
}

int main()
{
    string name ="ABCDEFG";

    reverse(name,0,6);

    cout<<name<<endl;

    return 0;
}