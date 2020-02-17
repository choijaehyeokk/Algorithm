#include <iostream>
using namespace std;

class Shape
{
public:
	Shape()
	{

	}
	virtual ~Shape() {}
	virtual void Draw() { cout << "Shape::Draw()" << endl; };
};
class Rectangle : public Shape
{
public:
	virtual void Draw() { cout << "Rectangle::Draw()" << endl; };
};
class Circle : public Shape
{
public:
	virtual void Draw() { cout << "Circle::Draw()" << endl; };
};
int main(void)
{
	cout << "도형의 번호를 입력하세요[1.사각형,2.원]: " << endl;
	int nInput = 0;
	cin >> nInput;

	Shape *pShape = NULL;
	if (nInput == 1)
	{
		pShape = new Rectangle;
	}
	else if (nInput == 2)
	{
		pShape = new Circle;
	}
	else
	{
		pShape = new Shape;
	}
	pShape->Draw();

	Rectangle *pRectangle = dynamic_cast<Rectangle*>(pShape);
	if (pRectangle != NULL)
		cout << "Rectangle::Draw()" << endl;
	else
	{
		Circle *pCircle = dynamic_cast<Circle*>(pShape);
		if (pCircle != NULL)
			cout << "Circle::Draw()" << endl;
		else
			cout << "Shape::Draw()" << endl;
	}
	return 0;
}