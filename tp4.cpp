#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int val;
    struct element *suivant;
} element;

element* creerliste() {
    return NULL;
}

element* chargerListe(int* Tab, int x, element* head) {
    for (int i = 0; i < x; i++) {
        element* list = (element*)malloc(sizeof(element));
        list->val = Tab[i];
        list->suivant = NULL;

        if (head == NULL) {
            head = list;
        } else {
            element* tim = head;
            while (tim->suivant != NULL) {
                tim = tim->suivant;
            }
            tim->suivant = list;
        }
    }
    return head;
}

void afficherListe(element* head) {
    element* tim = head;
    while (tim != NULL) {
        printf("%d -> ", tim->val);
        tim = tim->suivant;
    }
    printf("NULL\n");
}

element* supprimerEnFin(element* head) {
    if (head == NULL) return NULL;

    if (head->suivant == NULL) {
        free(head);
        return NULL;
    }

    element* tim = head;
    while (tim->suivant->suivant != NULL) {
        tim = tim->suivant;
    }

    free(tim->suivant);
    tim->suivant = NULL;

    return head;
}

element* ajouterEnDebut(element* head, int n) {
    element* list = (element*)malloc(sizeof(element));
    list->val = n;
    list->suivant = head;
    return list;
}

void viderListe(element* L) {
    element* tmp;
    while (L != NULL) {
        tmp = L;
        L = L->suivant;
        free(tmp);
    }
    
}

int main() {
    int Tab[10] = {1, 3, 5, 7, 8, 10, 9, 11, 13, 20};

    element* liste = creerliste();
    element* L = chargerListe(Tab, 10, liste);

    afficherListe(L);

    element* L1 = supprimerEnFin(L);
    afficherListe(L1);

    element* L2 = ajouterEnDebut(L1, 40);
    afficherListe(L2);

    viderListe(L2);

    return 0;
}

