class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int min) {
        int n=customers.size();
        // prefix will store the best ans till index i according to the original grumpy arr
        
        vector<int>pref(n,0);
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            {
                sum+=customers[i];
            }
            pref[i]=sum;
        }
        
        // Using the sliding window try to find the sum of the customer for window size min
        
        int i=0;
        int j=0;
        
        int sumtemp=0;
        int ans=INT_MIN;
        
        for(j=0;j<=min-2;j++)
        {
            sumtemp+=customers[j];
        }
        
        j=min-1;
        
        while(j<n)
        {
            
           sumtemp+=customers[j];
           int leftsum=0;
           int rightsum=0;
            
            if(i>=1)
            {
                leftsum=pref[i-1];
                
                
            }
            rightsum=pref[n-1]-pref[j];
            
            int currsum=sumtemp+leftsum+rightsum;
            ans=max(ans,currsum);
            
            sumtemp-=customers[i];
            i++;
            j++;
            
    
        }
        
        return ans;
    }
};