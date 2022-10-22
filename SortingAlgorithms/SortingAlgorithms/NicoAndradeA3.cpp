/*	Name: Nico Andrade
 *	Student ID: 201261260
 *	Email: andra106@csusm.edu
 * 
 *	Known error: calling mergeSort() sometimes causes the program to crash, but sometimes does not. Even with the same input.
*/
using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <vector>


/*	selectionSort()
*	1. Iterates through array and looks for highest value.
*	2. Swaps highest value for value at last index.
*	3. Repeats 1 and 2 for the sub array A[0..len - 1]	*/
void selectionSort(int A[], int len) {
	printf("Using selection sort\n");
	
	int index, max, maxLoc, end, store; //index is the current array index. min is the current minimum value, start is the starting value and gets iterated by one for each sorted element, stor is used for temporarily holding values.
	max = A[0];
	maxLoc = 0;
	end = len - 1;

	bool sorted;
	sorted = false;
	
	while (!sorted) {
		max = 0;
		maxLoc = 0;
		for (index = 0; index <= end; index++) { //iterate through array and find largest value
			if (A[index] > max) {
				max = A[index];
				maxLoc = index;
			}
		}
		
		//put the largest value at the end of the sub-array
		store = max;
		A[maxLoc] = A[end];
		A[end] = store;

		if (end == 0)
			sorted = true;
		else
			end--;
	}
	return;
}

/*	bubbleSort()
*	1. Compares adjacent indexes and swaps if the left is greater than the right.
*	2. Runs through the array until it has a run where it makes no swaps.	*/
void bubbleSort(int A[], int len) {
	cout << "Using Bubble Sort" << endl;
	int left, right, temp;//left and right store adjacent indexes. temp is used as a placeholder to swap.
	bool solved = false;

	while (!solved) {
		solved = true;
		for (int i = 0; i < len; i++) {
			left = i;
			right = i + 1;
			if ( ( right < len) && (A[left] > A[right]) ) {
				//swap
				temp = A[left];
				A[left] = A[right];
				A[right] = temp;
				solved = false;
			}
		}
		
		
	}

	return;
}

/*	insertionSort()
* 1. Compare two adjacent elements.
* 2. If right element is less than left element, swap it down and continue comparing
* 3. Once the element is in it's correct spot, continue from where the first swap occurred	*/
void insertionSort(int A[], int len) {
	cout << "Using Insertion Sort" << endl;
	int left, right, current, temp; //left and right are two adjacent indices. current is where the for loop left off. temp is used for swapping

	for (int i = 0; i < len; i++) {
		left = i;
		right = i + 1;
		if ((right < len) && (A[right] < A[left])) {
			while (A[right] < A[left]) {
				temp = A[left];
				A[left] = A[right];
				A[right] = temp;
				left--;
				right--;
			}
		}
	}
}

/*	partition()
*	This fuction calculates the pivot point.
*	1. pivot is set to r. i is set to p - 1. c is set to zero and used in the for loop.
*	2. It will iterate through the array or sub-array
*	3. If the current element is less than the pivot, elements c and i get swapped, and smaller element (i) is incremented.
*	4. It will then swap the low and high values (i and r) and return (i+1) as the result.	*/
int partition(int A[], int p, int r) {
	int pivot, q, l, temp;
	pivot = A[r];
	l = (p - 1);

	for (int c = p; c <= r - 1; c++) {
		if (A[c] <= pivot) {
			l++;
			temp = A[l];
			A[l] = A[c];
			A[c] = temp;
		}
	}
	temp = A[l + 1];
	A[l + 1] = A[r];
	A[r] = temp;

	return (l + 1);
}


/*	quicksort()
*	1. Returns to calling function if low bound(p) is >= high bound(r)
*	2. Else it will call partion()
*	3. Next it will recursively call quicksort() for both sub-arrays	*/
void quickSort(int A[], int p, int r) {
	if (p >= r) {
		return;
	}
	else {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

/*	Automatically calculates p and r. Then calls the real quickSort()	*/
void quickSort(int A[], int len) {
	quickSort(A, 0, len - 1);
}

/*	merge()
*	1. Iterates through both sub-arrrays
*	2. Puts each element from both sub-arrays into new array B. making sure they're in order
*	3. Copies the contents of B[] back into A[]
*/
void merge(int A[], int p, int q, int r) {
	int size = (r - p);
	int* B = new int[size];
	
	int i, j, k;
	i = k = p;
	j = q + 1;

	while(i <= q && j <= r) {
		if (A[i] <= A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}

	while (i <= q)
		B[k++] = A[i++];
	while (j <= r) 
		B[k++] = A[j++];
	for (i = p; i <= r; i++)
		A[i] = B[i];
}

/** mergeSort()
 *	1. returns if p >= r
 *	2. splits the array into 2 sub-arrays
 *	3. calls mergeSort() recursively on both sub-arrays
 *	4. calls merge() to combine the two sub-arrays	*/
void mergeSort(int A[], int p, int r) {
	if (p >= r)
		return;
	int q = (p + r) / 2;
	mergeSort(A, p, q);
	mergeSort(A, q + 1, r);
	merge(A, p, q, r);
}

/*	helper mergeSort()
*	calls the real mergeSort() above	*/
void mergeSort(int A[], int len) {
	cout << "Using Merge Sort" << endl;
	mergeSort(A, 0, len - 1);
}

/*	main()
*	1. Prompts the user to input a list of integers
*	2. Puts this input into a vector
*	3. Copies the contents of the vector to an array.
*	4. Prints out another prompt, asking the user which sorting algorithm they want.
*	5. Calls the selected algorith.
*	6. Prints the sorted array to the screen.
*/
int main(void) {
	int* masterArray;
	vector<int> input;

	cout << "Please enter a list of integers separated by space:" << endl;
	string line;
	getline(cin, line);
	istringstream iss(line);
	int num, i, len;
;
	while (iss >> num) {
		input.push_back(num);
	}
	masterArray = new int[input.size()];
	len = input.size();
	for (i = 0; i < input.size(); i++) {
		masterArray[i] = input[i];
	}


	for (i = 0; i < input.size(); i++) {
		cout << masterArray[i] << " ";
	}
	cout << endl;

	cout << "Which sorting algorithm would you like to use? \n 1.Selction Sort\n 2.Bubble Sort\n 3.Insertion Sort\n 4.Quick Sort\n 5.Merge Sort" << endl;
	int selection;
	cin >> selection;

	
	switch (selection) {
	case 1:	
		selectionSort(masterArray, len); 
		break;
	case 2:
		bubbleSort(masterArray, len); 
		break;
	case 3:
		insertionSort(masterArray, len);
		break;
	case 4: 
		quickSort(masterArray, len); 
		break;
	case 5:
		mergeSort(masterArray, len);
		break;
	default: 
		cout << "Error: illegal selection." << endl; 
		return -1;
	}
	
	
	for (i = 0; i < len; i++) {
		cout << masterArray[i] << " ";
	}
	
	return 0;
}