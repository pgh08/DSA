#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void threeSome(int arr[], int n, vector<vector<int>> &ans){
    if(n < 3){
        return;
    }
    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            break;
        }
        if((i > 0) && (arr[i-1] == arr[i])){
            continue;
        }

        int j = i+1;
        int k = n-1;

        while(j < k){
            int sum = arr[i] + arr[j] + arr[k];

            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                ans.push_back({arr[i], arr[j], arr[k]});

                while((j < k) && (arr[j] == arr[j+1])){
                    j++;
                }
                j++;

                while((j < k) && (arr[k] == arr[k-1])){
                    k--;
                }
                k--;
            }
        }
    }
}

int main()
{
    int arr[6]= {-1,0,1,2,-1,-4};
    int n = 6;

    vector<vector<int>> ans;

    threeSome(arr, n, ans);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}