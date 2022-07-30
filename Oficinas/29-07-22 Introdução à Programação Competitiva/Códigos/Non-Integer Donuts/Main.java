import java.util.*;

public class x {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        int n, ponto;
        n = sc.nextInt();
        str = sc.next();
        ponto = str.indexOf(".");

        int centavos = Integer.parseInt(str.substring(ponto + 1)), atrasado = 0;

        for (int i = 0; i < n; i++) {
            str = sc.next();
            ponto = str.indexOf(".");
            
            int decimal = Integer.parseInt(str.substring(ponto + 1));
            centavos = (centavos + decimal) % 100;

            if (centavos != 0) {
                atrasado++;
            }
        }

        System.out.println(atrasado);
        sc.close();
    }
}