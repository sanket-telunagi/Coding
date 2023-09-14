/**
 * Array_List_In_java
 */
import java.util.ArrayList ;
import java.util.Collections
 ;

public class Array_List_In_java {

    public static void main(String[] args) {
        
        // only takes objects 
        ArrayList<Integer> list = new ArrayList<>() ;
        
        // adding an element at last 
        list.add(35) ;
        list.add(24);
        list.add(10);
        list.add(25);
        System.out.println(list);

        // adding element add specific index (index, element)
        list.add(3,25);
        System.out.println(list);

        // accesign any lement 
        Integer num = list.get(3) ;
        System.out.println(num);

        // getting size 
        System.out.println(list.size());

        // sorting 
        Collections.sort(list) ;
        System.out.println(list);

        // set an element 
        list.set(0, 100) ;
        System.out.println(list);


        // looping 
        for (Integer it : list) {
            System.out.println(it);
        }

        // looping with index 
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
    }
}