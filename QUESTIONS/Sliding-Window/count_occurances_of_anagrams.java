import java.util.Vector;


public class count_occurances_of_anagrams {

    public static int search_angrams(String s, String ptr) {
        int res = 0 ;
        Vector<Integer> ptrV = new Vector<>(26, 0) ;
        Vector<Integer> match = new Vector<>(26, 0) ;

        for (char ch : ptr.toCharArray()) {
            ptrV[ch - 'a'] ;
        }
        return res ;
    }

    public static void main(String[] args) {
        
    }
}