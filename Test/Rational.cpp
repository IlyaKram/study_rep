#include "Rational.h"
#include "AlgoHelper.h"
#include "stdio.h"

Rational::Rational(int nNum, int nDen) : m_nNum(nNum),
										 m_nDen(nDen)
{
}

Rational operator+ (Rational& A, Int& B)
{
	Rational Res = Rational(B.m_nVal, 1);
	Res += A;
	return Res;
}

Rational& Rational::operator+= (Rational& B)
{
	Sum(B);
	return *this;
}

Rational& Rational::operator*= (Rational& B)
{
	Simplify();
	m_nNum *= B.GetNum();
	m_nDen *= B.GetDen();
	Simplify();
	return *this;
}

Rational::operator double() const
{
	return double(m_nNum)/double(m_nDen);
}

Rational operator+ (Rational& A, Rational& B)
{
	Rational Res = A;
	Res += B;
	return Res;
}

Rational operator* (Rational& A, Rational& B)
{
	Rational Res = A;
	Res *= B;
	return Res;
}

Rational operator^ (Rational& A, int nDeg)
{
	Rational RatTmp(A);
	for (int i = 0; i < nDeg; i++)
	{
		RatTmp *= A;
	}
	return RatTmp;
}

void Rational::Sum(Rational B)
{
	Simplify();
	B.Simplify();
	int nNOK = AlgoHelper::GetNOK(m_nDen, B.GetDen());
	m_nNum = m_nNum * ( nNOK / m_nDen )
			 + B.GetNum() * (nNOK / B.GetDen());
	m_nDen = nNOK;
	Simplify();
}

void Rational::Dec(Rational B)
{
	Simplify();
	B.Simplify();
	int nNOK = AlgoHelper::GetNOK(m_nDen, B.GetDen());
	m_nNum = m_nNum * ( nNOK / m_nDen )
			 - B.GetNum() * (nNOK / B.GetDen());
	m_nDen = nNOK;
	Simplify();
}

void Rational::Mul(Rational B)
{
	Simplify();
	B.Simplify();
	m_nNum *= B.GetNum();
	m_nDen *= B.GetDen();
	Simplify();
}

void Rational::Div(Rational B)
{
	Simplify();
	B.Simplify();
	m_nNum *= B.GetDen();
	m_nDen *= B.GetNum();
	Simplify();
}

void Rational::Simplify()
{
	int nNOD = AlgoHelper::GetNOD(m_nNum, m_nDen);
	m_nNum /= nNOD;
	m_nDen /= nNOD;
}

void Rational::Print()
{
	printf( " %d/%d \n" , m_nNum , m_nDen ) ;
}
