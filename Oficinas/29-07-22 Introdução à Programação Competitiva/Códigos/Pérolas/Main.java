import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;
import java.util.SortedSet;
import java.util.TreeSet;


public class Main {
 
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int p, a, r, i, j;
        while(true) //Loop "eterno"
        {
            p = in.nextInt();
            a = in.nextInt();
            r = in.nextInt();
            if (a == 0) //Loop encerrado qdo p == a == r == 0 (nesse caso só precisa testar um deles)
                break;
            int qtdePerolas, maxPerolas = 0;
            String resp, nome;
            Set<String> perolas = new HashSet<String>();        //conjunto que armazena as pérolas listadas pelo professor
            SortedSet<String> nomes = new TreeSet<String>();    //conjunto (ordenado) dos nomes que cometeram mais pérolas
            
            in.nextLine(); //lendo o fim da primeira linha (\n = lixo)
            for(i = 0; i < p; i++){
                resp = in.nextLine();   //Lendo as pérolas (linhas inteiras, podendo ter espaços no meio)
                perolas.add(resp);      //Inserindo as pérolas em um conjunto
            }
            //Lendo os nomes dos alunos
            for(i = 0; i < a; i++){
                nome = in.nextLine();
                qtdePerolas = 0;

                //Lendo cada uma das respostas de um aluno
                for(j = 0; j < r; j++){
                    resp = in.nextLine();
                    if (perolas.contains(resp)) //Verificando se a resposta é uma pérola 
                        qtdePerolas++;          //Se sim, incrementamos a quantidade de pérolas
                }
                if (qtdePerolas > maxPerolas)   //Se esse é o aluno que mais cometeu pérolas até o momento
                {
                    nomes.clear();              //Limpamos o conjunto com nomes dos alunos com mais pérolas 
                    nomes.add(nome);            //inserimos o nome deste aluno
                    maxPerolas = qtdePerolas;   //e alteramos o número máximo de pérolas
                } 
                else if (qtdePerolas == maxPerolas) //Se esse aluno empatou com quem cometeu mais pérolas até o momento
                {
                    nomes.add(nome);                //inserimos ele no conjunto também
                }
            }

            //Imprimindo o nome dos alunos que cometeram mais pérolas
            Iterator<String> it = nomes.iterator(); //Utilizando um iterator para percorrer os elementos do set
            while(it.hasNext()) //Enquanto tiver mais elementos no conjunto
            {    
                nome = it.next();   //Pegamos o próximo elemento
                if (it.hasNext())                   //Se ainda tiver elementos depois do atual
                    System.out.print(nome+", ");    //imprimimos o nome com uma vírgula e um espaço no final (e não pulamos linha - print)
                else
                    System.out.println(nome);       //Caso contrário, imprimimos só o nome e pulamos linha (println)
            }
        }
        
        in.close();
    }
 
}