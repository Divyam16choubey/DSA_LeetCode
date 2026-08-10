class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        int flip = 0;

        for(int i=0; i<nums.size(); i++){
            if(!q.empty() && q.front()<i)
                q.pop();
            
            /*we have to flip only when there is 0, so when there is 1 and no. of flip(q.size() is
            odd we have to flip and for the case of 0 and no. of flips is even then we have to flip otherwise no flip required).*/
            if(q.size()%2 == nums[i]){
                if(i+k-1>=nums.size())
                    return -1;
                q.push(i+k-1);
                flip++;
            }
        }
        return flip;
    }
};
