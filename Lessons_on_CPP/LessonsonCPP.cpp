// LessonsonCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

using namespace std;

int simpleArraySum(int n, vector <int> ar) {
	// Complete this function
	int sum = 0;
	vector<int>::iterator par;
	for (par = ar.begin(); par <= ar.end(); par++)
		sum += *par;
	
	return sum;
}

int main() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int ar_i = 0; ar_i < n; ar_i++) {
		cin >> ar[ar_i];
	}
	int result = simpleArraySum(n, ar);
	cout << result << endl;
	return 0;
}