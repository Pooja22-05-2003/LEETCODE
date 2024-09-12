class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
       
        vector<int>st;
        for(int i=0;i<arr.size();i++)
        {
            
            int el=arr[i];
            
            while(!st.empty() && st[st.size()-1]>0 && el<0)
            {
                int sum=st[st.size()-1]+el;
                if(sum>0)
                {
                    // means right side is more powerful so dont pop the topmost element
                    el=0;
                }
                else if(sum<0)
                {
                    // means left side is more powerful
                    st.pop_back();
                }
                else
                {
                    // both are powerful
                    el=0;
                    st.pop_back();
                }
                
               
            }
            if(el!=0) st.push_back(el);
        }
        return st;
        
        
    }
};