#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void build_tree(int *p, int n) {
    int i = 1;
    while (i < n) {
        int j = i;
        while (p[j] > p[(j - 1) / 2]) {
            swap(p[j], p[(j - 1) / 2]);
            j = (j - 1) / 2;
        }
        i++;
    }
}

void fix_tree(int *p, int n) {
    int i = 0;
    while (i < (n - 1) / 2) {
        if (p[2 * i + 1] > p[i]) {
            if (p[2 * i + 1] > p[2 * i + 2])
                swap(p[2 * i + 1], p[i]);
            else
                swap(p[2 * i + 2], p[i]);
        } else if (p[2 * i + 2] > p[i]) {
            swap(p[2 * i + 2], p[i]);
        } else
            break;
    }
}

void sort(int *p, int n) {
    build_tree(p, n);
    while (n > 0) {
        swap(p[n - 1], p[0]);
        n--;
        fix_tree(p, n);
    }
}

void print(int *p, int n) {
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {1, 4, 67, 2, 6, 1, 6};

    sort(a, 7);
    print(a, 7);
    return 0;
}
