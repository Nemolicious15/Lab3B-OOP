// stdafx.cpp : source file that includes just the standard includes
// Lab3Pointeri.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information


#include "stdafx.h"
#include<iostream>
#include<assert.h>
#include<math.h>
using namespace std;

// CITIRE VECTOR

void readData(int&n, int* &x)
{
	// Functia citeste elem unui vector
	// In: n- nr int, repr lungimea vectorului 
	//     x- un vector cu nr int
	// Out: -

	cout << "Dati nr n= ";
	cin >> n;
	x = new int[n+1];
	for (int i = 1; i <= n; i++)
	{
		cout << "x[" << i << "]= ";
		cin >> x[i];
	}

}
// AFISARE VECTOR
void printData(int n, int* x)
{

	// Functia afiseaza elem unui vector
	// Out: n- nr int, repr lungimea vectorului 
	//      x- un vector cu nr int
	// In: -

	for (int i = 1; i <= n; i++)
		cout << x[i] << " ";
}
// MINIMUL
int minim(int n, int* x)
{

	// Functia determina cel mai mic elem din vectorul x
	// In: n- nr int, repr lungimea vectorului 
	//     x- un vector cu nr int
	// Out: cel mai mic element din vector

	int mini = x[1];
	for (int i = 2; i <= n; i++)
	{
		if (mini>x[i]) mini = x[i];
	}
	return mini;
}
//FUNCTIA DE TESTARE PT minim()
void testMini()
{	
	int* b,* a;
	b = new int[6];
	b[1] = 1;
	b[2] = 2;
	b[3] = 3;
	b[4] = 4;
	b[5] = 5;

	a = new int[5];
	a[1] = 2;
	a[2] = 3;
	a[3] = 45;
	a[4] = 3;


	assert(minim(5, b) == 1);
	assert(minim(4, a) == 2);

	cout << "teste ok";
	delete[] b; 
	delete[] a;

}
// VERIFICARE DACA UN ELEMENT ESTE PRIM
bool isPrime(int x)
{
	// Functia verifica daca x este prim
	// In: un nr nat x
	// Out: T/F
	if (x<2)
		return false;
	else
	{
		for (int i = 2; i <= sqrt(double(x)); i += 2)
		{
			if (x%i == 0)
			{
				return false;
			}
		}
		return true;
	}
}
//FUNCTIA DE TESTARE PT isPrime()
void testisPrime()
{
	assert(isPrime(7) == true);
	assert(isPrime(4) == false);
	assert(isPrime(2) == true);
	assert(isPrime(1) == false);
	assert(isPrime(0) == false);
	assert(isPrime(-1) == false);
	cout << "tests ok";
}
// SUMA ELEMENTELOR PRIME
int sumPrim(int n, int* x)
{

	// Functia determina suma elementelor prime din vector
	// In: n- nr int, repr lungimea vectorului 
	//     x- un vector cu nr int
	// Out: suma elementelor prime

	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isPrime(x[i]))
		{
			s = s + x[i];
		}
	}
	return s;
}
//FUNCTIA DE TESTARE PT sumPrim()
void testsumPrim()
{

	int* a,* b,* c;
	b = new int[6];
	b[1] = 12;
	b[2] = 4;
	b[3] = 7;
	b[4] = 3;
	b[5] = 5;

	a = new int[5];
	a[1] = 10;
	a[2] = 5;
	a[3] = 20;
	a[4] = 3;

	c = new int[6];
	c[1] = 2;
	c[2] = 3;
	c[3] = 8;
	c[4] = 8;
	c[5] = 10;

	assert(sumPrim(4, a) == 7);
	assert(sumPrim(5, b) == 15);
	assert(sumPrim(5, c) == 5);
	cout << "teste ok";
	delete[] a;
	delete[] b;
	delete[] c;

}
// VERIFICARE DACA UN ELEMENT ESTE PALINDROM
bool palindrom(int x)
{

	// Functia verifica daca x este palindrom
	// In: un nr nat x
	// Out: T/F

	int a, c = 0;
	a = x;
	while (a)
	{
		c = c * 10 + a % 10;
		a /= 10;
	}
	if (c == x)
	{
		return true;
	}
	else return false;
}
// FUNTIA DE TESTTARE PT palindrom()
void testPalindrom()
{
	assert(palindrom(121) == true);
	assert(palindrom(12) == false);
	assert(palindrom(0) == true);
	assert(palindrom(1) == true);
	assert(palindrom(111) == true);
	cout << "teste ok";
}
// SUMA ELEMENTELOR PALINDROM MAI MICI DECAT O VALOARE K DATA
int sumPalindrom(int n, int* x, int k)
{

	// Functia determina suma elementelor care: = sunt palindrom din vector
	//                                          = sunt mai mici decat o valoare k data 
	// In: n- nr int, repr lungimea vectorului 
	//     x- un vector cu nr int
	// Out: suma elementelor prime

	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		if ((palindrom(x[i])) && (x[i]<k))
		{
			s = s + x[i];
		}
	}
	return s;
}
// FUNCTIE DE TESTARE PT sumPalindrom()
void testsumPalindrom()
{
	int* a,* b,* c;
	b = new int[6];
	b[1] = 12;
	b[2] = 4;
	b[3] = 7;
	b[4] = 3;
	b[5] = 5;

	a = new int[5];
	a[1] = 10;
	a[2] = 5;
	a[3] = 20;
	a[4] = 3;

	c = new int[6];
	c[1] = 2;
	c[2] = 3;
	c[3] = 8;
	c[4] = 8;
	c[5] = 10;
	assert(sumPalindrom(4, a, 200) == 7);
	assert(sumPalindrom(5, b, 200) == 19);
	assert(sumPalindrom(5, c, 200) == 21);
	cout << "teste ok";
	delete[] a;
	delete[] b;
	delete[] c;
}

