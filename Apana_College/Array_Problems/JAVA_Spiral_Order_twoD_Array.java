import java.util.Scanner;

public class Spiral_Order_twoD_Array {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        int n , m ;
        n = sc.nextInt();
        m = sc.nextInt() ;
        int metrix [][] = new int [n][m] ;

        // metrix input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                metrix[i][j] = sc.nextInt() ;
            }
        }

        int colStart = 0 , colEnd = m - 1;
        int rowStart = 0 , rowEnd = n - 1 ;

        while (rowStart <= rowEnd && colStart <= colEnd) {

            //1
            for (int i = colStart; i <= colEnd; i++) System.out.print(metrix[rowStart][i] + " ");
            rowStart++ ;

            // 2
            for (int i = rowStart; i <= rowEnd; i++) System.out.print(metrix[i][colEnd] + " ");
            colEnd-- ;

            // 3
            for (int i = colEnd ; i >= colStart; i--) System.out.print(metrix[rowEnd][i] + " ");
            rowEnd-- ;

            // 4
            for (int i = rowEnd; i >= rowStart; i--) System.out.print(metrix[i][colStart] + " ");
            colStart++ ;
        }

        sc.close();
    }
}