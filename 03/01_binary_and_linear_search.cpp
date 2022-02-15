#include <iostream>
 
using namespace std;

void separator(int);
void print_array(int [], int);

pair<int, int> b_search(int arr[], int elem, int size) {
    int min = 0;
    int max = size - 1;

    int comparations = 0;
    
    cout << "Searching..." << endl;
    
    while(min != max) {
	int mid = (min + max) / 2;

	cout << "Current array is: " << endl;
	print_array(arr + min, max - min + 1);
	cout << endl;

	cout << "Testing elem with index " << mid << endl;
	cout << "Elem is: " << arr[mid] << endl;
	
	comparations ++; 
	if(arr[mid] == elem) {
	    cout << "Correct, found" << endl;
	    return {mid, comparations};
	}
	else if(arr[mid] > elem) {
	    cout << "Bigger than elem we search, testing lower part" << endl;
	    max = mid - 1;
	}
	else {
	    cout << "Smaller than elem we search, testing upper part" << endl;
	    min = mid + 1;
	}
	separator(5);
    }
    comparations ++;
    cout << "Left one element: " << arr[min] << endl;
    if(arr[min] == elem) {
	cout << "Found" << endl;
	return {min, comparations};
    }
    cout << "Elem not in array" << endl;
    return {-1, comparations};
}

int l_search(int arr[], int elem, int size) {
    for(int i = 0; i < size; i ++)
	if(arr[i] == elem)
	    return i;

    return -1;
}

void separator(int n) {
    n = 6 - n;
    cout << endl;
    for(; n > 0; n --) {
	cout << "--------------";
    }
    cout << endl << endl;
}

void print_array(int arr[], int size) {
    for(int i = 0; i < size - 1; i ++)
	cout << arr[i] << ", " ;
    cout << arr[size - 1];
}

void print_s_if_plural(int n) {
    if(n > 1)
	cout << 's';
}

void read_num(int &n) {
    cout << "Enter num(enter -1 to exit): ";
    cin >> n;
}

int main() {
    int arr[10];

    for(int i = 0; i < 10; i ++) {
	arr[i] = i + 1;
    }
    
    cout << "Your array is:" << endl;
    print_array(arr, 10);
    cout << endl;
    
    int n;
    read_num(n);

    while(n != -1) {
	separator(1);
	pair<int, int> res = b_search(arr, n, 10);
	int search_result = res.first;
	int comparations = res.second;
	separator(1);
	if(search_result == -1)
	    cout << "Not found" << endl;
	else
	    cout << "Index is: " << search_result << endl;

	cout << "Used " << comparations << " comparation";
	print_s_if_plural(comparations);
	cout << endl;
	read_num(n);
    }

    return 0;
}
	
