// Given the date find the number of that day in the year. (LeetCode Problem).
#include<iostream>
using namespace std;

int main()
{
    string date;
    cout<<"Enter the date"<<endl;
    cin>>date;

    int year = stoi(date.substr(0,4));
    int month = stoi(date.substr(5,2));
    int days = stoi(date.substr(8));
    int d[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(month > 2 && year%4 == 0 && (year%100 != 0 || year%400 == 0)){
        ++days;
    }

    while(--month > 0){
        days += d[month-1];
    }

    cout<<"Number of day is : "<<days<<endl;

    return 0;
}