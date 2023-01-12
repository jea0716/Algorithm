#include <iostream>

using namespace std;

int main()
{
    int n, score, p; cin >> n >> score >> p;
    int arr[p]; for(int i=0; i<p; i++) arr[i] = -1;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int answer = -1;
    for(int i=0; i<p; i++)
    {
        if(score > arr[i])
        {
            answer = i + 1;
            break;
        }
        else if(score == arr[i])
        {
            for(int j=i; j<p; j++)
            {
                if(arr[j] != arr[i])
                {
                    answer  = i + 1;
                    break;
                }
            }
            break;
        }
    }
    cout << answer << endl;
}