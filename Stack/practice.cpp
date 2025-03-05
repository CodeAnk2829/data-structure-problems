template <typename T>
class ListNode
{
private:
    int data;
    ListNode *next;

public:
    ListNode(int data) {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack
{
private:
    ListNode <T> *head;
    int size;

public:
    Stack() {
        head = NULL;
        size = 0;
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return head == NULL;
    }
    void push(T val) {
        ListNode <T> newNode = new ListNode<T>(val);
        newNode->next = head;
        head = head->next;
        size++;
    }
    T pop() {
        if(head == NULL) {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        ListNode<T> *temp = head;
        head = head->next;
        return temp->data;
    }
    T top() {
        if(head == NULL) {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        return head->data;
    }
};