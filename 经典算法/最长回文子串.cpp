# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;

const int N = 1000005;
char s[N];  //原字符串
char ss[N * 2]; //用'#'作为间隔填充之后的字符串 
int p[N * 2]; //p[i]表示以第i个字符为中心的回文子串的长度加1  
int ans; //最长回文子串的长度  

void Manacher() {
    int mx = 0; //mx表示当前回文子串扩展的最右端 
    int id; //id表示mx是由哪个回文子串扩展出来的  
    int len = (strlen(s) + 1) * 2, i;
    for (i = 0; i < len; i++) {
        ss[i] = '#';
        p[i] = 0;
    }
    for (i = 0; s[i] != 0; i++) {
        ss[(i + 1) * 2] = s[i];
    }
    ss[(i + 1) * 2] = 0;
    for (i = 1, ans = 0; ss[i] != 0; i++) {
        if (mx > i) {
            p[i] = min(p[id * 2 - i], mx - i);
        } else {
            p[i] = 1;
        }
        while (ss[i - p[i]] == ss[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
        ans = max(ans, p[i] - 1);
    }
}
int main()  {
    int Case = 0;
    while (cin >> s && s[0] != 'E') {
        Manacher();
        cout << "Case " << ++Case << ": " << ans << endl;
    }
    return 0;
}
