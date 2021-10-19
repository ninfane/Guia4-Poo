#include <iostream>
using namespace std;

class Racional {
private:
	int num, den;
public:
	Racional(int n, int d): num(n), den(d) {}
	int VerNum() const { return num; }
	int VerDen() const { return den; }
};

bool operator<(Racional a, Racional b){
	return a.VerNum()*b.VerDen() < a.VerDen()*b.VerNum();
}
bool operator>(Racional a, Racional b){
	return a<b;
}
bool operator<=(Racional a, Racional b){
	return not (a<b);
}
int main() {
	
	Racional a(1,2), b(3,5); //3/5 es mayor que 1/2 (0.6 y 0.5 respec)
	
	//sobrecarga <
	//funciona bien 
	if(a<b) cout << "a es menor que b" << endl;
	else cout << "error" << endl;
	
	//sobrecarga >
	if(b>a) cout << "b es mayor que a" << endl;
	else cout << "error" << endl;
	
	return 0;
}

