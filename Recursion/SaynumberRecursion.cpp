#include<iostream>
using namespace std;

void saynum(int n){
    //Base case.
    if(n == 0){
        return;
    }
    int digit = n%10;
    n = n/10;
    saynum(n);
    string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    cout<<arr[digit]<<" ";
}

int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    saynum(n);

    return 0;
}