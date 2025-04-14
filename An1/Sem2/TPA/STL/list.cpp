#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> lista;
	int n, x;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		lista.push_back(x);
	}

	for(int val : lista)
		cout << val << " ";

	cout << endl;
	lista.push_front(10);
	cout << lista.size() << endl;
	lista.pop_back();

	for(int val : lista)
		cout << val << " ";
	return 0;
}