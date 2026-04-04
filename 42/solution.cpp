#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cassert>
#include <chrono>

using namespace std;

/** Given n non-negative integers representing an elevation map where
the width of each bar is 1, compute how much water it can trap after
raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1] Output: 6

Explanation: The above elevation map (black section) is represented by
array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water
(blue section) are being trapped.  Example 2:

Input: height = [4,2,0,3,2,5] Output: 9

Constraints:

n == height.length 1 <= n <= 2 * 104 0 <= height[i] <= 105 */

class Solution {
public:
  int trap(vector<int>& height){
    if (height.size() == 0) return 0;
    int res = 0;

    auto ltop = 0;
    auto rtop = 0;
    auto l = 0U;
    auto r = height.size() - 1;

    while (l < r) {
      ltop = std::max(height[l], ltop);
      rtop = std::max(height[r], rtop);

      if (ltop < rtop) {
	res += ltop - height[l];
	l++;
      } else {
	res += rtop - height[r];
	r--;
      }
    }
    return res;
  }
};


int main() {
  auto sol = Solution();
  vector<int> test{0,1,0,2,1,0,1,3,2,1,2,1};
  auto res = sol.trap(test);
  cout << res << endl;
  assert(sol.trap(test) == 6);
  return 0;
}
