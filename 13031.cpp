//Accept 03/09/2016
//Anderson
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	int t, n, ki, pi;
	unsigned long long int resp = 0, tot_bat, bat_count[1001];
	set<unsigned int> power;
	cin >> t;
	
	for(int i = 1; i <= t; ++i){
		cin >> n;
		memset(bat_count, 0, sizeof(bat_count));
		power.clear();
		tot_bat = resp = 0;
		for(int j = 0; j < n; ++j){
			cin >> ki >> pi;
			power.insert(pi);
			bat_count[pi] += ki;
			tot_bat += ki;
		}

		for(auto it = power.begin(); it != power.end(); ++it){
			pi = *it;
			ki = bat_count[pi];
			resp = max(resp, tot_bat*pi);
			tot_bat -= ki;
		}
		cout << "Case " << i << ": " << resp << endl;
	}
    return 0;
}
