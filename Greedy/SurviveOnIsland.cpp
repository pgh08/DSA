/* Given 

    N – The maximum unit of food you can buy each day.
    S – Number of days you are required to survive.
    M – Unit of food required each day to survive.

    Find the minimum number of days you need to buy food to survive on island. Note that store is closed on sunday. Start with monday.
 */
#include<iostream>
using namespace std;

int main()
{
    int N, S, M;
    cout<<"Enter the value of N, S and M respectively"<<endl;
    cin>>N>>S>>M; // 16 10 2, 20 10 30, 16 49 16, 1 10 1.

    // Calculate number of sundays in given S.
    int sunday = S/7;

    // Total number of days you can buy food.
    int totalEligibleDays = S - sunday;

    // Total food required for all the days.
    int totalFood = S*M;

    int ans = 0;
    if(totalFood%N == 0){
        ans = totalFood/N;
    }
    else{
        // Fraction day so add one extra day.
        ans = totalFood/N + 1;
    }

    // If number of days on which we bought food is greater than totalEligibleDays then we can't survive on island.
    if(ans <= totalEligibleDays){
        cout<<"Minimum Number of days = "<<ans<<endl;
    }
    else{
        cout<<"You   cannot survive on island"<<endl;
    }

    return 0;
}