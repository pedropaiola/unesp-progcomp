#include<bits/stdc++.h>

using namespace std;

int main(){
    int p, a, r, i, j;
    while(1) //Loop "eterno"
    {
        cin >> p >> a >> r;
        if (a == 0) //Loop encerrado qdo p == a == r == 0 (nesse caso só precisa testar um deles)
            break;
        
        int qtdePerolas, maxPerolas = 0;
        string resp, nome;
        set<string> perolas;    //conjunto que armazena as pérolas listadas pelo professor
        set<string> nomes;      //conjunto dos nomes que cometeram mais pérolas

        getline(cin, resp); //lendo o fim da primeira linha (\n = lixo)
        for(i = 0; i < p; i++)
        {
            getline(cin, resp); //Lendo as pérolas (linhas inteiras, podendo ter espaços no meio)
            perolas.insert(resp);  //Inserindo as pérolas em um conjunto
        }
        //Lendo os nomes dos alunos
        for(i = 0; i < a; i++){
            getline(cin, nome);
            qtdePerolas = 0;
            
            //Lendo cada uma das respostas de um aluno
            for(j = 0; j < r; j++){
                getline(cin, resp);
                if (perolas.count(resp)) //Verificando se a resposta é uma pérola 
                    qtdePerolas++;       //Se sim, incrementamos a quantidade de pérolas
            }
            if (qtdePerolas > maxPerolas) //Se esse é o aluno que mais cometeu pérolas até o momento
            {
                nomes.clear();             //Limpamos o conjunto com nomes dos alunos com mais pérolas 
                nomes.insert(nome);        //inserimos o nome deste aluno
                maxPerolas = qtdePerolas;  //e alteramos o número máximo de pérolas
            }
            else if (qtdePerolas == maxPerolas) //Se esse aluno empatou com quem cometeu mais pérolas até o momento
            {
                nomes.insert(nome);             //inserimos ele no conjunto também
            }
        }

        //Imprimindo o nome dos alunos que cometeram mais pérolas
            //OBS: o set já armazena os valores de forma ordenada   
        for(auto it : nomes){   //"for-each": para cada valor (it) dentro do set (nomes)
            if (it == *nomes.begin()) //Se for o primeiro nome
                cout << it;           //imprime sem vírgula
            else
                cout << ", " << it;   //Caso contrário, coloca uma vírgula e um espaço antes do nome
        }
        cout << endl;   //No final, quebra a filha (o endl substitui o "\n", porém é mais lento, nem sempre é recomendável)
    }
}