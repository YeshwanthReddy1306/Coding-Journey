#include <unordered_map>

class LRUCache {
private:
    // Doubly linked list node to store key-value pairs
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Helper function to remove an existing node from the linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Helper function to insert a node right after the head (most recently used position)
    void insertNode(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        // Dummy head and tail nodes to avoid edge cases during insertion and deletion
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            // Move the accessed node to the front (most recently used)
            removeNode(node);
            insertNode(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // If key exists, update the value and move it to the front
            Node* node = cache[key];
            removeNode(node);
            node->val = value;
            insertNode(node);
        } else {
            // If cache is at capacity, evict the least recently used item (tail's previous)
            if (cache.size() == capacity) {
                Node* lru = tail->prev;
                cache.erase(lru->key);
                removeNode(lru);
                delete lru; // Free memory
            }
            // Create a new node and insert it at the front
            Node* newNode = new Node(key, value);
            insertNode(newNode);
            cache[key] = newNode;
        }
    }
};