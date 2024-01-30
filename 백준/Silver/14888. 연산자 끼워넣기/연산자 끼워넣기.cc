#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> num(12);
vector <int> sign;
vector <int> visited(12, 0);
vector <int> arr(12);

int min_num = 1111111111, max_num = -1111111111;

void calculate() {
    int sum = num[0];
    for(int i=0; i<N-1; i++) {
        if(arr[i] == 0) sum += num[i+1];
        else if(arr[i] == 1) sum -= num[i+1];
        else if(arr[i] == 2) sum *= num[i+1];
        else if(arr[i] == 3) sum /= num[i+1];
    }
    min_num = min_num > sum ? sum : min_num;
    max_num = max_num < sum ? sum : max_num;
}

void DFS(int n, int count) {
    if(count == N-1) {
        calculate();
    }

    int tmp = -1;
    for(int i=0; i<N-1; i++) {
        if(visited[i] || tmp == sign[i]) continue;
        visited[i] = 1;
        tmp = sign[i];
        arr[count] = sign[i];
        DFS(tmp, count + 1);
        visited[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) cin >> num[i];
    int num;
    for(int i=0; i<4; i++) {
        cin >> num;
        for(int j=0; j<num; j++) sign.push_back(i);
    }

    DFS(-1, 0);

    cout << max_num << "\n";
    cout << min_num << "\n";

    return 0;
}