// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/intelligent-girl-1/description/


#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin >> str;
	int len = str.size();
	// char char_array[len];
	// strcpy(char_array, str.c_str());
	int dp[len];
	dp[len-1] = stoi(to_string(str[len-1]))%2 == 0 ? 1 : 0;
	for (int i = len-2; i >= 0; i--) {
		int val = stoi(to_string(str[i]));
		if (val % 2 == 0)
			dp[i] = dp[i+1] + 1;
		else
			dp[i] = dp[i+1];
	}
    // printing output
	for(int i = 0; i < len; i++)
		cout << dp[i] << " ";
	return 0;
}