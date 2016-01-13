#include "list.h"

/*
 * The problem statement states that the listlist node is such that
 * every node contains a single digit. The sum never exceeds 2 digits, therefore
 * the new result value is as simple as sum/10 and the carry is sum%10
 */
List* addLists_(List* head1, List* head2, int carry) {
    int sum = 0;
    List *result = NULL;
    if (head1 == NULL && head2 == NULL) {
        if (carry == 0) return NULL;
        return new List(carry);
    }
    if (head1 == NULL) {
        sum = head2->data + carry;
        result = new List(sum%10);
        result->next = addLists_(head1, head2->next, sum/10);
        return result;
    }
    if (head2 == NULL) {
        sum = head1->data + carry;
        result = new List(sum%10);
        result->next = addLists_(head1->next, head2, sum/10);
        return result;
    }
    sum = head1->data + head2->data + carry;
    result = new List(sum%10);
    result->next = addLists_(head1->next, head2->next, sum/10);
    return result;
}

List* addLists(List* head1, List* head2) {
    return addLists_(head1, head2, 0);
}
