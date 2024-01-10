#include <iostream>

using namespace std;

int arr[10001], tmp, num;

int main() {
    for(int i=1; i<=10000; i++) {
        num = i;
        tmp = i;
        while(num <= 10000) {
            arr[num] += 1;
            while(tmp > 0) {
                num += tmp % 10;
                tmp /= 10;
            }
            tmp = num;
        }
    }

    for(int i=1; i<=10000; i++) {
        if(arr[i] == 1) cout << i << "\n";
    }


    return 0;
}


