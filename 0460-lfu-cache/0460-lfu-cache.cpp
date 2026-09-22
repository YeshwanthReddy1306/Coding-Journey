#include <unordered_map>
#include <list>
#include <utility>

class LFUCache {
private:
    int capacity;
    int minFreq;
    // key -> {value, frequency}
    std::unordered_map<int, std::pair<int, int>> cache; 
    // freq -> list of keys (front = most recently used, back = least recently used)
    std::unordered_map<int, std::list<int>> freqMap; 
    // key -> iterator pointing to the key's position in freqMap[freq]
    std::unordered_map<int, std::list<int>::iterator> pos; 

    // Helper function to update the frequency of an accessed key
    void updateFreq(int key) {
        int freq = cache[key].second;
        
        // Remove key from its current frequency list in O(1)
        freqMap[freq].erase(pos[key]);
        
        // If we just emptied the list representing the minimum frequency, increment minFreq
        if (freqMap[freq].empty() && minFreq == freq) {
            minFreq++;
        }
        
        // Increment frequency for the key
        cache[key].second++;
        freq++;
        
        // Add key to the front of the new frequency list (most recently used)
        freqMap[freq].push_front(key);
        pos[key] = freqMap[freq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        // Update the use counter and move it to the new frequency list
        updateFreq(key);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (cache.find(key) != cache.end()) {
            // If the key is already present, update its value and use counter
            cache[key].first = value;
            updateFreq(key);
            return;
        }
        
        if (cache.size() == capacity) {
            // Evict the least frequently used key. If there is a tie, 
            // the back of the list represents the least recently used key.
            int evictKey = freqMap[minFreq].back();
            freqMap[minFreq].pop_back();
            cache.erase(evictKey);
            pos.erase(evictKey);
        }
        
        // Insert the new item with a use counter of 1
        cache[key] = {value, 1};
        freqMap[1].push_front(key);
        pos[key] = freqMap[1].begin();
        minFreq = 1;
    }
};