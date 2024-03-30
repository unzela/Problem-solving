// “Design a data structure that follows the constraints of Least Recently Used
// (LRU) cache”.
// Implement the LRUCache class:

// LRUCache(int capacity) we need to initialize the LRU cache with positive size
// capacity. int get(int key) returns the value of the key if the key exists,
// otherwise return -1. Void put(int key,int value), Update the value of the key
// if the key exists. Otherwise, add the key-value pair to the cache.if the
// number of keys exceeds the capacity from this operation, evict the least
// recently used key. The functions get and put must each run in O(1) average
// time complexity.

// TC-O(N)
// SC-O(1)
#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
  class Node {
  public:
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int _key, int _value) {
      key = _key;
      value = _value;
    }
  };

  Node *head = new Node(-1, -1);
  Node *tail = new Node(-1, -1);

  int capacity;
  unordered_map<int, Node *> mpp;

  LRUCache(int cap) {
    capacity = cap;
    head->next = tail;
    tail->prev = head;
  }

  void addNode(Node *newNode) {
    Node *temp = head->next;
    newNode->next = temp;
    newNode->prev = head;
    head->next = newNode;
    temp->prev = newNode;
  }

  void deleteNode(Node *delNode) {
    Node *delPrev = delNode->prev;
    Node *delNext = delNode->next;
    delPrev->next = delNext;
    delNext->prev = delPrev;
  }

  int get(int key_) {
    if (mpp.find(key_) != mpp.end()) {
      Node *resNode = mpp[key_];
      int res = resNode->value;
      mpp.erase(key_);
      deleteNode(resNode);
      addNode(resNode);
      mpp[key_] = head->next;
      return res;
    }
    return -1;
  }

  void put(int key_, int value) {
    if (mpp.find(key_) != mpp.end()) {
      Node *existingNode = mpp[key_];
      mpp.erase(key_);
      deleteNode(existingNode);
    }
    if (mpp.size() == capacity) {
      mpp.erase(tail->prev->key);
      deleteNode(tail->prev);
    }
  }
};

int main() {
  LRUCache obj(2);
  obj.put(1, 1);
  obj.put(2, 2);
  cout << obj.get(1) << endl; // returns 1
  obj.put(3, 3);              // evicts key 2
  cout << obj.get(2) << endl; // returns -1 (not found)
  obj.put(4, 4);              // evicts key 1
  cout << obj.get(1) << endl; // returns -1 (not found)
  cout << obj.get(3) << endl; // returns 3
  cout << obj.get(4) << endl; // returns 4
  return 0;
}