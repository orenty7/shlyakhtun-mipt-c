#include<iostream>

using namespace std;

bool is_prime(int n) {
  if (n % 2 == 0 && n != 2)
    return false;
  
  for (int i = 3; i * i <= n; i += 2) {
    if(n % i == 0)
      return false;
  
  }

  return true;
}

int reverse(int n) {
  int tmp = 0;
  while (n != 0) {
    tmp *= 10;
    tmp += n % 10;
    n /= 10;
  }
  return tmp;
}

inline int is_palindrome(int n) {
  return n == reverse(n);
}


int main() {
  int n;

  cin >> n;
  for(int i = 0; i < n; i ++) {
    int x;
    cin >> x;

    cout << (is_palindrome(x) ? "palindrome" : "common number") << endl;
    cout << (is_prime(x) ? "prime" : "composite") << endl;
  }
  return 0;
}
