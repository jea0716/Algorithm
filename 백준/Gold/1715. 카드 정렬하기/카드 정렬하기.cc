#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, tmp; cin >> n;
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        pq.push(tmp);
    }

    int cnt = 0;

    for(int i=0; i<n-1; i++)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int num = first + second;
        pq.push(num);
        cnt += num;
    }

    cout << cnt << endl;
}