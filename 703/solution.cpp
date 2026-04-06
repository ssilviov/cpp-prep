#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <cassert>
#include <chrono>

using namespace std;

/*
You are part of a university admissions office and need to keep track
of the kth highest test score from applicants in real-time. This helps
to determine cut-off marks for interviews and admissions dynamically
as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k,
maintains a stream of test scores and continuously returns the kth
highest test score after a new score has been submitted. More
specifically, we are looking for the kth highest score in the sorted
list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer
k and the stream of test scores nums.  int add(int val) Adds a new
test score val to the stream and returns the element representing the
kth largest element in the pool of test scores so far.  */

class KthLargest {
  priority_queue<int, vector<int>, greater<int>> queue;
  int k;

public:
  KthLargest(int k, vector<int>& nums): queue(nums.begin(), nums.end()), k(k){
    while (queue.size() > k) {
      queue.pop();
    }
  }
    
  int add(int val) {
    if (queue.size() == k && queue.top() > val) {
      return queue.top();
    }
    queue.push(val);
    if (queue.size() > k) {
      queue.pop();
    }
    return queue.top();
  }
};

int main() {
  vector<int> v{4, 5, 8, 2};
  KthLargest kthLargest(3, v);
  assert(kthLargest.add(3) == 4);
  assert(kthLargest.add(5) == 5);
  assert(kthLargest.add(10) == 5);
  assert(kthLargest.add(9) == 8);
  assert(kthLargest.add(4) == 8);
  return 0;
}
