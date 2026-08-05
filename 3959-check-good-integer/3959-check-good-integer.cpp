class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitTotal = 0;
        int squareTotal = 0;
        while(n>0){
            int cur = n%10;
            digitTotal += cur;
            squareTotal += cur*cur;
            n /= 10;
        }
        if((squareTotal-digitTotal) >= 50)
            return true;
        else
            return false;
    }
};