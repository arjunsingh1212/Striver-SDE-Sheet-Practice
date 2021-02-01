/* https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1 */

priority_queue<int> mx_heap;
priority_queue<int,vector<int>,greater<int>> mn_heap;

// Function to insert heap
void FindMedian::insertHeap(int &x)
{
	// Your code here
	if(mx_heap.empty() && mn_heap.empty())
	{
	    mx_heap.push(x);
	    return;
	}
	if (mx_heap.size() > mn_heap.size()) 
    { 
        if (x < median) 
        { 
            mn_heap.push(mx_heap.top()); 
            mx_heap.pop(); 
            mx_heap.push(x); 
        } 
        else
            mn_heap.push(x); 
    } 
    else if (mx_heap.size()==mn_heap.size()) 
    { 
        if (x < median) 
        { 
            mx_heap.push(x); 
        } 
        else
        { 
            mn_heap.push(x); 
        } 
    } 
    else
    { 
        if (x > median) 
        { 
            mx_heap.push(mn_heap.top()); 
            mn_heap.pop(); 
            mn_heap.push(x); 
        } 
        else
            mx_heap.push(x); 
    } 
}


// Function to return getMedian
double FindMedian::getMedian()
{
	// Your code here
	if(mx_heap.size()==mn_heap.size()) return median=((mx_heap.top()+mn_heap.top())/2.0);
	else
	{
	    if(mx_heap.size()>mn_heap.size()) return median=mx_heap.top();
	    if(mn_heap.size()>mx_heap.size()) return median=mn_heap.top();
	}
}