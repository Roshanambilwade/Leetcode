class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = 0;
        int pow = 1;
        long long s =0 ;
        while(n>0){
            
            int ld = n%10;
            if(ld == 0){
                n = n/10;
                continue;

            }
            s+=ld;
            num = num +(ld*pow);
            n = n/10;
            pow = pow*10;
        }
        long long ans = num*s;
        return ans;
    }
};