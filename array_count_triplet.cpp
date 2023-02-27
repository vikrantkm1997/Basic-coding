	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    int j,k,count=0;
	    sort(arr,arr+n);
	    int max;
	    max=arr[n-1];
	    int freq[max+1]={0};
	    for(int i=0;i<n;i++)
	    {
	    freq[arr[i]]=1;
	    }
	    for(int i=n-1;i>=0;i--)
	    {
	        int cur=arr[i];
	        for(int j=i-1;j>=0;j--)
	        {
	            int diff=cur-arr[j];
	            if(freq[diff]==1&&diff!=arr[j])
	            count++;
	        }
	    }
	    return count/2;
	}
