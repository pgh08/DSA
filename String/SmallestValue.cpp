//Smallest value of rearranged number.
//Given an integer find the smallest possible combination without leading zeros.
//Negative numbers are also present.
/* Algorithm : 
   1. Convert given number to a string.
   2. sort the string in increasing order if the given number is non-negative.
   3. Sort the string in decreasing order if the given number is negative.
   4. In both case sort the absolute value of the number.
   5. (Important)Swap leading zero with the first non-zero number from the string.
   6. Convert the given string to an integer.
   7. Return the answer.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int num;
    cout<<"Enter the number"<<endl;
    cin>>num;

    string s = to_string(abs(num));
    if(num >= 0){
        sort(s.begin(),s.end());
    }
    else{
        sort(s.begin(),s.end(),greater<int>());
    }

    if(num > 0){
        int firstNonZeroIndex = s.find_first_not_of('0');
        swap(s[0],s[firstNonZeroIndex]);
    }

    long long ans = stoll(s);

    if(num < 0){
        cout<<"Minmum possible number combination is : "<<ans*-1<<endl;
    }
    else{
        cout<<"Minmum possible number combination is : "<<ans<<endl;
    }

    return 0;
}