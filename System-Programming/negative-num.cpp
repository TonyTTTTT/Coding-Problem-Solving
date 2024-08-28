#include <iostream>
#include <bitset>
using namespace std;

int main() {
    for (int i=0; i>-50; i--) {
        cout << i << ": " << bitset<64>(i) << endl;
    }

    return 0;
}