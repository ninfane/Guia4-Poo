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
	Racional operator*(Racional b){
		int num = this->num*b.num;
		int den = this->den*b.den;
		Racional mult(num,den);
		return mult;
	}
	Racional operator*(int x){
		Racional mult(this->num*x,this->den);
		return mult;
	}
};

Racional operator+(Racional r1, Racional r2){
	int n = r1.VerNum()*r2.VerDen()+r1.VerDen()*r2.VerNum();
	int d = r1.VerDen()*r2.VerDen();
	return Racional(n,d);
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
	
	cout << "Multiplicacion de 3 racionales: " << endl;
	c = a*b*c;
	/*
	cout << "Post incremento: " << endl;
	b = c++;
	VerRac(b);
	
	cout << "Pre incremento: " << endl;
	a = ++c;
	VerRac(a);*/
	
	return 0;
}

