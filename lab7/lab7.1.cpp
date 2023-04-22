#include <iostream>
#include <string>
using namespace std;

int findMin(int arr[], int n) {
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

int findMin(string str) {
	int minLen = str.length();
	int len = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			if (len < minLen) { minLen = len; }
			len = 0;
		}
		else { len++; }
	}
	if (len < minLen) minLen = len;
	return minLen;
}

int main() {
	setlocale(0, "");
	int arr[] = { 5, 2, 8, 1, 7 };
	int arrSize = 5;
	cout << "Минимальное число: " << findMin(arr, arrSize) << endl;
	string str = "Dog and cat sitting on a beanch";
	cout << "Минимальная длина слова: " << findMin(str) << endl;
	return 0;
}