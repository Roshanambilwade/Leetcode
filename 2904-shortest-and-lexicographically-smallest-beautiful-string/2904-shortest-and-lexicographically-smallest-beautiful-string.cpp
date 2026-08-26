class Solution { 
public: 
    string shortestBeautifulSubstring(string s, int k) { 
        int slen = INT_MAX; 
        vector<string> ans; 
 
        int r = 0, l = 0; 
        int n = s.length(); 
        int currk = 0; 
        string anss = "";
 
        while(r < n){ 
            if(s[r] == '1'){ 
                currk++; 
            } 
            
            while(currk >= k){ 
                slen = min(slen, r - l + 1); 
                ans.push_back(s.substr(l, r - l + 1)); 
                
                if(s[l] == '1'){ 
                    currk--; 
                } 
                
                l++; 
            } 
            
            r++; 
        }
        
            for(string a : ans){
                if(a.length()==slen){
                    if(anss=="" || a<anss){
                        anss = a;
                    }
                }
            }
        
        
        
        return anss;
    } 
};