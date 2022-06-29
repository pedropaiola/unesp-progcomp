#include<bits/stdc++.h>
#define MAXN 500001
#define ll long long int

using namespace std;

ll p[MAXN];
ll tam[MAXN];
ll pop[MAXN];
ll popInd[MAXN];
set<pair<ll, ll>> popRegion; //<população, id da região>

void init(ll n){
    for(ll i = 0; i <= n; i++){
        p[i] = i;
        tam[i] = 1; //A principio, cada conjunto contém apenas ele mesmo
    }
}

ll find(ll x){
    if (p[x] == x) 
        return x;
    return p[x] = find(p[x]); //Aplicando path compression
}

void merge(ll a, ll b){
    ll setA = find(a);
    ll setB = find(b);
    if (setA == setB) //Ja sao o mesmo conjunto
        return;
    if (tam[setA] > tam[setB])
        swap(setA, setB);   //queremos que setU seja o menor conjunto
    p[setA] = setB;         //liga a em b
    tam[setB] += tam[setA]; //atualiza o tamanho de b
    popRegion.erase({pop[setA], setA});
    popRegion.erase({pop[setB], setB});
    pop[setB] += pop[setA];
    popRegion.insert({pop[setB], setB});
}

ll maxRegionPop(){
    return popRegion.rbegin()->first;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll n, m, q, i, x, y, k;
    char op;
    vector<pair<ll,ll> > roads;
    vector<pair<ll, ll> > queries;
    vector<ll> becameUnusable;
    vector<ll> resp;

    cin >> n >> m >> q;
    init(n);
    becameUnusable.assign(m,0);
    //Lendo as populações iniciais
    for(i = 1; i <= n; i++){
        cin >> pop[i];
        popInd[i] = pop[i];
    }
    //Lendo as estradas
    for(i = 0; i < m; i++){
        cin >> x >> y;
        roads.emplace_back(x,y);
    }
    //Lendo as queries (que serão processadas posterioremente)
    for(i = 0; i < q; i++){
        cin >> op;
        if (op == 'D'){
            cin >> k;
            k--;
            queries.emplace_back(0, k);
            becameUnusable[k] = 1;
        }
        else
        {
            cin >> k >> x;
            //Como as queries serão processadas de trás pra frente,
            //iremos alterar as populações agora e salvar a população anterior
            queries.emplace_back(k, popInd[k]);
            popInd[k] = pop[k] = x; 
        }
    }
    for(i = 1; i <= n; i++)
        popRegion.insert({pop[i], i});
    //Unindo cidades que NÃO serão separadas pelas queries
    for(i = 0; i < m; i++){
        if (becameUnusable[i])
            continue;
        merge(roads[i].first, roads[i].second);
    }
    //Processando as queries na ordem inversa (de forma que iremos "construir" ao invés de destruir estradas)
    resp.push_back(maxRegionPop());
    for(i = queries.size() - 1; i >= 0; i--){
        if (queries[i].first == 0){
            k = queries[i].second;
            x = roads[k].first;
            y = roads[k].second;
            merge(x,y);
            resp.push_back(maxRegionPop());
        }
        else
        {
            k = queries[i].first;
            x = queries[i].second;
            y = find(k);
            popRegion.erase({pop[y], y});
            pop[y] = pop[y] - popInd[k] + x;
            popRegion.insert({pop[y], y});
            popInd[k] = x;
            resp.push_back(maxRegionPop());
        }
    }
    for(i = queries.size() - 1; i >= 0; i--){
        cout << resp[i] << endl;
    }
}