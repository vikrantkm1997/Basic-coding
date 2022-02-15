//Minimum cost to combine n ropes
long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        stack<long long>st;
        for(long long i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        long long ans=0;
        while(pq.size()!=1)
        {
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            ans+=a+b;
           
            pq.push(a+b);
        }
        return ans;
    }