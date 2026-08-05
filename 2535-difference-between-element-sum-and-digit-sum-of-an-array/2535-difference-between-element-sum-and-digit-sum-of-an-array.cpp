class Solution {
public:
    int extract(int n){
        int sum = 0;
        while(n>0){
            int ld = n%10;
            sum+=ld;
            n = n/10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int esum = 0;
        int dsum = 0;
        for(int x:nums){
            esum+=x;
        }
        for(int y:nums){
            dsum+=extract(y);

        }
        return abs(esum-dsum);
    }
};