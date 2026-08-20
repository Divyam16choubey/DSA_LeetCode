class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        if(x<0)
            return 0;
        
        long long num=0;
        while(x>0){
            num = (num*10) + (x%10);
            x = x/10;
        }
        if(num==n)
            return 1;
        else
            return 0;
    }
};