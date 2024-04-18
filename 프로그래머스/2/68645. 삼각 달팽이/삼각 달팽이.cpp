#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[1000][1000];
int dx[] = {-1, 1, 0};
int dy[] = {-1, 0, 1};
int nx, ny, dir;

bool check() {
    dir = (dir + 1) % 3;
    if(arr[nx + dx[dir]][ny + dy[dir]] == 0) return true;
    else return false;
}

vector<int> solution(int n) {
    vector<int> answer;
    int cn = 1; arr[0][0] = cn++;
    while(check()) {
        while(
            nx + dx[dir] >= 0 && nx + dx[dir] < n &&
            ny + dy[dir] >= 0 && ny + dy[dir] < n &&
            arr[nx + dx[dir]][ny + dy[dir]] == 0
        ) {
            arr[nx + dx[dir]][ny + dy[dir]] = cn;
            nx += dx[dir];
            ny += dy[dir];
            cn ++;  
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] != 0) answer.push_back(arr[i][j]);
        }
    }
    return answer;
}