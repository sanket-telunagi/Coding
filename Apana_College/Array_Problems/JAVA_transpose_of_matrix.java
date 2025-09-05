import java.util.Scanner;

public class JAVA_transpose_of_matrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        int rows = sc.nextInt() , cols = sc.nextInt() ;
        int [][] mat = new int [rows][cols] ;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = sc.nextInt() ;
            }
        }

        // printing transpose of matrix 
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(mat[j][i] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
