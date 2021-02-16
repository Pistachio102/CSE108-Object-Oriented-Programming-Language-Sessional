import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class Main {



    public static void main(String[] args) {

        CarWarehouse carWarehouse=new CarWarehouse();
        try{
            String line;
            BufferedReader br=new BufferedReader(new FileReader("Car.txt"));
            line=br.readLine();
            while (line!=null){
                String[] input=line.split(",");
                String reg=input[0];
                int year=Integer.parseInt(input[1]);
                String c1=input[2];
                String c2=input[3];
                String c3=input[4];
                String cMake=input[5];
                String cModel=input[6];
                int price=Integer.parseInt(input[7]);
                Car y=new Car(reg,year,c1,c2,c3,cMake,cModel,price);
                carWarehouse.AddCar(y);
                line=br.readLine();

            }

        }catch (Exception e){
            System.out.println(e.getMessage()+"The file not found.");
        }

        boolean b=true;
        int i;
        while (b)
        {
            System.out.println("1.Search Car");
            System.out.println("2.Add Car");
            System.out.println("3.Delete Car");
            System.out.println("4.Exit System");
            Scanner input=new Scanner(System.in);
            i=Integer.parseInt(input.nextLine());
            //input.nextLine();

            if(i==1)
                {
                    boolean x=true;
                    while (x){
                        System.out.println("Car searching options:\n1.By Registration Number");
                        System.out.println("2.By Car Make and Car Model");
                        System.out.println("3.Back to Main Menu");
                        int p=Integer.parseInt(input.nextLine());


                        if(p==1){
                                System.out.println("Enter the Registration Number: ");
                                String reg=input.next();
                                carWarehouse.SearchByRegNUm(reg);

                            }
                       else if(p==2) {
                                System.out.println("Enter the Car Make: ");
                                String cMake = input.next();
                                System.out.println("Enter the Car Model: ");
                                String cModel = input.next();
                                carWarehouse.SearchByCarMake_Model(cMake, cModel);


                            }

                       else if (p==3){break;}
                    }
                }
                else if(i==2){
                String[] out=null;
                    String carInfo=input.nextLine();
                     out=carInfo.split(",");
                    String reg=out[0];
                    int year=Integer.parseInt(out[1]);
                    String c1=out[2];
                    String c2=out[3];
                    String c3=out[4];
                    String cMake=out[5];
                    String cModel=out[6];
                    int price=Integer.parseInt(out[7]);
                    Car x=new Car(reg,year,c1,c2,c3,cMake,cModel,price);
                    carWarehouse.AddCar(x);
                    System.out.println("New car is added.");


                }
            else if(i==3){
                    System.out.println("Enter the Registration Number of the Car to Delete: ");
                    String regD=input.next();
                    carWarehouse.DeleteCar(regD);

                }


           else if (i==4){
                try{
                    BufferedWriter bw=new BufferedWriter(new FileWriter("Car.txt"));
                    int size=carWarehouse.getArraySize();
                    for (int t=0;t<size;t++){
                        bw.write(carWarehouse.getCarInfo(t).toString()+"\n");
                    }
                    bw.close();

                }catch (Exception c){
                c.printStackTrace();
                }
                break;
            }
           else{

               while (!(i>0 && i<5 )){
                   System.out.println("Enter any option between 1-4\n");
                   break;
               }
            }

        }

    }


	}

