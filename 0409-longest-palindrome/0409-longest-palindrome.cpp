class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        unordered_map<char, int> freq;
        for(auto x: s)
            freq[x]++;
        
        bool isOdd = false;
        //lower case
        for(int i=0; i<26; i++){
            char ch = 'a'+i;
            if(freq[ch]%2==0)
                ans += freq[ch];
            else{
                ans += freq[ch]-1;
                isOdd = true;
            }
        }
        //upper case
        for(int i=0; i<26; i++){
            char ch = 'A'+i;
            if(freq[ch]%2==0)
                ans += freq[ch];
            else{
                ans += freq[ch]-1;
                isOdd = true;
            }
        }
        if(isOdd)
            return ans+1;
        else
            return ans;
    }
};