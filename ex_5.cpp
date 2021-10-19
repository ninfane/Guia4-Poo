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
	float operator[](int i){
		if(i==0) return m_real;
		else return m_imag;
	}
};
istream &operator>>(istream &i, Complejo &c1){
	float real, imag;
	i >> real >> imag;
	c1 = Complejo(real,imag);
	return i;
}
int main() {
	
	Complejo c;
	cout << "Ingrese numero complejo" << endl;
	cin >> c;
	
	cout << "Parte real: " << c[0] << endl;
	cout << "Parte imaginaria: " << c[1] << endl;
	
	return 0;
}

