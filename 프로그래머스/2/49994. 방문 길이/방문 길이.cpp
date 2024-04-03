#include <string>
using namespace std;

struct direction {
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
};

direction visited[11][11];
int x, y, answer;

void BFS(char d) {
    if(d == 'U') {
        if(x + 1 <= 5) {
            if(visited[x+5][y+5].up == false) {
                answer++;
                visited[x+5][y+5].up = true;
                visited[x+6][y+5].down = true;
            }  
            x++;
        }
    }
    else if(d == 'D') {
        if(x - 1 >= -5) {
            if(visited[x+5][y+5].down == false) {
                answer++;
                visited[x+5][y+5].down = true;
                visited[x+4][y+5].up = true;
            }  
            x--;
        }
    }
    else if(d == 'L') {
        if(y - 1 >= -5) {
            if(visited[x+5][y+5].left == false) {
                answer++;
                visited[x+5][y+5].left = true;
                visited[x+5][y+4].right = true;
            }  
            y--;
        }
    }
    else if(d == 'R') {
        if(y + 1 <= 5) {
            if(visited[x+5][y+5].right == false) {
                answer++;
                visited[x+5][y+5].right = true;
                visited[x+5][y+6].left = true;
            }  
            y++;
        }
    }
}

int solution(string dirs) {
    for(int i=0; i<dirs.length(); i++) {
        BFS(dirs[i]);
    }
    
    return answer;
}