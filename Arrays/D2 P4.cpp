/* https://www.geeksforgeeks.org/counting-inversions/ */

long long int mergeInvCount(long long arr[],long long start,long long end)
{
    long long mid=(start+end)/2;
    long long i,j,k;
    long long temp[1000000];
    long long count=0;
    i=start,j=mid+1,k=start;
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            count+=mid-i+1;
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=end)
    {
        temp[k++]=arr[j++];
    }
    
    for(int i=start;i<=end;i++)
    {
        arr[i]=temp[i];
    }
    
    return count;
}

long long int mergeSortInvCount(long long arr[],long long start,long long end)
{
    if(start>=end) return 0;
    long long mid=(start+end)/2;
    long long x=mergeSortInvCount(arr,start,mid);
    long long y=mergeSortInvCount(arr,mid+1,end);
    long long z=mergeInvCount(arr,start,end);
    return x+y+z;
}



long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergeSortInvCount(arr,0,N-1);
}