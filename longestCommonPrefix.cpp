class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest = "";
        int letterIndx = 0;

        while (true) {
            char c = '\0';
            for (int i = 0; i < strs.size(); i += 1) {
                if (letterIndx >= strs[i].size()) {
                    return longest;
                }
                if (c == '\0') {
                    c = strs[i][letterIndx];
                } else if (strs[i][letterIndx] != c) {
                    return longest;
                }
            }
            longest += c;
            letterIndx += 1;
        }
    }
};
