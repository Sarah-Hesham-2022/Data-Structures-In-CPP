#include <iostream>//this is a binary search tree class
#include<queue>//for breadth first traversal
using namespace std;
template<class T>
class Node
{
private:
    T info;
    Node<T>*right;
    Node<T>*left;
public:
    Node()
    {
        left=right=NULL;
    }
    Node(T n,Node*in=0,Node*pr=0)
    {
        right=in;
        info=n;
        left=pr;
    }
    Node *getRight()
    {
        return right;
    }
    Node *getLeft()
    {
        return left;
    }
    void setRight(Node*pt)
    {
        right=pt;
    }
    void setLeft(Node*pt)
    {
        left=pt;
    }
    T getInfo()
    {
        return info;
    }
    void setInfo(T n)
    {
        info=n;
    }
};
template<class T>
class BST
{
private:
    Node<T>*root;
    bool treeDeleted;
public:
    BST()
    {
        root=NULL;
        treeDeleted=false;
    }
    void insertNode(T value)
    {
        Node<T>*traverse=root;
        Node<T>*newNode;
        newNode=new Node<T>(value,NULL,NULL);
        if(root==NULL)
            root=newNode;
        else
        {
            while(traverse)
            {
                if(value>(traverse->getInfo()))
                {
                    if(traverse->getRight()==NULL)
                    {
                        traverse->setRight(newNode);
                        break;
                    }
                    else
                        traverse=traverse->getRight();
                }
                else if(value<(traverse->getInfo()))
                {
                    if(traverse->getLeft()==NULL)
                    {
                        traverse->setLeft(newNode);
                        break;
                    }
                    else
                        traverse=traverse->getLeft();
                }
                else
                {
                    cout<<"Can't insert; duplicates are not allowed."<<endl;
                    return;
                }
            }
        }
    }
    void Delete(T value)
    {
        if(root==NULL)
            return;
        if(Search(value))
        {
            Node<T>*loop=new Node<T>;
            loop=returnNode(value);//here get the node we want to delete
            if(loop->getLeft()==NULL && loop->getRight()==NULL)
            {
                Node<T>*loop2=new Node<T>;
                loop2=returnRootNode(value);//here get the root node of the node we want to delete
                delete(loop);
                loop=NULL;
                if(loop2->getRight()==loop)
                    loop2->setRight(NULL);
                else
                    loop2->setLeft(NULL);
            }
            else if(loop->getLeft()&& !loop->getRight())
            {
                Node<T>*loop2=new Node<T>;
                loop2=returnRootNode(value);//here get the root node of the node we want to delete
                if(loop2->getRight()==loop)
                    loop2->setRight(loop->getLeft());
                else
                    loop2->setLeft(loop->getRight());

                delete(loop);
                loop=NULL;
            }
            else if(loop->getRight() && !loop->getLeft())
            {
                Node<T>*loop2=new Node<T>;
                loop2=returnRootNode(value);//here get the root node of the node we want to delete
                if(loop2->getRight()==loop)
                    loop2->setRight(loop->getRight());
                else
                    loop2->setLeft(loop->getRight());

                delete(loop);
                loop=NULL;
            }
            else//this is the hardest part to delete a node with 2 children
            {
                Node<T>*predecessor=loop->getLeft();
                while(predecessor->getRight())
                    predecessor=predecessor->getRight();
                Node<T>*before=returnRootNode(predecessor->getInfo());
                loop->setInfo(predecessor->getInfo());
                delete predecessor;
                predecessor=NULL;
                if(before->getRight()==predecessor)
                    before->setRight(NULL);
                else
                    before->setLeft(NULL);


            }

        }
        else
            cout<<"Value is not found"<<endl;
    }
    bool Search(T value)
    {
        if(root==NULL)
            return false;
        else
        {
            Node<T>*traverse=root;
            while(traverse)
            {
                if(value>(traverse->getInfo()))
                {
                    traverse=traverse->getRight();
                }
                else if(value<(traverse->getInfo()))
                {
                    traverse=traverse->getLeft();
                }
                else
                    return true;

            }
            insertNode(value);//Not found so ,we will insert it in our BST and still return false
            return false;
        }
    }
    Node<T>*returnNode(T value)//to get a node by entering its value
    {
        Node<T>*traverse=root;
        while(traverse)
        {
            if(value>(traverse->getInfo()))
            {
                traverse=traverse->getRight();
            }
            else if(value<(traverse->getInfo()))
            {
                traverse=traverse->getLeft();
            }
            else
                return traverse;
        }
    }
    Node<T>*returnRootNode(T value)//to get the root node of the node we want to delete
    {
        Node<T>*loop;
        loop=returnNode(value);
        Node<T>*loop2=new Node<T>;
        loop2=root;
        while(loop2->getInfo()!=loop->getInfo())
        {
            if(loop->getInfo()>(loop2->getInfo()))
            {
                if(loop2->getRight()->getInfo()==loop->getInfo())
                {
                    loop2->setRight(loop->getLeft());
                    break;
                }
                loop2=loop2->getRight();
            }
            else if(loop->getInfo()<(loop2->getInfo()))
            {
                if(loop2->getLeft()->getInfo()==loop->getInfo())
                {
                    loop2->setLeft(loop->getLeft());
                    break;
                }
                loop2=loop2->getLeft();
            }
        }
        return loop2;
    }
    Node<T>*returnRoot()
    {
        return root;
    }
    void inOrderPrint(Node<T>*loop)
    {
        if(!treeDeleted)
        {
            if(loop==NULL)
                return;
            inOrderPrint(loop->getLeft());
            cout<<loop->getInfo()<<" ";
            inOrderPrint(loop->getRight());
        }
        else
            cout<<"Can't traverse an empty deleted tree."<<endl;


    }
    void postOrderPrint(Node<T>*loop)
    {
        if(!treeDeleted)
        {
            if(loop==NULL)
                return;
            inOrderPrint(loop->getLeft());
            inOrderPrint(loop->getRight());
            cout<<loop->getInfo()<<" ";
        }
        else
            cout<<"Can't traverse an empty deleted tree."<<endl;


    }
    void preOrderPrint(Node<T>*loop)
    {
        if(!treeDeleted)
        {
            if(loop==NULL)
                return;
            cout<<loop->getInfo()<<" ";
            inOrderPrint(loop->getLeft());
            inOrderPrint(loop->getRight());
        }
        else
            cout<<"Can't traverse an empty deleted tree."<<endl;

    }
    void breadthFirst()
    {
        if(!treeDeleted)
        {
            queue<Node<T>*>myQueue;
            Node<T>*loop=new Node<T>;
            loop=root;
            if(loop==NULL)
                return;
            myQueue.push(loop);
            while(!myQueue.empty())
            {
                loop=myQueue.front();
                cout<<loop->getInfo()<<" ";
                myQueue.pop();
                if(loop->getLeft()!=NULL)
                    myQueue.push(loop->getLeft());
                if(loop->getRight()!=NULL)
                    myQueue.push(loop->getRight());
            }
        }
        else
            cout<<"Can't traverse an empty deleted tree."<<endl;

    }
    void deleteTree(Node<T>*loop)//we use Postorder traversal to delete the tree as we should delete its children then the root
    {
        if(loop==NULL)
            return;
        deleteTree(loop->getLeft());
        deleteTree(loop->getRight());
        delete loop;
        treeDeleted=true;
    }
    bool isSubTree(BST<T>tree2)
    {
        Node<T>*loop=tree2.returnRoot();
        Node<T>*loop1=tree2.returnRoot();
        if(this->Search(loop->getInfo()))
        {
            Node<T>*loop2=this->returnNode(loop->getInfo());
            Node<T>*loop3=this->returnNode(loop->getInfo());
            while(loop->getLeft())
            {
                loop=loop->getLeft();
                loop2=loop2->getLeft();
                if(loop->getInfo()!=loop2->getInfo())
                    return false;
            }
            while(loop1->getRight())
            {
                loop1=loop1->getRight();
                loop3=loop3->getRight();
                if(loop1->getInfo()!=loop3->getInfo())
                    return false;
            }
        }
        return true;
    }
};
int main()
{
    BST<int> tree;
    tree.insertNode(8);
    tree.insertNode(1);
    tree.insertNode(12);
    tree.insertNode(1);//here try to insert duplicate but refused
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(9);
    tree.insertNode(10) ;
    tree.inOrderPrint(tree.returnRoot());
    cout<<endl;
    tree.preOrderPrint(tree.returnRoot());
    cout<<endl;
    tree.postOrderPrint(tree.returnRoot());
    cout<<endl;
    tree.breadthFirst();
    cout<<endl;//here we have created our first tree and printed it in all ways,now let's create the second tree and use our isSubTree() function.
    BST<int>tree2;
    tree2.insertNode(1);
    tree2.insertNode(2);
    tree2.insertNode(3);
    cout<<"Is tree 2 sub tree of tree 1 : "<<tree.isSubTree(tree2)<<endl;
    BST<int>tree3;
    tree3.insertNode(1);
    tree3.insertNode(2);
    tree3.insertNode(7);
    cout<<"Is tree 3 sub tree of tree 1 : "<<tree.isSubTree(tree3)<<endl;
    BST<int>tree4;
    tree4.insertNode(12);
    tree4.insertNode(9);
    cout<<"Is tree 4 sub tree of tree 1 : "<<tree.isSubTree(tree4)<<endl;
    BST<int>tree5;
    tree5.insertNode(12);
    tree5.insertNode(0);
    cout<<"Is tree 5 sub tree of tree 1 : "<<tree.isSubTree(tree5)<<endl;
    cout<<tree.Search(10)<<endl;
    cout<<tree.Search(100)<<endl;//here search for 100 not exist but our code inserts it
    tree.postOrderPrint(tree.returnRoot());
    cout<<endl;
    tree.Delete(3);//3 is a leaf
    tree.postOrderPrint(tree.returnRoot());
    cout<<endl;
    tree.Delete(1);//1 has a child 2
    tree.postOrderPrint(tree.returnRoot());
    cout<<endl;
    tree.Delete(12);//12 has  child two children 9 and 100 with a predecessor 10
    tree.postOrderPrint(tree.returnRoot());
    cout<<endl;
    tree.Delete(8);//8 is our root has two children 12 and 2 with a predecessor 2
    tree.postOrderPrint(tree.returnRoot());
    cout<<endl;
    tree.deleteTree(tree.returnRoot());
    tree.postOrderPrint(tree.returnRoot());
    cout<<endl;

    return 0;
}
