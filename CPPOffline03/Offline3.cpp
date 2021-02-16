#include<iostream>
#include<cmath>
using namespace std;

typedef enum {UNDEFINED, POINT2D, POINT3D, CIRCLE, SQUARE, RECTANGLE, SPHERE} STYPE;


//********* Shape *********

class Shape
{
    STYPE type;
public:
    Shape();
    Shape(STYPE type);
    virtual void print();
    virtual double area();
    virtual bool contains(const Shape *s);
    //Intentionally made non-virtual
    bool operator==(const Shape &rhs);
    virtual ~Shape() {}
};

Shape::Shape()
{
    type = UNDEFINED;
}

Shape::Shape(STYPE argtype)
{
    type = argtype;
}

double Shape::area()
{
    cout << "I am a dummy Shape";
    return 0.0;
}

bool Shape::contains(const Shape *rhs)
{
    cout << "You see this, because appropriate contains function is undefined";
    return false;
}

void Shape::print()
{
    cout << "Type: " << type;
}

bool Shape::operator==(const Shape &rhs)
{
    return (type == rhs.type);
}

//********* Point2D : Shape *********


class Point2D : public Shape
{
    double x,y;
public:
    Point2D();
    Point2D(STYPE argtype, int argx, int argy);
    void print();
    double area();
    bool contains(const Shape * rhs);
    bool contains(const Point2D * rhs);
    bool operator==(const Point2D &rhs);
    void setX(double argx)
    {
        x=argx;
    }
    void setY(double argy)
    {
        y=argy;
    }

    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
    ~Point2D() {}
};

Point2D::Point2D() //calls Base's default constructor
{
    x = 0.0;
    y = 0.0;
}

Point2D::Point2D(STYPE argtype, int argx, int argy) : Shape(argtype)
{
    x = argx;
    y = argy;
}

void Point2D::print()
{
    //Shape::print();
    cout << " (" << x << "," << y << ")";
}

double Point2D::area()
{
    return 0.0;
}

bool Point2D::contains(const Shape *s)
{
    const Point2D * pointType = dynamic_cast<const Point2D*>(s);
    if(pointType!=NULL)
    {
        //Supported
        return contains(pointType);
    }
    //By default, use base
    return Shape::contains(s);
}

bool Point2D::contains(const Point2D * rhs)
{
    return (x == rhs->x && y == rhs->y);
}

bool Point2D::operator==(const Point2D & rhs)
{
    if( !Shape::operator==(rhs) ) return false;
    return (getX() == rhs.getX() && getY() == rhs.getY());
}

//********* Rectangle : Shape *********

class Rectangle : public Shape
{
    Point2D topRight;
    Point2D bottomLeft;
public:
    Rectangle();//implement this
    Rectangle(STYPE type, Point2D tr, Point2D bl);//implement this
    void print(); //implement this
    double area(); //implement this
    bool contains(const Shape *rhs); //implement this to check containment for point2d only
    bool operator==(const Rectangle &rhs); //implement this
    Point2D getBottomLeft() const
    {
        return bottomLeft;
    }
    Point2D getTopRight()const
    {
        return topRight;
    }
    ~Rectangle() {}
};

Rectangle::Rectangle()
{
    topRight.setX(0);
    topRight.setY(0);
    bottomLeft.setX(0);
    bottomLeft.setY(0);
}

Rectangle::Rectangle(STYPE type, Point2D tr, Point2D bl):Shape(type)
{
    topRight=tr;
    bottomLeft=bl;
}

void Rectangle::print()
{
    Shape::print();
    cout<<"Top-right point: ";
    topRight.print();
    cout<<"Bottom-left point: ";
    bottomLeft.print();
}

double Rectangle::area()
{
    // return Shape::area();
    return (fabs(bottomLeft.getX()-topRight.getX())*fabs(bottomLeft.getY()-topRight.getY()));
}

bool Rectangle::contains(const Shape *rhs)
{
    const Point2D * pointType = dynamic_cast<const Point2D*>(rhs);//checking if the input is point2d though it's written that the input will be only point2d
    if(pointType!=NULL)
    {
        if((topRight.getX() >= pointType->getX())&&(bottomLeft.getX() <= pointType->getX())&&(topRight.getY() >= pointType->getY())&&(bottomLeft.getY() <= pointType->getY()))
            return true;
        else return false;
    }
    else return Shape::contains(rhs);
}

bool Rectangle::operator==(const Rectangle &rhs)
{
    if(! Shape::operator==(rhs))
        return false;
    return (topRight==rhs.topRight && bottomLeft== rhs.bottomLeft);
}


//********* Circle : Shape *********

class Circle : public Shape
{
    Point2D center;
    double radius;
public:
    Circle();
    Circle(STYPE type, Point2D c, double r); //implement this
    double area(); //implement this
    void print(); //implement this
    bool contains(const Shape * s); //implemented partially
    bool contains(const Point2D * p); //implement this
    bool contains(const Circle * rhs); //implement this
    bool contains(const Rectangle * p); //implement this
    bool operator==(const Circle &rhs); //implement this
    ~Circle() {}
};

bool Circle::contains(const Shape * s)
{
    const Point2D * pointType = dynamic_cast<const Point2D*>(s);
    if(pointType!= NULL)
    {
        //Supported
        return contains(pointType);
    }
    const Circle * circleType = dynamic_cast<const Circle*>(s);
    if(circleType!= NULL)
    {
        //Supported
        return contains(circleType);
    }
    const Rectangle * rectangleType = dynamic_cast<const Rectangle*>(s);
    if(rectangleType!= NULL)
    {
        //Supported
        return contains(rectangleType);
    }
    //By default
    return Shape::contains(s);
}

Circle::Circle()
{
    center.setX(0);
    center.setY(0);
    radius=0;
}

Circle::Circle(STYPE type, Point2D c, double r):Shape(type)
{
    center=c;
    radius=r;
}

double Circle::area()
{
    //return Shape::area();
    return 3.1416*radius*radius;
}

void Circle::print()
{
    Shape::print();
    center.print();
    cout<<"\n";
    cout<<radius<<endl;
}

bool Circle::contains(const Point2D *p)
{
    if (sqrt((center.getX() - p->getX())*(center.getX() - p->getX())+(center.getY() - p->getY())*(center.getY() - p->getY()))<=radius)
        return true;
    else return false;
}

bool Circle::contains(const Circle *rhs)
{
    double distance;
    double p = (center.getX() - rhs->center.getX())*(center.getX() - rhs->center.getX());
    double q = (center.getY() - rhs->center.getY())*(center.getY() - rhs->center.getY());
    distance = p + q;
    double rad_diff = fabs(radius - (rhs->radius));
    if(  distance <= rad_diff*rad_diff)
    {
        return true;
    }
    return false;
    // return false;
}
bool Circle::contains(const Rectangle *p)
{
    Point2D p1(POINT2D,p->getBottomLeft().getX(),p->getTopRight().getY());
    Point2D p2,p4;
    p2 = p->getBottomLeft();
    Point2D p3(POINT2D,p->getTopRight().getX(),p->getBottomLeft().getY());
    p4 = p->getTopRight();
    //here p1..p4 are the four points of that rectangle;
    bool a = contains(&p1);
    bool b = contains(&p2);
    bool c = contains(&p3);
    bool d = contains(&p4);
    //checking if all are inside the circle;
    if(a && b && c && d)
    {
        return true;//checking if all the four points are inside that circle
    }
    return false;
}

bool Circle::operator==(const Circle &rhs)
{
    if(!Shape::operator==(rhs))
        return false;
    if(center==rhs.center && radius==rhs.radius)
        return true;
    else return false;
}




//********* Shape3D : Shape *********

class Shape3D : public Shape
{
public:
    Shape3D();
    Shape3D(STYPE type);
    virtual double volume();
    ~Shape3D() {}
};

Shape3D::Shape3D()
{

}

Shape3D::Shape3D(STYPE argtype) : Shape(argtype)
{

}

double Shape3D::volume()
{
    cout << "You see this, because appropriate function is missing in the derived class";
    return 0.0;
}

//********* Point3D : Point2D, Shape3D *********

class Point3D : virtual public Point2D, virtual public Shape3D
{
    double z;
public:
    Point3D(); //already implemented
    Point3D(STYPE type, double argx, double argy, double argz); //implement this
    virtual void print(); //already implemented
    //double area(); Not needed, base version is sufficient
    bool contains(const Shape *rhs); //implement this
    bool contains(const Point3D *rhs);
    //implement this
    void setZ(double argz)
    {
        z=argz;
    }
    double getZ()const
    {
        return z;
    }
    ~Point3D() {}
};

Point3D::Point3D()
{
    z = 0;
}

void Point3D::print()
{
    //Shape3D::print();
    cout << " (" << Point2D::getX() << "," << Point2D::getY() << "," << z << ")";
}

Point3D::Point3D(STYPE type, double argx, double argy, double argz):Point2D(type,argx,argy)
{
    z=argz;
}

bool Point3D::contains(const Shape *rhs)
{
    const Point3D * pointType = dynamic_cast<const Point3D*>(rhs);
    if(pointType!=NULL)
    {
        //Supported
        return contains(pointType);
    }
    return Point2D::contains(rhs);
}

bool Point3D::contains(const Point3D *rhs)
{
    if(getX()==rhs->getX() && getY()==rhs->getY()&& z==rhs->z)
        return true;
    return false;
}


//********* Sphere : Shape3D *********

class Sphere : public Shape3D
{
    Point3D center;
    double radius;
public:
    Sphere();//implement this
    Sphere(STYPE type, Point3D c, double r);//implement this
    void print(); //implement this
    double area(); //implement this
    double volume(); //implement this
    bool contains(const Shape * rhs); //implement this for checking containgment of Point3D, Sphere inside sphere
    bool contains(const Point3D * p); //implement this
    bool contains(const Sphere * s); //implement this
    ~Sphere() {}
};

Sphere::Sphere()
{
    center.setX(0);
    center.setY(0);
    center.setZ(0);
    radius=0;
}

Sphere::Sphere(STYPE type, Point3D c, double r):Shape3D(type)
{

    center=c;
    radius=r;

}

void Sphere::print()
{
   // Shape::print();
   cout<<"Center: ";
    center.print();
    cout<<"    ";
    cout<<"Radius: ";
    cout<<radius<<endl;
}

double Sphere::area()
{
    return (4*3.1416*pow(radius,2));     // return Shape::area();
}

double Sphere::volume()
{
    //return Shape3D::volume();
    return (4*3.1416*pow(radius,3))/3;
}

bool Sphere::contains(const Shape *rhs)
{
    const Point3D *pointType=dynamic_cast<const Point3D*>(rhs);
    if(pointType!= NULL)
    {
        //Supported
        return contains(pointType);
    }
    const Sphere * sphereType = dynamic_cast<const Sphere*>(rhs);
    if(sphereType!= NULL)
    {
        //Supported
        return contains(sphereType);
    }
    return Shape::contains(rhs);
}

bool Sphere::contains(const Point3D *p)
{
    double x,y,z;
    x = (center.getX() - p->getX())*(center.getX() - p->getX());
    y = (center.getY() - p->getY())*(center.getY() - p->getY());
    z = (center.getZ() - p->getZ())*(center.getZ() - p->getZ());
    if((x + y + z) <= radius*radius)
        return true;
    return false;
}

bool Sphere::contains(const Sphere *s)
{
    double x,y,z;
    x = (center.getX() - s->center.getX())*(center.getX() - s->center.getX());
    y = (center.getY() - s->center.getY())*(center.getY() - s->center.getY());
    z = (center.getZ() - s->center.getZ())*(center.getZ() - s->center.getZ());
    double distance = x + y + z; //basically the square of distance between two centers
    double rad_diff = fabs(radius - s->radius);
    if(distance <= rad_diff*rad_diff)
    {
        return true;
    }
    return false;
}


int main(void)
{
    //Write main function to demonstrate your code
    //Create circles, rectanges, point2d,point3d,and sphere objects using base class pointers
    //then call the virtual methods to show that polymorphism works!
    while(1)
    {
        int choice = 10;
        Shape * shape,*shape_1,*shape_2,*shape_3, *shape_4;
        Shape3D * shape3D,*shape3D_1,*shape3D_2;
        cout << "1. Point2D 2. Rectangle 3. Circle\n";
        cout << "4. Point3D 5. Sphere. 0. Exit\n";
        cout << "Your choice:";
        cin >> choice;
        switch(choice)
        {
        case 1:
        {
            shape = new Point2D(POINT2D, 5.0,10.0);
            shape_1 = new Point2D(POINT2D, 3.0,1.0);
            /* shape_2 = new*/ Point2D a(POINT2D, 5.0,10.0);

            shape->print();
            cout<<"\n";
            if(shape->contains(shape_1))
                cout<<"The point contains the second point."<<endl;
            else cout<<"The point doesn't contain the second point."<<endl;
            if(shape->contains(&a))
                cout<<"The point contains the second point."<<endl;
            else cout<<"The point doesn't contain the second point."<<endl;
            if(shape==shape_1)
                cout<<"Both the points are same."<<endl;
            else cout<<"The points aren't similar."<<endl;
            cout << "\nArea: " << shape->area();
             delete shape;
            delete shape_1;
            delete shape_2;
            break;

        }
        case 2:
        {
            Point2D p1(POINT2D,5.0,5.0);
            Point2D p2(POINT2D,20.0,20.0);
            //Point2D p3(POINT2D,10.0,10.0);
           // Point2D p4(POINT2D,6.0,6.0);
            shape = new Rectangle(RECTANGLE, p1, p2);
            shape->print();

            shape_1=new Point2D(POINT2D,3.0,4.0);
            //shape_2=new Rectangle(RECTANGLE, p3, p4);
            if(shape->contains(shape_1))
                cout<<"The rectangle contains the point."<<endl;
            else cout<<"The rectangle doesn't contain the point."<<endl;

            cout<<"\n";

            cout << "\nArea: " << shape->area();
            delete shape;
            delete shape_1;
            break;
        }
        case 3:
        {
            Point2D p1(POINT2D,0.0,0.0);
            shape = new Circle(CIRCLE,p1,10.0);
            shape->print();
            shape_1=new Point2D(POINT2D,3.0,4.0);
             Point2D a(POINT2D,6.0,4.0);
             Point2D b(POINT2D,3.0,2.0);

            if(shape->contains(shape_1))
              cout<<"The circle contains the point."<<endl;
            else cout<<"The circle doesn't contain the point."<<endl;

             if(shape->contains(&a))
              cout<<"The circle contains the point."<<endl;
            else cout<<"The circle doesn't contain the point."<<endl;

            shape_2=new Circle(CIRCLE,a,2);

            if(shape->contains(shape_2))
              cout<<"The circle contains the new circle."<<endl;
             else cout<<"The circle doesn't contain the circle."<<endl;

             shape_3=new Rectangle(RECTANGLE,b,a);
              if(shape->contains(shape_3))
              cout<<"The circle contains the rectangle."<<endl;
             else cout<<"The circle doesn't contain the rectangle."<<endl;



            cout<<"\n";

            shape->area();
            delete shape;
            delete shape_1;
            delete shape_2;
            delete shape_3;

            break;
        }
        case 4:
        {
            cout << "The 1st point is: ";
            shape3D = new Point3D(POINT3D,5.0,10.0,20.0);
            shape3D->print();
            shape3D_1 = new Point3D(POINT3D,4.0,20.0,15.0);
            if(shape3D->contains(shape3D_1))
                cout<<"The points are similar."<<endl;
            else cout<<"The points aren't similar."<<endl;



            cout << "\nArea: " << shape3D->area();
            cout << "\nVolume: " << shape3D->volume();

            delete shape3D;
            delete shape3D_1;
            delete shape3D_2;
            break;
        }
        case 5:
        {
             Point3D a(POINT3D,0.0,0.0,0.0);
				shape3D = new Sphere(SPHERE,a,10.0);

				shape3D->print();
				cout << "\nArea: " << shape3D->area();

				cout << "\nVolume: " << shape3D->volume();

				shape3D_1 = new Point3D(POINT3D,1.0,1.0,1.0);
				if(shape3D->contains(shape3D_1))
                    cout<<"The Sphere contains the point."<<endl;
                else
                    cout<<"The Sphere does not contain the point."<<endl;

                Point3D b(POINT3D,2.0,3.0,4.0);

				shape3D_2 = new Sphere(SPHERE,b,6.0);

				if(shape3D->contains(shape3D_2))
                    cout<<"The 1st Sphere contains the 2nd Sphere."<<endl;
                else
                    cout<<"\nThe 1st Sphere does not contain the 2nd Sphere."<<endl;


                    delete shape3D;
                    delete shape3D_1;
                    delete shape3D_2;
                    break;

        }
        }
        if(choice==0)
            break;
    }


    return 0;
}
