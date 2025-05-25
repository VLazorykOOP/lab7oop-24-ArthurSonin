// OOPLab8T.cpp :  for Lab7 (new)
//

#include <iostream>
#include "example.h"
using namespace std;

//---------------------------------------------------task1---------------------------------------------------------------------;

template <typename T>
void change(T& x, T& y) {
    T r;
    r = x;
    x = y;
    y = r;
    return;
}

template<>
void change<char*>(char*& x, char*& y)
{
    char* r;
    r = x;
    x = y;
    y = r;
    return;
}

//---------------------------------------------------task2---------------------------------------------------------------------;

template <typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

template <>
void insertionSort<char*>(char* arr[], int size) {
    for (int i = 1; i < size; i++) {
        char* key = arr[i];
        int j = i - 1;
        while (j >= 0 && std::strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


//---------------------------------------------------task3---------------------------------------------------------------------;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    Node<T>* root;

    void insert(Node<T>*& node, T value) {
        if (!node) {
            node = new Node<T>(value);
            return;
        }
        if (value < node->data)
            insert(node->left, value);
        else
            insert(node->right, value);
    }

    void inorder(Node<T>* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void reverseOrder(Node<T>* node) {
        if (!node) return;
        reverseOrder(node->right);
        cout << node->data << " ";
        reverseOrder(node->left);
    }

    bool search(Node<T>* node, T value) {
        if (!node) return false;
        if (node->data == value) return true;
        return value < node->data ? search(node->left, value) : search(node->right, value);
    }

public:
    BinaryTree() : root(nullptr) {}

    void addElement(T value) {
        insert(root, value);
    }


    void traverseAscending() {
        inorder(root);
        cout << endl;
    }

    void traverseDescending() {
        reverseOrder(root);
        cout << endl;
    }

    bool findElement(T value) {
        return search(root, value);
    }
};

//---------------------------------------------------task4---------------------------------------------------------------------;

template <typename T>
class Node1 {
public:
    T data;
    Node1* prev;
    Node1* next;

    Node1(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node1<T>* head;
    Node1<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addFront(T value) {
        Node1<T>* newNode = new Node1<T>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addBack(T value) {
        Node1<T>* newNode = new Node1<T>(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void displayForward() {
        Node1<T>* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node1<T>* temp = tail;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    class Iterator {
    private:
        Node1<T>* current;

    public:
        Iterator(Node1<T>* start) : current(start) {}

        bool hasNext() {
            return current != nullptr;
        }

        T next() {
            if (!current) throw out_of_range("End of list reached");
            T value = current->data;
            current = current->next;
            return value;
        }
    };

    Iterator getIterator() {
        return Iterator(head);
    }
};



void MenuTask()
{
    cout << "    Menu Task \n";
    cout << "    1.  task1 \n";
    cout << "    2.  task2 \n";
    cout << "    3.  task3 \n";
    cout << "    4.  task4 \n";
    cout << "    5.  Exit  \n";
}

int main()
{
    setlocale(LC_CTYPE, "ukr");
    cout << " Lab #6  !\n";

    char ch = '5';
    do {
        setlocale(LC_CTYPE, "ukr");
        system("cls");
        MenuTask();
        ch = cin.get();

        cin.get();

        switch (ch) {
        case '1': {
            int e;
            int    a = 5, b = 4;
            double t = 3.5, q = 3.05;
            char   s = 'a', n = 'f';

            cout << "a= " << a << "   b= " << b << endl;
            change(a, b);
            cout << "a= " << a << "   b= " << b << endl;

            cout << "t= " << t << "   q= " << q << endl;
            change(t, q);
            cout << "t= " << t << "   q= " << q << endl;

            cout << "s= " << s << "   n= " << n << endl;
            change(s, n);
            cout << "s= " << s << "   n= " << n << endl;

            char* s1 = (char*)"text", * s2 = (char*)"txt";
            cout << "s1= " << s1 << "   s2= " << s2 << endl;
            change(s1, s2);
            cout << "s1= " << s1 << "   s2= " << s2 << endl;
            cin >> e;
        }break;
        case '2': {
            int e;
            int arrInt[] = { 5, 2, 9, 1, 5, 6 };
            int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);
            double arrDbl[] = { 5.3, 5.7, 0.9, 1.2, 5.1, 0.00999 };
            int sizeDbl = sizeof(arrDbl) / sizeof(arrDbl[0]);

            insertionSort(arrInt, sizeInt);

            cout << "Вiдсортований масив цiлих чисел: ";
            for (int i = 0; i < sizeInt; i++) {
                cout << arrInt[i] << " ";
            }
            cout << endl;

            insertionSort(arrDbl, sizeDbl);

            cout << "Вiдсортований масив дробових чисел: ";
            for (int i = 0; i < sizeDbl; i++) {
                cout << arrDbl[i] << " ";
            }
            cout << endl;

            char arrStr1[][10] = { "banana", "apple", "cherry", "date" };
            char* arrStr[4];

            for (int i = 0; i < 4; i++) {
                arrStr[i] = arrStr1[i];
            }

            int sizeStr = sizeof(arrStr) / sizeof(arrStr[0]);

            insertionSort(arrStr, sizeStr);

            cout << "Вiдсортований масив рядкiв: ";

            for (int i = 0; i < sizeStr; i++) {
                cout << arrStr[i] << " ";
            }
            cout << endl;
            cin >> e;
        }break;
        case '3': {
            int e;
            BinaryTree<int> tree;

            tree.addElement(570);
            tree.addElement(307);
            tree.addElement(790);
            tree.addElement(596);
            tree.addElement(406);
            tree.addElement(690);
            tree.addElement(860);

            cout << "Обхiд у висхiдному порядку: ";
            tree.traverseAscending();

            cout << "Обхiд у спадному порядку: ";
            tree.traverseDescending();

            int searchValue = 40;
            cout << "Пошук " << searchValue << ": " << (tree.findElement(searchValue) ? "Знайдено" : "Не знайдено") << endl;

            searchValue = 860;
            cout << "Пошук " << searchValue << ": " << (tree.findElement(searchValue) ? "Знайдено\n" : "Не знайдено\n") << "----------------------------------------------------------------\n";

            BinaryTree<char> ctree;

            ctree.addElement('s');
            ctree.addElement('f');
            ctree.addElement('g');
            ctree.addElement('b');
            ctree.addElement('m');
            ctree.addElement('u');
            ctree.addElement('e');

            cout << "Обхiд у висхiдному порядку: ";
            ctree.traverseAscending();

            cout << "Обхiд у спадному порядку: ";
            ctree.traverseDescending();

            char csearchValue = 'p';
            cout << "Пошук " << csearchValue << ": " << (ctree.findElement(csearchValue) ? "Знайдено" : "Не знайдено") << endl;

            csearchValue = 'm';
            cout << "Пошук " << csearchValue << ": " << (ctree.findElement(csearchValue) ? "Знайдено" : "Не знайдено") << endl;
            cin >> e;            
        }break;
        case '4': {
            int e;
            DoublyLinkedList<int> list;
            list.addFront(10);
            list.addFront(20);
            list.addBack(5);
            list.addBack(1);

            cout << "Список у прямому порядку: ";
            list.displayForward();

            cout << "Список у зворотному порядку: ";
            list.displayBackward();

            cout << "Прохiд через iтератор: ";
            DoublyLinkedList<int>::Iterator it = list.getIterator();
            while (it.hasNext()) {
                cout << it.next() << " ";
            }
            cout << endl;
            cin >> e;
        }break;
        case '5': return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '6');

    return 0;
    int r;
    cout << " Run example press 1 \n";
    cin >> r; if (r == 1) example();
    
}

