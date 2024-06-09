#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, x, y, d, g;
bool map[102][102];
int answer;
vector<int> v;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

void draw() {
	v.clear();
	v.push_back(d);

	for(int i=0; i<g; i++) {
		vector<int> tmp;
		for(int j=0; j<v.size(); j++) {
			tmp.push_back((v[j] + 1) % 4);
		}
		while(!tmp.empty()) {
			v.push_back(tmp.back());
			tmp.pop_back();
		}
	}

	int nx = x, ny = y;
	map[nx][ny] = true;
	for(int i=0; i<v.size(); i++) {
		nx += dx[v[i]];
		ny += dy[v[i]];
		map[nx][ny] = true;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N;

	for(int i=0; i<N; i++) {
		cin >> x >> y >> d >> g;
		draw();
	}

	for(int i=0; i<100; i++) {
		for(int j=0; j<100; j++) {
			if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]) answer++;
		}
	}

	cout << answer << '\n';

	return 0;
}