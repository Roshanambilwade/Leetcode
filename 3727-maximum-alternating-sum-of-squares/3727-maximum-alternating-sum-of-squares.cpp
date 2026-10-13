class Solution {
public:
    long long maxAlternatingSum(vector<int>& sq) {
        int n = sq.size();
        
        for(int i=0;i<n;i++){
           sq[i] = sq[i]*sq[i];
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