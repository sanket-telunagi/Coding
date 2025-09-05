import java.util.Scanner;

public class maximum_and_minimum_num_array {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        int n = sc.nextInt() ;
        int [] nums = new int[n] ;

        int min_value = Integer.MAX_VALUE ;
        int max_value = Integer.MIN_VALUE ;
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt() ;
            if (nums[i] <= min_value) min_value = nums[i] ;
            if (nums[i] >= max_value) max_value = nums[i] ;
        }
        System.out.println(min_value + " " + max_value);
        sc.close();
    }
}
