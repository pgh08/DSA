#include<bits/stdc++.h>
using namespace std;

int internNumber(int pass)
{
    int count=1,i=0;
    long day[49];
    day[0] = 5000;
    if(day[0] == pass){
        return count;
    }
    while (pass != day[i] && i < 49)
    {
        i++;
        count++;
        day[i] = day[i-1]+5000*count+i;
    }
    if(day[i] == pass)
        return count;

    return 0;
}

int main()
{
    int pass;
    cout<<internNumber(105015);
}