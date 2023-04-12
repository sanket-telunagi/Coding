import java.util.Scanner;

public class JAVA_spiral_order {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        int rows = sc.nextInt() , cols = sc.nextInt() ;
        int [][] mat = new int [rows][cols] ;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = sc.nextInt() ;
            }
        }

        // spral order 
        int r_start = 0 , c_start = 0 , r_end = rows-1, c_end = cols-1;
         while(r_start <= r_end){

            for (int i = c_start; i <= c_end; i++) {
                System.out.print(mat[r_start][i] + " ");
            }
            r_start ++ ;

            for (int i = r_start; i <= r_end; i++) {
                System.out.print(mat[i][c_end] + " ");
            }
            c_end-- ;

            for (int i = c_end; i >= c_start; i--) {
                System.out.print(mat[r_end][i] + " ");
            }
            r_end-- ;

            for (int i = r_end; i >= r_start; i--) {
                System.out.print(mat[i][c_start] + " ");
            }
            c_start++ ;

        }


        sc.close();
    }
}
