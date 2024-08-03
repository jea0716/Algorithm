#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N;
string S;
char A = '-', B = '|';
int arr[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> S;

    for(int i=0; i<S.length(); i++) {
        int tmp = S[i] - '0';
        cout << ' ';
        for(int j=0; j<N; j++) {
            if(arr[tmp][0] == 1) cout << A;
            else cout << ' ';
        }
        cout << ' ';
        cout << ' ';
    }

    cout << '\n';

    for(int k=0; k<N; k++) {
        for(int i=0; i<S.length(); i++) {
            int tmp = S[i] - '0';
            if(arr[tmp][5] == 1) cout << B;
            else cout << ' ';

            for(int j=0; j<N; j++) cout << ' ';

            if(arr[tmp][1] == 1) cout << B;
            else cout << ' ';
            cout << ' ';
        }
        cout << '\n';
    }

    for(int i=0; i<S.length(); i++) {
        int tmp = S[i] - '0';
        cout << ' ';
        for(int j=0; j<N; j++) {
            if(arr[tmp][6] == 1) cout << A;
            else cout << ' ';
        }
        cout << ' ';
        cout << ' ';
    }

    cout << '\n';

    for(int k=0; k<N; k++) {
        for(int i=0; i<S.length(); i++) {
            int tmp = S[i] - '0';
            if(arr[tmp][4] == 1) cout << B;
            else cout << ' ';

            for(int j=0; j<N; j++) cout << ' ';

            if(arr[tmp][2] == 1) cout << B;
            else cout << ' ';
            cout << ' ';
        }
        cout << '\n';
    }

    for(int i=0; i<S.length(); i++) {
        int tmp = S[i] - '0';
        cout << ' ';
        for(int j=0; j<N; j++) {
            if(arr[tmp][3] == 1) cout << A;
            else cout << ' ';
        }
        cout << ' ';
        cout << ' ';
    }

    cout << '\n';

    return 0;
}