#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  //base case: if the list is empty both outputs are set to null
  if(head == NULL){
    smaller = NULL;
    larger = NULL;
    return;
  }
  //detach first node from the list
  Node* current = head;
  head = head->next; //moves head to next node
  current->next = NULL; //isolates current node

  //recursive partition of rest of list
  Node *smallerRest = NULL;
  Node *largerRest = NULL;
  llpivot(head, smallerRest, largerRest, pivot);

  //Adds current node to appropriate list
  if(current->val <= pivot) {
    current->next = smallerRest;
    smaller = current;
    larger = largerRest;
  } else {
    current->next = largerRest;
    larger = current;
    smaller = smallerRest;
  }
}


