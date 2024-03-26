// Given the start and end time of each meeting in a form of an array. Find maximum number of meetings which can be done in the room.
// Meeting can be conducted if endtime of previous meeting is greater than starttime of current meeting.
#include<iostream>
#include<vector>
#include<algorithm>
#define pi pair<int,int>
using namespace std;

static bool compare(pi &a, pi &b){
    return a.second < b.second;
}

int getMaxMeetings(vector<int> &start, vector<int> &end, int &n){
    vector<pi> startEndPair;

    for(int i=0; i<n; i++){
        startEndPair.push_back({start[i],end[i]});
    }

    sort(startEndPair.begin(), startEndPair.end(),compare);

    int meetingEnd = startEndPair[0].second;
    int count = 0;

    for(int i=0; i<n; i++){
        if(startEndPair[i].first > meetingEnd){
            count++;
            meetingEnd = startEndPair[i].second;
        }
    }

    return count;
}

int main()
{
    int n;
    cout<<"Enter the number of meetings"<<endl;
    cin>>n;

    vector<int> start(n, 0), end(n, 0);
    cout<<"Enter the value of start and end time respectively in single row"<<endl;
    for(int i=0; i<n; i++){
        cin>>start[i]>>end[i];
    } // start : 1 3 0 5 8 5, end : 2 4 6 7 9 9.

    int ans = getMaxMeetings(start, end, n);

    cout<<"Maximum number of meetings which can be conducted are : "<<ans<<endl;

    return 0;
}