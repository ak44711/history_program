#include<vector>
#include<iostream>

using namespace std;

void backtrack(vector<vector<int> >& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.push_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
int main() {
	vector<vector<int> > res;
	int n = 3;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		v.push_back(i);
	}
	res = permute(v);
} 
