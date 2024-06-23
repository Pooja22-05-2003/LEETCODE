class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        bool ans=false;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            for(int j=i+1;j<n;j++)
            {
                int y=nums[j];
                int z=x|y;
                   // cout<<"x:"<<x<<" y:"<<y<<" z:"<<z<<" op:"<<(((z>>1)&1)==0)<<endl;
                if(((z&1)==0)) return true;
              
            }
        }
        
        return false;
    }
};