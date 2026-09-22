#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>

class RandomizedCollection {
private:
    std::vector<int> nums;
    std::unordered_map<int, std::unordered_set<int>> valToIndices;

public:
    RandomizedCollection() {}
    
    bool insert(int val) {
        bool isNew = valToIndices.find(val) == valToIndices.end() || valToIndices[val].empty();
        
        valToIndices[val].insert(nums.size());
        nums.push_back(val);
        
        return isNew;
    }
    
    bool remove(int val) {
        if (valToIndices.find(val) == valToIndices.end() || valToIndices[val].empty()) {
            return false;
        }
        
        int idxToRemove = *valToIndices[val].begin();
        
        valToIndices[val].erase(idxToRemove);
        
        int lastIdx = nums.size() - 1;
        int lastElement = nums.back();
    
        if (idxToRemove != lastIdx) {
            nums[idxToRemove] = lastElement;
            valToIndices[lastElement].erase(lastIdx);
            valToIndices[lastElement].insert(idxToRemove);
        }
        nums.pop_back();
        
        if (valToIndices[val].empty()) {
            valToIndices.erase(val);
        }
        
        return true;
    }
    
    int getRandom() {
        int randomIndex = std::rand() % nums.size();
        return nums[randomIndex];
    }
};