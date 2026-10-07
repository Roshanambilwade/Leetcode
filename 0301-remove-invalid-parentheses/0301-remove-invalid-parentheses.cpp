class Solution {
public:
    set<string>ans;

    void solve(string &s,int lr,int rr,int b,string curr,int i){
        // End of string
        if (i == s.length()) {
            if (lr== 0 && rr == 0 && b == 0) {
                ans.insert(curr);
            }
            return;
        }

        char c = s[i];
        
        if(c=='('){
            // exclude
            if(lr>0){
                solve(s,lr-1,rr,b,curr,i+1);
            }
            // include
            solve(s,lr,rr,b+1,curr+c,i+1);
        }
        else if(c==')'){
            //exclude
            if(rr>0){
                solve(s,lr,rr-1,b,curr,i+1);
            }
            // include
            if(b>0){
                solve(s,lr,rr,b-1,curr+c,i+1);
            }
            


            
        }else{
            solve(s,lr,rr,b,curr+c,i+1);
            }
        }

    
    

    vector<string> removeInvalidParentheses(string s) {
        int leftrem =0;
        int rightrem=0;
        for(char c:s){
            if(c=='('){
                leftrem++;
            }
            else if(c==')'){
                if(leftrem>0){
                    leftrem--;
                }else{
                    rightrem++;
                }
               
            }
        }
        int balance =0;
        string curr = "";

        solve(s,leftrem,rightrem,balance,curr,0);

        return vector<string>(ans.begin(), ans.end());
        
    }
};