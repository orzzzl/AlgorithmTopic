class NumArray {
    vector<int> s;
    vector<int> v;
    int maxInd;
public:
    NumArray(vector<int> &nums) {
        int N = nums.size();
        v = vector<int> (N, 0);
        maxInd = N;
        s = vector<int> (maxInd + 1, 0);
        for (int i = 0; i < v.size(); i++) update(i, nums[i]);
    }



    void update(int ind, int val) {
        int i = ind + 1;
        int old_val = v[ind];
        while (i <= maxInd) {
            s[i] += val - old_val;
            i += i & -i;
          //  cerr << "update " << i << endl;
        }
        v[ind] = val;
    }

    int sumRange(int i, int j) {
        if (i == 0) return getSum(j);
        return getSum(j) - getSum(i - 1);
    }

    int getSum(int ind) {
        int ans = 0;
        int i = ind + 1;
        while (i > 0) {
            ans += s[i];
            i -= i & -i;
           // cerr << "get " << i << endl;
        }
        return ans;
    }
};
