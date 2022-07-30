import java.util.Scanner;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

public class Main {
 
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in).useLocale(Locale.US);

        int t, i;

        t = in.nextInt();
        for(int k = 0; k < t; k++){ //para cada caso de teste k = 0, 1, ..., t-1
            int n, m, qtde;
            //map para armazenar os preços de cada item, em que o nome do item é a chave
            Map<String, Double> precos = new HashMap<String, Double>();
            String item;
            Double valor, total = 0.;

            n = in.nextInt();
            //Lendo cada um dos itens e seus valores unitários
            for(i = 0; i < n; i++){
                item = in.next();
                valor = in.nextDouble();
                precos.put(item, valor); //Armazenando no map (diferente do C++, não temos a sobrecarga de operadores, logo
                                         //temos que usar métodos (put, no caso), sem poder fazer precos[item] = valor)
            }

            m = in.nextInt();
            //Lendo a lista de compras
            for(i = 0; i < m; i++){
                item = in.next();
                qtde = in.nextInt();
                total += precos.get(item) * qtde;
            }

            System.out.println("R$ " + String.format("%.2f", total));
        }
        
        in.close();
    }
 
}