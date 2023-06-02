import java.util.Scanner;

/**
 * CodeForces_1550A_Find_the_array
 */
public class CodeForces_1550A_Find_the_array {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        int t = sc.nextInt() ;
        while(t-- != 0) {
            System.out.println((int)(Math.ceil(Math.sqrt(sc.nextInt()))));;
        }
        sc.close() ;
    }
}