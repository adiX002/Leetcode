class Solution {
public:
    array<int, 256> generateHash(string s) {
        array<int, 256> hash = {0};

        for (int i = 0; i < s.length(); i++) {
            hash[s[i]]++;
        }

        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<std::array<int, 256>, vector<string>> mp;

        for (auto str : strs)   mp[generateHash(str)].push_back(str);

        for (auto str : mp) ans.push_back(str.second);

        return ans;
    }
};
