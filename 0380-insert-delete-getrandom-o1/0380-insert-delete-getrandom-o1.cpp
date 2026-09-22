#include <vector>
#include <unordered_map>
#include <cstdlib>

class RandomizedSet {
private:
    std::vector<int> nums;
    std::unordered_map<int, int> valToIndex;

public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        nums.push_back(val);
        valToIndex[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            return false;
        }
        
        int idxToRemove = valToIndex[val];
        int lastElement = nums.back();
        
        nums[idxToRemove] = lastElement;
        
        valToIndex[lastElement] = idxToRemove;
        
        nums.pop_back();
        valToIndex.erase(val);
        
        return true;
    }
    
    int getRandom() {
        int randomIndex = std::rand() % nums.size();
        return nums[randomIndex];
    }
};