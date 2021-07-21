class MyHashSet {
public:
    /** Initialize your data structure here. */
    struct hashList{
        hashList* next = nullptr;
        int key = -1;
    };
    hashList** ptrMap;
    
    MyHashSet() {
        ptrMap = new hashList*[10000];
        for(int i = 0; i < 10000; i++){
            ptrMap[i] = nullptr;
        }
    }
    
    void add(int key) {
        int index = key % 10000;
        hashList* target = ptrMap[index];

        if (target == nullptr) {//empty
            ptrMap[index] = new hashList;
            ptrMap[index]->key = key;
        }
        else {//collison
            while (target->next != nullptr && target->key != key) target = target->next;
            if (target->key != key) {
                target->next = new hashList;
                target = target->next;
                target->key = key;
            }
        }
    }
    
    void remove(int key) {
        int index = key % 10000;
        hashList* target = ptrMap[index];
        hashList* prev = nullptr;
        while(target != nullptr && target->key != key){
            prev = target;
            target = target->next;
        }
        if(target == nullptr) return;//nothing to do
        else{
            if(prev != nullptr) prev->next = target->next;
            else { ptrMap[index] = target->next; }
            delete target;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = key % 10000;
        hashList* target = ptrMap[index];
        
        while(target != nullptr && target->key != key) target = target->next;//find specific key
        if(target == nullptr) return false;
        else return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
