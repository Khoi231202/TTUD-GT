#include <iostream>
#include <queue>
#include <unordered_map>
// #include<algorithm>
using namespace std;

const int MAX = 106;
int a[1000000];
int Q, n, L = 0, R, sum = 0, res = 0;

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> Q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (R = 0; R < n; R++)
    {
        sum += a[R];
        while (sum > Q)
        {
            sum = sum - a[L];
            L++;
        }
        res = max(res, R - L + 1);
    }
    cout << res;
    return 0;
}
