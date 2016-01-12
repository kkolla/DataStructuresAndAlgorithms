#include "list.h"

int main(int argc, char *argv[]) {
    int listLen;
    int *input = processInputs(&listLen, argc, argv);
    List *head1 = makeSLL(listLen, input);
    for (size_t i = 0; i < listLen; i++) {
        input[i] *= 10;
    }
    List *head2 = makeSLL(listLen, input);
    printList(sortList(head1));
    printList(sortList(head2));
    printList(reverseMerge(head1, head2));

    return 0;
}
