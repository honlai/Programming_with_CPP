#include <iostream>
using namespace std;
struct Node
{
    string name = "";
    Node *prev = nullptr;
    Node *next = nullptr;
    Node(string arg_name = "", Node *arg_iter_prev = nullptr, Node *arg_iter_next = nullptr)
        : name(arg_name), prev(arg_iter_prev), next(arg_iter_next) {}
    void print() const;
    ~Node() {}
};
struct Josephus_circle
{
    int size = 0;
    Node *head = nullptr;
    Node *gun = nullptr;
    void create(const int &arg_size);
    void turn_to_cir();
    void add_node(Node *node);
    void delete_node(char cmd);
    void gun_shoot(char cmd);
    void prev();
    void next();
    void print() const;
};
int main()
{
    int len = 0, cmd_len = 0;
    cin >> len >> cmd_len;
    Josephus_circle j_circle;
    j_circle.create(len);
    for (int i = 0; i < cmd_len; ++i)
    {
        string tmp = "";
        cin >> tmp;
        if (tmp == "print")
        {
            j_circle.print();
        }
        else
        {
            j_circle.delete_node(tmp[0]);
        }
    }
    return 0;
}

void Josephus_circle::create(const int &arg_size)
{
    size = arg_size;
    for (int i = 0; i < size; ++i)
    {
        string tmp = "";
        cin >> tmp;
        Node *node = new Node(tmp);
        add_node(node);
    }
    turn_to_cir();
    return;
}
void Josephus_circle::turn_to_cir()
{
    head->prev = gun;
    gun->next = head;
    next();
    return;
}
void Josephus_circle::add_node(Node *arg_node)
{
    if (gun != nullptr)
    {
        gun->next = arg_node;
        arg_node->prev = gun;
    }
    else
    {
        head = arg_node;
    }
    gun = arg_node;
    return;
}
void Josephus_circle::gun_shoot(char cmd)
{
    gun->next->prev = gun->prev;
    gun->prev->next = gun->next;
    cout << "remove " << gun->name << endl;
    --size;
    Node *died = gun;
    if (cmd == 'p')
    {
        prev();
    }
    if (cmd == 'n')
    {
        next();
    }
    delete died;

    return;
}
void Josephus_circle::delete_node(char cmd)
{
    int pos = 0;
    cin >> pos;
    if (cmd == 'p')
    {
        while (--pos)
        {
            prev();
        }
        gun_shoot(cmd);
    }
    if (cmd == 'n')
    {
        while (--pos)
        {
            next();
        }
        gun_shoot(cmd);
    }
    return;
}
void Josephus_circle::prev()
{
    Node *tmp = gun->prev;
    gun = tmp;
    return;
}
void Josephus_circle::next()
{
    Node *tmp = gun->next;
    gun = tmp;
    return;
}

void Node::print() const { cout << name << endl; }
void Josephus_circle::print() const
{
    Node *iter = gun;
    cout << size << endl;
    if (size == 0)
    {
        cout << "None" << endl;
    }
    for (int i = 0; i < size; ++i)
    {
        cout << iter->name << endl;
        Node *tmp = iter->next;
        iter = tmp;
    }
    return;
}