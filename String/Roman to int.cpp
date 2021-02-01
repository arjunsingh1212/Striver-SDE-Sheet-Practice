/* https://leetcode.com/problems/roman-to-integer/ */

class Solution {
public:
    int convert(char a)
    {
        switch(a){
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
            
        }
        return 0;
    }
    int romanToInt(string s) {
        int res=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            int x=convert(s[i]);
            if(i<n-1)
            {
                    int y=convert(s[i+1]);
                    if(x<y)
                    {
                        res+=y-x;
                        i+=1;
                    }
                    else
                    {
                        res+=x;
                    }
            }
            else
            {
                res+=x;
            }
        }
        return res;
    }
};