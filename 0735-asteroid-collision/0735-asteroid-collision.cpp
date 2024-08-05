class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        
        for(auto el:asteroids)
        {
            while(!st.empty() && st[st.size()-1]>0 && el<0)
            {
                int sum=st[st.size()-1]+el;
                
                if(sum>0)
                {
                    // means right asteroid is more powerful
                    el=0;
                }
                else if(sum<0)
                {
                    st.pop_back();
                }
                else
                {
                    // means both the left and right asteroid are of same strength
                    st.pop_back();
                    el=0;
                }
            }
            
            if(el!=0) st.push_back(el);
        }
        
        return st;
    }
};