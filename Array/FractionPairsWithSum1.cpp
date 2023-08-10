// Given two arrays named numerator and denominator find pairs of fraction which sum up to 1.
// Time Complexity : O(n*log(n));
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int getCountFractionPairs(vector<int> &numerator, vector<int> &denominator, int n){
    map<pair<int,int>,int> pairToFrequency;
    int count = 0;

    for(int i=0; i<n; i++){
        int gcd = __gcd(numerator[i], denominator[i]);
        int num1 = numerator[i]/gcd;
        int num2 = denominator[i]/gcd;

        int x = num2-num1;

        if(pairToFrequency.count({x, num2})){
            count += pairToFrequency[{x, num2}];
        }
        pairToFrequency[{num1, num2}]++;
    }

    return count;
}

int main()
{
    int n; // 5.
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    vector<int> numerator(n), denominator(n);
    cout<<"Enter the value of numerator"<<endl;
    for(int i=0; i<n; i++){
        cin>>numerator[i]; // 3 1 12 81 2.
    }

    cout<<"Enter the value of denominator"<<endl;
    for(int i=0; i<n; i++){
        cin>>denominator[i]; // 9 10 18 90 5.
    }

    int ans = getCountFractionPairs(numerator, denominator, n);

    cout<<"Total number of fraction pairs present are : "<<ans<<endl; // 2.

    return 0;
}