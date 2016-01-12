#include "list.h"
void displayDown(multiLevelList* head)
{
    while (head != NULL) {
        head->show();
        head = head->down;
    }
    cout<<endl;
}
void sortMergeReverseMergeTest(int argc, char *argv[])
{
    List *head1 = getList(argc, argv, 1);
    List *head2 = getList(argc, argv, 10);
    printList(sortList(head1));
    printList(sortList(head2));
    printList(reverseMerge(head1, head2));
}
void digDeep(multiLevelList *head, int level) {
    for (size_t i = 2; i < level; i++) {
        head->down = new multiLevelList(head->data*i);
        head = head->down;
    }
}
multiLevelList* makeMultiLevelList(int argc, char *argv[])
{
    multiLevelList *head = getMultiLevelList(argc, argv, 1);
    multiLevelList *temp = head;
    while (temp != NULL) {
        digDeep(temp, 6);
        temp = temp->next;
    }
    return head;
}
multiLevelList* mergeDown(multiLevelList *head1, multiLevelList *head2) {
    if (head1 == NULL && head2 == NULL) return head1;
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    head1->next = NULL;
    head2->next = NULL;

    multiLevelList* result = NULL;
    if (head1->data <= head2->data) {
        result = head1;
        result->down = mergeDown(head1->down, head2);
        result->next = NULL;
    } else {
        result = head2;
        result->down = mergeDown(head1, head2->down);
        result->next = NULL;
    }

    return result;
}
multiLevelList * flattenList(multiLevelList *head) {
    if (head == NULL || head->next == NULL) return head;
    multiLevelList *res = mergeDown(head, flattenList(head->next));
    res->next = NULL;
    return res;
}
void flattenTest(int argc, char *argv[])
{
    multiLevelList *head = makeMultiLevelList(argc, argv);
    cout<<"Input : \n";
    printList(head);
    head = flattenList(head);
    cout<<"Output : \n";
    printList(head);
}
int main(int argc, char *argv[]) {
    flattenTest(argc, argv);
    return 0;
}
