#include <iostream>

using namespace std;

void letters(int len, bool reversed) {
    if(!reversed) {
	for(int i = 0; i < len; i ++) {
	    cout << (char)('A' + i);
	}
    } else {
	for(int i = len - 1; i >= 0; i --) {
	    cout << (char)('A' + i);
	}
    }
}

void spaces(int n) {
    for(int i = 0; i < n; i ++)
	cout << " ";
}

int main() {
    int n;
    cin >> n;
    
    n --;
    
    letters(n + 1, false);
    letters(n, true);
    cout << endl;
    
    for(int i = 0; i < n; i ++) {
	letters(n - i, false);
	spaces(2 * i + 1);
	letters(n - i, true);
	cout << endl;
    }
    
    return 0;
}
