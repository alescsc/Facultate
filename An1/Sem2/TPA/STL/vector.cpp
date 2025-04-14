#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	int n, x;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	for(int i = 0; i < n; i++)
		cout << v[i] << " ";

	cout << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;

	v.pop_back();

	for(int i = 0; i < n; i++)
		cout << v[i] << " ";

	cout << endl;

	cout << v.size() << endl;

	cout << v.empty();
	return 0;
}