class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string,string>mp;
        int n = k.size();
        for(int i=0;i<n;i++){
            mp[k[i][0]] = k[i][1];
        }
        string ans ="";

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                string curr = "";
                i++;
                while(s[i] != ')'){
                    
                    curr+=s[i];
                    i++;
                }
                if(mp.find(curr) != mp.end()){
                    ans+=mp[curr];
                }
                else{
                    ans+='?';
                }

            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};