#include<iostream>
#include<cmath>
using namespace std;


class Point2D
{
	int x,y;
public:
	Point2D(){ x = 0; y = 0; } //default constructor initializes to (0,0)
	Point2D(int argx, int argy);
	void setX(int argx);
	void setY(int argy);
	int  getX();
	int getY();
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
	x=argx;//Complete this function
}

void Point2D::setY(int argy)
{
	y =argy;
}

int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	return y;//Complete this function
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
	//write getter and setter methods for this class
	double area(); //returns area of the circle
	void print(); //prints the rectangle in the stdout
	int intersect(Circle rhs); //determine if this circle intersects with rhs
	int contains(Circle rhs); //determine if this circle contains circle rhs
	int contains(Point2D p); //determine if this circle contains point p
	double perimeter(); //returns perimeter of the circle
	~Circle()
	{
	    center.setX(0);
	    center.setY(0);
	    radius=0;
	}
	//write a destructor that sets all values to 0
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

int Circle::intersect(Circle rhs)
{
	int p,q;
	p=rhs.center.getX()-center.getX();
	q=rhs.center.getY()-center.getY();
	p=p*p-q*q;
	if(sqrt(p)<=(rhs.radius+radius))
        return 1;
        else return 0;

	//complete this function
}

int Circle::contains(Circle rhs)
{
	int p,q,m,n,s;
	p=center.getX();
	q=center.getY();
	m=rhs.center.getX();
	n=rhs.center.getY();
	s=sqrt(pow((p-m),2)-pow((q-n),2));
	if(s<rhs.radius+radius)
        return 1;
    else if(m<(p+radius)&& m>(p-radius)&& n<(q+radius)&& n>(q-radius)&& radius>rhs.radius)
        return 1;
       else return 0;

        //complete this function
}
	int Circle::contains(Point2D p)
	{
	    int m,n,s,q,t;
	   s=center.getX();
	   q=center.getY();
	   m=p.getX();
	    n=p.getY();
	    t=sqrt((s-m)*(s-m)+(q-n)*(q-n));

	       if(t<=radius)
              return 1;
        else return 0;
	}

	double Circle:: perimeter()
	{
	    return 2*3.1416*radius;
	}




void Circle::print()
{
	cout << "Center: ";
	center.print();
	cout << "\nRadius: " << radius;
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
	//write a default constructor that initializes all values to 0
	Rectangle(Point2D a, Point2D b);
	//write a constructor that accepts values of all member variables and set the members
	//variables accordingly
	void setBottomLeft(Point2D x);
	//void setBottomLeftY(int y);
	void setTopRight(Point2D x);
	 //void setTopRightY(int y);
	 Point2D getBottomLeft();
	//int getBottomLeftY();
	Point2D getTopRight();
	 //int getTopRightY();


	//write getter and setter methods for this class
	double areaR(); //returns area of the rectangle
	int intersect(Rectangle rhs); //determine if this rectangle intersects with rhs
	int contains(Rectangle rhs); //determine if this rectangle contains rhs
	int inside(Circle c); //determine if this rectangle is completely inside the circle c
	double perimeter(); //returns perimeter of the circle
	~Rectangle()
	{
	     bLeft.setX(0);
	    bLeft.setY(0);
        tRight.setX(0);
	    tRight.setY(0);
	}
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



     double Rectangle::areaR()
     {
        int p,q;
         p=abs((tRight.getX()-bLeft.getX()));
         q=abs((tRight.getY()-bLeft.getY()));
         return p*q;
     }
     double Rectangle::perimeter()
     {
         double p,q;
         p=abs((tRight.getX()-bLeft.getX()));
         q=abs((tRight.getY()-bLeft.getY()));

         return 2*(p+q);
     }
int Rectangle::intersect(Rectangle rhs)
{
    int p1,p2,q1,q2,a1,a2,b1,b2;
    p1=rhs.bLeft.getX();
    p2=rhs.bLeft.getY();
    q1=rhs.tRight.getX();
    q2=rhs.tRight.getY();
    a1=bLeft.getX();
    a2=bLeft.getY();
    b1=tRight.getX();
    b2=tRight.getY();
    if((p1<=b1&&p1>=a1&&q2<=b2 && q2>=a2)&&(p1<=b1&&p1>=a1&&p2<=b2 && p2>=a2)&&(q1<=b1&&q1>=a1&&q2<=b2 && q2>=a2)&&(q1<=b1&&q1>=a1&&p2<=b2 && p2>=a2))
        return 0;//cout<<"Doesn't intersect."<<endl;

    else if((p1<=b1&&p1>=a1&&q2<=b2 && q2>=a2)||(p1<=b1&&p1>=a1&&p2<=b2 && p2>=a2)||(q1<=b1&&q1>=a1&&q2<=b2 && q2>=a2)||(q1<=b1&&q1>=a1&&p2<=b2 && p2>=a2))
        return 1;//cout<<"Intersects."<<endl;
    else if((a1<=q1&&a1>=p1&&a2<=q2 &&a2>=p2)||(a1<=q1&&a1>=p1&&b2<=q2 &&b2>=p2)||(b1<=q1&&b1>=p1&&a2<=q2 &&a2>=p2)||(b1<=q1&&b1>=p1&&b2<=q2 &&b2>=p2))
        return 1;//cout<<"Intersects."<<endl;
    else return 0;// cout<<"Doesn't intersect."<<endl;
}

int Rectangle::contains(Rectangle rhs)
{

     int p1,p2,q1,q2,a1,a2,b1,b2;
    p1=rhs.bLeft.getX();
    p2=rhs.bLeft.getY();
    q1=rhs.tRight.getX();
    q2=rhs.tRight.getY();
    a1=bLeft.getX();
    a2=bLeft.getY();
    b1=tRight.getX();
    b2=tRight.getY();
    if((p1<=b1&&p1>=a1&&q2<=b2 && q2>=a2)&&(p1<=b1&&p1>=a1&&p2<=b2 && p2>=a2)&&(q1<=b1&&q1>=a1&&q2<=b2 && q2>=a2)&&(q1<=b1&&q1>=a1&&p2<=b2 && p2>=a2))
        return 1;//cout<<"Contains a rectangle"<<endl;
         else return 0;//cout<<"Doesn't contain a rectangle"<<endl;


}
int Rectangle::inside(Circle c)
{
    int p,q,r,s;
    p=bLeft.getX();
    q=bLeft.getY();
    r=tRight.getX();
    s=tRight.getY();
    Point2D p1,q1,r1,s1;
    if((c.contains(p1))&&(c.contains(q1))&&(c.contains(r1))&&(c.contains(s1)))
        return 1;
    else return 0;
}
//Practice: Extend your program to include other geometric objects such as square, ellipse, triangle, etc.


   int main()
{
    Point2D c;
    int x,y;
    cout<<"Enter the position of the X co ordinate of the point: "<<endl;
    cin>>x;
    cout<<"Enter the position of the Y co ordinate of the point: "<<endl;
    cin>>y;
    c.setX(x);
    c.setY(y);
    cout<<"The point is: ";
    c.print();
    cout<<"\nThis point will be used as the center of the circle.\n"<<endl;
    Circle d;
    d.setCenter(c);
    double r;
    cout<<"\nEnter the radius of the circle: "<<endl;
    cin>>r;
    d.setRadius(r);
    d.print();
    cout<<"\nArea of the circle is: ";
    cout<<d.area();
    cout<<"\n";
    cout<<"Perimeter of the circle is: "<<d.perimeter()<<endl;
    //Circle d1;
    //Point2D c1;
    int x1,y1;
    double r1;
    cout<<"Enter the center of the new circle to check intersection: "<<endl;
    cin>>x1>>y1;
    Point2D c1(x1,y1);
    //c1.setX(x1);
    //c1.setY(y1);
    //d1.setCenter(c1);
    cout<<"Enter the radius of the new circle: "<<endl;
    cin>>r1;
    Circle d1(c1,r1);

    //d1.setRadius(r1);
    if(d.intersect(d1))
        cout<<"Circles intersect with each other."<<endl;
        else cout<<"Circles don't ntersect with each other."<<endl;
    if(d.contains(d1))
         cout<<"Contains radius"<<endl;
    else cout<<"Doesn't contain radius."<<endl;
    cout<<"\n";
    int k1,k2;
    cout<<"Enter a point to check whether it's inside the circle or not: "<<endl;
    cin>>k1>>k2;
    Point2D k(k1,k2);
    if((d.contains(k)))
        cout<<"The circle contains the point."<<endl;
    else cout<<"The circle doesn't contain the point."<<endl;


//Demonstrate your circle class
	//Demonstrate your area funciton showing that it successfully prints area of a circle
	//Demonstrate intersect(Circle) function by creating appropriate circles and showing that they intersect
	//Demonstrate contains(Circle) function by creating appropriate circles and showing that one circle
	//contains another circle
Rectangle e;
int b1,b2,t1,t2;
cout<<"Enter the bottom-left point(X and Y co-ordinates) of the rectangle: "<<endl;
cin>>b1>>b2;
Point2D b(b1,b2);
e.setBottomLeft(b);
cout<<"\n";
cout<<"Enter the top-right point(X and Y co-ordinates) of the rectngle: "<<endl;
cin>>t1>>t2;
Point2D t(t1,t2);
e.setTopRight(t);
cout<<"The area of the rectangle is: "<<e.areaR()<<endl;
cout<<"The perimeter of the rectangle is: "<<e.perimeter()<<endl;
Rectangle f;
cout<<"Enter the bottom-left point(X and Y co-ordinates) of the second rectangle: "<<endl;
int g1,g2,h1,h2;
cin>>g1>>g2;
Point2D g(g1,g2);
f.setBottomLeft(g);
cout<<"\n";
cout<<"Enter the top-right point(X and Y co-ordinates) of the second rectngle: "<<endl;
cin>>h1>>h2;
Point2D h(h1,h2);
f.setTopRight(h);
if(e.intersect(f))
cout<<"Intersects."<<endl;
    else cout<<"Doesn't intersect."<<endl;


cout<<"\n";
if(e.contains(f))
    cout<<"Contains a rectangle"<<endl;
         else cout<<"Doesn't contain a rectangle"<<endl;
cout<<"\n";

int z1,z2;
double v;
cout<<"Enter the center of the circle to check whether the rectangle is inside the circle or not: "<<endl;
cin>>z1>>z2;
Point2D z(z1,z2);
cout<<"Enter the radius of that circle: "<<endl;
cin>>v;
Circle j(z,v);
cout<<"\n";
if((e.inside(j)))
    cout<<"The rectangle is inside the circle."<<endl;
else cout<<"The rectancle is not inside the circle."<<endl;

//Demonstrate your Rectangle class
	//Demonstrate your area funciton showing that it successfully prints area of a rectangle
	//Demonstrate intersect(Rectangle) function by creating appropriate circles and showing that
	//they intersect
	//Demonstrate contains(Rectangle) function by creating appropriate circles and showing that
	//one rectangle contains another rectangle
	//Demonstrate inside(Circle) function by creating appropriate rectangle and circle and showing that
	//a rectange is completely inside a circle

	return 0;

}
