class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
           unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            vector<int> count(26, 0);

            for (char c : word) {
                count[c - 'a']++;
            }

            // Convert the frequency array into a string key
            string key;
            for (int frequency : count) {
                key += to_string(frequency) + "#";
            }

            groups[key].push_back(word);
        }

        vector<vector<string>> result;

        for (auto& [key, words] : groups) {
            result.push_back(words);
        }

        return result;
    }
};
