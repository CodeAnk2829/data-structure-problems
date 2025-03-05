template <typename T> 
class StackofArray
{
private:
    T *data;
    int nextIndex;
    int capacity;

public:
    StackofArray() {
        capacity = 5;
        data = new T[capacity];
        nextIndex = 0;
    }

    // Find size of the current stack
    int size() {
        return nextIndex;
    }

    // Check whether stack is empty or not
    bool isEmpty() {
        return nextIndex == 0;
    }

    // Insert elements dynamically
    void push(T element) {
        if(nextIndex == capacity) {
            capacity *= 2;
            T *newData = new T[capacity];
            for(int i = 0; i < nextIndex; ++i) {
                newData[i] = data[i];
            }
            delete [] (data);
            data = newData;
        }
        data[nextIndex++] = element;
    } 

    // Delete an element form the top
    T pop() {
        if(isEmpty()) {
            cout << "Stack is empty !" << endl;
            return 0;
        }
        return data[--nextIndex];
    }

    // Access the top element 
    T top() {
        if (isEmpty()) { 
            cout << "Stack is empty !" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};