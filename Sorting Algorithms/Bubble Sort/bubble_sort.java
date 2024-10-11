import java.util.Random;

public class bubble_sort {
    public static void main ()
    {
        int [] array = new int [10];

        Random random = new Random();

        for(int i = 0 ; i <= 10 ; i++)
        {
            array[i] = random.nextInt(100);
        }

        for(int i = 0 ; i < 10 ; i++)
        {
            for(int j = 0 ; j < 10 ; j++)
            {
                if(array[j] > array[j+1])
                {
                    int aux = array[j];
                    array[j] = array[j+i];
                    array[j+1] = aux;
                }
            }
        }

        System.out.println(array);
    }
}
