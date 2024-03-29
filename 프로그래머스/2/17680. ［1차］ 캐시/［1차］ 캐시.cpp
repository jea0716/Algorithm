#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    for(int i=0; i<cities.size(); i++) {
        for(int j=0; j<cities[i].length(); j++) {
            if(cities[i][j] >= 'A' && cities[i][j] <= 'Z') cities[i][j] += 32;
        }
    }
    
    vector<string> v;
    for(int i=0; i<cities.size(); i++) {
        bool check = false;
        for(int j=0; j<v.size(); j++) {
            if(v[j] == cities[i]) check = true;
        }
        if(check == false) {
            answer += 5;
            if(cacheSize == 0) continue; 
            if(v.size() < cacheSize) v.push_back(cities[i]);
            else {
                for(int j=0; j<v.size()-1; j++) v[j] = v[j+1];
                v[v.size()-1] = cities[i];
            }
        }
        else {
            answer++;
            bool check = false;
            for(int j=0; j<v.size()-1; j++) {
                if(v[j] == cities[i]) check = true;
                if(check) {
                    v[j] = v[j+1];
                }
            }
            v[v.size()-1] = cities[i];
        }
    }
    return answer;
}