class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        std::vector<int> o(26);

        for (int i = 0; i < order.size(); ++i) o[order[i] - 'a'] = i;
        for (auto& word : words) {
            for (char& c : word) {
                c = 'a' + o[c - 'a'];
            }
        }
        
        for (int i = 1; i < words.size(); ++i) {
            if (words[i - 1] > words[i]) return false;
        }

        return true;
    }
};