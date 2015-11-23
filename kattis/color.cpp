#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int socks, cap, diff;
    cin >> socks >> cap >> diff;

    vector<int> colors(socks);
    for (int i = 0; i < socks; i++)
        cin >> colors[i];
    
    sort(colors.begin(), colors.end());

    int machines = 0;
    int added = 0;
    while (added < socks) {
        int machine = 0;
        int bcolor = colors[added];
        while (added < socks && machine < cap && colors[added] - bcolor <= diff) {
            added++;
            machine++;
        }
        machines++;
    }

    cout << machines << '\n';

    return 0;
}
