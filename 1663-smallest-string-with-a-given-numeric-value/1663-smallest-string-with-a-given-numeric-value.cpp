class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        for(int i=1;i<=n;i++){
            ans+="a";
        }
        
        int rem = k-n;
        int i = n-1;
        while(rem){
            if(ans[i]=='z'){
                i--;
            }
           ans[i]++;
           rem--;



        }
        return ans;
    }
};