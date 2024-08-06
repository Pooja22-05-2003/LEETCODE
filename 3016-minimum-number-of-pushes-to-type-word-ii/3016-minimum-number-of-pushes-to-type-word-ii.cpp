class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length(), pushes = 0;
        vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            count[word[i] - 'a']++;
        }

        // Elements, which have less frequency in the word....we are giving it 4pushes....and so on.
        sort(count.begin(), count.end());

        for (int i = 25; i >= 18; i--) {
            pushes += count[i];
        }

        for (int i = 17; i >= 10; i--) {
            pushes += 2 * count[i];
        }

        for (int i = 9; i >= 2; i--) {
            pushes += 3 * count[i];
        }

        for (int i = 1; i >= 0; i--) {
            pushes += 4 * count[i];
        }

        return pushes;
    }
    
};