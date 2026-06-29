class Solution {
public:
    int largestRectangleArea(vector<int>& hei) {
    int n = hei.size();
    stack<int>s; // store idex of top
    vector<int>right(n,0);
    vector<int>left(n,0);

    // first find right nearest element

    for(int i=n-1;i>=0;i--){
        while(!s.empty() && hei[i]<= hei[s.top()]){
            s.pop();
        }
        if(s.empty()){
            right[i] = n;
            s.push(i);
        }
        else{
            right[i] = s.top();
            s.push(i);
        }
    }
// first clear the stack

    while(!s.empty()){
    s.pop();
    }
    // now find left samller nearest element
    for(int i=0;i<n;i++){
        while(!s.empty() && hei[i]<= hei[s.top()]){
            s.pop();
        }
        if(s.empty()){
            left[i] = -1;
            s.push(i);
        }
        else{
            left[i] = s.top();
            s.push(i);
        }
    }

    // now calculate the max area

    int area = 0;
    for(int i=0;i<n;i++){
        int currarea = hei[i] * (right[i]-left[i]-1);
        area = max(currarea,area);
    }
    return area;
    }
};