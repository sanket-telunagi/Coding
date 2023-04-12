import java.util.Scanner;

public class JAVA_reversing_string {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        String str = sc.next() ;
        StringBuilder sb = new StringBuilder(str) ;

 
        // reversing the string 
        for (int i = 0; i < str.length()/2; i++) {
            char f = sb.charAt(i) ;
            char l = sb.charAt(str.length() - 1 - i) ;
            sb.setCharAt(i, l);
            sb.setCharAt(str.length() - i -1, f);
        }

        System.out.println(sb) ;;
    }
}
