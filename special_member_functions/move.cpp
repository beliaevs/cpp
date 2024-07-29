#include<iostream>
#include <string>
#include<vector>

class Node
{
    friend class Object;
public:
    Node(): id(freeId()) 
    {
        Nodes.push_back(this);
    }
    
    Node(const Node&) = delete;
    Node(Node&&) = delete;
    Node& operator=(const Node&) = delete;
    Node& operator=(Node&&) = delete;
    ~Node() = default;

    static std::vector<Node*>& getNodes()
    {
        return Nodes;
    }

    static void snapshot()
    {
        auto dump = [](Node* node){ return node ? std::to_string(node->id) : "(null)"; }; 
        for(auto* n: getNodes())
        {
            std::cout << (n->deleted ? "Deleted " : "") << "node(" << n->id << "): parent=" << dump(n->parent)
            << ", prev=" << dump(n->prev)  << ", assigned=" << dump(n->assigned) << "\n";  
        }
    }
private:
    Node* parent = nullptr;
    Node* prev = nullptr;
    Node* assigned = nullptr;
    int id; 
    bool deleted = false;

    static int freeId()
    {
        static int Id = 0;
        return ++Id;
    }

    static std::vector<Node*> Nodes; 
};

std::vector<Node*> Node::Nodes;

class Object
{
public:
   Object(): node(new Node) {}
   Object(const Object& i_other): node(new Node)
   {
        node->parent = i_other.node;
   }
   Object& operator=(const Object& i_rhs)
   {
        Node* newNode = new Node;
        newNode->parent = node->parent;
        newNode->prev = node;
        newNode->assigned = i_rhs.node;
        node = newNode;
        return *this;
   }
   ~Object()
   {
        node->deleted = true;
   }

private:
    Node* node;
};

int main()
{
    Object obj1;
    {
        Object obj2(obj1);
        Object obj3(obj2);
        obj1 = obj3;
    }
    
    Node::snapshot();
    return 0;
}