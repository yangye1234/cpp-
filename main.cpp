#include <iostream>
//typedef int TypeVector;

template<class TypeVector>
class Vector {//�Զ����ӳ���������
private:
	int size;
	TypeVector* items;
public:
	Vector(const int size = 2)
		:size(size) {//��ʼ���б�lenĬ�ϳ���2���������ڴ��
		items = new TypeVector[size];
	}
	~Vector() {//�ͷ��ڴ�
		if (items != nullptr) {//��ֹΪ��
			delete[] items;
			items = nullptr;
		}
	}
	Vector& operator=(const Vector& vector) {//���� = ʵ�����
		delete[] items;//�ͷ�this��items�ڴ��
		size = vector.size;//��Ҫ���ƵĴ�С��������
		items = new TypeVector[size];//���´����ڴ��
		for (int i = 0; i < size; i++) {
			items[i] = vector.items[i];//��Ԫ�ظ��ƹ���
		}
		return *this;
	}
	void new_len(const int size) {//�Զ��������鳤��
		if (size <= this->size) {//���С�ڵ�ǰ����������
			return;
		}
		TypeVector* tem = new TypeVector[size];//�ô�������ֵ������ʱ������
		for (int i = 0; i < size; i++) {
			if (i < this->size) {//С�ڵ�ǰ�ĳ�����ֵ���Ƹ���ʱ����
				tem[i] = items[i];
			}
		}
		delete[] items;//�ͷŵ�ǰ�������ַ
		items = tem;//��tem����ʱ�����ַ����items
		this->size = size;//��������ֵ����this��size
	}
	TypeVector& operator[](int index) {//���޸�����Ԫ��
		if (index < size) {
			return items[index];
		}
		else {
			new_len(index + 1);
			return items[index];
		}
	}
	const TypeVector& operator[](const int index) const {//�����޸ĵ�����Ԫ��
		if (index < size) {
			return items[index];
		}
		else {
			return items[0];//û�и�Ԫ��
		}
	}
	int Extent_size() {
		return size;
	}
};

template<class TypeStack>
class Stack {
private:
	TypeStack* items = nullptr;//Ԫ��
	int top;//ջ��
	int size;//����
public:
	Stack(const int size = 5)//Ĭ�ϳ���5
		:size(size), top(0)//��ʼ���б�stacksize   top
	{
		items = new TypeStack[size];//�����ڴ��
	}
	~Stack() {//�ͷ��ڴ�
		if (items != nullptr) {
			delete[] items;
			items = nullptr;
		}
	}
	Stack& operator=(const Stack& stack) {//���� = ʵ�����
		delete[] items;//�ͷ�this��items�ڴ��
		size = stack.size;//��ȡ����ջ�Ĵ�С
		top = stack.top;//��ȡ����ջ�Ķ�ָ��
		items = new TypeStack[size];//���������Ĵ�С���ڴ��
		for (int i = 0; i < size; i++) {
			items[i] = stack.items[i];//��������Ԫ��
		}
		return *this;
	}
	bool Empty() const{//ջ�Ƿ�Ϊ��
		return top == 0;
	}
	bool Full() const {//�ж�ջ�Ƿ�����
		return top == size;
	}
	bool Enter(const TypeStack& item) {//��ջ
		if (top < size) {//�ж�ջ�Ƿ��Ѿ�����
			items[top++] = item;//��Ҫ��ջ��Ԫ�ش���ջ����top++
			return true;
		}
		return false;
	}
	bool Out(TypeStack& item) {//��ջ
		if (0 < top) {//�ж�ջ�Ƿ�Ϊ��
			item = items[--top];//��Ҫ��ջ��Ԫ�س�ջ����top--
			return true;
		}
		return false;
	}
	int Extent_size() const {//��ȡ����
		return size;
	}
	int Extent() const {
		return top;
	}
};


int main() {
	//Stack<int> a;//ջ�Ļ����÷�
	//for (int i = 0, size = a.Extent_size(); i < size; i++) {
	//	a.Enter(i);
	//}
	//for (int i = 0, size = a.Extent_size(); 0 < size; size--) {
	//	a.Out(i);
	//	std::cout << i << std::endl;
	//}
	//Stack<int>* b = new Stack<int>;//���
	//*b = a;
	//delete b ;
	
	//Vector<int> c;//�Զ�����Ļ����÷�
	//for (int i = 0; i < 5; i++) {
	//	c[i] = i;
	//}
	//for (int i = 0; i < c.Extent_size();i++) {
	//	std::cout << c[i] << std::endl;
	//}

	//Vector<Stack<std::string>> vs;//�Զ�����ջ VectorĬ�ϳ���2   StackĬ�ϳ���3
	//vs[0].Enter("yang");//�Զ������е�ջ
	//vs[0].Enter("ye");

	//vs[1].Enter("q");//�Զ������е�ջ
	//vs[1].Enter("j");
	//vs[1].Enter("j");

	//vs[2].Enter("t");//ͨ���Զ�����������ջ
	//vs[2].Enter("h");
	//vs[2].Enter("y");

	//for (int i = 0; i < vs.Extent_size(); i++) {
	//	while (vs[i].Extent()) {
	//		std::string tem;
	//		vs[i].Out(tem);
	//		std::cout << tem;
	//	}
	//	std::cout << std::endl;
	//}

	//Stack<Vector<std::string>> sv;//ջ�Զ����� StackĬ��3 VectorĬ�ϳ���2
	//Vector<std::string> tem;
	//tem[0] = "yang";//�Զ�����Ԫ��
	//tem[1] = "ye";
	//sv.Enter(tem);//��ջ
	//tem[0] = "qu";
	//tem[1] = "jun";
	//tem[2] = "jie";//�Զ�����������Ԫ��
	//sv.Enter(tem);//��ջ
	//tem[0] = "tan";
	//tem[1] = "hao";
	//tem[2] = "yuan";//�Զ�����������Ԫ��
	//sv.Enter(tem);//��ջ
	//while (sv.Empty() == false) {
	//	sv.Out(tem);
	//	for (int i = 0; i < tem.Extent_size(); i++) {
	//		std::cout << tem[i];
	//	}
	//	std::cout << std::endl;
	//}

	Vector<Vector<std::string>> vv;//�Զ�������ά���� Vector����Ĭ�ϳ���2
	vv[0][0] = "yang";
	vv[0][1] = "ye";
	vv[1][0] = "qu";
	vv[1][1] = "jun";
	vv[1][2] = "jie";
	vv[2][0] = "tan";
	vv[2][1] = "hao";
	vv[2][2] = "yuan";
	for (int i = 0; i < vv.Extent_size(); i++) {
		for (int j = 0; j < vv[i].Extent_size(); j++) {
			std::cout << vv[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}