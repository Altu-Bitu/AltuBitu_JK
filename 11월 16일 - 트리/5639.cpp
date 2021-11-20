#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

void postorder(Node *root) {
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int input;
	vector<Node> v;
	while (cin >> input)
		v.push_back({ input, NULL, NULL });
	// 트리를 직접 생성
	for (int i = 1; i < v.size(); i++)
	{
		Node* root = &v[0]; // 루트
		while (true) // 비어있는 노드를 찾을 때까지 이동
		{
			if (v[i].data < root->data)
			{
				if (root->left == NULL)
				{
					root->left = &v[i];
					break;
				}
				else
					root = root->left;
			}
			else
			{
				if (root->right == NULL)
				{
					root->right = &v[i];
					break;
				}
				else
					root = root->right;
			}
		}
	}
	postorder(&v[0]); // 후위 순회
}