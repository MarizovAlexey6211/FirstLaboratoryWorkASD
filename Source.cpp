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
    Node* insert(Node* r, T d)
    {
        if (r == NULL) {
            Node<T>* tmp = new Node<T>;
            tmp->data = d;
            tmp->left = tmp->right = NULL;
            return tmp;
        }
        if (d < r->data) {
            r->left = insert(r->left, d);
            return r;
        }
        else if (d > r->data) {
            r->right = insert(r->right, d);
            return r;
        }
        else
            return r;
    }
    void delete_node(Node* r) {

        if (r->left) delete_node(r->left);

        if (r->right) delete_node(r->right);

        delete r;
    }
    Node* remove_node(Node* r) {
        Node* current;
        if (!r->left) {
            current = r->right;
        }
        else {
            Node* previous = r;
            current = r->left;
            while (current->right) {
                previous = current;
                current = current->right;
            }
            if (previous != r) {
                previous->right = current->left;
                current->left = r->left;
            }
            current->right = r->right;
        }
        delete r;
        return current;
    }
};

template <typename T>
class Set {
    Node<T>* root;
    int size;

public:
    Set()
    {
        root = NULL;
        size = 0;
    }

    
    ~Set()
    {
        if (root) root->delete_node(root);
    }

    Node<T>* begin() {
        if (size == 0) return nullptr;
        Node<T>* tmp = root;
        while (tmp->left != nullptr) tmp = tmp->left;
        return tmp;
    }

    bool add(const T data)
    {
        if (!root->containsNode(root, data)) {
            root = root->insert(root, data);
            size++;
            return true;
        }
        return false;
    }
    bool remove(const T data) {
        Node<T>** current = &root;
        while (*current) {
            if (data == (*current)->data) {
                *current = root->remove_node(*current);
                --size;
                return true;
            }
            if (data < (*current)->data)
                current = &(*current)->left;
            else
                current = &(*current)->right;
        }
        return false;
    }
    bool contains(T data) const
    {
        return root->containsNode(root, data) ? true : false;
    }
    void displaySet()
    {
        cout << "{ ";
        root->inorder(root);
        cout << "}" << endl;
    }
    int getSize()
    {
        return size;
    }
};
int main(int argc, char* argv[]) {
    Set<int> set;
    set.add(4);
    set.add(8);
    set.add(5);
    set.add(9);
    set.add(12);
    set.add(10);
    set.add(6);
    set.add(7);
    set.displaySet();
    cout << set.remove(8) << endl;
    set.displaySet();
    cout << set.contains(9);
    return 0;
}