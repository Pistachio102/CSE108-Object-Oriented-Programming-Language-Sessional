public class Car {
    private String RegNumber;
    private int YearMade;
    private String Colour1;
    private String Colour2;
    private String Colour3;
    private String CarMake;
    private String CarModel;
    private int Price;

    public Car(String RegNumber,int YearMade,String Colour1,String Colour2,String Colour3,String CarMake,String CarModel,int Price)
    {
        this.RegNumber=RegNumber;
        this.YearMade=YearMade;
        this.Colour1=Colour1;
        this.Colour2=Colour2;
        this.Colour3=Colour3;
        this.CarMake=CarMake;
        this.CarModel=CarModel;
        this.Price=Price;
    }

    public String getRegNumber() {
        return RegNumber;
    }

    public int getYearMade() {
        return YearMade;
    }

    public String getColour1() {
        return Colour1;
    }

    public String getColour2() {
        return Colour2;
    }

    public String getColour3() {
        return Colour3;
    }

    public String getCarMake() {
        return CarMake;
    }

    public String getCarModel() {
        return CarModel;
    }

    public int getPrice() {
        return Price;
    }

    public void setRegNumber(String regNumber) {
        RegNumber = regNumber;
    }

    public void setYearMade(int yearMade) {
        YearMade = yearMade;
    }



    public void setCarMake(String carMake) {
        CarMake = carMake;
    }

    public void setCarModel(String carModel) {
        CarModel = carModel;
    }

    public void setPrice(int price) {
        Price = price;
    }
    public String toString(){
        return String.format("%s,%d,%s,%s,%s,%s,%s,%d",RegNumber,YearMade,Colour1,Colour2,Colour3,CarMake,CarModel,Price);
    }
}
