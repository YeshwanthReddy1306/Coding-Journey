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
        // Return true if the value is not present in the collection
        bool isNew = valToIndices.find(val) == valToIndices.end() || valToIndices[val].empty();
        
        // Add the new index to the set for this value
        valToIndices[val].insert(nums.size());
        // Append the value to the array
        nums.push_back(val);
        
        return isNew;
    }
    
    bool remove(int val) {
        // If the value doesn't exist, return false
        if (valToIndices.find(val) == valToIndices.end() || valToIndices[val].empty()) {
            return false;
        }
        
        // Get one of the indices where this value is stored
        int idxToRemove = *valToIndices[val].begin();
        
        // Remove that index from the value's set
        valToIndices[val].erase(idxToRemove);
        
        // Get information about the last element in the vector
        int lastIdx = nums.size() - 1;
        int lastElement = nums.back();
        
        // If the element to remove is not already the last element, swap them
        if (idxToRemove != lastIdx) {
            nums[idxToRemove] = lastElement;
            // Update the index set of the last element to reflect its new position
            valToIndices[lastElement].erase(lastIdx);
            valToIndices[lastElement].insert(idxToRemove);
        }
        
        // Remove the target element from the back of the vector
        nums.pop_back();
        
        // Optional cleanup: remove the key from the map if it has no more indices
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