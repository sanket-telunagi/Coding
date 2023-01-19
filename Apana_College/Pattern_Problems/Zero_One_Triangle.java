import java.util.Scanner;

public class Zero_One_Triangle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        int n = sc.nextInt() ;
        sc.close();

        // for (int i = 1; i < n + 1; i++) {
        //     if ((i & 1) == 1) toggle = 0 ;
        //     for (int j = 1; j <= i; j++) {
        //         toggle = toggle - 1 < 0 ? (-1*(toggle - 1)) : (toggle - 1);
        //         System.out.print(toggle + " ");
        //     }
        //     // toggle = toggle == 1 ? 1 : 0 ;
        //     System.out.println();
        // }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print( ((i+j) & 1) == 1 ? "0 " : "1 ");
            }
            System.out.println();
        } 

    }
}
