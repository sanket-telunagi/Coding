import java.util.Scanner;

public class Solid_Rhombus {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        int n = sc.nextInt() ;
        sc.close();

        for (int i = 1; i <= n; i++) {
            // print first spaces
            for (int j = i; j < n; j++) {
                System.out.print("- ");
            }
            for (int j = 1; j <= n; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
