#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[8];
bool visited[8];
int n, m, cnt;
vector <int> v;


void print()
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    return ;
}

void dfs(int cnt)
{
    if(cnt == m)
    {
        print();
        return ;
    }

    for(int i=0; i<n; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(arr[i]);
        dfs(cnt + 1);
        v.pop_back();
        visited[i] = false; 
    }
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        visited[i] = false;
    }

    sort(arr, arr + n);

    dfs(0);

    return 0;
}