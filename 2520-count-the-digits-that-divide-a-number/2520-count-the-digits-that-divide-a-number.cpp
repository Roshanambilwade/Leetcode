class Solution {
public:

    int countDigits(int num) {
        int ans = 0;
        int n = num;
        while(n>0){
            int ld = n%10;
            if(num%ld == 0) ans++;
            n = n/10;
        }
        return ans;
    }
};