#include <iostream>
using namespace std;

class Complejo {
private:
	float m_real, m_imag;
public:
	Complejo() {}
	Complejo(float r, float i): m_real(r), m_imag(i) {}
	float VerReal() const { return m_real; }
	float VerImag() const { return m_imag; }
};

ostream &operator<<(ostream &o, Complejo c1){
	o << c1.VerReal() << "+" << c1.VerImag() << "i";
	return o;
}

istream &operator>>(istream &i, Complejo &c1){
	float real, imag;
	i >> real >> imag;
	c1 = Complejo(real,imag);
	return i;
}

Complejo operator+(Complejo c1, Complejo c2){
	float r = c1.VerReal() + c2.VerReal();
	float i = c1.VerImag() + c2.VerImag();
	return Complejo(r,i);
}
Complejo operator-(Complejo c1, Complejo c2){
	float r = c1.VerReal() - c2.VerReal();
	float i = c1.VerImag() - c2.VerImag();
	return Complejo(r,i);
}
bool operator==(Complejo c1, Complejo c2){
	return c1.VerReal()==c2.VerReal() and c1.VerImag()==c2.VerImag();
}
Complejo operator*(Complejo c1, Complejo c2){
	float t1 = c1.VerReal() * c2.VerReal();
	float t2 = c1.VerReal() * c2.VerImag();
	float t3 = c1.VerImag() * c2.VerReal();
	float t4 = c1.VerImag() * c2.VerImag() * (-1);
	float r = t1+t4;
	float i = t2+t3;
	return Complejo(r,i);
}
int main() {
	
	Complejo c1, c2, c3;
	cout << "Ingrese dos complejos: " << endl;
	cin >> c1 >> c2;
	
	c3 = c1+c2;
	cout << "Suma: " << c3 << endl;
	
	c3 = c1-c2;
	cout << "Resta: " << c3 << endl;
	
	if(c1==c2) cout << "Son iguales" << endl;
	else cout << "No son iguales" << endl;
	
	c3 = c1*c2;
	cout << "Multiplicacion: " << c3 << endl; 
	
	return 0;
}

