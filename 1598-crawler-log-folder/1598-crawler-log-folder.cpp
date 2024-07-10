class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth=0;
        
        for(auto it: logs)
        {
            if(it=="../" ) 
            {
                if(depth!=0)
                depth--;
                else depth=0;
            }
            else if(it=="./") depth=depth;
            else depth++;
        }
        
        return depth;
    }
};