class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<string> ans;
        string word = "";
        
     
        for (int i = 0; i <= sentence.size(); ++i) {
            if (i < sentence.size() && sentence[i] != ' ') {
                word += sentence[i];
            } 
            else {
                if (!word.empty()) {
                    string curr = "";
                    bool found = false;
                    for (int j = 0; j < word.size(); ++j) {
                        curr += word[j];
                        if (dict.find(curr) != dict.end()) {
                            ans.push_back(curr);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        ans.push_back(word);
                    }
                    word = "";
                }
            }
        }

     
        string res = "";
        for (int i = 0; i < ans.size(); ++i) {
            if (i > 0) res += " ";
            res += ans[i];
        }

        return res;
    }
};
