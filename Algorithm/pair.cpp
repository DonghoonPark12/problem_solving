#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, string> pis;

int main(){
	vector<pair<int, string>> v;
	
	v.push_back(pis(3, "Dok2"));
	v.push_back(pis(6, "DMask"));
	v.push_back(pis(1, "Tiger JK"));
	v.push_back(pis(2, "Banana"));
	v.push_back(pis(2, "Apple"));
	
	cout << "===== Before Sort =====" <<endl;
	
	vector<pis>::iterator iter;
	for(iter = v.begin(); iter != v.end(); iter++){
		cout<<"["<<iter->first<<","<<iter->second<<"]"<<endl;
	}
	cout<<endl;

	sort(v.begin(), v.end())
	cout<< "===== After Sort =====" <<endl;
	for(iter = v.begin(); iter != v.end(); iter++){
		cout<<"["<<iter->first<<","<<iter->second<<"]"<<endl;
	}
	
	return 0;
}