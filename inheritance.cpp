#include <iostream>
using namespace std;

enum ShapeColor
{
	Red,
	Green,
	Blue
};

class Shape
{
public:
	void draw(ShapeColor color=Red) const {
		doDraw(color);
	}
	virtual ~Shape() { cout << "Destructor of Shape" << endl;};
private:
	virtual void doDraw(ShapeColor color) const {
		cout << "Shape's " << __func__ << " color = " << color << endl;
	}
};


class Rectangle : public Shape
{
	virtual ~Rectangle() { cout << "Destructor of Rectangle" << endl;};

private:
	virtual void doDraw(ShapeColor color) const;
};


void Rectangle::doDraw(ShapeColor color) const
{
	cout << "Rectangle's " << __func__ << ", color = " << color << endl;
}

void demo_inheritance()
{
	Shape *p = new Shape;
	p->draw();
	delete p;
	Shape *q = new Rectangle;
	q->draw();
	delete q;

}
