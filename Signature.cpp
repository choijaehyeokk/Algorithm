#include <iostream>

using namespace std;
class Box
{
private:
	double length;
	double width;
	double height;
public:
	Box(double len, double wid, double hei)
	{
		length = len;
		width = wid;
		height = hei;
	}
	double getLength()
	{
		return length;
	}
	double getWidth()
	{
		return width;
	}
	double getHeight()
	{
		return height;
	}
};
class Volume
{
public:
	double operator()(double x, double y, double z)
	{
		return x * y *z;
	}
	double operator()(Box &box)
	{
		return box.getLength()*box.getWidth()*box.getHeight();
	}
};
int main(void)
{
	Volume volume;
	double room = volume(16, 12, 8.4);
	double room2 = volume.operator()(11, 33, 10);
	cout << room << endl;
	cout << room2 << endl;
	Box box{ 1.0,2.0,4.0 };
	cout << volume(box) << endl;
	return 0;
}