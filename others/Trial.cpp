#include<iostream>
#include<vector>
using namespace std;

long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N+1, vector<long long int> (sum+1, 0));
        // long long int ans = findWays(coins, N, sum, dp);
        
        for(int i=0; i<=N; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=sum; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][sum];
}

int main()
{
    int coins[] = {1, 2, 3};
    int N = 3;
    int sum = 4;

    long long int ans = count(coins, N, sum);

    cout<<"Answer is : "<<ans<<endl;

    return 0;
}