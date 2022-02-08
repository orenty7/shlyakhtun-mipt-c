#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> equation(double a, double b, double c) {
    double D = b * b - 4 * a * c;
    if (D > 0) {
        return {(-b - sqrt(D)) / (2 * a), (-b + sqrt(D)) / (2 * a)  };
    } else if  (D == 0) {
        return {-b / (2 * a)};
    } else {
        return {};
    }
}

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        int tmp = a;
        a = b % a;
        b = tmp;
    }
    return a + b;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void io_equation() {
    double a, b, c;
    cout << "Enter equation" << endl;

    cout << "a: ";
    cin >> a;

    cout << "b: ";
    cin >> b;

    cout << "c: ";
    cin >> c;

    vector<double> solutions = equation(a, b, c);
    if(solutions.size() == 2) {
        cout << "Your equation has two solutions: " << solutions[0] << " and " << solutions[1] << endl;
    } else if(solutions.size() == 1) {
        cout << "Your equation has one solution: " << solutions[0] << endl;
    } else {
        cout << "Your equation has no solution" << endl;
    }
}


void io_gcd() {
    int a, b;
    cout << "Enter two number to count their greatest common divider" << endl;

    cout << "a: ";
    cin >> a;

    cout << "b: ";
    cin >> b;

    cout << "Greatest common divider of your numbers is " << gcd(a, b) << endl;
}


void io_lcm() {
    int a, b;
    cout << "Enter two number to count their least common multiple" << endl;

    cout << "a: ";
    cin >> a;

    cout << "b: ";
    cin >> b;

    cout << "Least common multiple of your numbers is " << lcm(a, b) << endl;
}


int main() {
    io_equation();
    io_gcd();
    io_lcm();

    return 0;
}
