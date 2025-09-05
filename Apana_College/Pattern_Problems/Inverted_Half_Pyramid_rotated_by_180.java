import java.util.Scanner;

public class Inverted_Half_Pyramid_rotated_by_180 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        int n = sc.nextInt() ;
        sc.close();

        /*
            Pattern : 
                          *
                        * *
                      * * * 
                    * * * *
        */

        for (int i = 1; i <= n; i++) {
            for (int j = 1 ; j <= n - i ; j++) {
                System.out.print("- ");
            }
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
