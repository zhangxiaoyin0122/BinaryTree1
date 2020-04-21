#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef char BTDataType;
typedef struct BinaryTreeNode {
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	char _data;
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"���������� 
BTNode* creatTree(char* str, int* idx) {
	if (str[*idx] == '#') {
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = str[*idx];
		++(*idx);
		root->_left=creatTree(str, idx);
		++(*idx);
		root->_right=creatTree(str, idx);
	}
	else {
		return NULL;
	}
}

// ���������� 
void BinaryTreeDestory(BTNode** root) {
	BTNode* cur = *root;
	while (cur) {
		BinaryTreeDestory(&cur->_left);
		BinaryTreeDestory(&cur->_right);
		free(cur);
		*root = NULL;
	}
}
														 
// �������ڵ���� 
int BinaryTreeSize(BTNode* root) {
	//�ݹ�ʵ��
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

//�ۼӼ�����
void BinaryTreeSize2(BTNode* root,int* count) {
	if (root) {
		(*count)++;
		BinaryTreeSize(root->_left);
		BinaryTreeSize(root->_right);
	}
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// ��������k��ڵ���� 
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ� 
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	BTNode* ret;
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	return BinaryTreeFind(root->_right, x);
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root) {
	if (root) {
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

// ������������� 
void BinaryTreeInOrder(BTNode* root) {
	if (root) {
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_left);
		BinaryTreeInOrder(root->_right);
	}
}

// �������������
void BinaryTreePostOrder(BTNode* root) {
	if (root) {
		printf("%c ", root->_data);
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
	}
}

// ������� 
void BinaryTreeLevelOrder(BTNode* root) {

}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root) {

}