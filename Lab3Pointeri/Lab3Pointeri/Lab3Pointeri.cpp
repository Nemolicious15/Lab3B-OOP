// Lab3Pointeri.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
using namespace std;


// FUNCTIA MAIN
int _tmain(int argc, _TCHAR* argv[])
{
	int n=0,* x, k;
	readData(n, x);
	cout << "Vectorul este= x[ ";
	printData(n, x);
	cout << "]";

	cout << endl << "Dati Valoarea k= ";
	cin >> k;
	cout << endl << "Minimul din vector este= " << minim(n, x);
	cout << endl << "Suma elementelor prime este= " << sumPrim(n, x);
	cout << endl << "Suma elementelor care sunt palindrom mai mici decat valoarea k este= " << sumPalindrom(n, x, k);


	
	
	delete[] x;
	_getch();
	return 0;
}

