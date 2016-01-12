#include "list.h"
/*
 *
    Input:  a: 5 -> 10-> 15 -> 40
            b: 2 -> 3 -> 20
                  temp
    Output: res: 40->20->15->10->5->3->2

    Input:  a: NULL
            b: 2->3->20
    Output: res: 20->3->2
 *
 */

 /*
  * Approach - merge lists and for the result list, add every new node at the head.
  */
List* reverseMerge(List *head1, List *head2)
{
    List *result = NULL;
    List *temp = NULL;
    if (head1 == NULL && head2 == NULL) return head1;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data) {

            // get a pointer to the next node of a list.
            temp = head1->next;

            // take the current node, and attach result to the end.
            head1->next = result;
            result = head1;
            head1 = temp;
        } else {
            // get a pointer to the next node of a list.
            temp = head2->next;

            // take the current node, and attach result to the end.
            head2->next = result;
            result = head2;
            head2 = temp;
        }
    }
    while (head1 != NULL)
    {
        temp = head1->next;
        head1->next = result;
        result = head1;
        head1 = temp;
    }
    while (head2 != NULL)
    {
        temp = head2->next;
        head2->next = result;
        result = head2;
        head2 = temp;
    }
    return result;
}
