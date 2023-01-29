class DListNode{
public:
    int key;
    int value;
    int freq;
    DListNode *prev, *next;
    
    DListNode(int k, int v){
        key = k;
        value = v;
        freq = 1;
        prev = next = nullptr;
    }
};

class DList{
public:
    DListNode* sentinel;
    int size;
    
    DList(){
        size = 0;
        sentinel = new DListNode(-1, -1);
        sentinel->prev = sentinel->next = sentinel;
    }
    
    void prepend(DListNode* node){
        node->next = sentinel->next;
        node->prev = sentinel;
        sentinel->next->prev = node;
        sentinel->next = node;
        ++size;
    }
    
    DListNode* pop(DListNode* node = nullptr){
        if(size == 0) return nullptr;
        if(node == nullptr) node = sentinel->prev;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        --size;
        return node;
    }
};

class LFUCache {
public:
    unordered_map<int, DListNode*> nodes;
    unordered_map<int, DList*> freqs;
    int capacity;
    int min_freq;
    
    LFUCache(int capacity) {
        this->capacity = capacity;
        min_freq = 0;
    }
    
    void _update(DListNode* node){
        if(freqs.find(node->freq) == freqs.end()){
            freqs[node->freq] = new DList();
        }
        if(freqs.find(node->freq+1) == freqs.end()){
            freqs[node->freq+1] = new DList();
        }
        freqs[node->freq]->pop(node);
        if(min_freq == node->freq && freqs[node->freq]->size == 0){
            ++min_freq;
        }
        
        ++node->freq;
        freqs[node->freq]->prepend(node);
    }
    
    int get(int key) {
        if(nodes.find(key) == nodes.end()){
            return -1;
        }
        
        DListNode* node = nodes[key];
        
        _update(node);
        
        return node->value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(nodes.find(key) != nodes.end()){
            DListNode* node = nodes[key];
            _update(node);
            node->value = value;
        }else{
            if(nodes.size() == capacity){
                if(freqs.find(min_freq) == freqs.end()){
                    freqs[min_freq] = new DList();
                }
                
                DListNode* node = freqs[min_freq]->pop();
                if(node){
                    nodes.erase(node->key);
                }
            }
            
            DListNode* node = new DListNode(key, value);
            nodes[key] = node;
            if(freqs.find(1) == freqs.end()) freqs[1] = new DList();
            freqs[1]->prepend(node);
            min_freq = 1;
        }
    }
};