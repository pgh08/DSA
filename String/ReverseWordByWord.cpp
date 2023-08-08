#include<iostream>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the value of s"<<endl;
    getline(cin, s);

    int n = s.length();

    string temp = "";
    string ans = "";

    for(int i=0; i<n; i++){
        char ch = s[i];

        if(ch == ' '){
            if(temp != ""){
                ans = temp + " " + ans;
            }
            temp = "";
        }
        else{
            temp += ch;
        }
    }

    if(temp != ""){
        ans = temp + " " + ans;
    }

    if(ans.length() > 0 && ans[ans.length()-1] == ' '){
        ans = ans.substr(0, ans.length()-1);
    }

    cout<<"String after reversing word by word is : "<<ans<<endl;

    return 0;
}