public class Circle extends Shape implements Area{
   private double Radius;
   private static int circleNumber;
   Circle(){ Radius=0.0;}
    Circle(double Radius){
        this.Radius=Radius;
        ++ circleNumber;
    }

    public double area(){
        return (3.1416*Radius*Radius);
    }

    @Override
    public void print()
    {
        System.out.println("Name: Circle"+circleNumber);
        System.out.println("Area: "+area()+"\n");

    }

    public void setRadius(double radius) {
        Radius = radius;
    }

    public double getRadius() {
        return Radius;
    }
}