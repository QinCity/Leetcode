/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start

struct Node{
    int val;
    Node* next;
    Node(int num) {
        val = num;
        next = NULL;
    }
};

class MyLinkedList {
public:
    MyLinkedList() {
        this->head = new Node(0);
        this->length = 0;
    }
    
    int get(int index) {
        if (index + 1 > this->length) {
            return -1;
        }
        Node* cur = this->head;
        for (int i = 0; i <= index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* new_node = new Node(val);
        if (this->head->next == NULL) {
            this->head->next = new_node;
        }
        else {
            new_node->next = this->head->next;
            this->head->next = new_node;
        }
        this->length++;
    }
    
    void addAtTail(int val) {
        Node* new_node = new Node(val);
        Node* cur = this->head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
        this->length++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > this->length) {
            return;
        }
        Node* new_node = new Node(val);
        Node* cur = this->head;
        for (int i = 0; i <= index - 1; i++) {
            cur = cur->next;
        }
        new_node->next = cur->next;
        cur->next = new_node;
        this->length++;
    }

    void deleteAtIndex(int index) {
        if (index + 1 > this->length) {
            return;
        }
        Node* cur = this->head;
        for (int i = 0; i <= index - 1; i++) {
            cur = cur->next;
        }
        Node* delte_node = cur->next; 
        cur->next = cur->next->next;
        delete delte_node;
        this->length--;
    }
private:
    Node* head;
    int length;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

