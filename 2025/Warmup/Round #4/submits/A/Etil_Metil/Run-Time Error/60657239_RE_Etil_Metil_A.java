package org.example;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);

        int tedad=sc.nextInt();

        for (int i = 0; i < tedad; i++) {
            int count=0;

            int tool=sc.nextInt();


            String binery=sc.next();

            for (int j = 0; j < tool; j++) {

                for (int k = 0; k < tool; k++) {

                    if(j==k){

                        if(binery.charAt(k)=='0')
                            count+=1;

                    }

                if(j!=k){
                    if(binery.charAt(k)=='1')
                        count+=1;

                }
                }




            }
            System.out.println(count);

        }

    }
}