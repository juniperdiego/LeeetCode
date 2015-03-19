
// LeetCode, Subsets
// λ�����������ѣ�ʱ�临�Ӷ� O(2^n)���ռ临�Ӷ� O(n)
class Solution {
    public:
        vector<vector<int> > subsets(vector<int> &S) {
            sort(S.begin(), S.end()); // ���Ҫ������
            vector<vector<int> > result;
            vector<bool> selected(S.size(), false);
            subsets(S, selected, 0, result);
            return result;
        }
    private:
        static void subsets(const vector<int> &S, vector<bool> &selected, int step,
                vector<vector<int> > &result) {
            if (step == S.size()) {
                vector<int> subset;
                for (int i = 0; i < S.size(); i++) {
                    if (selected[i]) subset.push_back(S[i]);
                }
                result.push_back(subset);
                return;
            }
            // ��ѡ S[step]
            selected[step] = false;
            subsets(S, selected, step + 1, result);
            // ѡ S[step]
            selected[step] = true;
            subsets(S, selected, step + 1, result);
        }
};
