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

int main () {
	quatro(); // testes
}
