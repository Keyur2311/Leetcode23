
class LRUCache {
public:
  int capacity = 0;
  list<pair<int, int>> l;
  unordered_map<int, list<pair<int, int>>::iterator> mp;

  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    auto itr = mp.find(key);
    if (itr == mp.end())
      return -1;
    l.splice(l.begin(), l, itr->second);
    return itr->second->second;
  }

  void put(int key, int value) {
    auto itr = mp.find(key);
    if (itr != mp.end()) {
      l.splice(l.begin(), l, itr->second);
      itr->second->second = value;
      return;
    }

    if ((int)mp.size() == capacity) {
      int k = l.back().first;
      l.pop_back();
      mp.erase(k);
    }

    l.emplace_front(key, value);
    mp[key] = l.begin();
    return;
  }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */