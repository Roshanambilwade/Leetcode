class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // int oddsum = n*n;
        // int evensum = n*(n+1);

        // return gcd(oddsum,evensum);

        // formula to calculate sum of first n odd numbers n = n*n;
        // formula to calculate sum of first n even numbers n = n*(n+1);

        int oddsum = n*n;
         int evensum = n*(n+1);

        // now find gcd using euledian algorithm
        int a = oddsum;
        int b = evensum;
        while(b!=0){
            int rem = a%b;
            a = b;
            b = rem;
        }
        return a;

    }
};