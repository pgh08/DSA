//Properties of taking mod on different operations.
//(a+b)%M = ((a%M) + (b%M))%M.
//(a-b)%M = ((a%M) - (b%M))%M.
//(a*b)%M = ((a%M) * (b%M))%M.
//If negative numbers (a-b+M)%M = ((a%M) - (b%M)+M)%M.

#include<bits/stdc++.h>
using namespace std;

int Permutations(string s)
{
    unordered_set<char> uset;
    for(int i=0; i<s.size(); i++){
        if(uset.find(s[i]) == uset.end()){
            uset.insert(s[i]);
        }
    }
    int m = 1000000007;
    long int  fact = 1;
    int n = uset.size();
    for (int  i = 2; i <= n; i++)
    {
        fact = (fact*i)%m;
    }
    return fact;
}



int main()
{
    string s;
    cin>>s;
    long int ans = Permutations(s);
    cout<<ans<<endl;
    return 0;
}