import java.util.Scanner;
import java.util.Collections;
import java.util.Vector;

 
public class teams {
 
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int aux, i, n = in.nextInt();
        Vector<Integer> a = new Vector<Integer>(n); //Criando um vector de inteiros

        //Lendo a pontuação de cada pessoa  
        for (i = 0; i < n; i++){
            aux = in.nextInt(); //Lendo a pontuação em uma variável auxiliar
            a.add(aux);         //e armazenando no vetor (sempre adicionada ao final = push_back)
        }
        
        //Ordenando o vetor
        Collections.sort(a);

        int resp = 0;
        //Percorrendo as posições i = 1, 3, 5, ...
        for (i = 1; i < n; i += 2){
            resp += a.get(i) - a.get(i-1); //Diferente do C++, não podemos acessar um Vector fazendo a[i]. Precisamos utilizar o metodo get()
        }
        
        System.out.println(resp);

        in.close();
    }
 
}