import java.util.ArrayList;
import java.util.List;

public class CarWarehouse {
    List<Car> carlist=new ArrayList();
    public int getArraySize(){
        return carlist.size();
    }

    public void AddCar(Car c)
    {
        int i;
        boolean f=false;

        for ( i=0;i<carlist.size();i++)
        {

            if (c.getRegNumber().equalsIgnoreCase(carlist.get(i).getRegNumber()))
            {

                f=true;
                break;
            }
        }
        if (f){
            System.out.println("Car  with the same registration number already exists.\n");
        }
        else carlist.add(c);

    }
    public void DeleteCar(String s)
    {
        int i;
        boolean f=false;

        for ( i=0;i<carlist.size();i++)
        {

            if (s.equalsIgnoreCase(carlist.get(i).getRegNumber()))
            {

                f=true;
                break;
            }
        }
        if (f){
            carlist.remove(carlist.get(i));
        }
        else System.out.println("No such car with this registration number.\n");

    }
    public void SearchByRegNUm(String s)
    {
        int i;
        boolean f=false;

        for ( i=0;i<carlist.size();i++)
        {

            if (s.equalsIgnoreCase(carlist.get(i).getRegNumber()))
            {

                f=true;
                break;
            }
        }
        if (f){
            System.out.println("Registration Number: "+carlist.get(i).getRegNumber());
            System.out.println("Year Made: "+carlist.get(i).getYearMade());
            System.out.println("Colour: "+carlist.get(i).getColour1());
            System.out.println("Colour: "+carlist.get(i).getColour2());
            System.out.println("Colour: "+carlist.get(i).getColour3());
            System.out.println("Car Make: "+carlist.get(i).getCarMake());
            System.out.println("Car Model: "+carlist.get(i).getCarModel());
            System.out.println("Price: "+carlist.get(i).getPrice()+"\n\n");

        }
        else System.out.println("No such car with this registration number.\n");
    }
    public void SearchByCarMake_Model(String cMake,String cModel){
        boolean isAny=false;
        int x=0;
        int j=0;
        if (cModel.equals("ANY"))
        {
            for (int i=0;i<carlist.size();i++)
            {
                if (cMake.equalsIgnoreCase(carlist.get(i).getCarMake())){
                    System.out.println("Registration Number: "+carlist.get(i).getRegNumber());
                    System.out.println("Year Made: "+carlist.get(i).getYearMade());
                    System.out.println("Colour: "+carlist.get(i).getColour1());
                    System.out.println("Colour: "+carlist.get(i).getColour2());
                    System.out.println("Colour: "+carlist.get(i).getColour3());
                    System.out.println("Car Make: "+carlist.get(i).getCarMake());
                    System.out.println("Car Model: "+carlist.get(i).getCarModel());
                    System.out.println("Price: "+carlist.get(i).getPrice()+"\n\n");
                }
            }
            isAny=true;

        }
        else {
            for ( j=0;j<carlist.size();j++){
                if (cMake.equalsIgnoreCase(carlist.get(j).getCarMake()) && cModel.equalsIgnoreCase(carlist.get(j).getCarModel())){
                    isAny=true;
                    x=1;
                    break;
                }
            }
        }
        if (isAny==true && x==1){
            System.out.println("Registration Number: "+carlist.get(j).getRegNumber());
            System.out.println("Year Made: "+carlist.get(j).getYearMade());
            System.out.println("Colour: "+carlist.get(j).getColour1());
            System.out.println("Colour: "+carlist.get(j).getColour2());
            System.out.println("Colour: "+carlist.get(j).getColour3());
            System.out.println("Car Make: "+carlist.get(j).getCarMake());
            System.out.println("Car Model: "+carlist.get(j).getCarModel());
            System.out.println("Price: "+carlist.get(j).getPrice()+"\n\n");
        }
        else System.out.println("No such car with this car make and car model.");
    }
        public Car getCarInfo(int z){
            return carlist.get(z);

    }
    }













