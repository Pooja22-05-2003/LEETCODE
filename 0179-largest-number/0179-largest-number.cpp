class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        auto mycomparator=[](int &a, int &b)
        {
            string x=to_string(a);
            string y=to_string(b);
            
            return (x+y)>(y+x);
        };
        
        sort(nums.begin(),nums.end(),mycomparator);
        
        if(nums[0]==0) return "0";
        string res="";
        
        for(auto it:nums) res+=to_string(it);
        
        return res;
    }
};