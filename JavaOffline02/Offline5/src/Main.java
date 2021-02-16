import java.util.Scanner;
class NegativeValueException extends Exception {
    public NegativeValueException(String message) {
        super(message);
    }
}
public class Main {

    public static void main(String[] args) {

        while(true) {
            System.out.println("Please select your choice:");
            System.out.println("1. Circle");
            System.out.println("2. Cylinder");
            System.out.println("3. Sphere");
            System.out.println("4. Square");
            System.out.println("5. Cube");
            Scanner input = new Scanner(System.in);
            int x=input.nextInt();
            if (x==1){
                try{
                    System.out.println("Enter radius: ");
                   double y=input.nextDouble();
                    check(y);
                    Shape circle=new Circle(y);
                    circle.print();


                }catch (NegativeValueException e) {
                    System.out.println(e.getMessage());}
            }
            else if(x==2){
                try{
                    System.out.println("Enter radius: ");
                    double y=input.nextDouble();
                    check(y);
                    System.out.println("Enter length: ");
                    double z=input.nextDouble();
                    check(z);
                    Circle cylinder=new Cylinder(y,z);
                    cylinder.print();


                }catch (NegativeValueException e) {
                    System.out.println(e.getMessage());}
            }
            else if(x==3){
                try{
                    System.out.println("Enter radius: ");
                    double y=input.nextDouble();
                    check(y);
                    /*System.out.println("Enter length: ");
                    double z=input.nextDouble();
                    validate(z);*/
                    Circle sphere=new Sphere(y);
                    sphere.print();


                }catch (NegativeValueException e) {
                    System.out.println(e.getMessage());}
            }
            else if(x==4){
                try{

                    System.out.println("Enter length: ");
                    double z=input.nextDouble();
                    check(z);
                    Shape square=new Square(z);
                    square.print();


                }catch (NegativeValueException e) {
                    System.out.println(e.getMessage());}
            }
            else if(x==5){
                try{

                    System.out.println("Enter length: ");
                    double z=input.nextDouble();
                    check(z);
                    Square cube=new Cube(z);
                    cube.print();


                }catch (NegativeValueException e) {
                    System.out.println(e.getMessage());}
            }
            else{
                break;
            }



    }
}
    public static void check ( double a) throws NegativeValueException {
        if (a < 0) {
            throw new NegativeValueException("Value can't be negative!\n");
        } else
            return;
    }
}
