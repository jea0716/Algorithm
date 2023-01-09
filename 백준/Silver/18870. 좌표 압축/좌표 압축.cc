#include <iostream>
#include <set>

using namespace std;



int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    set <int> s;
    for(int i=0; i<n; i++) s.insert(arr[i]);

    int zip_arr[s.size()]; int i = 0;
    set<int> ::iterator iter;
    for(iter=s.begin(); iter!=s.end(); iter++) zip_arr[i++] = *iter;

    int new_arr[n];
    for(i=0; i<n; i++)
    {
        int find_num = arr[i];
        int left = 0, right = s.size()-1;
        int mid = (left + right) / 2;
        while(find_num != zip_arr[mid])
        {
            if(find_num > zip_arr[mid])
            {
                left = mid + 1; mid = (left + right) / 2;
            }
            else
            {
                right = mid - 1; mid = (left + right) / 2;
            }
        }
        new_arr[i] = mid;
    }

    for(int i=0; i<n; i++) cout << new_arr[i] << " ";
    cout << '\n';

    return 0;
}