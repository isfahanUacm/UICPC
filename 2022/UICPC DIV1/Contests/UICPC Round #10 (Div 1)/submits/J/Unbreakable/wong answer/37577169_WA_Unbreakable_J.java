import java.util.Scanner;                                     
                                                              
public class r10_2 {                                          
    public static void main(String[] args) {                  
        Scanner sc = new Scanner(System.in);                  
        int t = sc.nextInt();                                 
        for (int i = 0; i < t; i++) {                         
            int n = sc.nextInt();                             
            int m = sc.nextInt();                             
            int ri_max = Integer.MIN_VALUE;                   
            int wi_max = Integer.MIN_VALUE;                   
            int total_r = 0;                                  
            int total_w = 0;                                  
            String ans = "";                                  
            for (int j = 0; j < m; j++) {                     
                int ri = sc.nextInt();                        
                int wi = sc.nextInt();                        
                if (ri > ri_max) {                            
                    ri_max = ri;                              
                }                                             
                if (wi > wi_max) {                            
                    wi_max = wi;                              
                }                                             
                for (int k = 0; k < ri - total_r; k++) {      
                    ans += "R";                               
                }                                             
                for (int k = 0; k < wi - total_w; k++) {      
                    ans += "W";                               
                }                                             
                total_r += ri;                                
                total_w += wi;                                
            }                                                 
            if (ri_max + wi_max > n) {                        
                System.out.println("IMPOSSIBLE");             
            } else {                                          
                System.out.println(ans);                      
            }                                                 
        }                                                     
    }                                                         
}                                                             
                                                              