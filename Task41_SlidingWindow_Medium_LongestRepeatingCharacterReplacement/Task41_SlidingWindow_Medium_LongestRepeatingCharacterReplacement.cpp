#include <iostream>
#include <unordered_map>

class Solution {
public:
    static int characterReplacement(std::string s, int k) {
        int super_max = 0, left = 0, max = 0;
        std::unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            max = std::max(max, freq[s[i]]);
            while (i - left + 1 - max > k) {
                freq[s[left]]--;
                left++;
            }
            super_max = std::max(super_max, i - left + 1);
        }
        return super_max;
    }
};

int main()
{
    std::cout << Solution::characterReplacement("ABAB", 2);
}
