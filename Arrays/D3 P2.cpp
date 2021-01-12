/* https://leetcode.com/problems/powx-n/ */

class Solution {
public:
    double pow(double x,int n)
    {
        double res=1;
        while(n)
        {
            if(n&1)
            {
                res=res*x;
            }
            n=n/2;
            x=x*x;
        }
        return res;
    }
    double myPow(double x, int n) {
        double ans=0;
        if(n==0) return 1.0;
        else if(n<0)
        {
            if(n==INT_MIN)
            {
                int posn=-1 * (n+1);
                ans=1/(pow(x,posn)*x);
            }
            else
            {
                int posn=-n;
                ans=1/pow(x,posn);
            }
        }
        else
        {
            ans=pow(x,n);
        }
        return ans;
    }
};