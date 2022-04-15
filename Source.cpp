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

};
int main(int argc, char* argv[]) {
    return 0;
}