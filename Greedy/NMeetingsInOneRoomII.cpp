// Given the start and end time of each meeting in a form of an array. Return the array of conducted meetings index which can be done in the room.
// Meeting can be conducted if endtime of previous meeting is greater than starttime of current meeting. Maximize meetings conducted.
#include<iostream>
#include<vector>
#include<algorithm>
#define pi pair<int,pair<int,int>>
using namespace std;

static bool compare(pi &a, pi &b){
    return a.second.first < b.second.first;
}

vector<int> getMeetingIndices(vector<int> &start, vector<int> &end, int &n){
    vector<pi> meetings;
    vector<int> ans;

    for(int i=0; i<n; i++){
        meetings.push_back(make_pair(start[i], make_pair(end[i], i+1)));
    }

    sort(meetings.begin(), meetings.end(), compare);
    int meetingEnd = meetings[0].second.first;
    ans.push_back(meetings[0].second.second);

    for(int i=0; i<n; i++){
        if(meetings[i].first > meetingEnd){
            ans.push_back(meetings[i].second.second);
            meetingEnd = meetings[i].second.first;
        }
    }

    return ans;
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

    vector<int> ans = getMeetingIndices(start, end, n);

    cout<<"Meeting which can be conducted are : "<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}