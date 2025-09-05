import java.util.Scanner;

public class Inverted_Half_Pyramid_with_numbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;

        int n = sc.nextInt() ;
        sc.close();
        for (int i = 1; i < n + 1; i++) {
            for (int j = n; j >= i; j--) {
                System.out.print((n - j + 1) + " ");
            }
            System.out.println();
        }
    }
}
