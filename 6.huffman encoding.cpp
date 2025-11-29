#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char ch;
    int coun;
    Node *left, *right;//'*' mane pointer bujhai
    Node(char c, int n)
    {
        ch=c;
        coun=n;
        left=right=nullptr;
    }
};
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->coun > b->coun;
    }
};
void printCodes(Node *root, string code)
{
    if(!root)return;
    if(!root->left && !root->right)//left o thakbena and right o thakbena
    {
        cout<<root->ch<<":" << code<<"\n";
        return;
    }

    printCodes(root->left, code+"0");
    printCodes(root->right, code+"1");
}
int main(){
    string text="i love baust CSE";
    map<char, int>mp;
    for(int i=0; i<text.length();i++)
    {
        if(text[i]==' ')
        {
            continue;
        }
        mp[text[i]]++;

    }
    priority_queue<Node*, vector<Node*>, Compare>pq;
    for(auto it: mp)
    {
        pq.push(new Node(it.first, it.second));
    }
    while(pq.size()>1)
    {
        Node *left=pq.top();
        pq.pop();

        Node *right=pq.top();
        pq.pop();

        Node *merged=new Node('$',left->coun + right->coun);
        merged->left=left;
        merged->right= right;

        pq.push(merged);
    }
    Node *root=pq.top();
    cout<<"Huffman Coding is : "<<endl;
    printCodes(root,"");
}
