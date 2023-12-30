// Given a matrix find the maximum rectangular sub-matrix with the sum 0.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> sum(n, vector<int> (m, 0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            sum[i][j] = a[i][j] + (j > 0 ? sum[i][j-1] : 0);
        }
     }
    
    int maxArea = 0, startRow = 0, endRow = -1, startCol = 0, endCol = -1;
    
    for(int c1=0; c1<m; c1++){
        for(int c2=c1; c2<m; c2++){
            vector<int> temp(n, 0);
          
            for(int i=0; i<n; i++){
                temp[i] = sum[i][c2] - (c1 > 0 ? sum[i][c1-1] : 0);
            }
            unordered_map<int,int> umap;
            umap[0] = -1;
            int currSum = 0;
          
            for(int i=0; i<n; i++){
                currSum += temp[i];
                
                if(umap.count(currSum)){
                    int area = (c2-c1+1) * (i-umap[currSum]);
                    if(area > maxArea){
                        maxArea = area;
                        startRow = umap[currSum]+1;
                        endRow = i;
                        startCol = c1;
                        endCol = c2;
                    }
                }
                else{
                    umap[currSum] = i;
                }
            }
        }
    }
    
    vector<vector<int>> ans;
    if(maxArea == 0){
        return ans;
    }
    
    for(int i=startRow; i<=endRow; i++){
        vector<int> temp;
        for(int j=startCol; j<=endCol; j++){
            temp.push_back(a[i][j]);
        }
        ans.push_back(temp);
    }
    
    return ans;
}

int main()
{
    int n, m;
    cout<<"Enter the size of the matrix"<<endl;
    cin>>n>>m;

    vector<vector<int>> a(n, vector<int> (m, 0));
    cout<<"Enter the value of the matrix"<<endl;
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    vector<vector<int>> ans = sumZeroMatrix(a);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}