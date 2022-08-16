#include <iostream>

using namespace std;

int one[3];
int two[3];
int arr[6];

int main(){
    int n; cin >> n;
    int t1, t2;
    int m1 = 0, m2 = 0;
    int small = 1;
    for(int i=0; i<6; i++){
        cin >> t1 >> t2;
        if(i % 2 == 0){
            if(t2 > m1) m1 = t2;
        }
        else if(i % 2 == 1){
            if(t2 > m2) m2 = t2;
        }
        arr[i] = t2;
    }
    for(int i=0; i<6; i++){
        if(arr[i] == m1){
            if(i == 0){
                if(arr[i+1] != m2) arr[i] = arr[i+1] = 0;
                if(arr[5] != m2) arr[5] = 0;
                arr[i] = 0;
            }
            else if(i == 5){
                if(arr[i-1] != m2) arr[i] =  arr[i-1] = 0;
                if(arr[0] != m2) arr[0] = 0;
                arr[i] = 0;
            }
            else{
                if(arr[i-1] == m2) arr[i] = arr[i+1] = 0;
                else if(arr[i+1] == m2) arr[i] = arr[i-1] = 0;
                else{
                    arr[i-1] = arr[i] = arr[i+1] = 0;
                }
            }
        }
        else if(arr[i] == m2){
            if(i == 0){
                if(arr[i+1] != m1) arr[i] = arr[i+1] = 0;
                if(arr[5] != m1) arr[5] = 0;
                arr[i] = 0;
            }
            else if(i == 5){
                if(arr[i-1] != m1) arr[i] =  arr[i-1] = 0;
                if(arr[0] != m1) arr[0] = 0;
                arr[i] = 0;
            }
            else{
                if(arr[i-1] == m1) arr[i] = arr[i+1] = 0;
                else if(arr[i+1] == m1) arr[i] = arr[i-1] = 0;
                else{
                    arr[i-1] = arr[i] = arr[i+1] = 0;
                }
            }
        }
    }
    for(int i=0; i<6; i++){
        cout << arr[i] << " ";
        if(arr[i] != 0) small *= arr[i];
    }
    cout << endl;

    cout << m1 << " " << m2 << " " << small << endl;
    int answer = ((m1 * m2) - small) * n;
    cout << answer << endl;
}