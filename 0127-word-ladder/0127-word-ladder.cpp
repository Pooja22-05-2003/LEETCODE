/*
Time Complexity: O(N * M * 26)

Where N = size of wordList Array and M = word length of words present in the wordList..

Note that, hashing operations in an unordered map takes O(1) time, but if you want to use map here, then the time complexity would increase by a factor of log(N) as hashing operations in a set take O(log(N)) time.

Space Complexity:  O( N ) { for creating an unordered map and copying all values from wordList into it }

Where N = size of wordList Array.

Amazon-41 , Facebook-13 , LinkedIn- 7, Microsoft-6, Qualtrics-6, Apple-5, Snapchat-4, Lyft-4
Adobe-4

*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord) return 0;
        unordered_map<string,int>mp;

        for(auto it : wordList) mp[it]++;

        queue<pair<string,int>>q;
        q.push({beginWord,1});
        mp.erase(beginWord);
        while(!q.empty())
        {   
            auto curr=q.front();
            string currString=curr.first;
            int t=curr.second;
            q.pop();
            
            if(currString==endWord) return t;
            
            for(int i=0;i<currString.size();i++)
            {
                string originalString=currString;
                
                for(char c='a';c<='z';c++)
                {
                    currString[i]=c;
                    if(mp.find(currString)!=mp.end())
                    {
                        mp.erase(currString);
                        q.push({currString,t+1});
                    }
                }
                currString=originalString;
            }
        }
        return 0;
    }
};