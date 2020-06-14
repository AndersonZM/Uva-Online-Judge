//Accept 03/09/2016
//Anderson
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t, n, size;
	vector<string> dad;
	string mommy;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cin >> n;
		dad.clear();
		for(int j = 0; j < n; ++j){
			cin >> mommy;
			dad.push_back(mommy);
		}
		cin >> mommy;
		size = mommy.length();
		cout << "Case " << i << ":\n";
		for(auto it = dad.begin(); it != dad.end(); ++it){
			int mistake = 0;
			auto number = *it;
			for(int j = 0; j < size; ++j){
				if(mommy[j] != number[j]){
					if(++mistake > 1) break;
				}
			}
			if(mistake < 2) cout << number << endl;
		}
	}
	
	
    return 0;
}
