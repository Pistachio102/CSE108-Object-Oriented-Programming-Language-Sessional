public class Cylinder extends Circle implements Volume{
   private double Height;
   private static int cylindernumber;

    Cylinder(double r,double h){
        Height=h;
        setRadius(r);
        ++cylindernumber;
    }
    public double baseArea()
    {
        return area();
    }
    public double surfaceArea(){
        return (2*3.1416* getRadius()*(getRadius()+Height));
    }


    public double volume(){
        return area()*Height;
    }
    @Override
    public void print(){
        System.out.println("Name: Cylinder"+cylindernumber);
        System.out.println("Area of the base: "+baseArea());
        System.out.println("Area of the surface: "+surfaceArea());
        System.out.println("Volume: "+volume()+"\n");
    }

}
