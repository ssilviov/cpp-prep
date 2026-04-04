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
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size
capacity.  int get(int key) Return the value of the key if the key
exists, otherwise return -1.  void put(int key, int value) Update the
value of the key if the key exists. Otherwise, add the key-value pair
to the cache. If the number of keys exceeds the capacity from this
operation, evict the least recently used key.  The functions get and
put must each run in O(1) average time complexity.
 */

class LRUCache {
  using Pointer = list<int>::iterator;
public:
  LRUCache(int capacity) : size(capacity) {}
    
  int get(int key) {
    auto f = cache.find(key);
    if (f == cache.end()) {
      return -1;
    }
    auto& v = f->second;
    lru.splice(lru.begin(), lru, v.second);
    return v.first;
  }
    
  void put(int key, int value) {

    auto f = cache.find(key);
    if (f != cache.end()) {
      lru.splice(lru.begin(), lru, f->second.second);
      f->second = make_pair(value, lru.begin());
      return;
    }

    if (cache.size() == size) {
      cache.erase(lru.back());
      lru.pop_back();
    }
    lru.push_front(key);
    cache[key] = {value, lru.begin()};
  }

private:
  friend ostream& operator<<(ostream& o, const LRUCache& lru);
  unordered_map<int, pair<int, Pointer>> cache;
  list<int> lru;
  int size;
};

ostream& operator<<(ostream& o, const LRUCache& lru) {
  o << "{ ";
  for (auto [key, it] : lru.cache) {
    o << key << "=" << it.first << " ";

  }
  o << "}";
  return o;
}



int main() {
  LRUCache lRUCache(2);
  cout << lRUCache << endl;
  lRUCache.put(1, 1); // cache is {1=1}
  cout << lRUCache << endl;
  lRUCache.put(2, 2); // cache is {1=1, 2=2}
  cout << lRUCache << endl;
  lRUCache.get(1);    // return 1
  cout << lRUCache << endl;
  lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  cout << lRUCache << endl;
  lRUCache.get(2);    // returns -1 (not found)
  cout << lRUCache << endl;
  lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  cout << lRUCache << endl;
  lRUCache.get(1);    // return -1 (not found)
  cout << lRUCache << endl;
  lRUCache.get(3);    // return 3
  cout << lRUCache << endl;
  lRUCache.get(4);    // return 4
  cout << lRUCache << endl;
  return 0;
}
