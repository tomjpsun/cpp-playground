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
	cout << "max of col(0) is 5, on index 4" << endl;
	cout << "max of col(1) is 10, on index 0" << endl;
	cout << "max of col(2) is 15, on index 2" << endl;
	cout << "max of col(3) is 20, on index 4" << endl;
	cout << "max of col(4) is 25, on index 4" << endl << endl;

	A.fill(0);

	/*
	  arma::find() 第一個參賽可以是 matrix 或 vec 或 relation (>, >=, <, <=, ==)
	  如果是 relation 就表示找出符合 relation 的 indexes.
	  第二個參數 k 表示取 k 個符合的 indexes.
	  本例 find 是找出 B.col(i) 中, 等於最大值的 index, 只取一個.
	  由於 armadillo 是從 0 開始計數, 標示 label 的 data 都是從 1 開始計數, 因此加一
	 */
	for (int i=0; i<B.n_cols; i++) {
		A(i) = arma::as_scalar(arma::find( arma::max(B.col(i)) == B.col(i), 1)) + 1;
	}
	cout << A << endl;

	return 0;
}
