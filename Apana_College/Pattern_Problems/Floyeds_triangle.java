import java.util.Scanner;

public class Floyeds_triangle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        int x = 1 ;
        int n = sc.nextInt() ;
        sc.close();
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(x++ + " ");
            }
            System.out.println();
        }
    }
}
