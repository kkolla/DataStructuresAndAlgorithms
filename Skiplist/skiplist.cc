#include "skiplist.h"
/*
 * make a skiplist that is similar to a linked list.
 * this forms the zeroth level.
 */
Skiplist* makeLevelZeroSkipList(int len, int* input)
{
    Skiplist *head;
    if(len == 0) {
        return NULL;
    }
    head = new Skiplist(input[0]);
    head->next[0] = makeLevelZeroSkipList(len - 1, input+1);
    return head;
}

/*
 * Now that the zeroth level is formed, we populate the next levels with this formula.
 * for (level = 1 to MAXLEVELS)
 * {
 *      previouslevel = level - 1
 *      node->next[level] = node->next[previouslevel]->next[previouslevel], provided we dont dereference a nullpointer.
 * }
 */
void populateLevels(Skiplist* head) {
    int level = 1, prevLevel = 0;
    Skiplist* curr;
    Skiplist* nextNode;
    while (level < LEVELS) {
        prevLevel = level - 1;
        curr = head;
        while (curr != NULL) {
            nextNode = curr->next[prevLevel];
            if (nextNode == NULL) {
                curr->next[level] = NULL;
                break;
            }
            curr->next[level] = nextNode->next[prevLevel];
            curr = curr->next[level];
        }

        level++;
    }
}
/*
 * 'multiply' multiplies the given data by a given number;
 *
 */
Skiplist* makeSkipList(int argc, char *argv[])
{
    int listLen;
    int *input = processInputs(&listLen, argc, argv);
    // Initially populate the zeroth level;
    Skiplist *head = makeLevelZeroSkipList(listLen, input);
    populateLevels(head);
    free(input);
    return head;
}
/*
 * this function prints spaces among various levels of a linked List
 */
inline void printSpaces(int level, int flag) {
    level++;
    int spaces = pow(2,level) - 1;
    //cout<<"SP: "<<spaces;
    spaces += flag;
    while (spaces > 0) {
        if (spaces == 1) {
            cout<<">";
        } else {
            cout<<"-";
        }
        spaces--;
    }
}
/*
 * Pretty printer for a skip List
 */
void showSkipList(Skiplist *head, int level) {
    if (level < 0 || level > LEVELS) return;
    while (level < LEVELS) {
        // For all the levels
        Skiplist *curr = head;
        while(curr != NULL)
        {
            /*
             * Take care of double digit numbers.
             * when a double digit number is printed, it eats one space.
             * Here we do some special handling, and account for the additional space printed.
             */
            if (curr->data > 9) {
                curr->show();
                /*
                 * Dont print the pointers if the next node is NULL;
                 */
                if (curr->next[level] != NULL) printSpaces(level, -1);
            } else {
                curr->show();
                if (curr->next[level] != NULL) printSpaces(level, 0);
            }
            curr = curr->next[level];
        }
        level++;
        cout << endl;
    }
    cout<<endl;
}
Skiplist* skipFind(Skiplist *head, int value) {
    if (value < head->data) return NULL;
    if (value == head->data) return head;
    int level = LEVELS - 1;
    Skiplist *curr;
    cout<<"Finding "<< value <<" in the above skiplist"<<endl;
    while (level >= 0) {
        curr = head;
        if (curr->next[level] == NULL)
        {
            level--;
            continue;
        } else {
            while (curr->next[level]->data <= value) {
                if (curr->next[level]->data == value)
                {
                    return curr->next[level];
                }
                curr = curr->next[level];
                if (curr == NULL || curr->next[level] == NULL) break; // Avoid looking inside a null pointer.
            }
        }
        level--;
    }
    return NULL;
}
int main(int argc, char *argv[]) {
    Skiplist *head = makeSkipList(argc, argv);
    int value = 0;
    cout<<"The current skip list is:\n";
    showSkipList(head, 0);
    cout<<"Enter a value to search this skiplist:\n";
    cin>>value;
    Skiplist *search = skipFind(head, value);
    if (search == NULL) cout <<"Not found"<<endl;
    else {
        search->show();
        cout <<" found"<<endl;
    }
    return 0;
}
