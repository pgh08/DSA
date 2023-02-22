#include<iostream>
using namespace std;

int factorial(int n){
//  Base case.
    if(n == 0){
        return 1;
    }
/*    int small = factorial(n-1);
    int big = n * small;

    return big;*/

    return n * factorial(n-1);
}

int powof2(int n){
//  Base Case.
    if(n == 0){
        return 1;
    }
/*    int small = powof2(n-1);
    int big = 2 * small;

    return big;*/

    return 2 * powof2(n-1);
}

void counting(int n){
//  Base case.
    if(n == 0){
        return;
    }
//  Head Recursion.
    cout<<n<<" ";

    counting(n-1);
//  Tail Recursion.
    cout<<n<<" ";
}

int fibonacci(int n){
//  Base case.
    if(n == 1 || n == 0){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;
    cin>>n;

    int fact = factorial(n);
    cout<<fact<<endl;

    int pow2 = powof2(n);
    cout<<pow2<<endl;

    counting(n);
    cout<<endl;
    
    cout<<fibonacci(n)<<endl;

    return 0;
}