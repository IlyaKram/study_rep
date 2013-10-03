#include "AlgoHelper.h"

int AlgoHelper::GetNOK(int nA, int nB)
{
	return ( nA / GetNOD(nA, nB) ) * nB;
}

int AlgoHelper::GetNOD(int nA, int nB)
{
	if (nB == 0) {
		return nA;
	}
	return GetNOD(nB, (nA % nB));
}
