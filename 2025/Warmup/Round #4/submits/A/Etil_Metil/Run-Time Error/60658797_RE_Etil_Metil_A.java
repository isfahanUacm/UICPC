package org.example;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);

        int tedad=sc.nextInt();

        for (int i = 0; i < tedad; i++) {
            int count1=0;
            int count;
            int sum=0;

            int tool=sc.nextInt();


            String binery=sc.next();


                int k=0;
            for (int j = 0; j < tool; j++) {

                if(binery.charAt(j)=='1')
                    count1+=1;

//                if(j==k){
//
//                    if(binery.charAt(j)=='0')
//                        count+=1;
//
//                }
//
//                if(j!=k){
//                    if(binery.charAt(j)=='1')
//                        count+=1;
//
//                }
//                k++;





            }


            for (int j = 0; j < tool; j++) {
                count=count1;

                if(binery.charAt(j)=='1')
                {
                    count-=1;
                    sum+=count;

                }
                else{
                    count+=1;
                    sum+=count;
                }


            }
            System.out.println(sum);

        }

    }

}