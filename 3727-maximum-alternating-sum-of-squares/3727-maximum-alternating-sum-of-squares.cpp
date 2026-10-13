class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>sq(n);
        for(int i=0;i<n;i++){
           sq[i] = nums[i]*nums[i];
        }
        sort(sq.begin(),sq.end());

        int i=0,j=n-1;
        long long ans = 0;
        if(n%2==0){
              while(i<=j){
            ans+=sq[j]-sq[i];
            i++;
            j--;
        }
        }
        else{
               while(i<=j){
            ans+=sq[j]-sq[i];
            i++;
            j--;
        }
        ans+=sq[n/2];
        }
      
        return ans;

    }
};