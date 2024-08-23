#include <string>
#include <vector>
#include <iostream>

using namespace std;

char map[31][31];
bool visited[31][31];
int answer = 0;
bool keep = true;

void clear() {
    for(int i=0; i<=30; i++) {
        for(int j=0; j<=30; j++) {
            visited[i][j] = 0;
        }
    }
    
    return ;
}

void rebuilding(int w, int h) {
    for(int i=0; i<w; i++) {
        for(int j=0; j<h; j++) {
            if(map[i][j] == '0') {
                for(int k=i; k>0; k--) {
                    map[k][j] = map[k-1][j];
                }
                map[0][j] = '0';
            }
        }
    }
    
    return ; 
}

void remove() {
    for(int i=0; i<=30; i++) {
        for(int j=0; j<=30; j++) {
            if(visited[i][j] == 1) {
                map[i][j] = '0';
                answer++;
            }
        }
    }    
    
    return ;
}

void check(int x, int y) {
    if(
        map[x][y] != '0' &&
        map[x][y] == map[x + 1][y] &&
        map[x][y] == map[x][y + 1] &&
        map[x][y] == map[x + 1][y + 1]
    ) {
        visited[x][y] = 1;
        visited[x + 1][y] = 1;
        visited[x][y + 1] = 1;
        visited[x + 1][y + 1] = 1;
        keep = true;
    }
    
    return ;
}

int solution(int m, int n, vector<string> board) {
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].length(); j++) {
            map[i][j] = board[i][j];
        }
    }
    
    while(keep) {
        keep = false;
        clear();
        for(int i=0; i<board.size()-1; i++) {
            for(int j=0; j<board[i].length()-1; j++) {
                check(i, j);
            }
        }
        remove();
        rebuilding(board.size(), board[0].length());
    }
    
    return answer;
}