#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the string"<<endl;
    cin>>s;

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    unordered_map<char, int> umap;
    int len = s.length();
    int i = 0;
    int j = 0;
    int ans = -1;
    
    while(j < len){
        umap[s[j]]++;

        while(umap.size() > k){
            umap[s[i]]--;
            
            if(umap[s[i]] == 0){
                umap.erase(s[i]);
            }
            
            i++;
        }
        
        if(umap.size() == k){
            ans = max(ans, j-i+1);
        }

        j++;
    }   
    
    cout<<ans<<endl;

    return 0;
}