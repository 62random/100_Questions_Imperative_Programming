

//2ª parte das 100 questões de PI




//isto não compila (nem é suposto). testem cada questão individualmente no codeboard com os testes dos stores
//as questãoes que não estão no codeboard podem ser testadas num ficheiro aparte (neste não, devido às chamadas
//de funções não estão aqui definidas)





//////////////////////////////////////////////////1

int length (LInt l){
    int c = 0;

    while ( l != NULL) {
        c++;
        l = l->prox;
    }

    return c;
}






//////////////////////////////////////////////////2
//podemos testar esta função ao substituir o código da pergunta 1 por uma chamada a esta função e retornar 0

void freeL(LInt l) {
	Lint* p = &l;

	while ( l != NULL) {
		p = &l;
		l = l-> prox;
		free(p);
	}
	free(l);
}












//////////////////////////////////////////////////3
void imprimeL(LInt l) {
	while (l != NULL) {
		printf("%d ", l->valor);
		l = l->prox;
	}
	printf("\n");
}








//////////////////////////////////////////////////4
LInt reverseL (LInt l){
    LInt aux;
    LInt prev = NULL;
    LInt freed;

    while(l != NULL ) {

        aux = newLInt(l->valor, prev); //cria uma lista que aponta para a lista anterior
        prev = aux; //regista a nova lista anterior

        freed = l; //regista a lista que entra em desuso
        l = l->prox; //avança na lista inicial
        free(freed); //librta a memória desnecessária
    }

    return aux;

}












//////////////////////////////////////////////////5

void insertOrd (LInt *l, int x){

    while (*l != NULL && x > (*l)->valor) {
        l = &(*l)->prox;
    }
    *l = newLInt(x,*l);
}












//////////////////////////////////////////////////6

int removeOneOrd (LInt *l, int x){

    while ( *l != NULL) {
        if ((*l)->valor == x) {
            if((*l)->prox == NULL)
                *l = NULL;
            else{
            	free(*l);
                *l = (*l)->prox;
            }
            return 0;
        }
        l = &(*l)->prox;
    }

    return 1;
}


















//////////////////////////////////////////////////7
void merge (LInt *r, LInt l1, LInt l2){
    LInt *reg = r, a = *r; //regista o endereço do restultado

    while(l1 != NULL || l2 != NULL) {


        if (*r == NULL)
            *r = newLInt(0, *r); //cria uma ista antes do resultado para construir a partir dai o resto
        else

            if (l1 == NULL){
                (*r)->prox = l2;
                break;
            }

            else if(l2 == NULL) {
                (*r)->prox = l1;
                break;
            }

            else if (l1->valor < l2->valor) {
                (*r)->prox = l1;
                r = &(*r)->prox;
                l1 = l1->prox;
            }

            else {
                (*r)->prox = l2;
                r = &(*r)->prox;
                l2 = l2->prox;
            }
    }

    *reg = (*reg)->prox;
    free(a);

}













//////////////////////////////////////////////////8
void splitMS (LInt l, int x, LInt *mx, LInt *Mx){


    while(l != NULL) {
        if(l->valor < x){
            if (*mx == NULL)
                *mx = l;
            else {
                (*mx)->prox = l;
                mx = &(*mx)->prox;
            }
        }
        else {
            if (*Mx == NULL)
                *Mx = l;
            else {
                (*Mx)->prox = l;
                Mx = &(*Mx)->prox;
            }
        }

        l = l->prox;
    }

    if (*mx != NULL)
        (*mx)->prox = NULL;
    if (*Mx != NULL)
        (*Mx)->prox = NULL;


}
















//////////////////////////////////////////////////9
LInt parteAmeio (LInt *l){
    int n, i;
    LInt prev = NULL; //lista para percorrer a lista sem perder informação
    LInt rt = *l; //lista para registar a cabeça (o que vai ser retornado)

    for(n = 0; *l != NULL; n++, *l = (*l)->prox) //percorre a lista e regista o tamanho
		;

    for(i = 0, *l = rt; i < n/2; i++, prev = *l, *l = (*l)->prox) //percorre a lista até metade
		;

    if (prev != NULL) //se a primeira metade da lista for vazia, coloca NULL na lista a retornar
        prev->prox = NULL;
    else
        rt = NULL;

    return rt;
}

















//////////////////////////////////////////////////10
int removeAll (LInt *l, int x){
    int c = 0;
    LInt aux = *l, prev = NULL;

    while ( aux != NULL) {
        if(aux->valor  == x) {
            if (prev != NULL)
                prev->prox = aux->prox;
            else
            *l = aux->prox;

            c++;
            free(aux);
        }
        else
            prev = aux;


        aux = aux->prox;
    }

    return c;
}


//////////////////////////////////////////////////11

int removeDups (LInt *l){
    LInt aux, prev = NULL, aux2;
    int c = 0, flag; //c para contar os removidos, flag para sinalizar se é repetido ou não


    aux = *l; //aux no início da lista

    while (aux != NULL) {
        for(aux2 = *l; aux2 != aux; aux2 = aux2->prox) {  //percorrer a lista outra vez em cada nodo
            flag = 0;
            if(aux2->valor == aux->valor) { //se houver um nodo anterior com o mesmo valor
                flag = 1;
                break;
            }

        }

        if (flag == 1) {
            prev->prox = aux->prox;
            free(aux);
            aux = prev->prox;
            c++;
        }
        else {
            prev = aux;
            aux = aux->prox;
        }

    }

    return c;
}



//////////////////////////////////////////////////12

int removeMaiorL (LInt *l){
    int m;                         //var que vai registar o maior valor
    LInt aux, prev = NULL;         //structs que percorrem a lista

    aux = *l;
    m = aux == NULL? 0 : aux->valor;   //m pode ser inicializado com o valor do primeiro elemento

    while( aux != NULL) {              //ciclo para estabelecer o valor máximo
        if(aux->valor > m)
            m = aux->valor;
        aux = aux->prox;
    }

    aux = *l;                       //voltar ao início da lista

    while(aux != NULL) {            //ciclo que encontra e remove a primeira ocorrência do valor máximo
        if(aux->valor == m) {
            if (prev == NULL) {
                free(*l);
                *l = aux->prox;
                break;
            }
            else {
                prev->prox = aux->prox;
                free(aux);
                aux = prev->prox;
                break;
            }
        }
        else {
            prev = aux;
            aux = aux->prox;
        }
    }

    return m;
}



//////////////////////////////////////////////////13

void init (LInt *l){
    LInt aux, prev = NULL;

    if (aux == NULL)       //lista vazia
        return;

    for(aux = *l; aux->prox != NULL; prev = aux, aux = aux->prox) //percorre a lista até ao ultimo elemento (tb guarda o penultimo)
        ;

    if(prev == NULL)                          //caso a lista tenha apenas 1 elemento
        *l = NULL;
    else {                                   //põe o penúltimo a acabar a lista e liberta o espaço do ultimo
        prev->prox = NULL;
        free(aux);
    }

}




//////////////////////////////////////////////////14

void appendL (LInt *l, int x){

    if (*l == NULL)       //se a lista for vazia, simplesmente aloca espaço para 1 lista
        *l = newLInt(x, NULL);
    else {
        for(; *l != NULL; l = &(*l)->prox) //ciclo que percorrec a lista utilizando a cópia do apontador
            ;
        *l = newLInt(x, NULL);             //acrescenta o ultimo elemento
    }
}



/////////////////////////////////////////////////15

void concatL (LInt *a, LInt b){
    LInt prev = NULL, aux;

    while(*a != NULL)
        a = &(*a)->prox; //percorre a primeira lista colocando o apontador no fim


    while (b != NULL) {

        *a = newLInt(b->valor, NULL); //aloca memória para o fim da primeira lista

        if(prev != NULL)
            prev->prox = *a;         //faz com que o anterior final da lista aponte para o novo final

        prev = *a;
        a = &(*a)->prox;
        b = b->prox;
    }
}



///////////////////////////////////////////////////16 (não testei isto por preguiça, se estiver mal alguem que diga)


LInt cloneL(LInt a) {
	LInt ret = NULL, prev = NULL, aux;

	while (a != NULL) {
		if (ret == NULL)
			ret = a;

		aux = newLInt(a->valor, NULL);

		if (prev != NULL)
			prev->prox = aux;

		prev = aux;

		a = a->prox;
	}


	return ret;
}





///////////////////////////////////////////////////17 #facel


LInt cloneRev (LInt l){
    LInt a = NULL;

    while (l != NULL) {

     a = newLInt(l->valor, a);
     l = l->prox;

    }

    return a;
}



/////////////////////////////////////////////////////18  >__<

int maximo (LInt l){
    int r;

    while (l != NULL) {
        if (l->valor > r)
            r = l->valor;

        l = l->prox;
    }
    return r;
}


///////////////////////////////////////////////////19

int take (int n, LInt *l){
    int c;
    LInt aux;

    for(c = 0; n >0 && *l != NULL; c++, n--)
        l = &(*l)->prox;

    while (*l != NULL) {
        aux = (*l)->prox;
        free(*l);
        *l = aux;
    }



    return c;
}





//////////////////////////////////////////////////20
int drop (int n, LInt *l){
    LInt a;
    int c  = 0;

    while( n > 0 && *l != NULL) {
        a = (*l)->prox;
        free(*l);
        *l = a;
        c++;
        n--;
    }
    return c;
}




////////////////////////////////////////////////////21 ._.


LInt NForward (LInt l, int N){


    for(; N > 0; N--)
        l = l->prox;

    return l;
}


////////////////////////////////////////////////////22

int listToArray (LInt l, int v[], int N){
    int c;

    for(c = 0; l != NULL && N > 0; c++, N--) {
        v[c] = l->valor;
        l = l->prox;
    }

    return c;
}


//////////////////////////////////////////////////////23 #facel

LInt arrayToList (int v[], int N){
    LInt ret = NULL;

    for(; N > 0; N--)
        ret = newLInt(v[N-1],ret);

    return ret;
}



////////////////////////////////////////////////////////24


LInt somasAcL (LInt l) {
    LInt aux, prev = NULL, ret;

    while( l != NULL) {

        if(prev != NULL) {
            aux = newLInt(prev->valor + l->valor, NULL);
            prev->prox = aux;
            prev = aux;
        }
        else {
            aux = newLInt(l->valor, NULL);
            prev = aux;
            ret = aux;
        }


        l = l->prox;
    }

    return ret;
}


//////////////////////////////////////////////////////////25



void remreps (LInt l){

    LInt aux, prev = NULL;


    while (l != NULL) {
            if (prev != NULL && prev-> valor == l->valor) {
                prev->prox = l->prox;
                aux = l;
                l = l->prox;
                free(aux);
            }
            else {
                prev = l;
                l = l->prox;
            }
    }
}



//////////////////////////////////////////////////////////26

LInt rotateL (LInt l){
    if (l == NULL)
        return l;

    LInt aux = l, ret = l->prox;


    while ( l->prox != NULL)
        l = l->prox;

    l->prox = aux;
    aux->prox = NULL;

    if (ret == NULL)
        return aux;

    return ret;
}





///////////////////////////////////////////////////////////27 *cancer* (só podia)


LInt parte (LInt l){

    LInt ret, prev1 = NULL; //para a lista resultante
    LInt prev2 = NULL; //para lista original
    int i;

    for(i = 1; l != NULL; i++, l = l->prox) {
        if (i % 2 != 0){
            if (prev1 != NULL)
                prev1->prox = l;

            prev1 = l;
        }

        else {
            if(prev2 != NULL)
                prev2->prox = l;
            else
                ret = l;

            prev2 = l;
        }
    }

    if (prev1 != NULL)
        prev1->prox = NULL;
    if (prev2 != NULL)
        prev2->prox = NULL;

    return ret;
}








//////////////////////////////////////////////////////28

int altura (ABin a){
    int e, d;

    if (a == NULL)
        return 0;

    if (( e = altura(a->esq)) > ( d = altura(a->dir) ))
        return e + 1;
    else
        return d + 1;
}







//////////////////////////////////////////////////////////29


ABin cloneAB (ABin a) {
    if( a == NULL)
        return NULL;

    ABin r;

    r = malloc(sizeof(ABin));

    r->valor = a->valor;
    r->dir = cloneAB(a->dir);
    r->esq = cloneAB(a->esq);

    return r;
}







///////////////////////////////////////////////////////////30


void mirror (ABin *a) {
    if (*a == NULL)
        return;

    ABin save;

    save = (*a)->dir;

    (*a)->dir = (*a)->esq;
    (*a)->esq = save;

    mirror(&(*a)->dir);
    mirror(&(*a)->esq);
}




////////////////////////////////////////////////////////////31


void inorder (ABin a, LInt * l) {
    LInt aux;
    if (a != NULL) {
        inorder(a->dir, l);
        aux = malloc (sizeof (LInt));
        aux -> valor = a -> valor;
        aux -> prox = *l;
        inorder(a->esq, &aux);
        *l  = aux;
    }
}



///////////////////////////////////////////////////////////////32


void preorder_aux (ABin a, LInt * l) {
    LInt aux;
    if (a != NULL) {

        preorder_aux(a->dir, l);
        preorder_aux(a->esq, l);

        aux = malloc (sizeof (LInt));
        aux -> valor = a -> valor;
        aux -> prox = *l;

        *l  = aux;
    }
}

void preorder(ABin a, LInt* l) {
	*l = NULL;

	preorder_aux (a, l);
}

//////////////////////////////////////////////////////////////33 ???????????????


void posorder_aux (ABin a, LInt * l) {
    LInt aux;
    if (a != NULL) {

        aux = malloc (sizeof (LInt));
        aux -> valor = a -> valor;
        aux -> prox = *l;
        *l  = aux;

        posorder_aux(a->dir, l);
        posorder_aux(a->esq, l);
    }
}

void posorder(ABin a, LInt* l) {
	*l = NULL;

	posorder_aux (a, l);
}






///////////////////////////////////////////////////////////34

int depth (ABin a, int x) {
    if (a == NULL)
        return -1;

    if (a->valor == x)
        return 1;
    else {
        int v, w;
        v = depth(a->esq, x);
        w = depth(a->dir, x);

        if (v > 0 && w > 0) {
            if (v > w)
                return 1 + w;
            else
                return 1 + v;
        }
        else if (v > 0)
            return 1 + v;
        else if (w > 0)
            return 1 + w;
        else
            return v;

    }
}



///////////////////////////////////////////////////////////////35


int freeAB (ABin a) {
    if (a == NULL)
        return 0;

    int r = 1 + freeAB(a->dir) + freeAB(a->esq);

    free(a);

    return r;
}






///////////////////////////////////////////////////////////////36


 int pruneAB (ABin *a, int l) {
     int r;
     if(*a == NULL)
        return 0;

     if (l == 0) {
         r = 1 + pruneAB(&(*a)->esq, 0) + pruneAB(&(*a)->dir, 0);
         free(*a);
         *a = NULL;
         return r;
     }
     else
          return pruneAB(&(*a)->esq, l - 1) + pruneAB(&(*a)->dir, l - 1);

 }




 //////////////////////////////////////////////////////////////37


 int iguaisAB (ABin a, ABin b) {

    if (a == b) //se forem os 2 null
        return 1;
    else if (a != NULL && b != NULL && a->valor == b->valor)
        return iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
    else
        return 0;
}


///////////////////////////////////////////////////////////////38



LInt nivelL (ABin a, int n) {

    if (a == NULL)
        return NULL;
    else {
        LInt aux, aux2, p, prev;

        if (n == 1) {
            aux = malloc(sizeof(LInt));
            aux->valor = a->valor;
            aux->prox = NULL;
            return aux;
        }
        else {
            aux = nivelL(a->esq, n - 1);
            aux2 = nivelL(a->dir, n - 1);

            for (p = aux, prev = aux; p != NULL; p = p->prox)
                prev = p;

            if (aux != NULL) {
                prev->prox = aux2;
                return aux;
            }
            else
                return aux2;
        }
    }
}


///////////////////////////////////////////////////////////////39

int nivelV (ABin a, int n, int v[]) {
    if (a == NULL)
        return 0;

    if ( n == 1) {
        *v = a->valor;
        return 1;
    }
    else {
        int d = nivelV(a->esq, n - 1, v);
        return d + nivelV(a->dir, n - 1, v + d);
    }
}


///////////////////////////////////////////////////////////////40


int dumpAbin (ABin a, int v[], int N) {
    if (a == NULL)
        return 0;
    else if (N > 0 ) {
        int d = dumpAbin(a->esq, v, N - 1);
        *(v + d) = a->valor;
        return 1 + d + dumpAbin(a->dir, v + d + 1, N - d - 1);
    }
    else
        return 0;

}



////////////////////////////////////////////////////////////////41

ABin somasAcA (ABin a) {
    if (a == NULL)
        return NULL;
    else {
        ABin aux1 = somasAcA(a->esq);
        ABin aux2 = somasAcA(a->dir);

        ABin ret = malloc(sizeof(ABin));

        int x = 0, y = 0;
        if (aux1 != NULL)
            x = aux1->valor;
        if (aux2 != NULL)
            y = aux2->valor;

        ret->valor = x + y + a->valor;
        ret->esq = aux1;
        ret->dir = aux2;

        return ret;
    }
}



///////////////////////////////////////////////////////////////42


int contaFolhas (ABin a) {
    if (a == NULL)
        return 0;

    if (a->dir == NULL && a->esq == NULL)
        return 1;


    return contaFolhas(a->dir) + contaFolhas(a->esq);
}


////////////////////////////////////////////////////////////////43

ABin cloneMirror (ABin a) {
    if (a == NULL)
        return NULL;
    ABin aux = malloc(sizeof(ABin));
    aux->valor = a->valor;
    aux->esq = cloneMirror(a->dir);
    aux->dir = cloneMirror(a->esq);

    return aux;

}


////////////////////////////////////////////////////////////////44

int addOrd (ABin *a, int x) {
    ABin aux = *a, prev = NULL;

    while(aux != NULL) {

        if (aux->valor == x)
            return 1;

        prev = aux;

        if (x > aux->valor)
            aux = aux->dir;
        else
            aux = aux->esq;

    }

    aux = malloc(sizeof(ABin));
    aux->valor = x;
    aux->esq = aux->dir = NULL;

    if (prev == NULL)
        *a = aux;
    else {
        if (x > prev->valor)
            prev->dir = aux;
        else
            prev-> esq = aux;
    }


    return 0;
}




/////////////////////////////////////////////////////////////////45


int lookupAB (ABin a, int x) {

    while (a != NULL) {
        if (a->valor == x)
            return 1;
        else if (x > a->valor)
            a = a->dir;
        else
            a = a->esq;
    }

    return 0;
}




/////////////////////////////////////////////////////////////////46


int depthOrd (ABin a, int x) {
    int depth;

    for (depth = 1; a != NULL; depth++)
        if (a->valor == x)
            return depth;
        else if (x > a->valor)
            a = a-> dir;
        else
            a = a->esq;

    return -1;
}



////////////////////////////////////////////////////////////////////47


int maiorAB (ABin a) {
    while (a->dir != NULL)
        a = a->dir;
    return a->valor;
}


//////////////////////////////////////////////////////////////////////48

void removeMaiorA (ABin *a) {

        ABin aux;

        while ((*a)->dir != NULL)
            a = &(*a)->dir;


        if ((*a)->esq != NULL) {
            aux = *a;
            *a = (*a)->esq;
            free(aux);
        }
        else {
            free(*a);
            *a = NULL;
        }

}

//////////////////////////////////////////////////////////////////////49

int quantosMaiores (ABin a, int x) {

    if ( a == NULL)
        return 0;
    else if ( a->valor <= x)
        return quantosMaiores(a->dir, x);
    else
        return 1 + quantosMaiores(a->dir, x) + quantosMaiores(a->esq, x);
}



//////////////////////////////////////////////////////////////////////50

void listToBTree (LInt l, ABin *a) {

    if (l == NULL)
        *a = NULL;
    else {

        LInt arg = l, aux = l->prox, prev = NULL;

        while (aux != NULL) {
            prev = arg;
            arg = arg->prox;

            if (aux->prox == NULL)
                aux = NULL;
            else
                aux = aux->prox->prox;
        }

        *a = malloc(sizeof(ABin));
        (*a)->valor = arg->valor;

        if (prev != NULL)
            prev->prox = NULL;


        if (l != arg)
            listToBTree(l, &(*a)->esq);
        else
            (*a)->esq = NULL;

        if (arg != NULL)
            listToBTree(arg->prox, &(*a)->dir);
        else
            (*a)->dir = NULL;
    }


}


////////////////////////////////////////////////////////////////////////51

int deProcura (ABin a) {
    if ( a == NULL)
        return 1;
    else {
        if(a->esq != NULL && (a->esq->valor > a->valor || a->esq->dir != NULL && a->esq->dir->valor > a->valor))
            return 0;
        if(a->dir != NULL && (a->dir->valor <= a->valor|| a->dir->esq != NULL && a->dir->esq->valor <= a->valor))
            return 0;
    }

    return deProcura(a->esq) && deProcura(a->dir);
}
