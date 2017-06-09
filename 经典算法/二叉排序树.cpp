#ifndef NODE
#define NODE
template <class Entry>
struct Node {
    Entry entry;
    Node<Entry> *left;
    Node<Entry> *right;
    Node(const Entry &en) {
        entry = en;
        left = NULL;
        right = NULL;
    }
};
#endif

// 二叉查找树的查找函数
// 查找target所在的位置，如果target存在二叉查找树中，则返回该结点的指针
// 否则返回NULL
template <class Entry>
Node<Entry>* BSTree_search(Node<Entry> *root, const Entry &target) {
    if (root == NULL || root->entry == target) {
        return root;
    } else if (root->entry > target) {
        return BSTree_search(root->left, target);
    } else {
        return BSTree_search(root->right, target);
    }
}

// 二叉查找树的插入函数
// 将target插入到二叉查找树中，二叉查找树的结点满足以下条件：
// 1、任意结点的左子树中的元素小于该结点的元素
// 2、任意结点的右子树中的元素大于该结点的元素
// 3、同一个元素在二叉查找树中只会出现一次
template <class Entry>
void BSTree_insert(Node<Entry> *&root, const Entry &target) {
    if (root == NULL) {
        root = new Node<Entry>(target);
    } else if (root->entry > target) {
        BSTree_insert(root->left, target);
    } else if (root->entry < target) {
        BSTree_insert(root->right, target);
    }
}

// 二叉查找树的删除函数
// 如果target存在二叉查找树中，则删除它，否则不进行任何操作
template <class Entry>
void BSTree_remove(Node<Entry> *&root, const Entry &target) {
    if (root != NULL) {
        if (root->entry == target) {
            Node<Entry> *toDelete = root;
            if (root->left == NULL) {
                root = root->right;
            } else if (root->right == NULL) {
                root = root->left;
            } else {
                Node<Entry> *parent = root;
                toDelete = toDelete->left;
                while (toDelete->right) {
                    parent = toDelete;
                    toDelete = toDelete->right;
                }
                root->entry = toDelete->entry;
                if (parent == root) {
                    parent->left = toDelete->left;
                } else {
                    parent->right = toDelete->left;
                }
            }
            delete toDelete;
        } else if (root->entry > target) {
            BSTree_remove(root->left, target);
        } else {
            BSTree_remove(root->right, target);
        }
    }
}                                 
