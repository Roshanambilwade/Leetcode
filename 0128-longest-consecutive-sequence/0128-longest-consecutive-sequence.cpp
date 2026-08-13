class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int start;
        int mx = 0;
        int len = 0;
        
        unordered_set<int>s(nums.begin(),nums.end());
        for(int x:s){
            if(s.find(x-1) == s.end()){
                start = x;
                 len = 1;
            }
            
            while(s.find(start + 1) != s.end()){
                start++;
                len++;
            }
            mx = max(mx,len);
        }
        return mx;
    }
};