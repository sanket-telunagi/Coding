import org.omg.CORBA.SystemException;

public class JAVA_StringBuilder {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder("Tony") ;
        // char at index 0 
        System.out.println(sb.charAt(0));

        // set character at zero 
        sb.setCharAt(0, 'p');
        System.out.println(sb);

        // inserting the character 
        sb.insert(0, "S") ;
        System.out.println(sb);

        // delete the extra n , end index is non inclusive 
        sb.delete(0, 1) ;
        System.out.println(sb);

        // apending 
        sb.append("abc") ;
        System.out.println(sb);

        // length 
        System.out.println(sb.length());

    }
}
