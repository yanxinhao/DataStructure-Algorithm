/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-05 12:02:25
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "tree/bintree.h"
#include "tree/input.h"
using namespace std;

template <typename T>
void visit(T &elem)
{
    cout << elem << " ";
}

int main(int argc, char const *argv[])
{

    /* code */
    // 利用先序和中序序列建立二叉树
    cout << "先序和中序序列分别为: " << p_order << " " << in_order << endl;

    // 建树
    cout << "1.利用先序和中序建立二叉树 :";
    bintree<char> tree(8, p_order, in_order);
    cout << "先序: ";
    tree.traverse(visit, PREORDER);
    cout << " 中序: ";
    tree.traverse(visit, INORDER);
    cout << " 后序: ";
    tree.traverse(visit, POSTORDER);
    cout << endl;
    // 遍历
    cout << "2.遍历二叉树 : ";
    cout << "先序非递归: ";
    tree.traverse(visit, PREORDERNOCURSION);
    cout << " 中序非递归: ";
    tree.traverse(visit, INORDERNOCURSION);
    cout << " 后序非递归: ";
    tree.traverse(visit, POSTORDERNOCURSION);
    cout << endl;
    return 0;
}
