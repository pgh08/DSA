#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> apples = {4, 2, 6, 100, 101, 101, 110, 102};
    int target = 2;
    int diff = 0;
    int count = 0;
    int start = 0, end = 1;

    sort(apples.begin(),apples.end());

    while((start < end) && (end < apples.size())){
        diff = apples[end] - apples[start];

        if(diff <= target){
            count = max(count, (end-start));
            end-1;
        }
        else{
            start++;
        }
        end++;
    }

    cout<<count<<endl;

    return 0;
}