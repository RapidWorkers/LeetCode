class MyHashMap {
    struct hashList{
        hashList* next = nullptr;
        int key = -1;
        int value = -1;
    };
    
public:
    /** Initialize your data structure here. */
    hashList** ptrMap;
    MyHashMap() {
        ptrMap = new hashList*[10000];
        for(int i = 0; i < 10000; i++){
            ptrMap[i] = nullptr;
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % 10000;
        hashList* target = ptrMap[index];

        if (target == nullptr) {//empty
            ptrMap[index] = new hashList;
            ptrMap[index]->key = key;
            ptrMap[index]->value = value;
        }
        else {//collison
            while (target->next != nullptr && target->key != key) target = target->next;
            if (target->key == key) target->value = value;//update
            else {
                target->next = new hashList;
                target = target->next;
                target->key = key;
                target->value = value;
            }
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % 10000;
        hashList* target = ptrMap[index];
        
        while(target != nullptr && target->key != key) target = target->next;//find specific key
        if(target == nullptr) return -1;
        else return target->value;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
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
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
