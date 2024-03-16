#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int x, y;
    for(int i=0; i<park.size(); i++) {
        for(int j=0; j<park[i].size(); j++) {
            if(park[i][j] == 'S') x = i, y = j;
        }
    }
    vector<int> answer;
    for(int i=0; i<routes.size(); i++) {
        if(routes[i][0] == 'N') {
            bool check = true;
            int cnt = routes[i][2] - '0';
            if(x - cnt >= 0) {
                for(int j=1; j<=cnt; j++) {
                    if(park[x-j][y] == 'X') check = false;
                }
                if(check) x = x - cnt, y = y;
            }
            else check = false;
        }
        if(routes[i][0] == 'S') {
            bool check = true;
            int cnt = routes[i][2] - '0';
            if(x + cnt < park.size()) {
                for(int j=1; j<=cnt; j++) {
                    if(park[x+j][y] == 'X') check = false;
                }
                if(check) x = x + cnt, y = y;
            }
        }
        if(routes[i][0] == 'W') {
            bool check = true;
            int cnt = routes[i][2] - '0';
            if(y - cnt >= 0) {
                for(int j=1; j<=cnt; j++) {
                    if(park[x][y-j] == 'X') check = false;
                }
                if(check) x = x, y = y - cnt;
            }
        }
        if(routes[i][0] == 'E') {
            bool check = true;
            int cnt = routes[i][2] - '0';
            if(y + cnt < park[0].size()) {
                for(int j=1; j<=cnt; j++) {
                    if(park[x][y+j] == 'X') check = false;
                }
                if(check) x = x, y = y + cnt;
            }
        }
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}