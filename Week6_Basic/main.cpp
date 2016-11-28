#include <iostream>
#include <stack>
class BinTreeNode
{
    //we have the binary tree class that holds the value
    // and 2 pointers that point towards left and right (the children)
    public:

    int value;
    BinTreeNode* left;
    BinTreeNode* right;

    BinTreeNode(int value)
    {
        this->value=value;
        this->left=NULL;
        this->right=NULL;
        //at first we set the pointers to NULL
    }
};

BinTreeNode* tree_insert(BinTreeNode* tree, int item)
{
    //we have the insert function that has the tree
    // where you insert the item and the item
    if(tree==NULL)
        //if the tree is empty, create a new tree with that value
        tree=new BinTreeNode(item);
    else
        //otherwise check where is the best position to place the value
        if(item < tree->value)
            //if the value is smaller than the tree's value, look in the left side
            if(tree->left==NULL)
                //if the left side is empty place the value there
                tree->left=new BinTreeNode(item);
            else
                //if the left side is not empty recursively
                // look in the left side for the place to put the value
                tree_insert(tree->left,item);
        else
            //if the value is higher than the tree's value, look in the right side
            if(tree->right==NULL)
                //if the right side is empty place the value there
                tree->right=new BinTreeNode(item);
            else
                //if the right side is not empty recursively
                //look in the right side for the place to put the value
                tree_insert(tree->right,item);
    return tree;
}

void postorder(BinTreeNode* tree)
{
    //in the post order function
    //print the values in the tree by looking in the left side,
    // then the right side and then print the value
    if(tree->left!=NULL)
        postorder(tree->left);
    if(tree->right!=NULL)
        postorder(tree->right);
    std::cout << tree->value << std::endl;
}
/*
void in_order(BinTreeNode* tree)
{
    //in the in order function
    //print the values in the tree by looking in the left side,
    //then print the value
    //then the right side
    if(tree->left!=NULL)
        in_order(tree->left);
    std::cout << tree->value << std::endl;
    if(tree->right!=NULL)
        in_order(tree->right);
}
*/
void in_order(BinTreeNode* tree)
{
    //in the non-recursive in_order function
    //we have the root as input
    int goLeft=1;
    //goLeft variable help us figure out
    //when to stop looking at a left side of the nodes
    std::stack<BinTreeNode*> s;
    BinTreeNode* v;
    s.push(tree);
    //place the root in the stack
    while(!s.empty())
    {
        //until the stack is empty
        if(goLeft==1)
            //we start looking at the left side of the current(tree)
            while(tree->left!=NULL)
            {
                //keep adding the nodes to the stack by going left
                s.push(tree->left);
                tree=tree->left;
            }
        //the left bit most is the smallest value in the tree so we pop and print it
        v=s.top();
        s.pop();
        std::cout <<  v->value << std::endl;
        if (tree->right!=NULL)
        {
            //now if the right side of the current is not null go right
            //and push the node to the stack
            tree=tree->right;
            s.push(tree);
            //we set the goLeft variable to 1 in case it was switch
            //we do that to be able to check the left side of the current again
            goLeft=1;
        }
        else
        {
            if(!s.empty())
            {
                //if the right side is NULL and the list is not empty
                //pop the element in the top of the stack and set the current to that node
                v=s.top();
                tree=v;
                //set the goLeft to 0 so we know that the left side of the current was visited
                goLeft=0;
            }
        }
    }
}
int main(int argc, char *argv[])
{
    BinTreeNode* t=tree_insert(0,15);
    tree_insert(t,20);
    tree_insert(t,17);
    tree_insert(t,16);
    tree_insert(t,18);
    tree_insert(t,19);
    tree_insert(t,23);
    tree_insert(t,7);
    tree_insert(t,4);
    tree_insert(t,2);
    tree_insert(t,3);
    tree_insert(t,9);
    tree_insert(t,8);
    in_order(t);

    return 0;
}
