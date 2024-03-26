// Given an array of different candies costs find minimum and maximum cost of candies if for every candy you buy you can choose K free candies.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, k;
    cout<<"Enter the number of different candies and free candies for each bought candy"<<endl;
    cin>>n>>k; // 4, 2.

    vector<int> costs(n, 0);
    cout<<"Enter the cost of each candies"<<endl;
    for(int i=0; i<n; i++){
        cin>>costs[i]; // 3 2 1 4.
    }

    // Sort the costs array.
    sort(begin(costs), end(costs));
    
    // To get minimum for every candy buy from start of the array skip K candies from end.
    int mini = 0, i = 0, j = n;
    while(i < j){
        mini += costs[i];
        j -= k;
        i++;
    }

    // To get maximum for every candy buy from end of the array skip K candies from start.
    int maxi = 0;
    i = 0, j = n-1;
    while(i <= j){
        maxi += costs[j];
        j--;
        i += k;
    }

    cout<<"Minimum cost is : "<<mini<<" and Maximum cost is : "<<maxi<<endl;

    return 0;
}