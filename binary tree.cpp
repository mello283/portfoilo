#include <iostream>
#include <fstream>
using namespace std;
int itemCount=0;
int value=0;
int deepest=0;
int counter=0;
fstream output;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
node*root;
struct node *newNode()
{
    struct node* node = new struct node;
    node->data=0;
    node->left=NULL;
    node->right=NULL;
    return node;

};
void insert(node*c,int val);
void printPreorder(node*root,int &i);
void printInorder(node*root,int &i);
void printPostorder(node*root,int &i);
int countUp(node*root);
int sumEmUp(node*root);
int getLeafCount(node*node);
int getDeepestNode(node*root,int level);
int startGetDeepestNode(node*root);
void printOneChild(node*root);
void printSubTree(node*root);
void printSubTree2(node*root,int maxLv,int level);
void Delete(int key);
void delete12(node*c,int val);
int digitSum(int a);

void insert(node*c,int val)
{
  if(root!=NULL)
  {
    node*p,*tmp;
    while(c)
    {
        if(val<c->data)
        {
            p=c;
            c=c->left;
        }
        else if(val>c->data)
        {
            p=c;
            c=c->right;
        }
    }
    tmp=newNode();
    tmp->data=val;
    if(val<p->data)
    {
        p->left=tmp;
    }
    else
    {
        p->right=tmp;
    }
  }

  else
  {
    root=new node;
    root->data=val;
    root->left=NULL;
    root->right=NULL;
  }

}
void printPreorder(node*root,int &i)
{
    if(root==NULL)
    {
        return;
    }
    i++;
    if(i<21)
    {
        cout<<root->data<<" ";
        output<<root->data<<" ";
        printPreorder(root->left,i);
        printPreorder(root->right,i);
    }
}
void printInorder(node*root,int &i)
{
    if(root==NULL)
    {
        return;//leaf reached
    }
    i++;
    if(i<20)
        printInorder(root->left,i);
    cout<<root->data<<" ";
    output<<root->data<<" ";
    if(i<20)
        printInorder(root->right,i);
}
void printPostorder(node*root,int &i)
{
    if(root==NULL)
    {
        return;
    }
    i++;
    if(i<21)
    {
        printPostorder(root->right,i);
        printPostorder(root->left,i);
        cout<<root->data<<" ";
        output<<root->data<<" ";
    }
}
int countUp(node*root)
{
    counter=0;
    if(root==NULL){
    return counter;
  }
  counter++;
  countUp(root->left);
  countUp(root->right);
  return counter;
}
int sumEmUp(node*root)
{
  int sum=0;
  if(root==NULL){
    return sum;
  }
  sum+=root->data;
  itemCount++;
  sumEmUp(root->left);
  sumEmUp(root->right);
  if(counter==itemCount)
  {
     return sum;
  }
}
int getLeafCount(node*node)
{
   if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    else
        return getLeafCount(node->left)+getLeafCount(node->right);

}
int getDeepestNode(node*root,int level)
{
    if(root!=NULL)
    {
        getDeepestNode(root->left,level+1);
        if(level>deepest)
        {
            value=root->data;
            deepest=level;
        }
        getDeepestNode(root->right,level+1);
    }
}
int startGetDeepestNode(node*root)
{
    int level=0;
    getDeepestNode(root,level);
    return value;
}
void printOneChild(node*root)
{
    if(root==NULL){
    return;
  }
    node*temp;
    if((root->left!=NULL)&&(root->right==NULL))
        cout<<root->data<<" ";
        output<<root->data<<" ";
    if((root->right!=NULL)&&(root->left==NULL))
        cout<<root->data<<" ";
        output<<root->data<<" ";
    printOneChild(root->left);
    printOneChild(root->right);

}
void printSubTree(node*root)
{
    static bool startPrint=false;
    if(root==NULL)
        return;
    if(!startPrint&&root->data==195)
        startPrint=true;
    printSubTree(root->left);
    if(startPrint)
        cout<<root->data<<" ";
        output<<root->data<<" ";
    printSubTree(root->right);

}
void printSubTree2(node*root,int maxLv,int level)
{
    if(root==NULL)
        return;
    if(maxLv<level)
    {
        cout<<root->data<<" ";
        output<<root->data<<" ";
        maxLv=level;
    }
    printSubTree2(root->right,maxLv,level+1);
    printSubTree2(root->left,maxLv,level+1);
}
void Delete(int key)
{
    //tree empty condition
    node *temp,*parent;
    temp = root,parent = root;
    if (temp == NULL){
        cout << "The tree is empty" << endl;
        output << "The tree is empty" << endl;}
    else {
        while (temp != NULL && temp->data != key) {
            parent = temp;
            if (temp->data < key) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }
    }

    //no next node condition
    if (temp == NULL){
//        cout << " No node present ";
    }
    //more than one value in tree
    else {
        if (temp->right == NULL && temp->left == NULL) {
            if (parent->right == temp)
                parent->right = NULL;
            else
                parent->left = NULL;
        }
        else if (temp->left == NULL) {
            if (parent->right == temp)
                parent->right = temp->right;
            else
                parent->left = temp->right;
        }
        else if (temp->right == NULL) {
            if (parent->right == temp)
                parent->right = temp->left;
            else
                parent->left = temp->left;
        }
        else {
            node* temp1;
            parent = temp;
            temp1 = temp;
            temp = temp1->right;
            while (temp->left != NULL) {
                parent = temp;
                temp = temp->left;
            }
         temp1->data = temp->data;

        if (temp->right == NULL && temp->left == NULL) {
            if (parent->right == temp)
                parent->right = NULL;
            else
                parent->left = NULL;
        }
        else if (temp->left == NULL) {
            if (parent->right == temp)
                parent->right = temp->right;
            else
                parent->left = temp->right;
        }
        else if (temp->right == NULL) {
            if (parent->right == temp)
                parent->right = temp->left;
            else
                parent->left = temp->left;
        }
            delete temp;

        }
    }

}

void delete12(node*c)//delete all where sum of the digits are 12
{
    if(c==NULL)
    {
        return;
    }
    delete12(c->left);
    delete12(c->right);
    if(digitSum(c->data)<13)
    {
        cout<<c->data<<" ";
        Delete(c->data);
        counter--;
    }
    return;
}
int digitSum(int a)
{
    if(a==0)
    {
        return 0;
    }
    return digitSum(a/10)+a%10;
}

int main()
{
    fstream input;
    int i=0;
    output.open("treeoutput.txt");
    input.open("TreeRandNbrs.dat");
    if(!input.is_open())
    {
        cout<<"\nInput file missing\n";
    }
    while(input>>i)
    {
        insert(root,i);
        counter++;
    }

    cout<<"All values within the tree:\n";
    output<<"All values within the tree:\n";

    cout<<"InOrder of the tree:\n";
    output<<"InOrder of the tree:\n";
    i=0;
    printInorder(root,i);
    cout<<"\n\n";
    output<<"\n\n";

    cout<<"PreOrder of the tree:\n";
    output<<"PreOrder of the tree:\n";
    i=0;
    printPreorder(root,i);
    cout<<"\n\n";
    output<<"\n\n";
    i=0;
    cout<<"PostOrder of the tree:\n";
    output<<"PostOrder of the tree:\n";
    printPostorder(root,i);
    cout<<"\n\n";
    output<<"\n\n";
    int sum=sumEmUp(root);
    cout<<"Count of numbers in list: "<<itemCount<<endl;
    output<<"Count of numbers in list: "<<itemCount<<endl;
    cout<<"Sum of numbers in list: "<<sum<<endl;
    output<<"Sum of numbers in list: "<<sum<<endl;
    cout<<"Average of numbers in list: "<<sum/counter<<endl;
    output<<"Average of numbers in list: "<<sum/counter<<endl;

    cout<<"Leaf node count:\n";
    output<<"Leaf node count:\n";
    cout<<getLeafCount(root)<<endl;
    output<<getLeafCount(root)<<endl;

    cout<<"Deepest Node:\n";
    output<<"Deepest Node:\n";
    cout<<startGetDeepestNode(root);
    output<<startGetDeepestNode(root);
    cout<<"\n\n";
    output<<"\n\n";

    cout<<"Each node with one child:\n";
    output<<"Each node with one child:\n";
    printOneChild(root);
    cout<<"\n\n";
    output<<"\n\n";
    cout<<"Print the subtree starting at 195\n";
    output<<"Print the subtree starting at 195\n";
    printSubTree(root);
    cout<<"\n\n";
    output<<"\n\n";

    cout<<"Print the left of root\n";
    output<<"Print the left of root\n";
    printSubTree2(root->left,1,0);
    cout<<"\n\nPrint the right of root\n";
    output<<"\n\nPrint the right of root\n";
    printSubTree2(root->right,1,0);

    cout<<"\n\nAll numbers who's digits total 12 or less\n";
    output<<"\n\nAll numbers who's digits total 12 or less\n";
    delete12(root);
//    deleteNegatives(root);
    cout<<"\n\nNew list after deletes\n";
    output<<"\n\nNew list after deletes\n";
    i=0;
    printInorder(root,i);
    cout<<"\n\nNumber of nodes\n";
    output<<"\n\nNumber of nodes\n";

    cout<<counter<<endl;
    output<<counter<<endl;
    cout<<"\n\nSum of all nodes\n";
    output<<"\n\nSum of all nodes\n";
    cout<<sumEmUp(root);
    output<<sumEmUp(root);
    if(!output.is_open())
    {
        cout<<"\nOutput file missing\n";
    }
    input.close();
    output.close();
    return 0;
}
