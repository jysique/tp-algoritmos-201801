#include <conio.h>
#include <iostream>
#include <functional>
#include <iomanip>
using namespace std;

template<typename T>

T**p1(int n, int m) {
	T** t = new T*[n];
	for (int i = n - 1; i >= 0; i--) {
		t[i] = new T[m];

	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			t[i][j] = (T)(97 + j + i * m);
		}
	}
	return t;
}

void p3(int n, int m, int i, int j) {
	if (i <n){
		if (j>= 0) {
			cout << i * m + j;
			p3(n, m, i, j - 1);
		}
		else {
			cout << endl;
			p3(n, m, i + 1, m - 1);
		}
	}

}

void p2(int n, function<int(int&)> f) {
	for (int i = n; i < 0; i--)	{
		cout << f(i) << endl;
	}
}

int main()
{
	char**m = p1<char>(3, 4);
	cout << m[2] << m[0] << endl;

	p2(20, [](int& x) {return x--; });
		
	p3(3, 3, 0, 2);

	_getch();
}