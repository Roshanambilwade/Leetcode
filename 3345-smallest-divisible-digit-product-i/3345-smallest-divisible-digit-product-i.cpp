class Solution {
public:
    int smallestNumber(int n, int t) {
       int original = n;
      
       while(true){
          n = original;
         int ans = 1;
        while(n>0){
            int ld = n%10;
            ans*=ld;
            n = n/10;

        }
        if(ans % t==0){
            return original;
        }
        original++;
       }
       return -1;
    }
};