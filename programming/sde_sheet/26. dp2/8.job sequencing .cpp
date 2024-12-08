struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    private:
        static bool compare(Job p, Job q) {
            return p.dead < q.dead; // Corrected to use . instead of ->
        }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, compare);
        int count = 1 ;
        int sum =0;
        priority_queue<int, vector<int>, greater<int>> minHeap;  
        minHeap.push(INT_MAX) ;       
        for(int i =0 ; i < n ; i++){
                if (arr[i].dead < count && minHeap.top() < arr[i].profit ){    
                    sum -= minHeap.top() ;
                    minHeap.pop() ;
                    sum += arr[i].profit ;
                    minHeap.push(arr[i].profit ) ;
                } 
                else if (arr[i].dead >= count){
                    sum += arr[i].profit ;
                    minHeap.push(arr[i].profit) ;
                    count ++  ;
                }
        }
        return {count-1 , sum } ;
        // your code here
    } 
};