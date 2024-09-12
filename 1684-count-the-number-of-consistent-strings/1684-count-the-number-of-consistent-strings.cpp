class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>mp;
        int cnt=0;
        for(auto el:allowed) mp[el]++;
        
        for(int i=0;i<words.size();i++)
        {
            bool found=true;
            string curr=words[i];
            for(int j=0;j<curr.size();j++)
            {
                char c=curr[j];
                if(mp.find(c)==mp.end())
                {
                    found=false;
                    break;
                }
            }
            
            if(found) cnt++;
        }
        
        return cnt;
    }
};