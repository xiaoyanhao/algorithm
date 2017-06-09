#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int x, y, z;
    int cr = 0, cy = 0, cb = 0;
    int last_index = -1, ans = 0;
    string sequence;
    
    cin >> x >> y >> z;
    cin >> sequence;
    
    int len = sequence.size();
    for (int i = 0; i < len; i++) {
        char ball = sequence[i];
        if (ball == 'R') {
            cr++;
        } else if (ball == 'Y') {
            cy++;
        } else if (ball == 'B') {
            cb++;
        }
        
        int ry = abs(cr - cy);
        int yb = abs(cy - cb);
        int br = abs(cb - cr);
        if ((ry == x && yb == y && br == z)
            || (ry == x && yb == z && br == y)
            || (ry == y && yb == x && br == z)
            || (ry == y && yb == z && br == x)
            || (ry == z && yb == x && br == y)
            || (ry == z && yb == y && br == x)) {
            ans = max(i - last_index, ans);
            last_index = i;
            cr = cy = cb = 0;
        }
    }
    if (last_index != len - 1 && ans < len - 1 - last_index) {
        ans = len - 1 - last_index;
    }
    
    cout << ans << endl;
    
    return 0;
}

