#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
	int n;	
	cin >> n;
	
	int weight[26] = {0,};

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		 
		for (int j = word.length()-1; j >= 0; j--){
		    char c = (char)word[j];
		    weight[c-65] += pow(10, word.length()-j-1);
		}
	}
	
	sort(weight, weight+26, greater<int>()); 
	
	int ans = 0;
	for(int i = 9; i >= 0; i--){
	    ans += i * weight[9-i];
	}
	
	cout << ans;
}
