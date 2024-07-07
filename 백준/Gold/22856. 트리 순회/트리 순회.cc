#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct node
{
    node *left=NULL, *right=NULL, *parent=NULL;
};
node *ptr = new node[100005];
node* root = ptr + 1;
bool visited[100005];

int answer = -1;
int ed = -1;
void travel(node* nodeptr){
    visited[nodeptr - ptr] = true;
    answer++;
    if(nodeptr->left != NULL && !visited[nodeptr->left - ptr]) travel(nodeptr->left);
    else if(nodeptr->right != NULL && !visited[nodeptr->right - ptr]) travel(nodeptr->right);
    else if(nodeptr - ptr == ed) return;
    else if(nodeptr->parent != NULL) travel(nodeptr->parent);    
}
void inorder(node* nodeptr){
    if(nodeptr == NULL) return;
    inorder(nodeptr->left);
    ed = nodeptr - ptr;
    inorder(nodeptr->right);
}


int main(){
    fastio;
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int p, c;
        cin >> p;
        for (int j = 0; j < 2; j++)
        {
            cin >> c;
            if(c == -1) continue;
            if(j ==0){
                (ptr+p)->left = (ptr+c);                
            }
            else{
                (ptr+p)->right = (ptr+c);
            }
            (ptr+c)->parent = (ptr+p);
        }        
    }
    inorder(root);
    travel(root);
    cout << answer;

    return 0;
}