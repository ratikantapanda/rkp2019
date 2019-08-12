import java.util.Arrays;

class Sort{
    public static void swap(int[] A, int i, int j)
    {
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    public static void bubble(int[] A)
    {
        for(int i=0; i < A.length-1; i++)
        {
            for(int j=0; j < A.length-1-i; j++)
            {
                if(A[j] > A[j+1])
                {
                    swap(A,j,j+1);
                }
            }
        }
    }
    public static void main(String[] args) {
        int[] A= {8,3,5,9,7,4};
        bubble(A);
        System.out.println(Arrays.toString(A));
    }
}