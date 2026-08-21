class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[n-1]<target)
            return n;
        if(nums[0]>target)
            return 0;
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target){
                start = mid+1;
            }
            else 
                end = mid-1;
        }
        return start;
    }
};