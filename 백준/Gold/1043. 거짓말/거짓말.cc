#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
bool people[51];
vector <int> list;
vector <vector<int> > v;
vector <vector<int> > graph(51);

void BFS(int n) {
    queue <int> q;
    q.push(n);

    while(!q.empty()) {
        int nn = q.front();
        q.pop();

        for(int i=0; i<graph[nn].size(); i++) {
            if(!people[graph[nn][i]]) {
                q.push(graph[nn][i]);
                people[graph[nn][i]] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M;

    int T, tmp; cin >> T;
    for(int i=0; i<T; i++) {
        cin >> tmp;
        people[tmp] = true;
        list.push_back(tmp);
    }
    for(int i=0; i<M; i++) {
        vector <int> t;
        int n; cin >> n;
        for(int j=0; j<n; j++) {
            cin >> tmp;
            t.push_back(tmp);
        }

        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(j != k) graph[t[j]].push_back(t[k]);
            }
        }
        v.push_back(t);
    }

    for(int i=0; i<list.size(); i++) {
        BFS(list[i]);
    }

    int answer = 0;

    for(int i=0; i<v.size(); i++) {
        bool check = true;
        for(int j=0; j<v[i].size(); j++) {
            if(people[v[i][j]]) check = false;
        }
        if(check) answer++;
    }

    cout << answer << endl;

    return 0;
}