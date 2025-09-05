import java.util.Scanner;

public class printing_pattern {
    public static void main(String[] args) {
        /*
        print the following pattern for any input n 
            n = 3
            *
            * *
            * * *

         */
        Scanner sc = new Scanner(System.in) ;
        int n = sc.nextInt() ;
        sc.close() ;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}