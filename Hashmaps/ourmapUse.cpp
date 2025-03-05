#include "ourmap.h"
int main()  {
    ourmap<int> O;
    for(int i = 0; i < 10; ++i) {
        char ch = '0' + i;
        string key = "abc";
        key = key + ch;
        int value = i + 1;
        O.insert(key, value);
        cout << key << " " << O.getValue(key) << endl;
    }
    cout << O.size() << endl;
    return 0;
}