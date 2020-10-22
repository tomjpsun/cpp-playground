#include <iostream>

// By using compiler built-in conversion, from unsigned number to signed number
//
// https://graphics.stanford.edu/~seander/bithacks.html#FixedSignExtend
//

using namespace std;

// T is destination type, i.e. a signed number type,
// B is the fixed bits of source.

template<typename T, unsigned B>
inline T signextend(const T x)
{
	// we use fixed bits in struct, to direct
	// the compiler to convert (compiler's built-in
	// capability)

	struct { T x: B;} s;
	return s.x = x;
}

void verify_sign_convert()
{
	uint16_t a1 = 0xfffe;
	uint16_t a2 = 0x8001;
	uint16_t a3 = 0x7fff;
	uint16_t a4 = 0x0;
	int j = signextend<int,16> (a1);
	cout << "0xfffe --> " << j << endl;
	j = signextend<int,16> (a2);
	cout << "0x8001 --> " << j << endl;
	j = signextend<int,16> (a3);
	cout << "0x7fff --> " << j << endl;
	j = signextend<int,16> (a4);
	cout << "0x0 --> " << j << endl;

}
