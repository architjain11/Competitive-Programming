class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* prev;
        node* next;

        node(int key, int val) {
            this->key=key;
            this->val=val;
        }
    };

    node* head=new node(-1, -1);
    node* tail=new node(-1, -1);
    int cap;
    unordered_map<int, node*> mp;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void add(node* newnode) {
        node* tmp=head->next;
        newnode->next=tmp;
        newnode->prev=head;

        head->next=newnode;
        tmp->prev=newnode;
    }
    
    void dlt(node* delnode) {
        node* prevTmp=delnode->prev;
        node* nextTmp=delnode->next;

        prevTmp->next=nextTmp;
        nextTmp->prev=prevTmp;
    }

    int get(int key) {
        if(mp.count(key)) {
            node* res=mp[key];
            int ans=res->val;
            
            mp.erase(key);
            dlt(res);
            add(res);
            mp[key]=head->next;

            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            node* curr=mp[key];
            mp.erase(key);
            dlt(curr);
        }
        if(mp.size()>=cap) {
            mp.erase(tail->prev->key);
            dlt(tail->prev);
        }
        add(new node(key, value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */