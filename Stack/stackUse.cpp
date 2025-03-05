#include <bits/stdc++.h>
#include "FixedStackArray.cpp"
#include "StackUsingArray.cpp"
using namespace std;
int main() {
    FixedStack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;

    StackofArray <char> a;
    a.push(100);
    a.push(102);
    a.push(103);
    a.push(104);
    a.push(105);
    a.push(106);
    a.push(107);
    a.push(108);
    a.push(109);
    a.push(110);

    cout << a.pop() << endl;
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    return 0;
}