/*
Problema: Hide and Seek
Categorias:
	math > geometry
Dificuldade: dificil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define PI 3.141592653589793
#define EPS 1e-9
#define degreesToRadians(angleDegrees) ((angleDegrees) * M_PI / 180.0)
#define radiansToDegrees(angleRadians) ((angleRadians) * 180.0 / M_PI)
#define KID -1
//#define DEBUG 1

using namespace std;

struct Point{
	double x;
	double y;
	
	Point(double x = 0, double y = 0){
		this->x = x;
		this->y = y;
	}
	
	//Sobrecarga dos operadores +=, -=, *= e /=
	struct Point& operator+=(const Point& p){
		x += p.x;
		y += p.y;
		return *this;
	}

	struct Point& operator-=(const Point& p){
		x -= p.x;
		y -= p.y;
		return *this;
	}
	
	struct Point& operator*=(const double& k){
		x *= k;
		y *= k;
		return *this;
	}
	
	struct Point& operator/=(const double& k){
		x /= k;
		y /= k;
		return *this;
	}
	
    bool operator==(const Point& p){
		return ((x == p.x) && (y == p.y)); 
	}
};

struct Segment{
    Point a;
    Point b;
};

//Sobrecarga do operador << (para poder usar um ponto no cout)
ostream& operator<<(ostream& os, Point &p){
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

//Sobrecarga dos operadores +, -, * e =
Point operator+(Point p, const Point& q){
	return p += q;
}

Point operator-(Point p, const Point& q){
	return p -= q;
}

Point operator*(Point p, const double& k){
	return p *= k;
}

Point operator*(const double& k, Point p){
	return p *= k;
}

Point operator/(Point p, const double& k){
	return p /= k;
}

Point operator/(const double& k, Point p){
	return p /= k;
}

//Comparar double considerando uma margem de erro EPS
//retorna 0  se a = b
//		  -1 se a < b
//		  1  se a > b
int compDouble(double a, double b, double erro = EPS)
{
	if (abs(a - b) < erro)
		return 0;
	if (a < b)
		return -1;
	return 1;
}


//M�dulo do produto vetorial
	//Se cross(v, u) = 0 => vetores colineares
	//Se cross(v, u) < 0 => andando no sentido hor�rio
	//Se cross(v, u) > 0 => andando no sentido anti-hor�rio
double cross(Point v, Point u){
	return v.x * u.y - u.x * v.y;
}

//M�dulo do produto vetorial entre ab e ac
	//Se cross(a, b, c) = 0 => pontos colineares
	//Se cross(a, b, c) < 0 => c est� � direita de ab
	//Se cross(a, b, c) > 0 => c est� � esquerda de ab
double cross(Point a, Point b, Point c){
	return ((b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y)); 
}

double cross(Segment s, Point c){
	return cross(s.a, s.b, c); 
}

//Produto escalar
	//Se dot(v, u) = 0 => o �ngulo entre u e v � de 90�
	//Se dot(v, u) < 0 => o �ngulo entre u e v � maior que 90�
	//Se dot(v, u) > 0 => o �ngulo entre u e v � menor que 90�
double dot(Point v, Point u){
	return v.x * u.x + v.y * u.y;
}

//Verifica se c est� dentro da "caixa" formada por a e b (m�todo auxiliar para segIntersec)
bool dentroDaCaixa(Point a, Point b, Point c){
	return (min(a.x, b.x) <= c.x) and (c.x <= max(a.x, b.x)) and
		   (min(a.y, b.y) <= c.y) and (c.y <= max(a.y, b.y));
}

//Se x = 0 => retorna 0
//Se x < 0 => retorna -1
//Se x > 0 => retorna 1
int sinal(double x){
	if (abs(x) < EPS)
		return 0;
	if (x < 0) 
		return -1;
	return 1;
}

//Verifica se h� a intersec��o entre os segmentos a1a2 e b1b2
bool segIntersec(Point a1, Point a2, Point b1, Point b2){
	int d1, d2, d3, d4;
	d1 = sinal(cross(a2 - a1, b1 - a2));
	d2 = sinal(cross(a2 - a1, b2 - a2));
	d3 = sinal(cross(b2 - b1, a1 - b2));
	d4 = sinal(cross(b2 - b1, a2 - b2));
	return ((d1 * d2 == -1) and (d3 * d4 == -1)) or
		   ((d1 == 0) and dentroDaCaixa(a1, a2, b1)) or
		   ((d2 == 0) and dentroDaCaixa(a1, a2, b2)) or
		   ((d3 == 0) and dentroDaCaixa(b1, b2, a1)) or
		   ((d4 == 0) and dentroDaCaixa(b1, b2, a2));
}

bool segIntersec(Segment s1, Segment s2){
    return segIntersec(s1.a, s1.b, s2.a, s2.b);
}

//Retorna o m�dulo/norma do vetor
double norma(Point v){
	return sqrt(v.x*v.x + v.y*v.y);
}

//Retorna o m�dulo/norma do vetor ao quadrado
double norma2(Point v){
	return v.x*v.x + v.y*v.y;
}

//Dist�ncia entre dois pontos
double dist(Point a, Point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

//Dist�ncia ao quadrado (normalmente � melhor para fazer compara��es)
double dist2(Point a, Point b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

//Dist�ncia de ponto(c) a reta (formada pelos pontos a e b)
double distPontoReta(Point a, Point b, Point c){
	return cross(a, b, c)/dist(a, b);
}

Point proj(Point u, Point v){
	return (dot(u,v)/norma2(v))*v;
}

Point oposto(Segment s, Point x){
    if (x == s.a)
        return s.b;
    return s.a;
}

//Dist�ncia de ponto(c) ao segmento de reta ab (ESSA FUN��O TEM QUE SER MELHOR TESTADA)
double distPontoSeg(Point a, Point b, Point c){
	Point p = a + proj(c-a,b-a);
	double da, db;
	da = dist2(p, a);
	db = dist2(p, b);
	if (da + db > dist2(a,b))
	{
		if (da < db)
			p = a;
		else
			p = b;
	}
	return dist(c, p);
}

double distPontoSeg(Segment s, Point c){
	return distPontoSeg(s.a, s.b, c);
}

//Radial Sort com cen como ponto central
double angle(Point p){
    double ret = atan2(p.y, p.x);
    while(ret < 0)
        ret += 2*PI;
    return ret;
}

Point cen;
bool radialComp(const pair<Point, int> &a, const pair<Point, int> &b){
	Point v = a.first - cen,
		  u = b.first - cen;
	return angle(v) < angle(u);
}

double angTest(Point p){
    return radiansToDegrees(angle(p));
}

int consegueVer(Point seeker, Point kid, vector<Segment> walls, set<int> paredesAtivas){
    Segment visao;
    visao.a = seeker;
    visao.b = kid;
    for(auto it = paredesAtivas.begin(); it != paredesAtivas.end(); it++){
        if (segIntersec(visao, walls[*it]))
            return 0;
    }
    return 1;
}

//Teste das fun��es
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int s, k, w, i, j;
    Point p, q;
    Segment l;
    int entrou[10000];
    while(cin >> s >> k >> w){
        vector<Point> seekers;
        vector<Point> kids;
        vector<Segment> walls;
        vector<pair<Point, int> > radialSweep;
        //Entrada dos seekers
        for(i = 0; i < s; i++){
            cin >> p.x >> p.y;
            kids.push_back(p);
            seekers.push_back(p);
            radialSweep.push_back({p, KID});
        }
        //Entrada das outras crianças
        for(i = s; i < k; i++){
            cin >> p.x >> p.y;
            kids.push_back(p);
            radialSweep.push_back({p, KID});
        }
        //Entrada das paredes
        for(i = 0; i < w; i++){
            cin >> p.x >> p.y;
            cin >> q.x >> q.y;
            l.a = p;
            l.b = q;
            walls.push_back(l);
            radialSweep.push_back({p,i});
            radialSweep.push_back({q,i});
        }
        //Radial Sweep para cada seeker
        int n = radialSweep.size();
        for(i = 0; i < s; i++){
            memset(entrou,0,sizeof(int)*w);
            int qtdeParedes = 0;
            set<int> paredesAtivas;
            int ans = 0;
            cen = seekers[i];
            sort(radialSweep.begin(), radialSweep.end(), radialComp);
            //Na primeira passada eu só quero ver como as paredes entram e saem da visão do seeker
            //pq é possível q no ângulo 0 já tenha uma parede na frente e eu não saiba
            for(j = 0; j < n; j++){
                if (radialSweep[j].second == KID) //Não vamos olhar para as crianças nesse momento
                    continue;
                int reta = radialSweep[j].second;
                l = walls[reta];
                p = radialSweep[j].first;
                q = oposto(l, p);
                if (entrou[reta]) //Se já passamos pela reta
                {
                    entrou[reta] = 0;   //Então agora é o ponto de saída com ctza
                    qtdeParedes--;
                    paredesAtivas.erase(reta);
                }
                else if (cross(cen, p, q) > 0) //Senão, temos que ver se de fato é um ponto de entrada
                {
                    entrou[reta] = 1;
                    qtdeParedes++;
                    paredesAtivas.insert(reta);
                }
            }
            //Agora sim, vamos procurar as crianças
            for(j = 0; j < n; j++){
                if (radialSweep[j].second == KID) //Se for criança
                {
                    if (radialSweep[j].first == cen) //vamos pular o próprio seeker, é claro
                        continue;
                    if ((qtdeParedes == 0) || consegueVer(cen, radialSweep[j].first, walls, paredesAtivas))
                        ans++;  //Se não tem paredes no momento atual OU elas não estão entre o seeker e a criança
                    continue;
                }
                //O resto é igual o ciclo anterior
                int reta = radialSweep[j].second;
                l = walls[reta];
                p = radialSweep[j].first;
                q = oposto(l, p);
                if (entrou[reta])
                {
                    entrou[reta] = 0;
                    qtdeParedes--;
                    paredesAtivas.erase(reta);
                }
                else if (cross(cen, p, q) > 0)
                {
                    entrou[reta] = 1;
                    qtdeParedes++;
                    paredesAtivas.insert(reta);
                }
            }
            cout << ans << endl;
        }
    }
}

