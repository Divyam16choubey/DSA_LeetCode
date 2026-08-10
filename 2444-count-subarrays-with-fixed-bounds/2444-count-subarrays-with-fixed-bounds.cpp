class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count=0;
        int minI = -1;
        int maxI = -1;
        int invalid = -1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>maxK || nums[i]<minK)
                invalid = i;
            if(nums[i] == minK)
                minI = i;
            if(nums[i] == maxK)
                maxI = i;
            int st = min(minI, maxI);

            if(st>invalid)
                count+=st-invalid;

        }
        return count;
    }
};