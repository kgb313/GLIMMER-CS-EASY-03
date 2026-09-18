#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100
/*
 * 顺序存储二叉树结点
 * - data：结点数据
 * - used：当前位置是否有结点
 */
typedef struct {
    int data;
    bool used;
} SeqTreeNode;

/*
 * 顺序存储二叉树
 * - nodes：结点数组
 * - size：数组最大容量
 */
typedef struct {
    SeqTreeNode nodes[MAX_TREE_SIZE];
    int size;
} SeqBiTree;


//初始化二叉树
void init_tree(SeqBiTree *tree){
    tree->size=MAX_TREE_SIZE;
    for(int i=0;i<100;i++){
        tree->nodes[i].data=0;
        tree->nodes[i].used=false;
    }
}


//创建根节点
bool set_root(SeqBiTree *tree, int value){
    if(tree->size<2){return false;}
    tree->nodes[1].data=value;
    tree->nodes[1].used=true;
    return true;
}


//创建左孩子
bool set_left_child(SeqBiTree *tree, int parent_node, int value){
    if(tree->size-1<parent_node){return false;}
    tree->nodes[parent_node].data=value;
    tree->nodes[parent_node].used=true;
    return true;
}


//创建右孩子
bool set_right_child(SeqBiTree *tree, int parent_node, int value){
    if(tree->size-1<parent_node){return false;}
    tree->nodes[parent_node].data=value;
    tree->nodes[parent_node].used=true;
    return true;
}


//层序遍历
void level_order(SeqBiTree *tree){
    if(tree->nodes[1].used==false){return;}
    int p;
    for(int i=1;i<100;i++){
        if(tree->nodes[i].used==true){p=i;}}
    int maxnumber=1;
    for(int i=1;i<=p;i*=2){maxnumber*=2;}
    int q=2;
    for(int i=1;i<maxnumber;i++){
        if(tree->nodes[i].used==false){printf("-1 ");}
        if(tree->nodes[i].used==true){printf("%d ",tree->nodes[i].data);}
        if(i==q-1){
            printf("\n");
            q*=2;
        }
    }
}


int main(){
    SeqBiTree tree;
    init_tree(&tree);
    set_root(&tree,1);
    set_left_child(&tree,2,2);
    set_right_child(&tree,3,3);
    set_left_child(&tree,4,4);
    set_left_child(&tree,6,6);
    set_right_child(&tree,7,7);
    level_order(&tree);
    getchar();
    return 0;
    }