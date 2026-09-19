#include <stdio.h>
#include <stdlib.h>

//定义节点
typedef struct TreeNode {
    int data;                       // 节点存储的数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right;         // 右子树指针
} TreeNode;

//创建节点
TreeNode* create_node(int value){
    TreeNode* NewNode=malloc(sizeof(TreeNode));
    NewNode->data=value;
    NewNode->left=NULL;
    NewNode->right=NULL;
    return NewNode;
}

//连接节点
void connect (TreeNode* parent,TreeNode* LChild,TreeNode* RChild){
    if(parent==NULL){return;}
    parent->left=LChild;
    parent->right=RChild;
}

//前序遍历
void preorder(TreeNode* tree){
    if(tree==NULL){return;}
    printf("%d ",tree->data);
    preorder(tree->left);
    preorder(tree->right);
}

//中序遍历
void midorder(TreeNode* tree){
    if(tree==NULL){return;}
    midorder(tree->left);
    printf("%d ",tree->data);
    midorder(tree->right);
}

//后序遍历
void postorder(TreeNode* tree){
    if(tree==NULL){return;}
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ",tree->data);
}

//计算树的深度
int depth(TreeNode *root,int current_depth,int max_depth){
    if(root==NULL){return max_depth;}
    current_depth++;
    max_depth=current_depth;
    int Ldepth=depth(root->left,current_depth,max_depth);
    int Rdepth=depth(root->right,current_depth,max_depth);
    if(Ldepth>Rdepth){max_depth=Ldepth;}
    else{max_depth=Rdepth;}
    return max_depth;
}

//定义一个栈
typedef struct Stack {
    TreeNode **arr;//主要内容，可理解为存放指向节点的指针的数组
    int top;//栈顶到了哪里
    int capacity;//栈容量
} Stack;

//创建栈
Stack *createStack(int capacity) {
    Stack *stack = malloc(sizeof(Stack));
    stack->arr = malloc(sizeof(TreeNode *) * capacity);//问ai得知C语言通常不用强转
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

//判断栈是否为空
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

//入栈
void push(Stack *stack, TreeNode *node) {
    if (stack->top == stack->capacity - 1) {
        return;//栈满了
    }
    stack->arr[++stack->top] = node;//在arr中第top个元素里存入node
}

//出栈
TreeNode *pop(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;//出到底了
    }
    return stack->arr[stack->top--];//取出顶上的节点，回退一格
}

//前序遍历
void preorderTraversal(TreeNode *root){
    TreeNode* p=root;
    Stack* stack=createStack(100);
    while(stack->top!=-1||p!=NULL){
        while(p!=NULL){ 
        push(stack,p);
        printf("%d ",p->data);
        p=p->left;
        }
        if(stack->top!=-1){p=pop(stack)->right;}
    }
} 

int main(){
    //创建节点
    TreeNode* Node1=create_node(1);
    TreeNode* Node2=create_node(2);
    TreeNode* Node3=create_node(3);
    TreeNode* Node4=create_node(4);
    TreeNode* Node5=create_node(5);
    TreeNode* Node6=create_node(6);
    TreeNode* Node7=create_node(7);

    //连接节点
    connect(Node1,Node2,Node3);
    connect(Node2,Node4,Node5);
    connect(Node3,Node6,Node7);
    preorderTraversal(Node1);
    getchar();
    return 0;

}