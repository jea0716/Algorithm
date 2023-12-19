#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int X, Y;
int map[51][51];
int visited[51][51];

void clear() {
   for(int i=0; i<=50; i++) {
      for(int j=0; j<=50; j++) {
         map[i][j] = 0;
         visited[i][j] = 0;
      }
   }
}

void bfs(int x, int y) {
   visited[x][y] = 1;

   queue <pair<int, int>  >q;
   q.push(make_pair(x, y));

   while(!q.empty()) {
      int a = q.front().first;
      int b = q.front().second;
      q.pop();

      if (a+1 < X && map[a+1][b] == 1 && visited[a+1][b] == 0) {
         q.push(make_pair(a+1, b));
         visited[a+1][b] = 1;
      }
      if (a-1 >=0 && map[a-1][b] == 1 && visited[a-1][b] == 0) {
         q.push(make_pair(a-1, b));
         visited[a-1][b] = 1;
      }
      if (b+1 < Y && map[a][b+1] == 1 && visited[a][b+1] == 0) {
         q.push(make_pair(a, b+1));
         visited[a][b+1] = 1;
      }
      if (b-1 >= 0 && map[a][b-1] == 1 && visited[a][b-1] == 0) {
         q.push(make_pair(a, b-1));
         visited[a][b-1] = 1;
      }
   }
}


int main() {

   int N; cin >> N;

   for(int k=0; k<N; k++) {
      int cnt; cin >> X >> Y >> cnt;

      clear();

      int tmp_x, tmp_y;
      for(int i=0; i<cnt; i++) {
         cin >> tmp_x >> tmp_y;
         map[tmp_x][tmp_y] = 1;
      }

      int answer = 0;
      for(int i=0; i<X; i++) {
         for(int j=0; j<Y; j++) {
            if(visited[i][j] == 0 && map[i][j] == 1) {
               answer++;
               bfs(i, j);
            }
         }
      }

      cout << answer << "\n";
   }

   return 0;
}