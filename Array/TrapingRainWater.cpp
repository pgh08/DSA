// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.
/* Approach :
   Using 2 pointer :
            --> Use leftMax and rightMax to store the maximum length of the bars.
            --> If these maximum bar is less than current bar then assign current bar to maximum bars.
            --> If these maximum bar is greater than current bar then we can store (leftmax/rightMax - currentBar) amount of water.
            --> Iterate left and right pointer of the array.
            --> Time Complexity : O(n), Space Complexity : O(1).
*/
#include<iostream>
using namespace std;

int getWaterCount(int *height, int &n){
    if(n <= 2){
        return 0;
    }

    int leftMax = height[0], rightMax = height[n-1];
    int left = 1, right = n-2;
    int water = 0;

    while(left <= right){
        if(leftMax < rightMax){
            if(height[left] > leftMax){
                leftMax = height[left];
            }
            else{
                water += leftMax - height[left];
            }
            left++;
        }
        else{
            if(height[right] > rightMax){
                rightMax = height[right];
            }
            else{
                water += rightMax - height[right];
            }
            right--;
        }
    }
    
    return water;
}

int main()
{
    int n;
    cout<<"Enter the size of elevation map"<<endl;
    cin>>n; // 12.

    int *height = new int[n];
    cout<<"Enter the height of the bars"<<endl;
    for(int i=0; i<n; i++){
        cin>>height[i]; // 0 1 0 2 1 0 1 3 2 1 2 1.
    }

    int water = getWaterCount(height, n);

    cout<<"Amount of water which can be stored is : "<<water<<endl; // 6.

    delete []height;

    return 0;
}