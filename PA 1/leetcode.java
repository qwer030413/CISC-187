class Solution {
    static boolean isPalindrome(int x) {
        double reverse = 0;
        if(Integer.toString(x).contains("-"))
        {
            return false;
        }
        int index = Integer.toString(x).replace("-", "").length() - 1;
        
        int copy = x;
        while(copy != 0)
        {
            reverse += (copy % 10) * Math.pow(10, index);
            

            copy = copy/10;
            index--;
        }
        System.out.println(reverse);
        if(reverse == x)
        {
            return true;
        }
        

        return false;
    }
    public static void main(String[] args){ 
        int[] a = new int[];
        a[0] = 1;

    }
}
