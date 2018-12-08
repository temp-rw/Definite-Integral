#pragma once
#ifndef MATRIX_H
#define MATRIX_H


#include <string>
#include <fstream>
#include <iostream>

enum Print_type{
	dont_close = 0,
	close = 1
};

template <class T>
class Matrix
{
	T** M;
	size_t xsize;
	size_t ysize;
public:
	Matrix();
	Matrix(size_t xsize = 3);
	Matrix(size_t xsize, size_t ysize);
	Matrix(size_t xsize, size_t ysize, T num = 0);
	Matrix(size_t xsize, size_t ysize, T** matr);
	Matrix(const Matrix&other);
	~Matrix();

	string Print(Print_type t = close);
	string Input();
	T StrSum(const size_t str_Number, const unsigned Number_of_elem = xsize);	//Ñóììà ýëåìåíòîâ ñòðîêè N
	T ColSum(const size_t col_Number, const unsigned Number_of_elem = ysize);	//Ñóììà ýëåìåíòîâ ñòîëáöà N
  /*T MMax();
	T MMin();
	T& MtoVect();*/

	//Âûáîð ãëàâíîãî ýëåìåíòà ïî ñòîëáöó (+ïåðåñòàíîâêà ñòðîê)
	void Col_Max(int, int);
	

	//Get 
	size_t Get_x();
	size_t Get_y();
	///////////////////////

	//òðàíñïîíèðîâàíèå ìàòðèöû
	void transform();

	//operators
	T* operator [](size_t _size);

	Matrix<T> operator +(const Matrix& M2);
	Matrix<T> operator -(const Matrix& M2);
	Matrix<T> operator *(const Matrix& M2);
	Matrix<T> operator *(const T& N);

	friend Matrix<T> operator * (T& N, Matrix<T>& M2)
	{
		if (N == 1) return Matrix(M2);
		/*Matrix<T> temp(M2);
		temp = M2 * N;*/
		//counter--;
		return M2 * N;
	}
	Matrix<T> operator /(const T& N);
	//Matrix<T> operator ^(const size_t& N);

	Matrix<T>& operator +=(const Matrix& M2);
	Matrix<T>& operator -=(const Matrix& M2);
	Matrix<T>& operator *=(const Matrix& M2);
	//Matrix<T>& operator ^=(const int& N);
	Matrix<T>& operator =(const Matrix& M2);
	Matrix<T>& operator *=(const T& N);
	Matrix<T>& operator /=(const T& N);

	bool operator == (const Matrix& M);
	bool operator != (const Matrix& M);

	friend istream& operator >> (istream& is, Matrix& M)
	{
		for (size_t i = 0; i < M.ysize; i++)
		{
			for (size_t j = 0; j < M.xsize; j++)
			{
				is >> M.M[i][j];
			}
		}
		return is;
	}
	friend ostream& operator << (ostream& os, const Matrix& M)
	{
		for (size_t i = 0; i < M.ysize; i++)
		{
			for (size_t j = 0; j < M.xsize; j++)
			{
				os << setw(14) << M.M[i][j];
			}
			os << endl;
		}
		return os;
	}
};

template<class T>//êîíñòðóêòîð áåç ïàðàìåòðîâ
Matrix<T>::Matrix() : xsize(10), ysize(10)
	{
		M = new T*[ysize];
		for (size_t i = 0; i < ysize; i++)
		{
			M[i] = new T[xsize];
		}

		for (size_t i = 0; i < ysize; i++)
		{
			for (size_t j = 0; j < xsize; j++)
			{
				M[i][j] = 0;
			}
		}
	}

template<class T>//êîíñòðóêòîð êâàäðàòíîé ìàòðèöû òèïà Mtype
Matrix<T>::Matrix(size_t _xsize) : xsize(_xsize)
	{
		size_t size = xsize;
		M = new T*[size];
		for (size_t i = 0; i < size; i++)
		{
			M[i] = new T[size];
		}

		//if (mt == Unit)//		åäèíè÷íàÿ ìàòðèöà
		//	for (size_t i = 0; i < size; i++)
		//	{
		//		for (size_t j = 0; j < size; j++)
		//		{
		//			if (i == j) { M[i][j] = 1; continue; }
		//			M[i][j] = 0;
		//		}
		//	}

		//if (mt == Null)//		íóëåâàÿ ìàòðèöà
		//{
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				M[i][j] = 0;
			}
		}
		//}
	}

template<class T>//êîíñòðóêòîð ìàòðèöû ðàçìåðà x * y òèïà Mtype 
Matrix<T>::Matrix(size_t _xsize, size_t _ysize) : xsize(_xsize), ysize(_ysize)
	{
		M = new T*[ysize];
		for (size_t i = 0; i < ysize; i++)
		{
			M[i] = new T[xsize];
		}

		/*if (mt == Unit)//		åäèíè÷íàÿ ìàòðèöà
			for (size_t i = 0; i < ysize; i++)
			{
				for (size_t j = 0; j < xsize; j++)
				{
					if (i == j) { M[i][j] = 1; continue; }
					M[i][j] = 0;
				}
			}*/

			//if (mt == Null)//		íóëåâàÿ ìàòðèöà
			//{
		for (size_t i = 0; i < ysize; i++)
		{
			for (size_t j = 0; j < xsize; j++)
			{
				M[i][j] = 0;
			}
		}
		//}
	}

template<class T>//êîíñòðóêòîð ìàòðèöû ðàçìåðà x * y ñîñòîÿùåé èç ÷èñåë num
Matrix<T>::Matrix(size_t _xsize, size_t _ysize, T num) : xsize(_xsize), ysize(_ysize)
	{
		M = new T*[ysize];
		for (size_t i = 0; i < ysize; i++)
		{
			M[i] = new T[xsize];
		}

		for (size_t i = 0; i < ysize; i++)
		{
			for (size_t j = 0; j < xsize; j++)
			{
				M[i][j] = num;
			}
		}
	}

template<class T>//êîíñòðóêòîð ìàòðèöû êîïèðóþùèé äâóìåðíûé ìàññèâ
Matrix<T>::Matrix(size_t _xsize, size_t _ysize, T** A) : xsize(_xsize), ysize(_ysize)
	{
		M = new T*[ysize];
		for (size_t i = 0; i < ysize; i++)
		{
			M[i] = new T[xsize];
		}

		for (size_t i = 0; i < ysize; i++)
		{
			for (size_t j = 0; j < xsize; j++)
			{
				M[i][j] = A[i][j];
			}
		}
	}

template<class T>//êîíñòðóêòîð êîïèðîâàíèÿ
Matrix<T>::Matrix(const Matrix& other) : xsize(other.xsize), ysize(other.ysize)
	{
		M = new T*[ysize];
		for (size_t i = 0; i < ysize; i++)
		{
			M[i] = new T[xsize];
		}

		for (size_t i = 0; i < ysize; i++)
		{
			for (size_t j = 0; j < xsize; j++)
			{
				M[i][j] = other.M[i][j];
			}
		}
	}

template<class T>//äåñòðóêòîð
Matrix<T>::~Matrix()
	{
		for (size_t i = 0; i < ysize; i++)
		{
			delete[] M[i];
			M[i] = nullptr;
		}
		delete[] M;
		M = nullptr;
	}


template <class T>//Ââîä èç ôàéëà
string Matrix<T>::Input()
{
		fstream fin;
		string file;// = "Matrix.txt";
		for (;;)
		{
			if (fin.is_open()) break;
			cout << "Íàïèøèòå èìÿ ôàéëà ââîäà:\n";
			cin >> file;
			fin.open(file);
			if (fin.is_open()) break;
			else {
				cout << "Íå âåðíîå èìÿ ôàéëà èëè ôàéë ïîâðåæä¸í\n";
				system("pause");
			}
		}

		for (size_t i = 0; i < ysize; i++)
		{
			for (size_t j = 0; j < xsize; j++)
			{
				fin >> M[i][j];
				//cout << setw(8) << M[i][j];
			}
			//cout << endl;
		}
		fin.close();
		return file;
}

template<class T>//Âûâîä â ôàéë
string Matrix<T>::Print(Print_type t)
	{
		ofstream fout;
		string file;
		for (;;)
		{
			if (fout.is_open()) break;
			cout << "Íàïèøèòå èìÿ ôàéëà âûâîäà:\n";
			cin >> file;
			fout.open(file, ofstream::app);
			if (fout.is_open()) break;
			else {
				cout << "Íå âåðíîå èìÿ ôàéëà èëè ôàéë ïîâðåæä¸í\n";
				system("pause");
			}
		}
		//fout.open(file, fstream::app);
		for (size_t i = 0; i < ysize; i++)
		{
			for (size_t j = 0; j < xsize; j++)
			{
				//cout << setw(8) << M[i][j];
				fout << setw(8) << M[i][j];
			}
			//cout << endl;
			fout << endl;
		}
		//cout << endl;
		if (t == close) fout.close();
		return file;
	}

template<class T>
void Matrix<T>::Col_Max(int Str_num, int Col_num)
	{
		//if (Str_num + 1 == ysize) return;
		T max = fabs(M[Str_num][Col_num]);
		int i_max = Str_num;					//ïåðåìåííàÿ õðàíÿùàÿ íîìåð ñòðîêè
		for (size_t i = Str_num; i < ysize; i++)
		{
			if (max < fabs(M[i][Col_num])) {
				max = fabs(M[i][Col_num]);
				i_max = i;
			}
		}
		//cout << "Ìàêñèìàëüíûé ýëåìåíò ñòðîêè " << Str_num << ": " << max << endl;
		if (max < 1e-12) {
			cout << "\nÌàòðèöà âûðîæäåííàÿ!!!\n";
			exit(101);
		}
		if (i_max == Str_num) return;
		else {
			swap(M[i_max], M[Str_num]);
		}
	}

template<class T>
size_t Matrix<T>::Get_x()
	{
		return this->xsize;
	}

template<class T>
size_t Matrix<T>::Get_y()
	{
		return this->ysize;
	}

template<class T>
void Matrix<T>::transform()
{
	Matrix<T> temp(*this);
	swap(xsize, ysize);		//swaps amount of rows with amount of columns

	this->M = new T*[ysize];
	for (size_t i = 0; i < ysize; i++)
	{
		this->M[i] = new T[xsize] {};
	}

	for (size_t i = 0; i < ysize; i++)
	{
		for (size_t j = 0; j < xsize; j++)
		{
			this->M[i][j] = temp.M[j][i];
		}
	}
}

template<class T>//ïåðåãðóæåííûé îïåðàòîð èíäåêñèðîâàíèÿ
T* Matrix<T>::operator[](size_t _size)
	{
		return M[_size];
	}

//Ïåðåãðóçêè àðèôìåòè÷åñêèõ îïåðàòîðîâ è îïåðàòîðîâ ïðèñâàèâàíèÿ

template<class T>
Matrix<T>& Matrix<T>::operator =(const Matrix& M2)
{
	if (xsize != M2.xsize || ysize != M2.ysize)
	{
		xsize = M2.xsize; ysize = M2.ysize;
		M = new T*[ysize];
		for (size_t i = 0; i < ysize; i++)
		{
			M[i] = new T[xsize];
		}
	}
	for (size_t i = 0; i < M2.ysize; i++)
	{
		for (size_t j = 0; j < M2.xsize; j++)
		{
			this->M[i][j] = M2.M[i][j];
		}
	}
	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator +(const Matrix& M2)
	{
		if (xsize != M2.xsize || ysize != M2.ysize)
		{
			cout << "Ìàòðèöû èìåþò ðàçíûå ðàçìåðû!\nÎïåðàöèÿ '+' íåâîçìîæíà!\n";
		}
		Matrix<T> temp(*this);
		for (size_t i = 0; i < M2.ysize; i++)
		{
			for (size_t j = 0; j < M2.xsize; j++)
			{
				temp[i][j] += M2.M[i][j];
			}
		}
		return Matrix(temp);
	}

template<class T>
Matrix<T> Matrix<T>::operator -(const Matrix& M2)
	{
		if (xsize != M2.xsize || ysize != M2.ysize)
		{
			cout << "Ìàòðèöû èìåþò ðàçíûå ðàçìåðû!\nÎïåðàöèÿ '+' íåâîçìîæíà!\n";
		}
		Matrix<T> temp(*this);
		for (size_t i = 0; i < M2.ysize; i++)
		{
			for (size_t j = 0; j < M2.xsize; j++)
			{
				temp[i][j] -= M2.M[i][j];
			}
		}
		return Matrix(temp);
	}

template<class T>
Matrix<T> Matrix<T>::operator *(const Matrix& M2)
{
	if (xsize != M2.ysize) {
		cout << "Îïåðàöèÿ óìíîæåíèÿ ìàòðèö íåâîçìîæíà:\n";
		cout << "êîëè÷åñòâî ñòîëáöîâ ïåðâîãî ñîìíîæèòåëÿ\n íå ðàâíî êîëè÷åñòâó ñòðîê âòîðîãî!\n";
		exit(001);
	}
		Matrix<T> temp(ysize, M2.xsize, 0.0);
	size_t n = 0, p;
	for (size_t i = 0; i < ysize; i++)
	{
	p = 0;
		for (size_t j = 0; j < M2.xsize; j++)
		{
			for (size_t k = 0; k < xsize; k++) {
				temp[i][j] += M[n][k] * M2.M[k][p];
			}
			p++;
		}
		n++;
	}
	return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator *(const T& N)
{
	if (N == 1) return *this;
	Matrix<T> temp(*this);
	for (size_t i = 0; i < ysize; i++)
	{
		for (size_t j = 0; j < xsize; j++)
		{
			if (temp[i][j] == 0) continue;
			temp[i][j] *= N;
		}
	}
	return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator /(const T& N)
{
	if (N == 0) cout << "Íà íîëü äåëèòü íåëüçÿ!!!\n"; exit(000);
	if (N == 1) return *this;
	Matrix<T> temp(*this);
	for (size_t i = 0; i < ysize; i++)
	{
		for (size_t j = 0; j < xsize; j++)
		{
			if (temp.M[i][j] == 0) continue;
			temp.M[i][j] /= N;
		}
	}
	return Matrix(temp);
}

/*template<class T>
	Matrix<T> Matrix<T>::operator ^(const size_t& N)
	{
		if (xsize != ysize) {
			cout << "Äëÿ âîçâåäåíèÿ â ñòåïåíü ìàòðèöà äîëæíà áûòü êâàäðàòíîé!!!\n";
			exit(123);
		}
		if (N == 1) return Matrix(*this);
		if (N == 0) {
			return	Matrix<T>(xsize, ysize, Unit);
		}

		Matrix<T> temp(*this);
		for (size_t i = 1; i < N; i++)
		{
			temp *= *this;
		}
		return Matrix(temp);
	}*/

template<class T>
Matrix<T>& Matrix<T>::operator +=(const Matrix& M2)
	{
		if (xsize != M2.xsize || ysize != M2.ysize)
		{
			cout << "Ìàòðèöû èìåþò ðàçíûå ðàçìåðû!\nÎïåðàöèÿ \"+\" íåâîçìîæíà!\n";
		}

		for (size_t i = 0; i < ysize; i++)
		{
			for (size_t j = 0; j < xsize; j++)
			{
				M[i][j] += M2.M[i][j];
			}
		}
		return *this;
	}

template<class T>
Matrix<T>& Matrix<T>::operator -=(const Matrix& M2)
	{
		if (xsize != M2.xsize || ysize != M2.ysize)
		{
			cout << "Ìàòðèöû èìåþò ðàçíûå ðàçìåðû!\nÎïåðàöèÿ \"-\" íåâîçìîæíà!\n";
		}

		for (size_t i = 0; i < ysize; i++)
		{
			for (size_t j = 0; j < xsize; j++)
			{
				M[i][j] -= M2.M[i][j];
			}
		}
		return *this;
	}

template<class T>
Matrix<T>& Matrix<T>::operator *=(const Matrix& M2)
	{
		if (xsize != M2.ysize) {
			cout << "Îïåðàöèÿ óìíîæåíèÿ ìàòðèö íåâîçìîæíà:\n";
			cout << "êîëè÷åñòâî ñòîëáöîâ ïåðâîãî ñîìíîæèòåëÿ\n íå ðàâíî êîëè÷åñòâó ñòðîê âòîðîãî!\n";
			exit(001);
		}
		Matrix<T> temp(ysize, M2.xsize, 0.0);
		size_t n = 0, p;
		for (size_t i = 0; i < ysize; i++)
		{
			p = 0;
			for (size_t j = 0; j < M2.xsize; j++)
			{
				for (size_t k = 0; k < xsize; k++) {
					temp[i][j] += M[n][k] * M2.M[k][p];
				}
				p++;
			}
			n++;
		}
		*this = temp;
		return *this;
	}

/*template<class T>
	Matrix<T>& Matrix<T>::operator ^=(const int& N)
	{
		if (N < 0) { cout << "Ñòåïåíü íå ìîæåò áûòü ìåíüøå íóëÿ!"; exit(120); }
		if (xsize != ysize) { cout << "Äëÿ âîçâåäåíèÿ â ñòåïåíü ìàòðèöà äîëæíà áûòü êâàäðàòíîé!!!\n"; exit(123); }
		if (N == 1) return *this;
		if (N == 0)
		{
			Matrix<T> temp(xsize, ysize, Unit);
			*this = temp;
			return *this;
		}
		for (int i = 1; i < N; i++)
		{
			*this *= *this;
		}
		return *this;
	}*/

template<class T>
Matrix<T>& Matrix<T>::operator *=(const T& N)
	{
		if (N == 1) return *this;
		for (size_t i = 0; i < ysize; i++)
		{
			for (size_t j = 0; j < xsize; j++)
			{
				if (M[i][j] == 0) continue;
				this->M[i][j] *= N;
			}
		}
		return *this;
	}

template<class T>
Matrix<T>& Matrix<T>::operator /=(const T& N)
	{
		if (N == 0) { cout << "Íà íîëü äåëèòü íåëüçÿ!!!\n"; exit(000); }
		if (N == 1) return *this;
		for (size_t i = 0; i < ysize; i++)
		{
			for (size_t j = 0; j < xsize; j++)
			{
				if (M[i][j] == 0) continue;
				this->M[i][j] /= N;
			}
		}
		return *this;
	}

template<class T>
bool Matrix<T>::operator ==(const Matrix& M)
	{
		if (xsize != M.xsize || ysize != M.ysize) {
			return false;
		}

		for (int i = 0; i < ysize; i++)
		{
			for (int j = 0; j < xsize; j++)
			{
				if (*this[i][j] != M.M[i][j]) return false;
			}
		}
		return true;
	}

template<class T>
bool Matrix<T>::operator !=(const Matrix& M)
	{
		return !(operator == (M));
	}

template<class T>
T Matrix<T>::StrSum(const size_t str_N, const unsigned Number_of_elem)
	{
		int sum = 0;
		for (unsigned i = 0; i < xsize; i++)
		{
			sum += M[str_N][i];
		}
		return sum;
	}

template<class T>
T Matrix<T>::ColSum(const size_t col_N, const unsigned Number_of_elem)
	{
		int sum = 0;
		for (unsigned i = 0; i < xsize; i++)
		{
			sum += M[i][col_N];
		}
		return sum;
	}

#endif //MATRIX_H