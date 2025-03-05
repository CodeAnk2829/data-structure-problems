template <typename T>
class ListNode 
{
public:
    T data;
    ListNode <T> *next;
    ListNode(T data) {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack
{
private: 
    ListNode <T> *head;
    int len;

public:
    Stack() {
        head = NULL;
        len = 0;
    }

    int size() {
        return len;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(T val) {
        ListNode <T> *newNode = new ListNode <T> (val);
        newNode->next = head;
        head = newNode;
        len++;
    }

    T pop() {
        if(head == NULL) return 0;
        T ans = head->data;
        ListNode <T> *temp = head;
        head = head->next;
        delete(temp);
        len--;
        return ans;
    }

    T top() {
        if(head == NULL) return 0;
        return head->data;
    }
};