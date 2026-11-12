class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1,long long need2) {
        long long ans1 = (cost1*need1)+(cost2*need2);
        long long maxm = max(need1,need2);
        long long ans2 = maxm*costBoth;
        long long ans3 = 0;
        if(need1>need2){
            int diff = need1-need2;
            need1-=diff;
            ans3+=(cost1*diff);
            ans3+=(costBoth*need2);
        }
        else{
             int diff = need2-need1;
            need2-=diff;
            ans3+=(cost2*diff);
            ans3+=(costBoth*need1);
        }


        return min({ans1,ans2,ans3});
        
    }
};