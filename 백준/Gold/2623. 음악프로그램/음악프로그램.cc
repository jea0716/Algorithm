#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr[1001];
vector<int> degree(1001, 0);
vector<int> answer;

void solve() {
	queue<int> q;

	for(int i=1; i<=N; i++) {
		if(degree[i] == 0) {
			q.push(i);
		}
	}

	for(int k=0; k<N; k++){
		if(q.empty()) return ;

		int n = q.front();
		q.pop();

		answer.push_back(n);

		for(int i=0; i<arr[n].size(); i++) {
			int nn = arr[n][i];
			degree[nn]--;
			if(degree[nn] == 0) q.push(nn);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N >> M;

	int tmp, tmp2;
	vector<int> v;
	for(int i=0; i<M; i++) {
		cin >> tmp;
		v.clear();
		for(int j=0; j<tmp; j++) {
			cin >> tmp2;
			v.push_back(tmp2);
		}
		for(int j=0; j<v.size()-1; j++) {
			arr[v[j]].push_back(v[j + 1]);
			degree[v[j + 1]]++;
		}
	}

	solve();

	if(answer.size() != N) cout << "0\n";
	else {
		for(int i=0; i<answer.size(); i++) cout << answer[i] << '\n';
	}

	return 0;
}