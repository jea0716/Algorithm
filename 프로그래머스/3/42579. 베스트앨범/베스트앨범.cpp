#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> map;
int genreCnt = 0;

vector<pair<int, int>> v[100];
vector<int> playSum;
vector<pair<int, int>> ranking;
vector<int> answer;

bool cmp(pair<int, int> const p1, pair<int, int> const p2) {
    if(p1.first == p2.first) return p1.second < p2.second;
    
    return p1.first > p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    for(int i=0; i<genres.size(); i++)
    {
        if(map.find(genres[i]) == map.end())
        {
            map.insert({ genres[i], genreCnt++ });
            playSum.push_back(0);
        }
        
        v[map[genres[i]]].push_back({ plays[i], i });
        playSum[map[genres[i]]] += plays[i];
    }
    
    for(int i=0; i<genreCnt; i++)
    {
        sort(v[i].begin(), v[i].end(), cmp);
        ranking.push_back({ playSum[i], i });
    }
    
    sort(ranking.rbegin(), ranking.rend());
    
    for(int i=0; i<genreCnt; i++)
    {
        if(v[ranking[i].second].size() == 1) 
        {
            answer.push_back(v[ranking[i].second][0].second);
        }
        else 
        {
            for(int j=0; j<2; j++)
            {
                answer.push_back(v[ranking[i].second][j].second);
            }
        }
    }
        
    return answer;
}