// Problem Code: ARRPART

#include <iostream>
#include <vector>

using ll = long long;

class Solution {
public:
    std::vector<ll> partitionArray(std::vector<ll> &nums, int x) {
        int n = nums.size();

        std::vector<int> numsMax(n, -1);
        int idx = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < x) {
                numsMax[i] = idx;
            } else {
                idx = i;
            }
        }

        std::vector<std::vector<ll>> numsRes(n+1,
                                             std::vector<ll>(n+1, 0));
        numsRes[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (nums[i-1] >= x) {
                    numsRes[i][j] = ((j > 0? numsRes[i-1][j-1]: 0) + numsRes[i-1][j]) % 998244353;
                } else {
                    numsRes[i][j] = ((numsMax[i-1] >= 0 && j > 0? numsRes[numsMax[i-1]][j-1]: 0) + numsRes[i-1][j]) % 998244353;
                }
            }
        }

        std::vector<ll> res{};
        for (int i = 1; i <= n; ++i) {
            auto val = (numsRes[n][i] - numsRes[n-1][i]) % 998244353;
            res.push_back(val < 0? val + 998244353: val);
        }
        return res;
    }
};

int main() {
    Solution solution{};
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, x;
        std::cin >> n >> x;

        std::vector<ll> nums{};
        for (int j = 0; j < n; ++j) {
            int num;
            std::cin >> num;
            nums.push_back(num);
        }

        auto res = solution.partitionArray(nums, x);
        for (int j = 0; j < n - 1; ++j) {
            std::cout << res[j] << " ";
        }
        std::cout << res[n-1] << std::endl;
    }
    return 0;
}
