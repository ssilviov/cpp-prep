#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k): data(k), capacity(k){}
    
    bool enQueue(int value) {
      if (isFull()) {
	return false;
      }
      data[tail] = value;
      count++;
      tail++;
      tail %= capacity;
      return true;
    }
    
    bool deQueue() {
      if (isEmpty()) {
	return false;
      }
      head++;  
      head %= capacity;
      count--;
      return true;
    }
    
    int Front() {
      if (isEmpty()) return -1; 
      return data[head];
    }
    
    int Rear() {
      if (isEmpty()) return -1; 
      return data[(tail + capacity - 1) % capacity];
    }
    
    bool isEmpty() {
      return count == 0;
    }
    
    bool isFull() {
      return count == capacity;
    }

private:
  std::vector<int> data;
  int head = 0;
  int tail = 0;
  int count = 0;
  int capacity = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {

  MyCircularQueue myCircularQueue(3);
  cout << "creation" << endl;

  assert(myCircularQueue.enQueue(1));
  cout << "adding 1" << endl;
  assert(myCircularQueue.enQueue(2));
  cout << "adding 2" << endl;
  assert(myCircularQueue.enQueue(3));
  cout << "adding 3" << endl;
  assert(myCircularQueue.enQueue(4) == false);
  cout << "adding 4 but failed" << endl;
  assert(myCircularQueue.Rear() == 3);
  cout << "rear == 3" << endl;
  assert(myCircularQueue.isFull());
  cout << "isFull" << endl;
  assert(myCircularQueue.deQueue());
  cout << "deQueue" << endl;
  assert(myCircularQueue.enQueue(4));
  cout << "adding 4" << endl;
  assert(myCircularQueue.Rear() == 4);
  cout << "rear == 4" << endl;
  return 0;
}
