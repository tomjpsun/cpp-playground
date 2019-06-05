#include <vector>
#include <memory>
#include <iostream>

using namespace std;

void f(std::shared_ptr<vector<int>>& pvec)
{
	cout << "f() call by ref (of smartptr)" << endl;
	pvec = std::shared_ptr<vector<int>>(new vector<int> {1,2,3,4,5});
}

void g(std::shared_ptr<vector<int>> pvec)
{
	cout << "g() call by value (of smartptr)" << endl;
	pvec = std::shared_ptr<vector<int>>(new vector<int> {1,2,3,4});
}

void h(std::shared_ptr<vector<int>> pvec)
{
	cout << "h() call by ref (of target object)" << endl;
	shared_ptr<vector<int>> p = make_shared<vector<int>>(vector<int>{1,2,3});
	*pvec = *p;
}

void pass_smartptr()
{
	std::shared_ptr<vector<int>> pv(new vector<int> {1});
	cout << "before calling f(), pv size() " << pv->size() << endl;
	f(pv);
	cout << "after calling f(), pv size() " << pv->size() << endl << endl;
	cout << "before calling g(), pv size() " << pv->size() << endl;
	g(pv);
	cout << "after calling g(), pv size() " << pv->size() << endl << endl;
	cout << "before calling h(), pv size() " << pv->size() << endl;
	h(pv);
	cout << "after calling h(), pv size() " << pv->size() << endl;

}
