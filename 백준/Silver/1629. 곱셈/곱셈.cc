#include <iostream>

using namespace std;

unsigned long long A, B, C;
unsigned long long answer;

unsigned long long solved(unsigned long long a, unsigned long long b) {
    if(b == 1) return a % C;

    unsigned long long tmp = solved(a, b/2) % C;

    if(b % 2 == 0) {
        return tmp * tmp % C;
    }
    else {
        return tmp * tmp % C * a % C;
    }
}

int main() {
    cin >> A >> B >> C;
    cout << solved(A, B) << "\n";
}