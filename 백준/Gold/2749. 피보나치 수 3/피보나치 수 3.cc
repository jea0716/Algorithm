#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ull = unsigned long long int;

#define SIZE 1500000
#define MOD 1000000

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ull N;
    int arr[SIZE] = { 0, 1 };

    for(int i=2; i<SIZE; i++) arr[i] = (arr[i-1] + arr[i-2]) % MOD;

    cin >> N;
    cout << arr[N % SIZE] << '\n';

    return 0;
}