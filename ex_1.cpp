#include <iostream>
using namespace std;

//clase racional dada por la guia
class Racional {
private:
	int num, den;
public:
	Racional(int n, int d): num(n), den(d) {}
	int VerNum() const { return num; }
	int VerDen() const { return den; }
	//pre incremento
	Racional &operator++() {
		num = num+den;
		return *this;
	}
	//post incremento
	Racional operator++(int) {
		Racional v(num,den);
		num += den;
		return v;
	}
};

Racional operator+(Racional r1, Racional r2){
	int n = r1.VerNum()*r2.VerDen()+r1.VerDen()*r2.VerNum();
	int d = r1.VerDen()*r2.VerDen();
	return Racional(n,d);
}
Racional operator*(Racional a, Racional b){
	int n = a.VerNum() * b.VerNum();
	int d = a.VerDen() * b.VerDen();
	return Racional(n,d);
}
Racional operator*(Racional a, int x){
	Racional mult(a.VerNum()*x,a.VerDen());
	return mult;
}
void VerRac(Racional c){
	cout << c.VerNum() << "/" << c.VerDen() << endl;
}

int main() {
	
	Racional a(3,5), b(2,3), c(0,1);
	
	cout << "Suma: " << endl;
	c = a+b; //sobrecarga de suma 
	//este anda bien 
	VerRac(c);
	//sobrecarga de multiplicacion de dos racionales, funciona bien
	cout << "Multiplicacion entre racionales: " << endl;
	c = a*b; 
	VerRac(c);
	//sobrecarga multiplicacion racional * entero, funciona bien
	cout << "Multiplicacion racional * entero: " << endl;
	Racional d = a*3;
	VerRac(d);
	
	//funciona 
	cout << "Suma de 3 racionales: " << endl;
	c = a+b+c;
	VerRac(c);
	
	//funciona bien 
	cout << "Multiplicacion de 3 racionales: " << endl;
	c = a*b*c;
	VerRac(c);
	
	//funciona
	cout << "Post incremento: " << endl;
	b = c++;
	VerRac(b);
	
	//funciona pero no hace bien el calculo, con otros numeros si anda
	cout << "Pre incremento: " << endl;
	a = ++c;
	VerRac(a);
	
	return 0;
}

