#include <iostream>
using namespace std;

int main(){
	
	int n = 38;
	
	int sp = 0, si= 0,r = 0, c = 0;
	
	while(n > 0){
		r = (n % 10);
		if(r % 2 != 0) si = si + r;
		else sp = sp + r;
		
		n = n / 10;
		c = c + 1;
		
		cout << n << endl;
		cout << r << endl;
		cout << sp << endl;
		cout << si << endl;
		cout << c << endl << endl;
	}
	
	cout << endl << endl << endl;
	cout << sp << endl;
	cout << si << endl;
	cout << c << endl;
	cout << si + sp << endl;
	
	return 0;
}
