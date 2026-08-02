class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans=0;
        for(int i=0; i<=heights.size(); i++){
            while(!st.empty() && (i==heights.size() || heights[st.top()] > heights[i])){
                int h = heights[st.top()];
                st.pop();

                int l = st.empty()?-1:st.top();
                int w = i - l - 1;

                ans = max(ans, h*w);
            }
            st.push(i);
        }
        return ans;
    }
};