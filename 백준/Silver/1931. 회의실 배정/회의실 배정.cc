#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct table_time {
    int s, e;
};

table_time arr[100001];

bool cmp(table_time t1, table_time t2) {
    if(t1.e == t2.e) return t1.s < t2.s;

    return t1.e < t2.e;
}

int main() {
    int n; cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i].s >> arr[i].e;
    }

    sort(arr, arr + n, cmp);

    int t = arr[0].e;
    int count = 1;
    for(int i=1; i<n; i++) {
        if(t <= arr[i].s) {
            count++;
            t = arr[i].e;
        }
    }

    cout << count << endl;

    return 0;
}