

#include <iostream>
using namespace std;

template <typename T> class ListaEnlazada {

  struct Node {
    T data;
    Node *next;
    Node(T dato) {
      data = dato;
      next = nullptr;
    }
  }; 

  Node *head;
  int size_;

public:
  ListaEnlazada() {
    head = nullptr;
    size_ = 0;
  }

  T front() {
    if (head != nullptr) {
      return head->data;
    } else {
      throw "lista vacia";
    }
  }

  T back() {
    Node *temp = head;
    if (temp != nullptr) {
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      return temp->data;
    } else {
      throw "lista vacia";
    }
  }

  void push_front(T data) {
    Node *nodo = new Node(data);
    nodo->next = head;
    head = nodo;
    size_++;
  }

  void push_back(T data) {
    Node *nodo = new Node(data);

    if (head == nullptr) {
      head = nodo;
      size_++;
      return;
    }

    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = nodo;
    size_++;
  }

  T pop_front() {

    if (head == nullptr) {
      throw "lista vacia";
    }

    Node *temp = head;
    T valor = temp->data;
    head = head->next;
    delete temp;
    temp = nullptr;
    size_--;
    return valor;
  }

  T pop_back() {

    if (head == nullptr) {
      throw "lista vacia";
    }
    T dato;
    if (head->next == nullptr) {
      dato = head->data;
      delete head;
      head = nullptr;
    } else {
      Node *temp = head;
      while (temp->next->next != nullptr) {
        temp = temp->next;
      }
      dato = temp->data;
      delete temp->next;
      temp->next = nullptr;
    }
    size_--;
    return dato;
  }

  T operator[](int i) {
    if (i > size_) {
      throw "fuera de rango";
    }
    Node *temp = head;

    for (int it = 0; it < i; it++) {
      temp = temp->next;
    }
    return temp->data;
  }

  bool empty() { return (size_ == 0); }

  int size() { return size_; }

  void clear() {
    while (head != nullptr) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
    size_ = 0;
  }

  void reverse() {
    Node *temp = nullptr;
    while (head != nullptr) {
      Node *last = head;

      Node *novo = new Node(last->data);
      novo->next = temp;
      temp = novo;

      head = head->next;

      delete last;
      last = nullptr;
    }
    head = temp;
  }

void sort() {
    if (size_ <= 1) {
        return;
    }

    bool swapped = true;

    while (swapped) {
        swapped = false;
        Node *temp = head;
        Node *previous = nullptr;
        Node *nextNode = head->next;

        while (nextNode != nullptr) {
            if (temp->data > nextNode->data) {
                if (previous != nullptr) {
                    previous->next = nextNode;
                } else {
                    head = nextNode;
                }
                temp->next = nextNode->next;
                nextNode->next = temp;

                previous = nextNode;
                nextNode = temp->next;

                swapped = true;
            } else {
                previous = temp;
                temp = nextNode;
                nextNode = nextNode->next;
            }
        }
    }
}


  void print() {
    Node *temp = head;
    while (temp != nullptr) {
      cout << "[" << temp->data << "]";
      temp = temp->next;
      cout << "->";
    }
    cout << "NULL" << endl;
  }
};

int main() {
  ListaEnlazada<int> lista;
  // PUSH_BACK //
  cout << "Tamaño actual : " << lista.size() << endl;

  cout << "// PUSH BACK //" << endl;

  lista.push_back(5);
  lista.push_back(4);
  lista.push_back(96);
  lista.print();

  cout << "Tamaño actual : " << lista.size() << endl;

  cout << "// PUSH FRONT //" << endl;
  lista.push_front(70);
  lista.push_front(170);

  lista.push_front(10);
  lista.push_front(95);

  lista.push_front(40);

  lista.print();

  cout << "Tamaño actual : " << lista.size() << endl;

  cout << "// POP BACK //" << endl;
  lista.pop_back();
  lista.print();

  cout << "Tamaño actual : " << lista.size() << endl;

  cout << "// POP BACK //" << endl;
  lista.pop_back();
  lista.print();

  cout << "Tamaño actual : " << lista.size() << endl;

  cout << "// POP FRONT //" << endl;
  lista.pop_front();
  lista.print();

  cout << "Tamaño actual : " << lista.size() << endl;

  cout << "// LISTA[3] //" << endl;
  cout << lista[3] << endl;
  cout << "// REVERSE //" << endl;
  lista.reverse();
  lista.print();
  cout << "Tamaño actual : " << lista.size() << endl;
  cout << "// FRONT //" << endl;
  cout << lista.front() << endl;
  cout << "// BACK //" << endl;
  cout << lista.back() << endl;
  cout << "// EMPTY //" << endl;
  cout << "Tamaño actual : " << lista.size() << endl;
  cout << lista.empty() << endl;
  cout << "// SORT //" << endl;
  lista.sort();
  lista.print();
  cout << "// CLEAR //" << endl;
  lista.clear();
  lista.print();

  cout << "// EMPTY //" << endl;
  cout << "Tamaño actual : " << lista.size() << endl;
  cout << lista.empty() << endl;
}
