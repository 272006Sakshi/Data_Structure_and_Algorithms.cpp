/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                int loopLength = 1;
                Node* temp = slow->next;
                while (temp != slow) {
                   loopLength++;
                   temp = temp->next;
                }
                return loopLength; // 5 - 3+1;
            }
        }
        return 0;
    }
};
