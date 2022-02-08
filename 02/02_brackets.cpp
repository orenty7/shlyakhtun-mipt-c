#include <iostream>


#define ENABLE_COLORS 1

#if ENABLE_COLORS 

#define RED    "\033[31m"  // Escape color codes 
#define YELLOW "\033[33m"  // Wikipedia says that it should work everywhere, because it is from the ANSI standards
#define GREEN  "\033[32m"  // But I haven't tested it on non-linux systems, so it can be broken
                           // Change ENABLE_COLORS to 0 if it messed up the output
#define RESET "\033[0m"

#else

#define RED    ""  
#define YELLOW ""
#define GREEN  "" 

#define RESET ""

#endif


using namespace std;


int main() {
    int n;
    cin >> n;
    
    int stack = 0;
    bool is_correct = true;
    
    for (int i = 0; i < n; i ++) {
	char tmp;
	cin >> tmp;
	
	if (tmp == '(')
	    stack ++;
	else if (tmp == ')')
	    stack --;
	else {
	    cerr << RED "Incorrect input" RESET << endl;
	    return 5;
	}
	
	if (stack < 0) {
	    is_correct = false;
	    break;
	}
    }
    
    if (is_correct && !stack)
	cout << GREEN "correct" RESET << endl;
    else if (is_correct)
	cout << YELLOW "correct, but no closing bracket" RESET << endl;
    else
	cout << RED "incorrect" RESET << endl;
    
    return 0;
}
