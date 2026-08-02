class Solution {
public:
    int maxArea(vector<int> &height){
        int n = height.size();
        int index;
        int ans = 0;
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && height[st.top()] > height[i]){
                index = st.top();
                st.pop();

                if(!st.empty())
                    ans = max(ans, height[index] * (i-st.top()-1));
                else
                    ans = max(ans, height[index] * i);
            }
            st.push(i);
        }
        while(!st.empty()){
            index = st.top();
            st.pop();
            if(!st.empty())
                ans = max(ans, height[index] * (n-st.top()-1));
            else
                ans = max(ans, height[index]*n);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> height(col, 0);
        int ans = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            ans = max(ans, maxArea(height));
        }
        return ans;
    }
};