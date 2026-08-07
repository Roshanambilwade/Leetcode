class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int count = 1;
        sort(pairs.begin(),pairs.end(),
        [](auto &a, auto &b){
            return a[1]<b[1];
        });
       int currend = pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>currend){
                count++;
                 currend = pairs[i][1];

            }
           

            
        }
        return count;
    }
};