// TC=O(2*n)
// SC=O(1)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        
        for(auto el:asteroids)
        {
            
            while(!st.empty() && st[st.size()-1]>0 && el<0) // collision will only happen if the current esteroid is moving left and the topmost element of the stack is moving right ----> <----
                        
            {
                 int sum=el+st[st.size()-1];
                 if(sum>0)
                 {
                     // means the right asteroid is more powerful
                     // do nothing
                     el=0;
                 }
                else if(sum<0)
                {
                    // means the left is more poweful and it will kill right , so st.pop
                    st.pop_back();                   
                    
                }
                else
                {
                    // equal
                    st.pop_back();
                    el=0;
                }
                
                    
            }
            
           if(el!=0) st.push_back(el);
        }
        
        return st;
       
    }
};