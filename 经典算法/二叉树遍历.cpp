#include <stack>
#include <queue>

template <class Entry>
struct Node {
	Entry entry;
	Node<Entry> *left;
	Node<Entry> *right;
};

// 先序遍历非递归形式
template <class Entry>
void preorder(Node<Entry> *root, void (*visit)(Entry &)) {
    stack<Node<Entry> *> S;
    S.push(root);

	while (!S.empty()) {
		Node<Entry> *node = S.top();
		S.pop();
		(*visit)(node->entry);
		if (node->right) {
			S.push(node->right);
		}
		if (node->left) {
			S.push(node->left);
		}
	}
}

// 中序遍历的非递归形式
template <class Entry>
void inorder(Node<Entry> *root, void (*visit)(Entry &)) {
    stack<Node<Entry> *> S;
    Node<Entry> *r = root;

    while (r || !S.empty()) {
        if (r) {
            S.push(r);
            r = r->left;
        } else {
            r = S.top();
            S.pop();
            (*visit)(r->entry);
            r = r->right;            
        }
    }
}

// 后序遍历的非递归形式
template <class Entry>
void postorder(Node<Entry> *root, void (*visit)(Entry &)) {
    stack<Node<Entry> *> S;
    S.push(root);
    Node<Entry> *pre = NULL;

    while (!S.empty()) {
        Node<Entry> *current = S.top();

        if ((!current->left && !current->right) || (pre != NULL && (pre == current->left || pre == current->right))) {
            (*visit)(current->entry);
            S.pop();
            pre = current;
        } else {
            if (current->right) {
                S.push(current->right);
            }
            if (current->left) {
                S.push(current->left);
            }
        }
    } 
}


// 先序遍历递归形式 
template <class Entry>
void preorder(Node<Entry> *root, void (*visit)(Entry &)) {
	if (root != NULL) {
		(*visit)(root->entry);
		preorder(root->left, visit);
		preorder(root->right, visit);
	}
}

// 中序遍历的递归形式 
template <class Entry>
void inorder(Node<Entry> *root, void (*visit)(Entry &)) {
    if (root != NULL) {
        inorder(root->left, visit);
        (*visit)(root->entry);
        inorder(root->right, visit);
    }
}

// 后序遍历的递归形式 
template <class Entry>
void postorder(Node<Entry> *root, void (*visit)(Entry &)) {
    if (root != NULL) {
        postorder(root->left, visit);
        postorder(root->right, visit);
        (*visit)(root->entry);
    }
}

// 层次遍历
template <class Entry>
void levelTraversal(Node<Entry> *root) {
	queue<Node<Entry> *> Q;
	Q.push(root);
	Q.push(NULL);

	while (!Q.empty()) {
		Node<Entry> *node = Q.front();
		Q.pop();
		if (node) {
			cout << node->entry << ' ';
			if (node->left) {
				Q.push(node->left);
			}
			if (node->right) {
				Q.push(node->right);
			}
		} else if (!Q.empty()) {
			Q.push(NULL);
			cout << endl;
		}
	}
}