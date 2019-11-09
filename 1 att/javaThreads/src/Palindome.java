import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;
class Checking implements Runnable {
    private String word;
    private boolean isPalindrome;

    public Checking(String w) {
        this.word = w;
        this.isPalindrome = true;
    }

    public void setPalindrome(boolean palindrome) {
        isPalindrome = palindrome;
    }

    public boolean isPalindrome() {
        return isPalindrome;
    }

    @Override
    public void run() {
        int right = this.word.length()-1;
        int left = 0;
        while (left != this.word.length() / 2) {
            if (word.charAt(right) != word.charAt(left)) {
                this.isPalindrome = false;
                return;
            }
            left++;
            right--;
        }
        this.setPalindrome(true);

    }
}
public class Palindome {

    public static void main(String[] args){
        System.out.println("Hello");
        Scanner input =new Scanner(System.in);
        Checking check=new Checking(input.next());
        Thread thread1 = new Thread(check);
        thread1.start();
        try{
            thread1.join();
            if(check.isPalindrome()){
                System.out.println("It is a palindrome\n");
            }else{
                System.out.println("It isn't a palindrome\n");
            }
        } catch (InterruptedException e) {

        }

    }
}
