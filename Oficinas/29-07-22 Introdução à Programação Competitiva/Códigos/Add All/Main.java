import java.util.Scanner;
import java.util.PriorityQueue;

public class Main {
 
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, i, v;

        while(true) //Loop "eterno"
        {
            n = in.nextInt();
            if (n == 0)     //Se n == 0
                break;      //encerra-se o loop
            
            PriorityQueue<Integer> pq = new PriorityQueue<Integer>(); //fila de prioridades

            //Lendo os valores a serem somados
            for(i = 0; i < n; i++){
                v = in.nextInt();
                pq.add(v); //Armazenando cada valor na fila de prioridades
            }
            
            int resp = 0;
            while(pq.size() > 1) //Enquanto a fila tiver pelo menos dois elementos (ainda não somamos tudo)
            {
                //Obtemos os dos primeiros elementos do topo
                int a = pq.poll();  //Obtém o topo da fila de prioridades e já o retira desta estrutura
                int b = pq.poll();
                //Somamos e adicionamos o custo na resposta
                resp += a+b;
                //Adicionamos a soma na fila de prioridades (para ser utilizada em alguma soma futura)
                pq.add(a+b);
            }
            //Imprime total dos custos
            System.out.println(resp);
        }
        
        in.close();
    }
 
}