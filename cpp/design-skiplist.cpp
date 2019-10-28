1206. Design Skiplist
Hard

45

7

Favorite

Share
Design a Skiplist without using any built-in libraries.

A Skiplist is a data structure that takes O(log(n)) time to add, erase and search. Comparing with treap and red-black tree which has the same function and performance, the code length of Skiplist can be comparatively short and the idea behind Skiplists are just simple linked lists.

For example: we have a Skiplist containing [30,40,50,60,70,90] and we want to add 80 and 45 into it. The Skiplist works this way:


Artyom Kalinin [CC BY-SA 3.0], via Wikimedia Commons

You can see there are many layers in the Skiplist. Each layer is a sorted linked list. With the help of the top layers, add , erase and search can be faster than O(n). It can be proven that the average time complexity for each operation is O(log(n)) and space complexity is O(n).

To be specific, your design should include these functions:

bool search(int target) : Return whether the target exists in the Skiplist or not.
void add(int num): Insert a value into the SkipList. 
bool erase(int num): Remove a value in the Skiplist. If num does not exist in the Skiplist, do nothing and return false. If there exists multiple num values, removing any one of them is fine.
See more about Skiplist : https://en.wikipedia.org/wiki/Skip_list

Note that duplicates may exist in the Skiplist, your code needs to handle this situation.

 

Example:

Skiplist skiplist = new Skiplist();

skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0);   // return false.
skiplist.add(4);
skiplist.search(1);   // return true.
skiplist.erase(0);    // return false, 0 is not in skiplist.
skiplist.erase(1);    // return true.
skiplist.search(1);   // return false, 1 has already been erased.
 

Constraints:

0 <= num, target <= 20000
At most 50000 calls will be made to search, add, and erase.

struct Node {
    int val;
    vector<Node*> forward;
    Node(int v, int level): val(v), forward(level) { }
};

class Skiplist {
public:
    Skiplist() {
        probability=0.5;
        maxLevel=16;
        head=new Node(INT_MIN, maxLevel);
        nil=new Node(INT_MAX, maxLevel);
        for (int i=0; i<maxLevel; ++i) head->forward[i]=nil;
    }
    
    bool search(int target) {        
        Node* curr=head;    
        for (int i=nodeLevel(head)-1; i>=0; --i) {
            while (curr->forward[i]->val<target) curr=curr->forward[i];
        }
        return curr->forward[0]->val==target;
    }
    
    void add(int num) {
        int level=randomLevel();
        Node* n=new Node(num, level);        
        
        vector<Node*> prev=getPrev(num);
        for (int i=0; i<level; ++i) {
            n->forward[i]=prev[i]->forward[i];
            prev[i]->forward[i]=n;            
        }        
    }
    
    bool erase(int num) {
        vector<Node*> prev=getPrev(num);
        Node* n=prev[0]->forward[0];
        if (n->val!=num) return false;

        for (int i=0; i<nodeLevel(n); ++i) {
            prev[i]->forward[i]=n->forward[i];
        }
        delete n;        
        return true;
    }
private:
    int nodeLevel(Node* n) {
        return n->forward.size();
    }
    
    int randomLevel() {
        int res=1;
        while ((double)rand()/RAND_MAX<probability && res<maxLevel) res++;
        return res;
    }
    
    vector<Node*> getPrev(int num) {
        vector<Node*> prev(nodeLevel(head));
        Node* curr=head;
        for (int i=nodeLevel(head)-1; i>=0; --i) {
            while (curr->forward[i]->val<num) curr=curr->forward[i];
            prev[i]=curr;
        }
        return prev;
    }
    
    double probability;
    int maxLevel;
    Node* head;
    Node* nil;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
