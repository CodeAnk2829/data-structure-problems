// Program to implement unordered_map (inbuilt hashmap).
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
    unordered_map<string, int> ourmap;

    // insert
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    // find or access
    cout << ourmap["abc"] << endl;
    cout << ourmap["def"] << endl;
    cout << ourmap.at("abc") << endl;
    // cout << outmap.at("ghi") << endl;
    cout << "size: " << ourmap.size() << endl;
    cout << ourmap["ghi"] << endl; 
    cout << "size: " << ourmap.size() << endl;

    // check presence
    if(ourmap.count("ghi") > 0) {
        cout << "ghi is present" << endl;
    }

    // erase
    ourmap.erase("ghi");
    cout << "size: " << ourmap.size() << endl;
    if(ourmap.count("ghi") > 0) {
        cout << "ghi is present" << endl;
    }
    return 0;
}