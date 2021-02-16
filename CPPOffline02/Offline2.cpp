#include<iostream>
#include<cmath>
using namespace std;


class Point2D
{
	int x,y;
public:
	Point2D(){ x = 0; y = 0; } //default constructor initializes to (0,0)
	Point2D(int x, int y);
	void setX(int argx);
	void setY(int argy);
	int  getX();
	int  getY();
	Point2D operator+(Point2D p2);
	Point2D operator*(int n);
	bool operator==(const Point2D &p2)const;
	bool operator!=(const Point2D &p2)const;

	void print();
	~Point2D(){ x = 0; y = 0; } //destructor that sets all values to 0
};

Point2D::Point2D(int argx,int argy)
{
	x = argx;
	y = argy;
}

void Point2D::setX(int argx)
{
	x=argx;
}

void Point2D::setY(int argy)
{
	y = argy;
}

int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	return y;
}
Point2D Point2D::operator+(Point2D p2)
{
    Point2D temp;
    temp.x=x+p2.getX();
    temp.y=y+p2.getY();
    return temp;
}
Point2D Point2D::operator*(int n)
{
    Point2D temp;
    temp.x=x*n;
    temp.y=y*n;
    return temp;
}
bool Point2D::operator==(const Point2D &p2)const
{
    return (x==p2.x &&y==p2.y);
}
bool Point2D::operator!=(const Point2D &p2)const
{
    return (x!=p2.x && y!=p2.y);
}

void Point2D::print()
{
	cout << "(" << x << "," << y << ")";
}

class Circle
{
	Point2D center;
	double radius;
public:
    Circle()
    {
        center.setX(0);
        center.setY(0);
        radius=0;
    }

	//write a default constructor that initializes all values to 0
	Circle(Point2D c, double r);
	void setCenter(Point2D p);
	//void setCenterY(int y);
	void setRadius(double r);
	Point2D getCenter();
	//int getcenterY();
	double getRadius();
	//write a default constructor that initializes all values to 0
	//Circle(Point2D c, double r);
	Circle operator+(Point2D p);
	Circle operator*(int n);
	Circle operator+(Circle c2);
    Circle operator-(Circle c2);
    bool operator==(Circle c2);
    bool operator>=(Circle c2);
    bool operator>(Circle c2);
    bool operator<=(Circle c2);
    bool operator<(Circle c2);
    Circle operator++();
    Circle operator++(int notused);
~Circle()
	{
	    center.setX(0);
	    center.setY(0);
	    radius=0;
	}

    double area();
	//write getter and setter methods for this class
	//double area(); //returns area of the circle
	void print(); //prints the rectangle in the stdout

};
void Circle::setCenter(Point2D p)

{
    center.setX(p.getX());
    center.setY(p.getY());


}

void Circle::setRadius(double r)
{
    radius=r;
}
Point2D Circle::getCenter()
{
    return center;
}

double Circle::getRadius()
{
    return radius;
}
 Circle Circle::operator++(int notused)
 {
     Circle c;
     c.radius=radius;
          radius++;

     return c;
 }
 Circle Circle::operator++()
 {
     Circle c;
     radius++;

     c.radius=radius;

     return c;
 }





Circle::Circle(Point2D c, double r)
{
	center.setX(c.getX());
    center.setY(c.getY());
    radius=r;//complete this function
}
double Circle::area()
{
	return 3.1419*radius*radius;
}


/*Circle::Circle(Point2D c, double r)
{
	center=c;
	radius=r;//complete this function
}*/
Circle Circle::operator+(Point2D p)
{
    Circle temp;
    temp.center.setX(center.getX()+ p.getX());
    temp.center.setY(center.getY()+ p.getY());
    temp.setRadius(getRadius());
    return temp;


}
	Circle Circle:: operator*(int n)
	{
	     Circle temp;
    temp.center.setX((center.getX())*n);
    temp.center.setY((center.getY())*n);
    temp.setRadius((getRadius())*n);
    return temp;
	}
Circle Circle::operator+(Circle c2)
{
    double p,q,a;
    p=getRadius();
    q=c2.getRadius();
    a=p/(p+q);
    Circle c;
    c.center.setX((center.getX())*a +(c2.center.getX())*(1-a));

    c.center.setY((center.getY())*a +(c2.center.getY())*(1-a));
    c.setRadius(p+q);
    return c;
}
Circle Circle::operator-(Circle c2)
{
    double p,q,a,b;
    p=getRadius();
    q=c2.getRadius();
    a=p/(p+q);
    b=abs(p-q);
    Circle c;
    c.center.setX((center.getX())*a +(c2.center.getX())*(1-a));

    c.center.setY((center.getY())*a +(c2.center.getY())*(1-a));
    c.setRadius(b);
    return c;
}
 bool Circle::operator==(Circle c2)
 {
     return area()==c2.area();
 }

 bool Circle::operator>=(Circle c2)
 {
     return area()>=c2.area();
 }
 bool Circle::operator>(Circle c2)
 {
     return area()> c2.area();
 }
 bool Circle::operator<=(Circle c2)
 {
     return area()<=c2.area();
 }
bool Circle::operator<(Circle c2)
 {
     return area()<c2.area();
 }

void Circle::print()
{
	cout << "Center: ";
	center.print();
	cout << "Radius: " << radius;
}

class Rectangle
{
	Point2D bLeft;
	Point2D tRight;//define two variables that specifies the rectangle in a 2d space
	//the variables should represent: top-right point, bottom-left point
public:
    Rectangle()
	{
	    bLeft.setX(0);
	    bLeft.setY(0);
        tRight.setX(0);
	    tRight.setY(0);
	}
    Rectangle(Point2D a, Point2D b);
	void setBottomLeft(Point2D x);
	void setTopRight(Point2D x);
	 Point2D getBottomLeft();
	Point2D getTopRight();

	Rectangle operator+(Point2D p);
	Rectangle operator*(int n);
	void print();
	~Rectangle()
	{
	     bLeft.setX(0);
	    bLeft.setY(0);
        tRight.setX(0);
	    tRight.setY(0);
	} //returns perimeter of the circle
	//write a destructor that sets all values to 0
};
     Rectangle :: Rectangle(Point2D m, Point2D n)
     {
         bLeft=m;
         tRight=n;
     }
     void Rectangle:: setBottomLeft( Point2D x)
	{
	    bLeft=x;

	    	}

	void Rectangle::setTopRight(Point2D x)
	{
	    tRight=x;

	}

	Point2D Rectangle::getBottomLeft()
	{
	   return bLeft;
	}
		Point2D Rectangle::getTopRight()
	{
	   return tRight;

	}
	Rectangle Rectangle::operator+(Point2D p1)
	{
	   Point2D p,q;
	   p=bLeft+p1;
	   q=tRight+p1;
	   Rectangle r(p,q);
	   return r;
	}
	Rectangle Rectangle::operator*(int n)
	{
	    Point2D p,q;
	   p=bLeft*n;
	   q=tRight*n;
	   Rectangle r(p,q);
	   return r;
	}

void Rectangle::print()
{
    cout<<"Bottom-left point of the rectangle is: ";
    bLeft.print();
    cout<<"\n";
    cout<<"Top-right point of the rectangle is: ";
    tRight.print();

}

//Practice: Extend your program to include other geometric objects such as square, ellipse, triangle, etc.


int main(void)
{
Point2D c(3,4),d(3,4),e,f;
e=c+d;
f=c*3;
e.print();
cout<<"\n";
f.print();
cout<<"\n";
Circle x(c,5),y,z,a,a1,a2;
y=x+d;
z=x*4;
y.print();
cout<<"\n";
cout<<"\n";
z.print();
a=y+z;
cout<<"\n";
cout<<"\n";
a.print();
cout<<"\n";
cout<<"\n";
(y-z).print();
cout<<"\n";
if(y==z)
    cout<<"Area of both circles are same."<<endl;
else cout<<"Area of the circles are not same."<<endl;
if(y>=z)
    cout<<"Area of the circle y is greater than or equal to the circle z."<<endl;
else cout<<"Area of the circle y is not greater than or equal to the circle z."<<endl;
if(y>z)
    cout<<"Area of the circle y is greater than the circle z."<<endl;
else cout<<"Area of the circle y is not greater than the circle z."<<endl;
if(y<=z)
    cout<<"Area of the circle y is less than or equal to the circle z."<<endl;
else cout<<"Area of the circle y is not less than or equal to the circle z."<<endl;
if(y<z)
    cout<<"Area of the circle y is less than the circle z."<<endl;
else cout<<"Area of the circle y is not less than the circle z."<<endl;
a1=++y;
cout<<"Prefix notation will set the radius to: "<<a1.getRadius()<<endl;

a2=y++;
cout<<"Postfix notation will set the radius to: "<<a2.getRadius()<<endl;

Rectangle m(c,d);
Rectangle n,o;
n=m+e;
n.print();
cout<<"\n";
o=m*2;
o.print();







return 0;
}
