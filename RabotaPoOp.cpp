#include "pch.h"
#include <iostream>
using namespace std;

template <typename Mtx>

class MATRIX
{
public:
	Mtx** Matrix;
	int n;
	int m;

public:
	MATRIX() 
	{
		n = m = 0;
		Matrix = 0;
	}
	
	MATRIX(int n1, int m1)
	{
		m = m1, n = n1;
		Matrix = (Mtx**) new Mtx*[n];
		for(int i = 0; i < n; i++)
			Matrix[i] = (Mtx*) new Mtx[m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				Matrix[i][j] = rand()% 21-10;
			}
	};



	Mtx PoluchitMatrixIJ(int i, int j, Mtx value)
	{
		if ((n > 0) && (m > 0))
			return Matrix[i][j];
		else
			return 0;
	}



	void ZadatMatrixIJ(int i, int j, Mtx value)
	{
		if ((i < 0) || (i >= n))
			return 0;
		else if ((j < 0) || (j >= m))
			return 0;
		Matrix[i][j] = value;
	}


	friend void print(const MATRIX<Mtx>& Default);


	friend void add(const MATRIX<Mtx>& Default1, const MATRIX<Mtx>& Default2);


	friend void mult(const MATRIX<Mtx>& Default1, const MATRIX<Mtx>& Default2);


	~MATRIX()
	{
		if (m > 0)
		{
			for (int i = 0; i < m; i++)
				delete[] Matrix[i];
		}

		if (n > 0)
			delete[] Matrix;
	}


};



template <typename Mtx>
void print(MATRIX<Mtx>& Default)
{
	for (int i = 0; i < Default.n; i++)
	{
		for (int j = 0; j < Default.m; j++)
		{
			cout << Default.Matrix[i][j] << "\t";
		}
		cout << "\n";


	}
	cout << endl;
}


template <typename Mtx>
void add(MATRIX<Mtx>& Default1, MATRIX<Mtx>& Default2)
{
	MATRIX<Mtx> MatrixDef1(Default1.n, Default1.m);
	for (int i = 0; i < Default1.n; i++)
		for (int j = 0; j < Default1.m; j++)
			MatrixDef1.Matrix[i][j] = 0;


	for(int i = 0; i < Default1.n; i++)
		for (int j = 0; j < Default1.m; j++)
		{
			MatrixDef1.Matrix[i][j] = Default1.Matrix[i][j] + Default2.Matrix[i][j];
			
		}
	print(MatrixDef1);
}


template <typename Mtx>
void mult(MATRIX<Mtx>& Default1, MATRIX<Mtx>& Default2)
{
	MATRIX<Mtx> MatrixDef1(Default1.n, Default1.m);
	for (int i = 0; i < Default1.n; i++)
		for (int j = 0; j < Default1.m; j++)
			MatrixDef1.Matrix[i][j] = 0;


	int** matrx2;
	matrx2 = new int*[Default1.n];
	for (int i = 0; i < Default1.n; i++)
	{
		matrx2[i] = new int[Default2.m];
		for (int j = 0; j < Default2.m; j++)
		{
			matrx2[i][j] = 0;
			for (int k = 0; k < Default1.m; k++)
				matrx2[i][j] += Default1.Matrix[i][k] * Default2.Matrix[k][j];
		}
	}
	for (int i = 0; i < Default1.n; i++)
	{
		for (int j = 0; j < Default2.m; j++)
			cout << matrx2[i][j] << " ";
		cout << endl;
	}
}







int main()
{
	MATRIX<int> Matrix1(3, 3), Matrix2(3,3);
	print(Matrix1);
	print(Matrix2);
	add(Matrix1, Matrix2);
	mult(Matrix1, Matrix2);
		

}

