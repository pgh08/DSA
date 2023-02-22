#include<iostream>
using namespace std;

void pattern11(int n){
    int i = 0;

    while(i < n){
        int j = 0;
        while(j < n){
            char ch = 'A' + i;
            cout<<ch<<" "; 
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern12(int n){
    int i = 0;

    while(i < n){
        int j = 0;
        while(j < n){
            char ch = 'A' + j;
            cout<<ch<<" "; 
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern13(int n){
    int i = 0;

    while(i < n){
        int j = 0;
        while(j < n){
            char ch = 'A' + (i+j);
            cout<<ch<<" "; 
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern14(int n){
    int i = 0;

    while(i < n){
        int j = 0;
        while(j <= i){
            char ch = 'A'+i;
            cout<<ch<<" "; 
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern15(int n){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n){
        k = n-i;
        while(k > 0){
            cout<<" "; 
            k--;
        }
        int j = 0;
        while (j < i){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern16(int n){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n){
        k = n-i;
        while(k > 0){
            cout<<" "; 
            k--;
        }
        int j = 0;
        while (j < i){
            cout<<"*"<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern17(int n){
    int i = 0;
    while(i < n){
        int j = i;
        while (j < n){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern18(int n){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n){
        k = 0;
        while(k < i){
            cout<<" "; 
            k++;
        }
        int j = 0;
        while (j < n-i){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}

void pattern19(int n){
    int i = 0;
    while(i < n){
//  For Space.
        int j = n-i;
        while(j > 0){
            cout<<" ";
            j--;
        }
//  For First Half of a triangle.
        int k = 0;
        while(k <= i){
            cout<<"*";
            k++;
        }
//  For Second Half of a triangle.
        int l = 0;
        while(l < i){
            cout<<"*";
            l++;
        }
        cout<<endl;
        i++;
    }
}

void pattern20(int n){
    int i = 0;
    while(i < n){
//  For Spaces.
        int k = n-i;
        while(k > 0){
            cout<<" ";
            k--;
        }
//  First Half of a triangle
        int j = 0;
        while(j <= i){
            cout<<j+1;
            j++;
        }
//  Second Half of triangle.
        int h = 0;
        while(h < i){
            cout<<(i-h);
            h++;
        }
        cout<<endl;
        i++;
    }
}

void pattern21(int n){
    int i = 0;
    while(i < n){
//  For I Half of a Square.
        int j = 0;
        while(j < n-i){
            cout<<(j+1);
            j++;
        }
//  For II(1) Half of a Square.
        int k = 0;
        while(k < i){
            cout<<"*";
            k++;
        }
//  For II(2) Half of a Square.
        int l = 0;
        while(l < i){
            cout<<"*";
            l++;
        }
//  For III Half of a Square.
        int m = n-i;
        while(m > 0){
            cout<<m;
            m--;
        }
        cout<<endl;
        i++;
    }
}

int main()
{
    int n;
    cin>>n;

    pattern11(n);
    cout<<endl;
    pattern12(n);
    cout<<endl;
    pattern13(n);
    cout<<endl;
    pattern14(n);
    cout<<endl;
    pattern15(n);
    cout<<endl;
    pattern17(n);
    cout<<endl;
    pattern18(n);
    cout<<endl;
    pattern19(n);
    cout<<endl;
    pattern20(n);
    cout<<endl;
    pattern21(n);
    cout<<endl;

    return 0;
}