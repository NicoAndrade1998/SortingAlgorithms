using namespace std;
#include <iostream>
#include <string>
#include <sstream>

void selectionSort(int A[], int len) {

}
void bubbleSort(int A[], int len) {

}
void insertionSort(int A[], int len) {

}
void quickSort(int A[], int len) {

}
void mergeSort(int A[], int len) {

}
int main(void) {
	int* usrinput;

	cout << "Please enter a list of integers separated by space:" << endl;
	string line;
	getline(cin, line);
	istringstream iss(line);
	int num, i, len;
	len = 0;
	while (iss >> num) {
		len++;
	}

	usrinput = new int[len];
	i = 0;
	while (iss >> num) {
		usrinput[i] = num;
		i++;
	}

	for (i = 0; i < len; i++) {
		cout << usrinput[i] << endl;
	}

	return 0;
}