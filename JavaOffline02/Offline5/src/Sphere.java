public class Sphere extends Circle implements Volume{
  private   static int sphereNumber;
    Sphere(double r){
        setRadius(r);
        ++sphereNumber;
    }

    public double volume(){
        return (4*3.1416*getRadius()*getRadius()*getRadius())/3;
    }
    @Override
   public void print(){
       System.out.println("Name: Sphere"+sphereNumber);
       System.out.println("Volume: "+volume()+"\n");
    }
}
