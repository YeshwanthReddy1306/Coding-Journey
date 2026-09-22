#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

class AllOne {
private:
    struct Bucket {
        int count;
        unordered_set<string> keys;
    };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> keyToBucket;

public:
    AllOne() {}
    
    void inc(string key) {
        if (keyToBucket.find(key) == keyToBucket.end()) {
            if (buckets.empty() || buckets.front().count != 1) {
                buckets.push_front({1, {key}});
            } else {
                buckets.front().keys.insert(key);
            }
            keyToBucket[key] = buckets.begin();
        } else {
            auto currBucket = keyToBucket[key];
            auto nextBucket = next(currBucket);
            
            if (nextBucket == buckets.end() || nextBucket->count != currBucket->count + 1) {
                nextBucket = buckets.insert(nextBucket, {currBucket->count + 1, {}});
            }
            nextBucket->keys.insert(key);
            keyToBucket[key] = nextBucket;
            
            currBucket->keys.erase(key);
            if (currBucket->keys.empty()) {
                buckets.erase(currBucket);
            }
        }
    }
    
    void dec(string key) {
        auto currBucket = keyToBucket[key];
        
        if (currBucket->count == 1) {
            keyToBucket.erase(key);
        } else {
            auto prevBucket = currBucket;
            if (currBucket == buckets.begin() || prev(currBucket)->count != currBucket->count - 1) {
                prevBucket = buckets.insert(currBucket, {currBucket->count - 1, {}});
            } else {
                prevBucket = prev(currBucket);
            }
            prevBucket->keys.insert(key);
            keyToBucket[key] = prevBucket;
        }
        
        currBucket->keys.erase(key);
        if (currBucket->keys.empty()) {
            buckets.erase(currBucket);
        }
    }
    
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.back().keys.begin());
    }
    
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.front().keys.begin());
    }
};