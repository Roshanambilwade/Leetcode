class Solution {
public:
    int subtractProductAndSum(int n) {
        int num = n;
        int p = 1;
        int s = 0;
        while(num>0){
            int ld = num%10;
            p *=ld;
            s+=ld;
            num = num/10;
        }

        return p-s;
        
    }
};