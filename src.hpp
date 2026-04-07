// Only allowed headers
#include <iostream>

template <typename T>
class LinkedList {
protected:
    struct Node {
        T val;
        Node* prev;
        Node* next;
        Node(const T& v) : val(v), prev(NULL), next(NULL) {}
    };

    Node* head_;
    Node* tail_;
    int size_;

    // Unsafe accessors: caller guarantees non-empty
    T frontUnsafe() const { return head_->val; }
    T backUnsafe() const { return tail_->val; }

public:
    // Virtual interface (won't be called on base in tests)
    virtual const char* name() { return "LinkedList"; }
    virtual T peak() { return T(); }
    virtual T pop() { return T(); }
    virtual void push(T) { /* no-op */ }

    // Constructors / destructor
    LinkedList() : head_(NULL), tail_(NULL), size_(0) {}

    LinkedList(const LinkedList& other) : head_(NULL), tail_(NULL), size_(0) {
        Node* cur = other.head_;
        while (cur) {
            pushBack(cur->val);
            cur = cur->next;
        }
    }

    virtual ~LinkedList() {
        Node* cur = head_;
        while (cur) {
            Node* nx = cur->next;
            delete cur;
            cur = nx;
        }
        head_ = tail_ = NULL;
        size_ = 0;
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this == &other) return *this;
        // Clear current list
        Node* cur = head_;
        while (cur) {
            Node* nx = cur->next;
            delete cur;
            cur = nx;
        }
        head_ = tail_ = NULL;
        size_ = 0;
        // Deep copy from other
        Node* o = other.head_;
        while (o) {
            pushBack(o->val);
            o = o->next;
        }
        return *this;
    }

    // Basic operations
    void pushFront(const T& v) {
        Node* n = new Node(v);
        n->next = head_;
        if (head_) head_->prev = n;
        head_ = n;
        if (!tail_) tail_ = n;
        ++size_;
    }

    void pushBack(const T& v) {
        Node* n = new Node(v);
        n->prev = tail_;
        if (tail_) tail_->next = n;
        tail_ = n;
        if (!head_) head_ = n;
        ++size_;
    }

    T popFront() {
        if (!head_) return T();
        Node* n = head_;
        T val = n->val;
        head_ = n->next;
        if (head_) head_->prev = NULL; else tail_ = NULL;
        delete n;
        --size_;
        return val;
    }

    T popBack() {
        if (!tail_) return T();
        Node* n = tail_;
        T val = n->val;
        tail_ = n->prev;
        if (tail_) tail_->next = NULL; else head_ = NULL;
        delete n;
        --size_;
        return val;
    }

    int size() const { return size_; }

    void print() const {
        Node* cur = head_;
        while (cur) {
            std::cout << cur->val << ' ';
            cur = cur->next;
        }
        std::cout << '\n';
    }
};

template <typename T>
class Stack : public LinkedList<T> {
public:
    // No new member variables allowed
    const char* name() /*override*/ { return "Stack"; }
    T peak() /*override*/ { return this->backUnsafe(); }
    T pop() /*override*/ { return this->popBack(); }
    void push(T val) /*override*/ { this->pushBack(val); }
};

template <typename T>
class Queue : public LinkedList<T> {
public:
    // No new member variables allowed
    const char* name() /*override*/ { return "Queue"; }
    T peak() /*override*/ { return this->frontUnsafe(); }
    T pop() /*override*/ { return this->popFront(); }
    void push(T val) /*override*/ { this->pushBack(val); }
};
