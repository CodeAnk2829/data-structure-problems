#include <iostream>
#include "Pair.cpp"
using namespace std;
int main() {
    Pair <int, int> P1;
    P1.setX(10);
    P1.setY(14);
    cout << P1.getX() << " " << P1.getY() << endl;

    Pair <int, double> P2;
    P2.setX(1);
    P2.setY(100.2);
    cout << P2.getX() << " " << P2.getY() << endl;

    Pair <char, int> P3;
    P3.setX('a');
    P3.setY(34);
    cout << P3.getX() << " " << P3.getY() << endl;

    Pair <Pair<int, int>, int> P4;
    P4.setX(P1);
    P4.setY(19);
    cout << P4.getX().getX() << " " << P4.getX().getY() << " " << P4.getY() << endl;

    Pair <double, Pair<int, char>> P;
    P.setX(199.223);
    Pair <int, char> temp;
    temp.setX(39);
    temp.setY('A');
    P.setY(temp);
    cout << P.getX() << " " << P.getY().getX() << " " << P.getY().getY() << endl;
    return 0;
}