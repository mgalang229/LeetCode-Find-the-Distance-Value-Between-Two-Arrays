class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (int& x : arr1) {
            int lower = lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
            int upper = upper_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
            bool ok = true;
            if (lower >= 0 && lower < arr2.size()) {
                ok &= (abs(x - arr2[lower]) > d);
            }
            if (lower - 1 >= 0 && lower - 1 < arr2.size()) {
                ok &= (abs(x - arr2[lower-1]) > d);
            }
            if (upper >= 0 && upper < arr2.size()) {
                ok &= (abs(x - arr2[upper]) > d);
            }
            cnt += ok;
        }
        return cnt;
    }
};
