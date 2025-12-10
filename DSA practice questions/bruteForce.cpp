#include<iostream>
#include<string>

using namespace std;

bool bruteForceSearch(const string &text, const string &pattern){
	int n = text.length();
	int m = pattern.length();
	
	for (int i = 0;i <= n-m; i++){
		int j;
		for ( j = 0; j < m;j++){
			if(text[i+j] != pattern[j])
			break;
		}
		if(j == m){
			return true;
		}
	}
	return false;
}

int main(){
	string text = "Hello Fastians, Best of luck for Finals";
	string pattern = "Fastians";
	
	  if (bruteForceSearch(text, pattern))
        cout << "Pattern found!" << endl;
    else
        cout << "Pattern not found!" << endl;

    return 0;
}