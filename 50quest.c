#include <stdio.h>

void um() {
	int i, s;
	for (i = 0; scanf("%d", &s)  && (s != 0); i += s)
		;
	printf("%d\n", i);
}

void dois() {
	int i, s;
	for (i = 0; scanf("%d", &s)  && (s != 0);)
		if (i < s)
			i = s;

	printf("%d\n", i);
}

void tres() {
	int i, s, n;
	for (i = 0; scanf("%d", &s)  && (s != 0); i++ , n += s)
		;
	printf("%.2f\n", ((float)n) / i);
}

void quatro() {
	int i, r, s;
	for (i = 0; scanf("%d", &s)  && (s != 0);) {
		if (i < s)
			r = i, i = s;
        else if (r < s)
            r = s;
	}

	printf("%d\n", r);
}

int bitsUm (unsigned int n) { //5
	int i, c = 0;
	for (i = 0; (n >> i) != 0; i++)
		if ( (n >> i) % 2 != 0)
			c++;
	printf("%d\n", c);
	return c;
}


int trailingZ (unsigned int n) { // 6
	int i;
	for (i = 0; (n >> i) % 2 == 0; i++)
		;
	printf("%d\n", i);
	return i;
}

int qDig (unsigned int n) { // 7
	int i, x = n;
	for (i = 1; (x/=10) >= 1 ; i++)
		;
	printf("%d\n", i);
	return i;
}

int strlennn ( char str[] ) { //8
	int i;
	for (i = 0; str[i] != '\0'; i++)
		;
	printf("%d\n", i);
	return i;
}

char * strcat (char s1[], char s2[]) { //9
	int i, l = strlennn(s1);
	for (i = 0; (*(s1 + l + i) = *(s2 + i)) != '\0'; i++)
		;
	printf("%s\n", s1);
	return s1;
}

char *mystrcpy(char s1[], const char s2[]) { //10
	int i;
	for (i = 0; (*(s1 + i) = *(s2 + i) ) != '\0'; i++)
        	;
	printf("%s", s1);
	return s1;
}


int mystrcmp(char s1[], char s2[]) { //11
	int i;
	for (i = 0; (*(s1 +i) == *(s2 + i)) && *(s1 + i) != '\0';i++)
        	;
	printf("%d\n", s1[i] - s2[i]);
	return (s1[i] - s2[i]);
}


char *mystrstr (char s1[], char s2[]) { //12
	int i, j;
	for (j = 0; s1[j] != '\0'; j++)
		for (i=0; s1[i + j] == s2[i];i++)
			if (s2[i + 1] == '\0' )
        			return s1 + j;
	if (*s2 == '\0')
		return s1;
	return NULL;
}


void strrev (char s[]) { //13
	char c;
	int i, j;
	for (j = 0; s[j] != '\0'; j++) {
		for (i = 0; s[i+1+j] != '\0'; i++) {
			c = s[i+1];
			s[i+1] = s[i];
			s[i] = c;
		}
	}
	return;
}

void strnoV (char t[]){  //14
	int i, j = 0;
	for (i = 0; t[i] != '\0'; i++)
		if (t[i] != 'a' && t[i] != 'e' &&
		    t[i] != 'i' && t[i] != 'o' &&
		    t[i] != 'u' && t[i] != 'A' &&
		    t[i] != 'E' && t[i] != 'I' &&
		    t[i] != 'O' && t[i] != 'U')
		    	t[j++] = t[i];
	t[j] = '\0';
}

void truncW (char t[], int n){ //15
int i, j = 0, c = 0;
	for (i = 0; t[i] != '\0'; i++) {
		if (t[i] == ' ')
			c = 0;
		else
			c++;
		if (c <= n)
			t[j++] = t[i];
	}
	t[j] = '\0';
}




char charMaisfreq (char s[]) { //16
	int i, j, n1, n2;
	char c = 0;
	for (i=0; s[i] != '\0';i++) {
		n2 = 0;
		for (j=0; s[j] != '\0';j++)
			if (s[j] == s[i])
				n2++;
		if (n2 > n1) {
			n1 = n2;
			c = s[i];
		}
	}
	return c;
}

int iguaisConsecutivos (char s[]) { //17
	int i,j,r = 0;
	for (i=0; s[i] != '\0'; i++) {
		for (j = 0;s[i+j] !='\0' && s[i] == s[i+j]; j++)
			;
		if (j > r)
			r = j;
	}
	return r;
}



int diff ( char s[], int j) { //função auxiliar ao ex. 18
	int d;
	for (d = 0; d < j; d++)
		if (s[d] == s[j])
			return 0;
	return 1;
}


int difConsecutivos(char s[]) { //18
	int i, j, c = 0;
	for (i = 0; s[i]!= '\0'; i++) {
		for (j = 0; s[i+j] != '\0' && diff( s+i , j);j++)
			;
		if ( j > c)
			c = j;
	}
	return c;
}









int maiorPrefixo (char s1 [], char s2 []) { // 19
	int i;
	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
	;
	return i;
}



int maiorSufixo (char s1 [], char s2 []) { // 20
	int i, e1, e2;
	for (e1 = 0; s1[e1 +1] != '\0';e1++)
		;
	for (e2 = 0; s2[e2 +1] != '\0';e2++)
		;
	for (i = 0; s2[e2 - i] == s1[e1 - i] ; i++)
		;
        return i;
}


int sufPref (char s1[], char s2[]) { //21
	int e, i, j, c = 0;
	for ( e = 0; s1[e+1] != '\0'; e++)
		;
	for (i = 0; s2[i] != '\0'; i++) {
		for (j = 0; s1[e-j] == s2[i - j] && j <= i && j<= e; j++)
			;
		if ( j > c)
			c = j;
	}
	return c;
}

int contaPal (char s[]) { //22
	int i, j = 0;
	for (i = 0; s[i] != 0; i++)
		if (s[i] != ' ' && s[i] != '\n' && (s[i-1] == ' ' || s[i-1] == '\0'))
			j++;
	return j;
}



int contaVogais (char s[]) { //23
	int i, j = 0;
	for (i = 0; s[i] != '\0'; i++)
		if ( s[i] == 'a' || s[i] == 'A' ||
		     s[i] == 'e' || s[i] == 'E' ||
		     s[i] == 'i' || s[i] == 'I' ||
		     s[i] == 'o' || s[i] == 'O' ||
		     s[i] == 'u' || s[i] == 'U' )
		     	j++;
	return j;
}

int contida (char a[], char b[]) { // 24
	int i, j;
	for (i = 0; a[i] != '\0'; i++) {
		if (*b == '\0')
			return 0;
		for (j = 0; b[j] != '\0';j++) {
			if (b[j] == a[i])
				break;
			else if (b[j + 1] == '\0' && b[j] != a[i])
				return 0;
		}
	}
	return 1;
}

int palindroma (char s[]) { //25
	int e, i;
	for (e = 0; s[e] != '\0'; e++)
		;
	e --; e >> 1;
	for (i = 0; i <= e; i++)
		if (s[i] != s[e-i])
			return 0;
	return 1;
}


int remRep (char texto []) { //26
	int i, r = 0;
	for (i = 0; texto[i] != '\0'; i++)
		if (texto[i] == texto[i +1])
			;
		else
			texto[r++] = texto[i];
	texto[r] = '\0';
	return r;
}


int limpaEspacos (char texto[]) { // 27
	int r = 0, w=0, l= strlen(texto);
	while (r<l){
if (texto[r] == ' ' && texto[r+1] == ' ')
r++;
else texto[w++] = texto[r++];
}
texto[w] = '\0';
return w;
}



void insere (int s[], int N, int x){ //28
	int i, j;
	for (i = 0; i < N && x > s[i]; i++)
		;
	for (j = N; j > i; j--)
		s[j] = s[j-1];
	s[i] = x;
}


void merge (int r [], int a[], int b[], int na, int nb){ // 29
	int i, j = 0, k = 0;
	for (i = 0; i < na + nb; i++)
		if (a[j] <= b[k] && j < na || k == nb)
			r[i] = a[j++];
		else if (b[k] < a[j] && k < nb || j == na)
			r[i] = b[k++];
}


int crescente (int a[], int i, int j){ //30
	int k;
	for (k = i; k < j; k++)
		if (a[k+1] < a[k])
			return 0;
	return 1;
}

int retiraNeg (int v[], int N){ //31
	int i, j = 0;
	for (i = 0; i < N; i++)
		if (v[i] >= 0)
			v[j++] = v[i];
	return j;
}

int menosFreq (int v[], int N){ //32
	int r= v[0], i, j, c, f = 1;
	for ( i = 0; i < N;i++) {
		c = 0;
		for(j = 0; j < N; j++)
			if (v[j] = v[i])
				c++;
			if (c < f) {
				f = c;
				r = v[i];
			}
	}
	return r;
}

/*  33 é exatamente igual ao 32, apenas muda o sinal '<' para '>'
    na condição (c < f) para alterar as variaveis f e c */


int maxCresc (int v[], int N) { //34
	int i, j, r = 0;
	for ( i = 0; i < N; i++) {
		for (j = 0; v[i + j + 1] >= v[i + j] && i + j < N; j++)
			;
		if ( ++j > r)
		r = j;
	}
	return r;
}

int elimRep (int v[], int N) { //35
	int i, j, d, r = N;
	for (i = 0; i < r; i++)
		for (j = i + 1; j < r; j++)
			if (v[j] == v[i]) {
				for (d = j; d < r; d++)
				v[d] = v[d+1];
				r--;
				j--;
			}
	return r;
}


int elimRepOrd (int v[], int N) { //36
	int i, j, r = N;
	for (i = 0; r > 1 && i < r;i++)
		if (v[i] == v[i+1]) {
			for (j = i + 1; j < r; j++)
				v[j] = v[j+1];
			r--;
			i--;
		}
	return r;
}

int comunsOrd (int a[], int na, int b[], int nb){ //37
	int i, j, r = 0;
	for ( i = 0, j = 0; i < na && j < nb;) {
		if (a[i] > b[j])
			j++;
		else if (a[i] < b[j])
			i++;
		else {
			r++;
			j++;
			i++;
		}
	}
	return r;
}

int comuns (int a[], int na, int b[], int nb){ //38 ,,, esta pergunta está mal feita o jbb é retardado
	int i, j, r=0;
	for ( i = 0; i < na; i++)
		for (j = 0; j < nb; j++)
			if (b[j] == a[i]) {
				r++;
				break;
			}
	return r;
}


int minInd (int v[], int n) { //39
	int i, c = v[0], r = 0;
	for (i = 0; i < n; i++)
		if (v[i] < c) {
			r = i;
			c = v[i];
		}
	return r;
}

void somasAc (int v[], int Ac [], int N){ //40
	int i;
	for (i = 0; i < N; i++)
		Ac[i] = (i != 0)? Ac[i-1] + v[i] : v[0];
}

int triSup (int N, float m [N][N]) { //41
	int i, j, k = 0;
	for (i = 0; i < N; i++, k++)
		for (j = 0; j < k; j++)
			if (m[i][j] != 0)
				return 0;
	return 1;
}

void transposta (int N, float m [N][N]) { //42
	int i, j, k = 0, c;
	for (i = 0; i < N; i++, k++)
		for (j = 0; j < k; j++) {
			c = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = c;
		}
}

void addTo(int N, int M, int a [N][M], int b[N][M]) { //43
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			a[i][j] += b[i][j];
}

void sumDiag(int N, int m [N][N]){ //44
	int i, j, s;
	for (i = 0; i< N; i++) {
		for(s = 0, j = 0; j < N; j++)
			s += m[i][j];
		m[i][i] = s - m[i][i];
	}
}

void quarentaecinco() { //45
	int i;
	for (i = 0; i < 26; i++)
		printf("%d\t%c\t\t\t%d\t%c\n", i + 65, i + 65, i + 97, i + 97);
}


int unionSet (int N, int v1[N], int v2[N], int r[N]){ //46
	int i;
	for ( i = 0; i< N; i++)
		r[i] = v1[i] || v2[i];
}

/*  A pergunta 47 é exatamente igual à 46; apenas muda o operador
	"||" para "&&", sendo uma interseção. */

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){ //48
	int i;
	for (i = 0; i < N; i++)
		r[i] = (v1[i] <= v2[i])? v1[i] : v2[i];
}


/* A pergunta 49 é exatamente igual à 49; apenas muda o operador
	"<=" para ">=" (ou de '<' para '>') */


int cardinalMSet (int N, int v[N]){ //50
	int c=0, i;
	for (i = 0; i < N; i++)
		c += v[i];
	return c;
}


int main () {
	quarentaecinco(); // testes
}
