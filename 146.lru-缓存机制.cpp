/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
struct Dlinklist{
    int key,value;
    Dlinklist* pre; // 前
    Dlinklist* next; // 后
    Dlinklist():key(0),value(0),pre(nullptr),next(nullptr){};
    Dlinklist(int k,int v){
        key = k;
        value = v;
        pre = nullptr;
        next = nullptr;
    };

};
class LRUCache {
public:
    // put 和get的改和拿可以利用map 删除最近最久未使用只能是队列 但是需要O(1)时间 
    // 所以只能是双向队列并且得是链表 因为只有链表移动元素才是O(1)
    // 在map中存链表节点得位置即可快速找到 由于是双向链表 也可以快速找到头 进行移动 
    int size = 0;
    int cap = 0;
    unordered_map<int,Dlinklist*> lru_map; //哈希表 O(1)
    Dlinklist* head;
    Dlinklist* tail;
    LRUCache(int capacity) {
        if(capacity<=0){
            return;
        }
        else{
            cap = capacity;
            head = new Dlinklist(); //伪头部
            tail = new Dlinklist(); //伪尾部
            head->next = tail;
            tail->pre = head;
        }
    }
    
    int get(int key) {
        if(!lru_map.count(key)){
            return -1;
        }
        Dlinklist* pos = lru_map[key]; // 定位位置
        moveTohead(pos); // 移到头部说明被使用了
        return pos->value; // 空则-1 有则取值
    }
    
    void put(int key, int value) {
        if(lru_map.count(key)>0){
            Dlinklist* pos = lru_map[key];
            pos->value = value;
            moveTohead(pos);
            return;
        }
        else{ // 不在cache中 需要判断当前容量
            Dlinklist* pos = new Dlinklist(key,value);
            // 放入map中
            lru_map[key] = pos;
            if(size<cap){
                moveTohead(pos);//直接加入头部
                size++;
                cout<<size<<endl;
            }
            else{//满了需要删除
                int pop_key = pop(); //删除尾部
                lru_map.erase(pop_key);
                moveTohead(pos); //插入头部
            }
        }
        return;
    }
    void remove(Dlinklist* pos){
        //先进行删除工作
        Dlinklist* pos_next = pos->next;// pos之后
        Dlinklist* pos_pre = pos->pre;//pos之前
        if (pos_next){
        pos_next->pre = pos_pre;
        }
        if(pos_pre){
        pos_pre->next = pos_next;
        }
    }

    void moveTohead(Dlinklist* pos){ //充当插入函数
        //先删除
        remove(pos);
        //再完成移动
        Dlinklist* head_next = head->next; //虚构头的后面
        pos->next = head_next;
        pos->pre = head;
        head->next = pos;
        head_next->pre = pos;
        return;
    }
    int pop(){
        Dlinklist* pos = tail->pre; //虚构尾的前面 删除的目标
        // cout<<pos<<endl;
        Dlinklist* pos_pre = pos->pre; //删除目标的前面用于接上链
        // if(!pos_pre){
        //     cout<<"空指针"<<endl;
        // }
        pos_pre->next = tail;
        tail->pre = pos_pre;
        int pos_key = pos->key;
        delete pos;
        return pos_key;
    }
};







/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

