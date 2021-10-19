#include <iostream>
using namespace std;

class Racional {
private:
	int num, den;
public:
	Racional() {}
	Racional(int n, int d): num(n), den(d) {}
	int VerNum() const { return num; }
	int VerDen() const { return den; }
};
//sobrecarga de << 
ostream &operator<<(ostream &o, Racional r){
	o << r.VerNum() << '/' << r.VerDen();
	return o;
}
int main() {
	
	Racional r1, r2;
	cin >> r1 >> r2;
	cout << "Racionales: " << endl;
	cout << r1 << endl;
	cout << r2 << endl;
	
	return 0;
}

