class Node{
    public:
    int key;
    int val;
    Node*next;
    Node*prev;

    Node(int k,int v){
        key = k;
        val = v;
        next = prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*>mp;
     int limit;
     Node* head;
     Node* tail;

     void addnode(Node* newnode){
        Node*oldhead = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = oldhead;
        oldhead->prev = newnode;
     }

     void delnode(Node*lastnode){
        Node*prev = lastnode->prev;
        Node*next = lastnode->next;
        prev->next = next;
        next->prev = prev;
     }
    LRUCache(int capacity) {
        limit = capacity;
         head = new Node(-1,-1);
         tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;      

    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        Node*currnode = mp[key];
        delnode(currnode);
        
        addnode(currnode);
        
        return currnode->val;
        
        
    }
    
    void put(int key, int value) {
        Node*newnode = new Node(key,value);
        if(mp.find(key) != mp.end()){ // key exist
            Node* del = mp[key]; // give that existance key
            mp.erase(key);
            delnode(del);
            addnode(newnode);
            mp[key] = newnode;
            return;
        }

        if( mp.size() < limit){
            addnode(newnode);
            mp[key] = newnode;
        }
        else{
             mp.erase(tail->prev->key);
            delnode(tail->prev);
           
            addnode(newnode);
            mp[key] = newnode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */