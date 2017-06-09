/* abcd % M  =  a * 1000 % M + b * 100 % M + c * 10 % M + d % M
             = ((((a) % M * 10 + b ) % M * 10 + c) % M * 10 + d) % M */
/* sicily 1020 */

#include <iostream>
using namespace std;

int main() {
    int b[101], result[101];
	int T, n;
    string x;
    cin >> T;
    
	while (T--) {
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        cin >> x;
        string::size_type x_len = x.size();

		for (int i = 0; i < n; i++) {
            result[i] = 0;
			for (int j = 0; j < x_len; j++) {
                result[i] = (result[i] % b[i]) * 10 + (x[j] - '0');
			}
			result[i] %= b[i];
		}
        
        cout << "(" << result[0];
		for (int i = 1; i < n; i++) {
            cout << "," << result[i];
		}
        cout << ")" << endl;
	}
	return 0;
}

