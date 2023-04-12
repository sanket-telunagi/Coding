import java.util.Scanner;

import javafx.css.CssMetaData;

public class JAVA_Create_Username_and_replace_e {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        String str= sc.next() ;


        // replace e with i
        String replace = str.replace('e', 'i') ;

        String uname = sc.next() ;
        StringBuilder sb = new StringBuilder(uname) ;
        StringBuilder ur = new StringBuilder("") ;

        for (int j = 0; j < uname.length(); j++) {
            if (sb.charAt(j) == '@') break ;
            ur.append(sb.charAt(j));
        }
        
        System.out.println(ur);
    }
}
