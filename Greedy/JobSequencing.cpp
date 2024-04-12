// Given a array of JobID, Deadline and Profit, find maximum profit which can be acheived.
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Job{
    public:
        int jobId;
        int deadline;
        int profit;
};  

static bool compare(Job &a, Job &b){
    return a.profit > b.profit;
}

int main()
{
    int n; // 5.
    cout<<"Enter the number of jobs"<<endl;
    cin>>n;

    Job arr[n];
    cout<<"Enter JobID, Deadline and Pofit for each job"<<endl;
    for(int i=0; i<n; i++){ // {[1,2,100], [2,1,19], [3,2,27], [4,1,25], [5,1,15]}.
        cin>>arr[i].jobId;
        cin>>arr[i].deadline;
        cin>>arr[i].profit;
    }

    // Step 1 : Sort array based on profit.
    sort(arr, arr+n, compare);

    // Step 2 : Array to store used deadline. Size must be of lagest deadline.
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        maxi = max(arr[i].deadline, maxi);
    }
    vector<int> usedDeadline(maxi+1, -1);

    // Step 3 : Iterate through array and compute the answer.
    pair<int,int> ans = {0,0}; // first to store number of jobs, second to store maximum profit.

    for(int i=0; i<n; i++){
        int currProfit = arr[i].profit;
        int currID = arr[i].jobId;
        int currDeadline = arr[i].deadline;

        for(int k=currDeadline; k>0; k--){
            if(usedDeadline[k] == -1){
                ans.first++;
                ans.second += currProfit;
                usedDeadline[k] = currID;
                break;
            }
        }
    }

    cout<<"Maximum profit of : "<<ans.second<<" can be acheived using "<<ans.first<<" jobs"<<endl;

    return 0;
}