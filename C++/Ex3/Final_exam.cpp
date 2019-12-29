template<typename T>
class Complex {
	friend operator+(const Complex& a, const Complex& b);
private:
	T real;
	T imagine
public:
	Complex(T = 0.0, T = 0.0);
	Complex add(const Complex&);
	Complex subtract(const Complex&);
	void printComplex();
	void setComplexnumber(T, T);

	//Complex& operator+(const Complex& right) {
	//	Complex& c = new Complex();
	//	c->add(*this);
	//	c->add(b);
	//	return *c;
	//}
};

template <typename T>
Complex& operator+(const Complex& a, const Complex& b) {

}
