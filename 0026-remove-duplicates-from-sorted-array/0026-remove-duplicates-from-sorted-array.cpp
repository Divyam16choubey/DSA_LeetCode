class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int first=0;
        for(int second =1; second<n; second++){
            if(nums[first]!=nums[second]){
                first++;
                nums[first] = nums[second];
            }
        }
        return first+1;
    }
};