
//��Ŀ������һ�������� triangle ���ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ����ڵĽ�� ������ָ���� �±� �� ��һ�����±� ��ͬ���ߵ��� ��һ�����±� + 1 ��������㡣Ҳ����˵�������λ�ڵ�ǰ�е��±� i ����ô��һ�������ƶ�����һ�е��±� i �� i + 1 ��

//�ⷨ�����䶯̬�滮+��������
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row - 1].size();
        //ע�⣬����+1��Ϊ�˼������һ��ʱ���һ�������������
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