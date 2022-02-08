#include <iostream>

void reverse(int &a) {
    int reversed = 0;
    
    while(a > 0) {
	reversed *= 10;
	reversed += a % 10;
	a /= 10;
    }
    a = reversed;
}


using namespace std;

int main() {
    int a;
    cin >> a;
    
    reverse(a);
    
    cout << a << endl;
    
    return 0;
}
