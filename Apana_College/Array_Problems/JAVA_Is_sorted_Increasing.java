/*
 * Program to check if the array is in the increasing order or not
 */

import java.util.Scanner;

public class Is_sorted_Increasing {
    static boolean is_sorted(int [] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i+1] < nums[i]) return false ;
        }
        return true ;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        int n = sc.nextInt() ;
        int nums [] = new int [n] ;
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt() ;
        }
        System.out.println(is_sorted(nums));
        sc.close();
    }
}
