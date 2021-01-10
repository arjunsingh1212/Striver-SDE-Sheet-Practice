/* https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/ */

void merge(int arr1[], int arr2[], int n, int m) 
{ 
    // code here 
    int gap=ceil((float)(n+m)/(float)(2));
    while(1)
    {
        int ptr1=0, ptr2=ptr1+gap;
        int c1=1;
        while(ptr2<(m+n))
        {
            int *v1,*v2;
            if(ptr1>=n) v1=&arr2[ptr1-n];
            else v1=&arr1[ptr1];
            
            if(ptr2>=n) v2=&arr2[ptr2-n];
            else v2=&arr1[ptr2];
            
            if((*v1) > (*v2)) 
            {
                int temp=*v1;
                *v1=*v2;
                *v2=temp;
            }
            
            ptr1++;
            ptr2++;
        }
        if(gap==1) break;
        gap=ceil((float)(gap)/(float)(2));
    }
} 