class Solution {
public:
    string sortSentence(string s) {
        int start = 0;
        vector<string> arr(10);
        string ans;
        for(int i=0; i<=s.size(); i++){
            if(s[i]== ' ' || i==s.size()){
                int index = s[i-1]-'0';
                string temp="";
                while(start<i-1){
                    temp += s[start];
                    start++;
                }
                arr[index-1] = temp;
                start = i+1;
            }
        }
        for(int i=0; i<10; i++){
            if(!arr[i].empty()){
                if(!ans.empty()){
                    ans += " ";
                }
                ans += arr[i];
            }
        }
        return ans;
    }
};