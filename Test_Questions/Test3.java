// package C++_kali.Test_Questions;

public class Test3 {

    public Test3() {
        System.out.printf("1");
        new Test3(10);
        System.out.printf("5");
    }

    public Test3(int data) {
        System.out.printf("2");
        new Test3(10,20) ;
        System.out.printf("4");
    }

    public Test3 (int data, int temp){
        System.out.printf("3");
    }

    public static void main(String[] args) {
        Test3 obj = new Test3();
    }
}
