import java.util.*;

public class fazendo{

    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        int n, q, l, r;
        int a[] = new int[100000];

        n = in.nextInt();
        for(int i = 0; i < n; i++){
            a[i] = in.nextInt();
        }
        q = in.nextInt();
        while(q-- > 0){
            l = in.nextInt();
            r = in.nextInt();
            int soma = 0;
            for(int i = l-1; i <= r-1; i++)
                soma += a[i];
            System.out.println(soma);
        }
        in.close();
    }

};