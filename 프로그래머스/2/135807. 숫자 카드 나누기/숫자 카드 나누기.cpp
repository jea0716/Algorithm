#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    int numA = 0, numB = 0;
    int maxA = 0, maxB = 0;
    
    for(int i=2; i<=arrayA[0]; i++) {
        bool check = true;
        if(arrayA[0] % i != 0) continue;
        for(int j=1; j<arrayA.size(); j++) {
            if(arrayA[j] % i != 0) {
                check = false;
                continue;
            }
        }
        if(check) {
            numA = i;
            bool check2 = true;
            for(int j=0; j<arrayB.size(); j++) {
                if(arrayB[j] % numA == 0) check2 = false; 
            }
            if(check2) maxA = numA;
        }
    }
    
    for(int i=2; i<=arrayB[0]; i++) {
        bool check = true;
        if(arrayB[0] % i != 0) continue;
        for(int j=1; j<arrayB.size(); j++) {
            if(arrayB[j] % i != 0) {
                check = false;
                continue;
            }
        }
        if(check) {
            numB = i;
            bool check2 = true;
            for(int j=0; j<arrayA.size(); j++) {
                if(arrayA[j] % numB == 0) check2 = false; 
            }
            if(check2) maxB = numB;
        }
    }
    
    answer = maxA > maxB ? maxA : maxB;
    
    return answer;
}