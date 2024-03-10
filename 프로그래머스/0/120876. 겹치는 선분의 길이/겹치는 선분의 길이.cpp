#include <string>
#include <vector>

using namespace std;

int arr[201];

int solution(vector<vector<int>> lines) {
    int answer=0;
    
    for(int i=0; i<lines.size(); i++)
        for(int j=lines[i][0]; j<lines[i][1]; j++)
            arr[j+100]++;

    for(int i=0; i<200; i++)
        if(arr[i]>=2) answer++;
    
    return answer;
}