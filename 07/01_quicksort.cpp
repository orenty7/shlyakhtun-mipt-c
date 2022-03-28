#include <iostream>
#include <vector>

using namespace std;

void print(int *p, int n) {
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n";
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

vector<int> quicksort(vector<int> arr) {
    if (arr.size() <= 1)
        return arr;
    int mid = arr[0];
    vector<int> right;
    vector<int> left;

    for (int i = 1; i < arr.size(); i++) {
        int elem = arr[i];
        if (elem < mid)
            left.push_back(elem);
        else
            right.push_back(elem);
    }
    left = quicksort(left);
    right = quicksort(right);

    left.push_back(mid);

    for (int elem : right) {
        left.push_back(elem);
    }

    return left;
}

void quicksort(int *p, int n) {
    if (n <= 1)
        return;

    int &mid = p[0];
    int left = 1;
    int right = n;

    while (left < right) {
        while (p[left] <= mid && left < right)
            left++;
        while (p[right - 1] >= mid && left < right)
            right--;

        if (left >= right)
            break;

        swap(p[left], p[right - 1]);
    }
    swap(mid, p[left - 1]);
    quicksort(p, left - 1);
    quicksort(p + left, n - left);
}
int main() {
    int a[] = {1, 2, 5, 2, 5, 6};

    print(a, 6);

    quicksort(a, 6);

    print(a, 6);

    return 0;
}
