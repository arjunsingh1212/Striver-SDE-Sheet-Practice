/* https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/ */

class Solution{
public:
    int *findTwoElement(int *a, int n) {
        // code here
        
        int x_xor_y=0;
        for(int i=1;i<=n;i++) x_xor_y^=a[i-1]^i;
    
        //Getting right-most set bit
        int rsb=x_xor_y & (-x_xor_y);
        
        //separating x and y
        int x=0,y=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i-1]&rsb) x^=a[i-1];
            else y^=a[i-1];
            
            if(i&rsb) x^=i;
            else y^=i;
        }
        
        //checking which one of x and y is repeating
        for(int i=0;i<n;i++)
        {
            if(a[i]==y)
            {
                swap(x,y);
                break;
            }
            else if(a[i]==x) break;
        }
        
        int *arr=new int[2];
        arr[0]=x;
        arr[1]=y;
        return arr;
        
    }
};