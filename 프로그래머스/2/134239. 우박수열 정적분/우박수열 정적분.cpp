#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<ull> v(1, k);
    vector<double> extent;
    
    while(k != 1)
    {
        if(k % 2 == 1) k = k * 3 + 1;
        else k = k / 2;
        
        v.push_back(k);
    }

    for(int i = 0; i < ranges.size(); i++) {
        int start = ranges[i][0];
        int end = v.size() - 1 + ranges[i][1];
        double tmp = 0;

        for(int j = start; j < end; j++)
            tmp += (double)(v[j] + v[j + 1]) / 2;
        
        if(start > end) answer.push_back(-1.0);
        else answer.push_back(tmp);
    }
    
    return answer;
}