/* Design and implement a data structure for Least Recently Used (LRU) cache. 
 * It should support the following operations: get and put.
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present. 
 * When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 * The cache is initialized with a positive capacity.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 */

class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {}

    int get(int key) {
        int value = -1;
        if (pos_.find(key) != pos_.end()) {
            value = pos_[key]->second;
            put(key,value);
        }
        return value;
    }

    void put(int key, int value) {
        if (pos_.find(key) != pos_.end()) {
            nodes_.erase(pos_[key]);
            pos_.erase(key);
        } else if (nodes_.size() >= capacity_){
            int last = nodes_.back().first;
            nodes_.erase(pos_[last]);
            pos_.erase(last);
        }
        nodes_.push_front({key,value});
        pos_[key] = nodes_.begin();
    }
private:
    int capacity_;
    list<pair<int,int>> nodes_;
    unordered_map<int, list<pair<int,int>>::iterator> pos_;
};

