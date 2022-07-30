import java.util.Scanner;
import java.util.Stack;

public class Main {
 
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n, i;
        String s;

        n = in.nextInt();
        for(int k = 0; k < n; k++){
            s = in.next();
            Stack<Character> pilha = new Stack<Character>(); //pilha para auxiliar na tarefa deste problema
            int resp = 0;

            //Percorrendo todos os caracteres de nossa string
            for(i = 0; i < s.length(); i++){
                if (s.charAt(i) == '<')         //Se o caractere for um <
                    pilha.push(s.charAt(i));    //empilhamos ele
                else if (s.charAt(i) == '>' && !pilha.empty()){
                    //Se o caractere for > e a pilha não estiver vazia,
                    //é pq temos um "diamante", como <....>
                    pilha.pop();    //tiramos o < da pilha
                    resp++;         //e incrementamos a resposta
                }
            }
            System.out.println(resp);
        }

        in.close();
    }
 
}