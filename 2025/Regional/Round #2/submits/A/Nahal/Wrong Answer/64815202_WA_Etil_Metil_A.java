import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);

        int n=scanner.nextInt();
        int s=scanner.nextInt();
        String harf=scanner.next();

        int a,b,c;

        if(harf.equals("L")){
           c=n-s;

           if(s%2==0){
               a=s/2;
               b=s/2;
           }
           else{
               a=(s/2)+1;
               b=(s/2)+1;
           }
        }
        else{
            a=s-1;

            if((n-s)%2==0){
                b=(n-s)/2;
                        c=(n-s)/2;
            }
            else{
                b=((n-s)/2)+1;
                c=((n-s)/2)+1;
            }

        }

        System.out.print(a+" "+b+" "+c);

    }
}


