public class Square extends Shape implements Area {
   private double length;
   private static int squareNumber;
    Square(){length=0;}
    Square(double l){
        length=l;
        ++squareNumber;

    }

    public double area(){

        return length*length;
    }
    @Override
    public void print(){
        System.out.println("Name: Square"+squareNumber);
        System.out.println("Area: "+area()+"\n");
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getLength() {
        return length;
    }
}
