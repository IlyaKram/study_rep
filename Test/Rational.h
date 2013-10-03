class Int;

class Rational
{
public:
	Rational(int nNum, int nDen);
	void Simplify();
	Rational& operator+= (Rational& B);
	Rational& operator*= (Rational& B);

	friend Rational operator+ (Rational& A, Int& B);

	operator double() const;

	void Sum(Rational B);
	void Dec(Rational B);
	void Mul(Rational B);
	void Div(Rational B);

	void Print();

	inline int GetNum() const { return m_nNum; }
	inline int GetDen() const { return m_nDen; }
private:
	int   m_nNum;
	int   m_nDen;
};

class Int
{
public:
	Int(int nVal);
	friend Rational operator+ (Rational& A, Int& B);
	inline int GetNum() const { return m_nVal; }
private:
	int   m_nVal;
};

Rational operator+ (Rational& A, Int& B);


Rational operator+ (Rational& A, Rational& B);
Rational operator* (Rational& A, Rational& B);
Rational operator^ (Rational& A, int nDeg);
