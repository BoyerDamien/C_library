#include "./includes/ft_list.h"

void print(t_element *element){
    printf("element %d = %s\n", element->index, (char *)element->content);
}

int main(void){

    // Création la liste chainée
    t_list list = ft_list();

    //Ajout de quelques éléments
    list.append(&list, "ok1");
    list.append(&list, "ok2");
    list.append(&list, "ok3");

    //Affichage de tous les éléments de la liste
    //list.iter(list.first, print);

    //Création d'une deuxième liste
    t_list list2 = ft_list();

    //Ajout de quelques elements dans la deuxième liste
    list.append(&list, "ok1");
    list.append(&list, "ok2");
    list.append(&list, "ok3");

    //Concatenation de la première liste et la seconde liste
    t_list list3 = list.concat(&list, &list2);
    list3.iter(list3.first, print);

    // Désallocation de la mémoire
    list.iter(list.first, print);
    list2.iter(list2.first, print);
    list3.iter(list3.first, print);
    return(0);
}