#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, i;
    string s;

    cin >> n;
    while(n--){
        cin >> s;

        stack<char> pilha;  //pilha para auxiliar na tarefa deste problema
        int resp = 0;
        //Percorrendo todos os caracteres de nossa string
        for(i = 0; i < s.size(); i++){
            if (s[i] == '<')        //Se o caractere for um <
                pilha.push(s[i]);   //Empilhamos ele
            else if ((s[i] == '>') && !pilha.empty()){
                //Se o caractere for > e a pilha não estiver vazia,
                //é pq temos um "diamante", como <....>
                pilha.pop(); //tiramos o < da pilha
                resp++;      //e incrementamos a resposta
            }
        }
        cout << resp << "\n";
    }
}