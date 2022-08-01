//
//题目：给你一个字符串 s，找到 s 中最长的回文子串。

//解法（官方）：以每一个元素为中心进行拓展（比较左右是否相等），时间复杂度为o(n^2)，空间复杂度为o(1).
//该解法思路较好理解，要点在于区分奇数和偶数回文子串。


class Solution {
public:
    //输入左右起始点，不断向两边扩展，输出最大扩展边界。
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return { left + 1, right - 1 };
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            //奇数回文子串
            auto [left1, right1] = expandAroundCenter(s, i, i);
            //偶数回文子串
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
