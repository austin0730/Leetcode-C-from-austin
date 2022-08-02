
//题目：给定一个三角形 triangle ，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

//解法：经典动态规划+滑动窗口
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row - 1].size();
        //注意，这里+1是为了计算最后一行时最后一个数不会溢出。
        vector<int> path(col + 1, 0);
        for (int j = row - 1; j >= 0; j--) {
            int len = triangle[j].size();
            for (int i = 0; i < len; i++) {
                path[i] = triangle[j][i] + min(path[i], path[i + 1]);
            }
        }
        return path[0];
    }
};