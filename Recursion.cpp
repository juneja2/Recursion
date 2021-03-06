#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

void target_count_in_main();
void helpFunc(int arr[], int target, int first, int last, int spaces);
int count(int arr[], int target, int first, int last);
bool isPal(string s, int first, int last);
string reverse(string s);

int main()
{
	try {
		target_count_in_main();

		string s[] = {"radar", "ab", "x", "abc", "aba", "123321", "xx", "xx1x"};
		for (int i = 0; i < 8; i++)
			cout << left << setw(50) << s[i] << (isPal(s[i], 0, s[i].length() - 1) ? "True\n": "False\n");

		string s0[] = {"Hello", "Hello world", "When in the course of human events"};
		for (int i = 0; i < 3; i++)
			cout << left << setw(50)  << s0[i] << reverse(s0[i]) << endl;
	}
	catch (char * error) {
		cout << error << endl;
		exit(EXIT_FAILURE);
	}
}
void target_count_in_main() {
	int arr[] = { 3, 9, 2, 7, 9, 4, 4, 3, 9 };

	int target[] = { 9, 4, 6, 9, 5 };

	cout << left << setw(30) << "Array" << setw(30) << "Target" << "Count\n";

	for (int i = 0; i < 2; i++)
		helpFunc(arr, target[i], 0, sizeof(arr) / sizeof(arr[0]) - 1, 15);

	int arr2[] = { 6 };
	helpFunc(arr2, target[2], 0, sizeof(arr2) / sizeof(arr2[0]) - 1, 31);

	int arr3[] = { 4, 6, 2, 3 };
	helpFunc(arr3, target[3], 0, sizeof(arr3) / sizeof(arr3[0]) - 1, 25);

	int arr4[] = { 12 };
	helpFunc(arr4, target[4], 0, sizeof(arr4) / sizeof(arr4[0]) - 1, 30);
}
void helpFunc(int arr[], int target, int first, int last, int spaces) {
	for (int j = first; j <= last; j++)
		cout << arr[j] << " ";
	cout << right << setw(spaces) << target << setw(30) << count(arr, target, first, last) << endl;
}
int count(int arr[], int target, int first, int last) {
	if (first == last)
		return (target == arr[first]? 1 : 0);
	else 
		return ((target == arr[first] ? 1 : 0) + count(arr, target, first + 1, last));
}
bool isPal(string s, int first, int last) {
	if (first >= last)
		return true;
	else if (s[first] != s[last]) return false;
	else return isPal(s, first + 1, last - 1);
}
string reverse(string s) {
	unsigned space_char_index = s.find(' ');
	if (space_char_index == string::npos)
		return s;
	else return (reverse(s.substr(space_char_index + 1)) + " " + s.substr(0, space_char_index));
}