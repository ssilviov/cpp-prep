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

/**
You are given an array of integers nums, there is a sliding window of
size k which is moving from the very left of the array to the very
right. You can only see the k numbers in the window. Each time the
sliding window moves right by one position.

Return the max in each sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

// Overload << for vector
template <typename S>
ostream& operator<<(ostream& os,
                    const vector<S>& vector) {
  
    // Printing all the elements using <<
    for (auto i : vector) 
        os << i << " ";
    return os;
}

class Solution {
public:
  vector<int> maxSlidingWindow_span(vector<int>& nums, int k) {
    vector<int> res;
    auto s = std::span(nums);

    for (auto i = 0U; i <= nums.size() - k; ++i) {
      auto ss = s.subspan(i, k);
      for (auto c : ss) {
	cout << c << " ";
      }
      cout << endl;
      res.push_back(*std::max_element(ss.begin(), ss.end()));
    }
    
    return res;
  } 

  vector<int> maxSlidingWindowQueue(vector<int>& nums, unsigned int k) {
    vector<int> res;
    auto q = deque<unsigned int>();

    for (auto i = 0U; i < nums.size(); ++i) {
      // Remove out of window indexes.
      while (!q.empty() && q.front() == i - k) {
	q.pop_front();
      }

      // Remove indexes for values less than current.
      while (!q.empty() && nums[q.back()] < nums[i]) {
	q.pop_back();
      }

      // add current index to the queue.
      q.push_back(i);

      // if we are after k, add the max to the result.
      if (i >= k - 1)  {
	res.push_back(nums[q.front()]);
      }
    }
    return res;
  }

};

// --- UNIT TEST HARNESS ---
struct TestCase {
  vector<int> input;
  int k;
  vector<int> output;
  string name;
};

void run_tests() {
    Solution sol;
    
    // Define your test cases here
    vector<TestCase> tests = {
      { {1,3,-1,-3,5,3,6,7}, 3, {3,3,5,5,6,7}, "simple case"},
    };

    int passed = 0;
    cout << "--- Running Unit Tests ---" << endl;

    for (auto& tc : tests) {
        auto start = chrono::high_resolution_clock::now();
        
        auto result = sol.maxSlidingWindowQueue(tc.input, tc.k);
	
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> elapsed = end - start;

        if (result == tc.output) {
            cout << "[PASS] " << left << setw(20) << tc.name 
                 << " | Time: " << setw(8) << elapsed.count() << " us" << endl;
            passed++;
        } else {
            cout << "[FAIL] " << left << setw(20) << tc.name 
                 << " | Expected: " << tc.output << " Got: " << result << endl;
        }
    }

    cout << "--------------------------" << endl;
    cout << "Summary: " << passed << "/" << tests.size() << " tests passed." << endl;
    
    // Hard exit if tests fail (useful for CI/CD or Makefiles)
    assert(passed == (int)tests.size()); 
}

int main() {
    run_tests();
    return 0;
}
