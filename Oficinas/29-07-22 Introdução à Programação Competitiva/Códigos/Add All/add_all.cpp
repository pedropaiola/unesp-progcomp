#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, i, v;
    while(1) //Loop "eterno"
    {
        cin >> n;

        if (n == 0) //Se n == 0
            break;  //encerra-se o loop

        priority_queue<int> pq; //fila de prioridades: o topo contém sempre o maior número armazenado

        //Lendo os valores a serem somados
        for(i = 0; i < n; i++){
            cin >> v;
            pq.push(-v); //Armazenando cada valor na fila de prioridades
                         //OBS: está sendo armazenado o valor negativo, já que o topo contém sempre o maior
                         //valor, e nós queremos o menor. Gambiarra show
        }

        int resp = 0;
        while(pq.size() > 1) //Enquanto a fila tiver pelo menos dois elementos (ainda não somamos tudo)
        {
            //Obtemos os dos primeiros elementos do topo
            int a = -pq.top();
            pq.pop();
            int b = -pq.top();
            pq.pop();
            //Somamos e adicionamos o custo na resposta
            resp += a+b;
            //Adicionamos a soma na fila de prioridades (para ser utilizada em alguma soma futura)
            pq.push(-(a+b));
        }
        //Imprime total dos custos
        cout << resp << "\n";
    }
}