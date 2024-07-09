/*
Google
4
Amazon
3
Apple
2

*/

class Solution {
public:
        void nextSmallerLeft( vector<int>&nsl, vector<int>arr)
    {
        stack<int>st;
        
        for(int i=0;i<arr.size();i++)
        {
            int el=arr[i];
            
            while(!st.empty() && arr[st.top()]>=el) st.pop(); //⭐missed equal to in both nsl and nsr
            
            if(st.empty()) nsl[i]=-1;
            else nsl[i]=st.top();
            st.push(i);
        }
    }
    
    void nextSmallerRight(vector<int>&nsr, vector<int>arr)
    {
        stack<int>st;
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            int el=arr[i];
            
            while(!st.empty() && arr[st.top()]>=el) st.pop();
            
            if(st.empty()) nsr[i]=arr.size();
            else nsr[i]=st.top();
            st.push(i);
        }
    }
    int MAH(vector<int>& height) {
        int n=height.size();
        int maxarea=0;
        if(n==1) return height[0]*1;
        
        vector<int>nsl(n,-1); // nsl=next smaller left
        vector<int>nsr(n,n); // nsr=next smaller right
        
        nextSmallerLeft(nsl,height);
        nextSmallerRight(nsr,height);
        for(int i=0;i<height.size();i++)
        {
            int el=height[i];         
            
            int smallerleft=nsl[i];
            int smallerright=nsr[i];
           
            int area=(smallerright-smallerleft-1)*height[i];
            maxarea=max(maxarea,area);
        }
        
        
        return maxarea;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m);
        for(int i = 0; i<m; i++) {
            height[i] = (matrix[0][i]=='1')?1:0;
        }
        int maxA = MAH(height);
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            maxA = max(maxA, MAH(height));
        }
        return maxA;
    
    }
};