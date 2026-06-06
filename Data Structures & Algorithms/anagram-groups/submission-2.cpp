class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> vec;
        int index=0; // stores indexes for new anargams that aren't in the map yet
        std::unordered_map<std::string, int> seen;

        for (std::string s : strs) {
            int arr[26]={0};
            for (char c : s) {
                arr[c-'a']++;
            }
            // Transform array into a number to be able to use it as a key in the hash map.
            std:string num="";
            for (int i=0; i<26; i++) {
                num+=arr[i];
            }

            auto it = seen.find(num);
            if (it != seen.end()) {
                int vec_index = it->second;
                vec[vec_index].push_back(s);
            } else {
                seen[num]=index;
                std::vector<std::string> new_vec;
                new_vec.push_back(s);
                vec.push_back(new_vec);
                index++;
            }
        }
        return vec;
    }
};
