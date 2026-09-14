class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        // Rectangle 1 is completely left of Rectangle 2
        if (rec1[2] <= rec2[0]) return false;

        // Rectangle 2 is completely left of Rectangle 1
        if (rec2[2] <= rec1[0]) return false;

        // Rectangle 1 is completely below Rectangle 2
        if (rec1[3] <= rec2[1]) return false;

        // Rectangle 2 is completely below Rectangle 1
        if (rec2[3] <= rec1[1]) return false;

        // None of the four non-overlap cases happened
        return true;
    }
};