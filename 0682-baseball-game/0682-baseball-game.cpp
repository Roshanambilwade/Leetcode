class Solution {
public:
    int calPoints(vector<string>& op) {
        int ans = 0;
        int n = op.size();
        stack<int>s;
        for(int i =0;i<n;i++ ){
            if(op[i] == "+"){
                int first = s.top();
                s.pop();
                int second = s.top();
                s.push(first);
                int sum = first + second;
                s.push(sum);
                ans += sum;
            }
            else if(op[i] == "D"){
                int x = 2*s.top();
                ans+=x;
                s.push(x);
            }
            else if(op[i]=="C"){
                ans-= s.top();
                s.pop();
            }
            else{
                ans+=stoi(op[i]);
                s.push(stoi(op[i]));

            }

            
        }
        return ans;
    }
};