import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int i = 0; i < t; i++) {
            int n = input.nextInt();
            int m = input.nextInt();
            int k = input.nextInt();
            String xx = input.next();
            input.nextLine();
            for(int j=0;j<k;j++){
                int check = input.nextInt();
                if(check==1){
                    int x = input.nextInt();
                    int y = input.nextInt();
                    int l = input.nextInt();
                    int r = input.nextInt();
                    for(int f = l-1;f<r;f++){
                        switch (xx.charAt(f)){
                            case 'U':{
                                if(x==0){
                                    break;
                                }
                                x-=1;
                                break;
                            }
                            case 'D':{
                                if(x==n){
                                    break;
                                }
                                x+=1;
                                break;
                            }
                            case 'L':{
                                if(y==0){
                                    break;
                                }
                                y--;
                                break;
                            }
                            case 'R':{
                                if(y==n){
                                    break;
                                }
                                y++;
                                break;
                            }
                        }
                    }
                    System.out.println(x+" "+y);

                }else if(check==2){
                    int z = input.nextInt();
                    char x = input.next().charAt(0);
                    StringBuilder xs = new StringBuilder(xx);
                    xs.setCharAt(z-1,x);
                    xx = xs.toString();
                }
            }
        }
    }
}