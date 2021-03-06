#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iostream>
#include "print.hpp"
using namespace std;
using namespace std::placeholders;

int demo_binder()
{
	cout << endl << "This demo shows the binder usage:" << endl;
	set<int, greater<int>> coll1 = {1,2,3,4,5,6,7,8,9};
	deque<int> coll2;
	PRINT_ELEMENTS(coll1, "coll1 initialized as: ");
	transform(coll1.begin(), coll1.end(),
		  back_inserter(coll2),
		  bind(multiplies<int>(), _1, 10));
	PRINT_ELEMENTS(coll2, "after coll1 calling transform: ");
	replace_if (coll2.begin(),coll2.end(), // range
		    bind(equal_to<int>(),_1,70), // replace criterion
		    42); // new value
	PRINT_ELEMENTS(coll2,"replaced a value(42): ");
// remove all elements with values between 50 and 80
	coll2.erase(remove_if(coll2.begin(),coll2.end(),
			      bind(logical_and<bool>(),
				   bind(greater_equal<int>(),_1,50),
				   bind(less_equal<int>(),_1,80))),
		    coll2.end());
	PRINT_ELEMENTS(coll2,"remove all elements with values between 50 and 80: ");
	return 0;
}
