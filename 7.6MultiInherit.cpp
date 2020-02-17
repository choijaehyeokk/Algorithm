#include <iostream>
using namespace std;

class Image
{
public:
	Image(int height, int width)
	{
		nheight = height;
		nwidth = width;
		cout << "Image(int,int) SETTING" << endl;
	}
	int GetHeight() const
	{
		return nheight;
	}
	int GetWidth() const
	{
		return nwidth;
	}
protected:
	int nheight=0;
	int nwidth = 0;

};
class Shape
{
public:
	Shape(int type)
	{
		ntype = type;
	}
	int GetType() const
	{
		return ntype;
	}
protected:
	int ntype = 0;
};
class Picture : public Shape, public Image
{
public:
	Picture():
		Shape(1),Image(200, 120)
	{
		
		cout << "MyPicture" << endl;
	}
};
int main()
{
	Picture a;
	cout << "Width: " << a.GetWidth() << endl;
	cout << "Height: " << a.GetHeight() << endl;
	cout << "Type: " << a.GetType() << endl;
	return 0;
}


