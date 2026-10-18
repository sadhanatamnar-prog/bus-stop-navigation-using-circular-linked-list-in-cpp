#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int price;
    Node *left, *right;
};

Node* insert(Node* root, int p) 
{
    if (root == NULL) 
	{
        root = new Node{p, NULL, NULL};
        return root;
    }
    if (p < root->price)
        root->left = insert(root->left, p);
    else
        root->right = insert(root->right, p);
    return root;
}

void inorder(Node* root, int a[], int &n) 
{
    if (root == NULL) return;
    inorder(root->left, a, n);
    a[n++] = root->price;
    inorder(root->right, a, n);
}

int main() 
{
    Node* root = NULL;
    int n, a[100], p, voucher, k = 0;

    cout << "Enter number of products: ";
    cin >> n;

    cout << "Enter product prices: ";
    for (int i = 0; i < n; i++) 
	{
        cin >> p;
        root = insert(root, p);
    }

    cout << "Enter voucher value: ";
    cin >> voucher;

    inorder(root, a, k);

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) 
		{
            if (a[i] + a[j] == voucher) 
			{
                cout << "Pair found: " << a[i]
                     << " + " << a[j] << " = " << voucher;
                return 0;
            }
        }
    }

    cout << "No pair found!";
    return 0;
}
