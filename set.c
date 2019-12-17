/************  SET.c  *************/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "set.h"

symset uniteset(symset s1, symset s2) // sort and unite s1 and s2 from small to large
{
	symset s;
	snode* p;
	
	s = p = (snode*) malloc(sizeof(snode)); //pointer
	s1 = s1->next;
	s2 = s2->next;

	
	while (s1 && s2)
	{
		p->next = (snode*) malloc(sizeof(snode));
		p = p->next;
		if (s1->elem < s2->elem)
		{
			p->elem = s1->elem;
			s1 = s1->next;
		}
		else if (s1->elem > s2->elem)
		{
			p->elem = s2->elem;
			s2 = s2->next;
		}
		/* TO BE MODIFIED */
		else{
            p->elem = s1->elem;
            s1 = s1->next;
            s2 = s2->next;
		}
	}

	while (s1)
	{
		p->next = (snode*) malloc(sizeof(snode));
		p = p->next;
		p->elem = s1->elem;
		s1 = s1->next;
		
	}

	while (s2)
	{
		p->next = (snode*) malloc(sizeof(snode));
		p = p->next;
		p->elem = s2->elem;
		s2 = s2->next;
	}

	p->next = NULL;

	return s;
} // uniteset

void setinsert(symset s, int elem) // insert an element into set s by order
{
    /* TO BE MODIFIED */
    snode* p;
    p = s;
    while(p->next && (p->next->elem < elem)){
        p = p->next;
    }
    snode* insert;
    insert = (snode*)malloc(sizeof(snode));
    insert->next = p->next;
    p -> next = insert;
    insert -> elem = elem;

} // setinsert

symset createset(int elem, .../* SYM_NULL */)
{
	va_list list;
	symset s;

	s = (snode*) malloc(sizeof(snode));
	s->next = NULL;

	va_start(list, elem);
	while (elem)
	{
		setinsert(s, elem);
		elem = va_arg(list, int);
	}
	va_end(list);
	return s;
} // createset

void destroyset(symset s) // delete s
{
	snode* p;

	while (s)
	{
		p = s;
		s = s->next;
		free(p);
	}
} // destroyset

int inset(int elem, symset s) // judge if a element is in set s
{
    /* TO BE MODIFIED */
    int inSet = 0;
    snode* p;
    p = s;
    while(p){
        if(p->elem == elem){
            inSet=1;
            break;
        }
        p = p->next;
    }
    return inSet;
} // inset

// EOF set.c

/*DEBUG*/
void printset(symset s)
{
    snode* p;
    p = s;
    while(p){
        int elem = p->elem;
        printf("%d -> ",elem);
        p = p->next;
    }
    printf("end \n");
}

