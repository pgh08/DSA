class Solution {
public:
    
    int PivotSearch(vector<int>& nums, int size){
        int s = 0; 
        int e = size-1;
        int mid = s + (e-s)/2;
        
        while(s<e){
            if(nums[mid] >= nums[0]){
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }
    
    int BinarySearch(vector<int>& nums, int s, int e, int key){
        int start = s;
        int end = e;
        int mid = s + (e-s)/2;
        
        while(s<=e){
            if(nums[mid] == key){
                return mid;
            }
            if(nums[mid] > key){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int pivot = PivotSearch(nums, size);
        if(target >= nums[pivot] && target <= nums[size-1]){
            return BinarySearch(nums, pivot, size-1, target);
        }
        else{
            return BinarySearch(nums, 0, pivot-1, target);
        }
    }
};