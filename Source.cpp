#include<iostream>
using namespace std;
template <typename T>
struct Node {
    
    T data;
    Node* left;
    Node* right;
public:
    void inorder(Node* r)
    {
        if (r == NULL) {
            return;
        }
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }

    int containsNode(Node* r, T d)
    {
        if (r == NULL) {
            return 0;
        }
        int x = r->data == d ? 1 : 0;
        return x | containsNode(r->left, d) | containsNode(r->right, d);
    }
};
int main(int argc, char* argv[]) {
    return 0;
}