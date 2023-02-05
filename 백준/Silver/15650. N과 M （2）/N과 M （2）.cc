#include <iostream>
#include <vector>

using namespace std;

int arr[8];
bool visited[8];
int n, m, cnt;
vector <int> v;


void print()
{
    bool check = true;
    for(int i=0; i<v.size()-1; i++)
    {
        if(v[i] > v[i+1]) check = false;
    }
    if(check == true)
    {
        for(int i=0; i<v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
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
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        arr[i] = i + 1;
        visited[i] = false;
    }

    dfs(0);

    return 0;
}