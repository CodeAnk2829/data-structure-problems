#include <iostream>
#include "StackUsingLL.cpp"
using namespace std;
int main() {
    Stack <int> s;

    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    cout << s.top() << " ";

    cout << endl;

    cout << s.pop() << " ";
    cout << s.pop() << " ";
    cout << s.pop() << " ";
    cout << s.pop() << " ";
    cout << s.pop() << " ";

    cout << endl << s.size() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}