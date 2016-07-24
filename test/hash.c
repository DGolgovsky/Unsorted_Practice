/* Работа с хэш-таблицей. Часть функций написана так, чтобы
 * быть независимой от типов ключа и значения и легко
 * подвергаться модификации.
 */
#include <stdio.h>
#include <string.h>     /* prototype for strchr() */
extern void *malloc(unsigned size);
/* типы ключа и значения: в нашем случае это строки */
typedef unsigned char uchar;
typedef uchar *VAL; typedef uchar *KEY;
/* Для использования следует реализовать операции
int  HASHFUNC(KEY); int  EQKEY(KEY, KEY);
void FREEVAL(VAL);  void SETVAL(VAL, VAL);
void FREEKEY(KEY);  void SETKEY(KEY, KEY);
*/
#define HASHSIZE 21     /* размер таблицы: очень хорошо 2**n */
uchar *strudup(const uchar *s){ /* создание копии строки в "куче" */
  uchar *p =  (uchar *) malloc(strlen(s)+1); strcpy(p, s); return p;
}
/* одна из возможных хэш-функций */
unsigned int hash; /* последнее вычисленное значение хэш-функции */
int HASHFUNC(KEY key){
    unsigned int i = 0; uchar *keysrc = key;
    while(*key){
      i = (i << 1)|(i >> 15); /* ROL */
      i ^= *key++;
    }
    hash = i % HASHSIZE;
    printf( "hash(%s)=%d\n", keysrc, hash);  /* отладка */
    return hash;
}
#define EQKEY(s1, s2)   (strcmp(s1, s2) == 0)
#define FREEKEY(s)      free(s)
#define FREEVAL(s)      free(s)
#define SETVAL(at,s)    at = strudup(s)
#define SETKEY(at,s)    at = strudup(s)
#define KEYFMT          "%s"
#define VALFMT          "%s"
/* ================== типо-независимая часть ================= */
struct cell {
    struct cell *next; /* ссылка на очередной элемент */
    KEY key;           /* ключ     */
    VAL val;           /* значение */
} *hashtable[ HASHSIZE ];  /* хэш-таблица */
/* получение значения по ключу */
struct cell *get(KEY key){
    struct cell *p;
    for(p = hashtable[HASHFUNC(key)]; p; p = p->next)
        if(EQKEY(p->key, key))
            return p;
    return NULL;    /* отсутствует */
}
/* занести пару ключ:значение в таблицу */
void set(KEY key, VAL val){
    struct cell *p;
    /* проверить - не было ли звена с таким ключом */
    if((p = get(key)) == NULL){       /* не было   */
        if(!(p = (struct cell *) malloc(sizeof(*p)))) return;
        SETKEY(p->key, key);
        p->next = hashtable[hash]; /* hash вычислено в get() */
        hashtable[hash] = p;
    } else /* уже было: изменить значение */
        FREEVAL(p->val);
    SETVAL(p->val, val);
}
/* удаление по ключу */
int del(KEY key){
    int indx = HASHFUNC(key);
    struct cell *p, *prev = NULL;
    if((p = hashtable[indx]) == NULL) return 0;
    for( ;p ;prev = p, p=p->next)
        if(EQKEY(p->key, key)){
            FREEVAL(p->val); FREEKEY(p->key);
            if( p == hashtable[indx] ) /* голова списка */
                 hashtable[indx] = p->next;
            else     prev->next = p->next;
            free((void *) p ); return 1; /* удален */
        }
    return 0;  /* не было такого */
}
/* распечатать пару ключ:значение */
void printcell(struct cell *ptr){
    putchar('(');
    printf( KEYFMT, ptr->key ); putchar(',');
    printf( VALFMT, ptr->val ); putchar(')');
}
/* распечатка таблицы (для отладки) */
void printtable(){
  register i; struct cell *p;
  printf("----TABLE CONTENTS----\n");
  for(i=0; i < HASHSIZE; i++)
      if((p = hashtable[i]) != NULL){
      printf( "%d: ", i);
      for(; p; p=p->next)
         printcell(p), putchar(' ');
      putchar('\n');
      }
}
/* итератор */
struct celliter {
    int index; struct cell *ptr;
};
/* выдать очередное значение */
struct cell *nextpair(struct celliter *ci){
    struct cell *result;
    while((result = ci->ptr) == NULL){
        if( ++(ci->index) >= HASHSIZE )
            return NULL;    /* больше нет */
        ci->ptr = hashtable[ci->index];
    }
    ci->ptr = result->next; return result;
}
/* инициализация итератора */
struct cell *resetiter(struct celliter *ci){
    ci->index = (-1); ci->ptr = NULL;
    return nextpair(ci);  /* первое значение */
}
/* =========================================================== */
void main(){ /* таблица из имен и размеров файлов текущего каталога */
 struct celliter ci; struct cell *cl;
 char key[40], value[40]; struct cell *val;
 extern FILE *popen();    FILE *fp;     char *s ;
 /* popen() читает вывод команды, заданной в 1-ом аргументе */
 fp = popen( "ls -s", "r" );
 while( fscanf( fp, "%s%s", value, key) == 2 )
    set(key, value);
 pclose(fp);  /* popen() надо закрывать pclose(); */
 for(;;){
    printf( "-> " );  /* приглашение */
    if( !gets( key )) break;   /* EOF */
    if( *key == '-' ){         /* -КЛЮЧ          :удалить     */
        printf( del( key+1 ) ? "OK\n" : "нет такого\n");
        continue;
    }
    if( !*key || !strcmp(key, "=")){ /* = :распечатать таблицу*/
        printtable();    continue;
    }
    if(s = strchr(key, '=')){ /* КЛЮЧ=ЗНАЧЕНИЕ  :добавить     */
        *s++ = '\0';
        set(key, s); continue;
    }
    if((val = get( key )) == NULL) /* КЛЮЧ :найти значение */
         printf( "нет такого ключа\n");
    else{ printf( "значение "); printf(VALFMT, val->val);
          putchar('\n');
    }
 }
 /* распечатка таблицы при помощи итератора */
 for( cl = resetiter(&ci) ; cl ; cl = nextpair(&ci))
    printcell(cl), putchar('\n');
}
