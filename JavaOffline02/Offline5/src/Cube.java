public class Cube extends Square implements Volume {
   private static int cubeNumber;
    Cube(double l){
        setLength(l);
        ++cubeNumber;
    }

    public double volume(){

        return area()*getLength();
    }
    @Override
    public void print(){
        System.out.println("Name: Cube"+cubeNumber);
        System.out.println("Volume: "+volume()+"\n");

    }
}
