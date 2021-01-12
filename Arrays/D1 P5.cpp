/* https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/ */

int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int mxi=arr[0];
    int mxsf=arr[0];
    
    for(int i=1;i<n;i++)
    {
        if(mxi<0) mxi=0;
        mxi+=arr[i];
        if(mxi>mxsf) mxsf=mxi;
    }
    return mxsf;
    
}