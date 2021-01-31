#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int armadillo_test()
{
	cout << __func__ << "():" << endl;

	mat A{ {1,2,3,4,5},
	       {10,6,7,8,9},
	       {11,12,15,13,14},
	       {16,17,18,19,20},
	       {21,22,23,24,25} };

	mat B{A.t()};

	cout << B << endl;

	A.fill(0);

	/*
	  arma::find() 第一個參賽可以是 matrix 或 vec 或 relation (>, >=, <, <=, ==)
	  如果是 relation 就表示找出符合 relation 的 indexes.
	  第二個參數 k 表示取 k 個符合的 indexes.
	  本例 find 是找出 B.col(i) 中, 等於最大值的 index, 只取一個.
	 */
	for (int i=0; i<B.n_cols; i++) {
		A(i) = arma::as_scalar(arma::find( arma::max(B.col(i)) == B.col(i), 1)) + 1;
	}
	cout << A << endl;

	return 0;
}
