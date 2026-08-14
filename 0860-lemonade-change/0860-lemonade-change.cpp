class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for(int i = 0; i < bills.size(); i++) {
            int rem = abs(5 - bills[i]);

            if(rem == 0) {
                five++;
            }
            
            else if(rem == 5) {  // $10
                if(five == 0)
                    return false;

                five--;
                ten++;
            }
            
            else {  // $20, need $15 change

                // Prefer $10 + $5
                if(ten > 0 && five > 0) {
                    ten--;
                    five--;
                }

                // Otherwise use three $5
                else if(five >= 3) {
                    five -= 3;
                }

                else {
                    return false;
                }
            }
        }

        return true;
    }
};