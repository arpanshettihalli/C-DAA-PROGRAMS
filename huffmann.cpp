#include<bits/stdc++.h>
using namespace std;
struct node
{
    char ch;
    int freq;
    node *left,*right;
    node(char c,int f)
    {
        ch=c;
        freq=f;
        left=right=NULL;
    }
};
struct cmp
{
    bool operator()(node* a,node* b)
    {
        return a->freq>b->freq;
    }
};
void generatecodes(node *root,string str)
{
    if(!root)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->ch<<" "<<str<<endl;
        return;

    }
    generatecodes(root->left,str+"0");
    generatecodes(root->right,str+"1");
}
int main()
{
    int n;
    cout<<"enter the number of characters"<<endl;
    cin>>n;
    priority_queue<node*,vector<node*>,cmp>pq;
    for(int i=0;i<n;i++)
    {
        char c;
        int f;
        cin>>c>>f;
        node *newnode=new node(c,f);
        pq.push(newnode);
    }
    while(pq.size()>1)
    {
        node *left=pq.top();
        pq.pop();
        node* right=pq.top();
        pq.pop();
        node *newnode=new node('#',left->freq+right->freq);
        newnode->left=left;
        newnode->right=right;
        pq.push(newnode);

    }
    node* root=pq.top();
    generatecodes(root,"");
    return 0;

}