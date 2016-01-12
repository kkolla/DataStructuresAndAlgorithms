#include "list.h"
List* breakList(List* head) {
    List* midNode = head;
    List* prevNode = NULL;
    while (head != NULL) {
        head = head->next;
        prevNode = midNode;
        midNode = midNode->next;
        if (head == NULL) break;
        head = head->next;
    }
    prevNode->next = NULL;
    return midNode;
}

List* mergeLists(List *head1, List *head2) {
    List *result = NULL;
    if (head1 == NULL && head2 == NULL) return NULL;
    if (head1 == NULL || head2 == NULL) return (head2 == NULL ? head1 : head2);
    if (head1->data < head2->data) {
        result = head1;
        result->next = mergeLists(head1->next, head2);
        return result;
    }
    result = head2;
    result->next = mergeLists(head1, head2->next);
    return result;
}

List* sortList(List *head) {
    if (head == NULL || head->next == NULL) return head;
    if (head->next->next == NULL) {
        // two nodes. Do manual stuff
        if (head->data < head->next->data) {
            return head;
        } else {
            int temp = head->data;
            head->data = head->next->data;
            head->next->data = temp;
            return head;
        }
    }
    List *midNode = breakList(head);
    sortList(head);
    sortList(midNode);
    return mergeLists(head, midNode);
}
