#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int time;
    char direction;
};
struct snake {
    int X, Y;
};

int N, K, L;
int map[101][101];
queue <node> List;
vector <snake> S;
int answer;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int current_direction;
int current_X = 1, current_Y = 1;

void update_map() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(map[i][j] == 2) map[i][j] = 0;
        }
    }

    for(int i=0; i<S.size(); i++) map[S[i].X][S[i].Y] = 2;
}

void last_chance() {
    int nx = current_X + dx[current_direction];
    int ny = current_Y + dy[current_direction];

    while(nx > 0 && ny > 0 && nx <= N && ny <= N) {
        nx = current_X + dx[current_direction];
        ny = current_Y + dy[current_direction];

        answer++;

        if(map[nx][ny] == 0) S.erase(S.begin()), S.push_back({ nx, ny });
        else if(map[nx][ny] == 1) S.push_back({ nx, ny });
        else if(map[nx][ny] == 2) return;

        update_map();

        current_X = nx, current_Y = ny;
    }
}

void solve() {
    map[1][1] = 2;
    S.push_back({ 1, 1 });
    
    while(!List.empty()) {
        node n = List.front();
        List.pop();

        int keep_going = n.time - answer;

        for(int i=0; i<keep_going; i++) {
            int nx = current_X + dx[current_direction];
            int ny = current_Y + dy[current_direction];

            answer++;

            if(nx > N || ny > N || nx <= 0 || ny <= 0) return;
            if(map[nx][ny] == 0) S.erase(S.begin()), S.push_back({ nx, ny });
            else if(map[nx][ny] == 1) S.push_back({ nx, ny });
            else if(map[nx][ny] == 2) return;

            update_map();

            current_X = nx, current_Y = ny;
        }

        if(n.direction == 'D') current_direction = (current_direction + 1) % 4;
        else current_direction = (4 + current_direction - 1) % 4;
    }

    last_chance();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tmp_X, tmp_Y;
    node tmp_node;

    cin >> N >> K;
    for(int i=0; i<K; i++) {
        cin >> tmp_X >> tmp_Y;
        map[tmp_X][tmp_Y] = 1;
    }

    cin >> L;
    for(int i=0; i<L; i++) {
        cin >> tmp_node.time >> tmp_node.direction;
        List.push(tmp_node);
    }

    solve();

    cout << answer << "\n";

    return 0;
}