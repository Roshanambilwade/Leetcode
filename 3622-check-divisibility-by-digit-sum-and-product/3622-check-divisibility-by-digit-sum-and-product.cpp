class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0;
        int pro = 1;
        int num = n;
        while(num>0){
            int ld = num%10;
            sum+=ld;
            pro*=ld;
            num = num/10;
        }
        int tsum = sum+pro;
        
        return n%tsum ==0 ? true : false;
    }
};