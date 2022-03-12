146. LRU 缓存机制
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
struct LRUNode{
    int value;
    int key;
    LRUNode*next;
    LRUNode*prev;
    LRUNode(){this->prev=NULL;this->next=NULL;}
    LRUNode(int key,int val){this->key=key;this->value=val;this->prev=NULL;this->next=NULL;}
};
class LRUCache {
private:
    int capacity;
    int size;
    LRUNode* head;
    unordered_map<int, LRUNode*> LRUMap;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        size=0;
    }
    
    int get(int key) {
        // cout<<key<<" "<<LRUMap.count(key)<<endl;
        if(LRUMap.count(key)==0)
            return -1;
        else if(LRUMap[key]!=head)
        {
            LRUNode*temp=LRUMap[key];
            LRUNode*tempPrev=temp->prev;
            LRUNode*tempNext=temp->next;
            cout<<"test"<<key<<endl;
            tempPrev->next=tempNext;
            tempNext->prev=tempPrev;
            temp->prev=head->prev;
            head->prev->next=temp;
            temp->next=head;
            head->prev=temp;
            return temp->value;
        }
        else
        {
            head=head->next;
            return head->prev->value;
        }
    }
    
    void put(int key, int value) {
        int getValue=this->get(key);
        // cout<<"put"<<key<<endl;
        if(getValue!=-1)
        {
            head->prev->value=value;
            return;
        }
        if(size<capacity)
        {
            LRUNode*temp=new LRUNode(key,value);
            LRUMap[key]=temp;
            if(size==0)
            {
                head=temp;
                temp->prev=temp;
                temp->next=temp;
            }
            else
            {
                temp->prev=head->prev;
                temp->next=head;
                head->prev->next=temp;
                head->prev=temp;
            }
            ++size;
            // cout<<LRUMap[key]->value<<endl;
            // cout<<head->value<<" "<<head->next->value<<endl;
        }
        else
        {
            if(capacity!=1)
            {
                LRUNode*temp=new LRUNode(key,value);
                LRUMap[key]=temp;
                LRUNode* deleteTemp=head;
                int deleteKey=head->key;
                temp->prev=head->prev;
                temp->next=head->next;
                head->prev->next=temp;
                head=head->next;
                head->prev=temp;
                // cout<<"delete:"<<deleteKey<<endl;
                LRUMap.erase(deleteKey);
                delete(deleteTemp);
            }
            else
            {
                LRUNode*temp=new LRUNode(key,value);
                LRUMap[key]=temp;
                LRUNode* deleteTemp=head;
                int deleteKey=head->key;
                temp->prev=temp;
                temp->next=temp;
                head=temp;
                LRUMap.erase(deleteKey);
                delete(deleteTemp);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */