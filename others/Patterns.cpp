#include<iostream>
using namespace std;

void pattern1(int n){
    int i = 0;

//For Row iteration.
    while(i < n){
        int j = 0;

        while(j < n){
            cout<<"*"<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern2(int n){
    int i = 1;
    while(i <= n){
        int j = 0;
        while(j < n){
            cout<<i<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern3(int n){
    int i = 0;
    while (i < n){
        int j = 1;
        while(j <= n){
            cout<<j<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    
}

void pattern4(int n){
    int i = 0;
    while (i < n){
        int j = n;
        while(j > 0){
            cout<<j<<" ";
            j--;
        }
        cout<<endl;
        i++;
    }
    
}

void pattern5(int n){
    int i = 0;
    int count = 1;
    while(i < n){
        int j = 0;
        while(j < n){
            cout<<count<<" ";
            j++;
            count++;
        }
        cout<<endl;
        i++;
    }
}

void pattern6(int n){
    int i = 0;
    while(i < n){
        int j = 0;
        while(j <= i){
            cout<<"*"<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern7(int n){
    int i = 1;
    while(i <= n){
        int j = 0;
        while(j < i){
            cout<<i<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern8(int n){
    int i = 1;
    int count = i;
    while(i <= n){
        int j = 1;
        while(j <= i){
            cout<<count<<" ";
            j++;
            count++;
        }
        cout<<endl;
        i++;
    }
}

void pattern9(int n){
    int i = 1;
    while(i <= n){
        int j = 1;
//        int value = i;
        while(j <= i){
            cout<<j+i-1<<" ";
            j++;
//            value++;
        } 
        cout<<endl;
        i++;
    }
}

void pattern10(int n){
    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= i){
            cout<<i-j+1<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}

int main()
{
    int n;
    cin>>n;

    pattern1(n);
    cout<<endl;
    pattern2(n);
    cout<<endl;
    pattern3(n);
    cout<<endl;
    pattern4(n);
    cout<<endl;
    pattern5(n);
    cout<<endl;
    pattern6(n);
    cout<<endl;
    pattern7(n);
    cout<<endl;
    pattern8(n);
    cout<<endl;
    pattern9(n);
    cout<<endl;
    pattern10(n);
    cout<<endl;

    return 0;
}