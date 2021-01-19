/* https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1 */

class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int low=0,high=n-1;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(mid%2==0)
            {
                if(arr[mid]==arr[mid+1])
                {
                    low=mid+2;
                }
                else
                {
                    high=mid;
                }
            }
            else
            {
                if(arr[mid]==arr[mid-1])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid;
                }
            }
        }
        return arr[low];
    }
};