#include <stdlib.h>
#include <stdio.h>
 
struct Lista{
    int value;
    struct Lista *next;
};
 
 
struct Lista *Lista_nowy(){
    struct Lista *n = malloc(sizeof(struct Lista));
    n->next = NULL;
}
 
struct Lista *Lista_dodaj(int value, struct Lista *last){
    struct Lista *next = malloc(sizeof(struct Lista));
    next->value = value;
    next->next = NULL;

    last->next = next;
    return next;
}

int main()
{
    FILE *f;
    int a;
    if ((f=fopen("we.txt", "r"))==NULL)
    {
        printf ("Nie moge otworzyc pliku we.txt do zapisu!\n");
        return -1;
    }

    struct Lista *l1 = Lista_nowy();
    struct Lista *w = Lista_nowy();
    w = l1;


    while(!(feof(f)))
    {
        fscanf(f,"%d",&a);
        printf("wczytalem wlasnie %d\n", a);
         w= Lista_dodaj(a,w);
    }
    fclose(f);

    while(l1!=NULL)
    {
        printf("%d\n",l1->value);
        l1 = l1->next;
    }
    return 0;

}