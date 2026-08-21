class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cd, count = 0;
        
        for(int i=0; i<n; i++){
            if(count == 0){
                count = 1;
                cd = nums[i];
            }
            else{
                if(cd == nums[i])
                    count++;
                else
                    count--;
            }
        }
        return cd;
    }   
};