#include<iostream>
#include<string>

using namespace std;
class Node {//이진트리
private:
	int data;
	Node *left;	//왼쪽 자식
	Node *right;	//오른쪽 자식
public:
	Node(int data, Node*left, Node*right) {//생성장
		this->data = data;
		this->left = left;
		this->right = right;
	}
	void addItem(Node* node, int data) {//데이터 추가
		if (node->data==NULL) {//현재 노드에 데이터가 없다면 저장
			node->data = data;
		}
		else {//현재 노드에 데이터가 있다면 크기를 비교해서 왼쪽,오른쪽 자식에 저장한다.
			if (node->data > data) {//저장되어 있는 데이터보다 작다면 왼쪽자식에 저장
				if (node->left == NULL) {//왼쪽 자식 노드에 데이터가 존재하지 않다면 생성자로 값을 저장
					node->left = new Node(data, NULL, NULL);
				}
				else {//존재 한다면 그냥 넘겨준다
					addItem(node->left, data);
				}
			}
			else {//저장되어 있는 데이터보다 크다면 오른쪽 자식에 저장
				if (node->right == NULL) {
					node->right = new Node(data, NULL, NULL);
				}
				else {
					addItem(node->right, data);
				}
			}
		}
	}
	void printSubTree(Node* node) {//트리 출력 후위 순회 이므로 왼쪽,오른쪽,루트 순으로 출력하겠금 구현
		if (node != nullptr) {
			printSubTree(node->left);
			printSubTree(node->right);
			cout << node->data << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node *tree=new Node(NULL,NULL,NULL);
	string num;
	while(getline(cin,num)){
		int n = atoi(num.c_str());
		tree->addItem(tree,n);
	}
	tree->printSubTree(tree);

	return 0;
}