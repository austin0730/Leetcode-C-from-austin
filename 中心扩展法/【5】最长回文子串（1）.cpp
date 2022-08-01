//
//��Ŀ������һ���ַ��� s���ҵ� s ����Ļ����Ӵ���

//�ⷨ���ٷ�������ÿһ��Ԫ��Ϊ���Ľ�����չ���Ƚ������Ƿ���ȣ���ʱ�临�Ӷ�Ϊo(n^2)���ռ临�Ӷ�Ϊo(1).
//�ýⷨ˼·�Ϻ���⣬Ҫ����������������ż�������Ӵ���


class Solution {
public:
    //����������ʼ�㣬������������չ����������չ�߽硣
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
            //���������Ӵ�
            auto [left1, right1] = expandAroundCenter(s, i, i);
            //ż�������Ӵ�
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
