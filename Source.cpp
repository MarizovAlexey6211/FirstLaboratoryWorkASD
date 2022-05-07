#include<iostream>
#include <ostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <conio.h>
using namespace std;
void print(ostringstream& out, const vector<int>& v) {
    for (auto el : v) {
        out << el;
    }
}
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
    void inorder(ostringstream& out, Node* r)
    {
        if (r == NULL) {
            return;
        }
        inorder(out, r->left);
        out << r->data << " ";
        inorder(out, r->right);
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
    void print(ostringstream& out)
    {
        out << "{ ";
        root->inorder(out, root);
        out << "}" << endl;
    }

    int getSize()
    {
        return size;
    }
};

void printMenu() {
    // system("CLS");
    cout << "1.Добавить элемент в set\n" <<
        "2.Удалить элемент из set\n" <<
        "3.Проверить наличие элемента в set\n" <<
        "4.Вывести содержимое set\n" <<
        "5.Выход\n" << endl;
}
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Rus");
    int choice = 1;
    Set<int> set;
    printMenu();
    choice = _getch();
    while (choice) {
        switch (choice) {
        case 49: {
            system("CLS");
            cout << "Введите число для добавления в set: " << endl;
            int a;
            cin >> a;
            while (cin.fail()) {
                cout << "Некорректный формат" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> a;
            }
            bool check = set.add(a);
            printMenu();
            if (check)
                cout << "Элемент успешно добавлен в set" << endl;
            else
                cout << "Элемент уже содержится в set" << endl;
            choice = _getch();
            break;
        }
        case 50: {
            system("CLS");
            cout << "Введите число для удаления в set: " << endl;
            int a;
            cin >> a;
            while (cin.fail()) {
                cout << "Некорректный формат" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> a;
            }
            bool check = set.remove(a);
            printMenu();
            if (check)
                cout << "Элемент успешно удален из set" << endl;
            else
                cout << "Элемент не содержится в set" << endl;
            choice = _getch();
            break;
        }
        case 51: {
            system("CLS");
            cout << "Введите число для проверки содержания в set: " << endl;
            int a;
            cin >> a;
            while (cin.fail()) {
                cout << "Некорректный формат" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> a;
            }
            bool check = set.contains(a);
            printMenu();
            if (check)
                cout << "Элемент содержится в set" << endl;
            else
                cout << "Элемент не содержится в set" << endl;
            choice = _getch();
            break;
        }
        case 52:
            printMenu();
            set.displaySet();
            choice = _getch();
            break;
        case 53:
            choice = 0;
            break;
        default:
            printMenu();
            choice = _getch();
        }
    }

    return 0;



}