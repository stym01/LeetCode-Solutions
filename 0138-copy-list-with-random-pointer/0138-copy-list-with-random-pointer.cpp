/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*temp=head;
        while(temp){
            Node*dup=new Node(temp->val);
            dup->next=temp->next;
            temp->next=dup;
            temp=dup->next;
        }

        temp=head;
        while(temp){
            if(temp->random!=NULL)
                temp->next->random=temp->random->next;
            else
                temp->next->random=NULL;

            temp=temp->next->next;
        }

        temp=head;
        Node*ans=new Node(-1);
        Node*dummy=ans;

        while(temp){
            ans->next=temp->next;
            ans=ans->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;

    }
};