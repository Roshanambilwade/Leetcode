class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intv) {
        sort(intv.begin(),intv.end(),
        [](auto &a,auto &b){
            return a[1] < b[1];
        });
    int remove = 0;
    int currend = intv[0][1];
    for(int i=1;i<intv.size();i++){
        if(intv[i][0]<currend){
            remove++;
        }
        else{
             currend = intv[i][1];

        }
    }    
    return remove;
    }
};