#include "./includes/ft_list.h"

void print(t_element *element){
    printf("element %d = %s\n", element->index, (char *)element->content);
}

int fn(t_element *element){
	return (((char *)element->content)[0] == '1');
}

int main(void){

    t_list test = ft_list();
    test.append(&test, "ok1");
    test.append(&test, "ok2");
    test.append(&test, "ok3");
    test.append(&test, "1k4");
    test.append(&test, "ok5");
    test.append(&test, "ok6");
    printf("result = %d\n", (test.search(test.first, fn))->index);
    test.iter(test.first, print);
    test.clear(&test);
    return(0);
}