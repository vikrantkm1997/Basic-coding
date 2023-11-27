int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freqMap;
        unordered_map<int,int> firstOccurence;
        int n = nums.size();
        int minLen = INT_MIN;
        int minCnt = INT_MIN;
        for(int i=0;i<n;i++)
        {
            freqMap[nums[i]]++;
            if(firstOccurence.find(nums[i]) == firstOccurence.end())
              firstOccurence[nums[i]] = i;
            if(freqMap[nums[i]] > minCnt)
            {
                minLen = i - firstOccurence[nums[i]] + 1;
                minCnt = freqMap[nums[i]];
            }
            else if(minCnt == freqMap[nums[i]] && minLen > i - firstOccurence[nums[i]] + 1)
            {
                minLen = i - firstOccurence[nums[i]] + 1;
            }
        }
        return minLen;
    }
