#include <iostream>
//typedef int TypeVector;

template<class TypeVector>
class Vector {//自动增加长度数组类
private:
	int size;
	TypeVector* items;
public:
	Vector(const int size = 2)
		:size(size) {//初始化列表len默认长度2，并创建内存块
		items = new TypeVector[size];
	}
	~Vector() {//释放内存
		if (items != nullptr) {//防止为空
			delete[] items;
			items = nullptr;
		}
	}
	Vector& operator=(const Vector& vector) {//重载 = 实现深拷贝
		delete[] items;//释放this中items内存块
		size = vector.size;//把要复制的大小拷贝过来
		items = new TypeVector[size];//重新创建内存块
		for (int i = 0; i < size; i++) {
			items[i] = vector.items[i];//将元素复制过来
		}
		return *this;
	}
	void new_len(const int size) {//自动创建数组长度
		if (size <= this->size) {//如果小于当前长度则不增加
			return;
		}
		TypeVector* tem = new TypeVector[size];//用传经来的值创建临时的数组
		for (int i = 0; i < size; i++) {
			if (i < this->size) {//小于当前的长度则将值复制给临时数组
				tem[i] = items[i];
			}
		}
		delete[] items;//释放当前的数组地址
		items = tem;//将tem的临时数组地址传给items
		this->size = size;//将传来的值赋给this的size
	}
	TypeVector& operator[](int index) {//可修改数组元素
		if (index < size) {
			return items[index];
		}
		else {
			new_len(index + 1);
			return items[index];
		}
	}
	const TypeVector& operator[](const int index) const {//不可修改的数组元素
		if (index < size) {
			return items[index];
		}
		else {
			return items[0];//没有该元素
		}
	}
	int Extent_size() {
		return size;
	}
};

template<class TypeStack>
class Stack {
private:
	TypeStack* items = nullptr;//元素
	int top;//栈顶
	int size;//长度
public:
	Stack(const int size = 5)//默认长度5
		:size(size), top(0)//初始化列表stacksize   top
	{
		items = new TypeStack[size];//创建内存块
	}
	~Stack() {//释放内存
		if (items != nullptr) {
			delete[] items;
			items = nullptr;
		}
	}
	Stack& operator=(const Stack& stack) {//重载 = 实现深拷贝
		delete[] items;//释放this中items内存块
		size = stack.size;//获取拷贝栈的大小
		top = stack.top;//获取拷贝栈的顶指针
		items = new TypeStack[size];//创建拷贝的大小的内存块
		for (int i = 0; i < size; i++) {
			items[i] = stack.items[i];//拷贝各各元素
		}
		return *this;
	}
	bool Empty() const{//栈是否为空
		return top == 0;
	}
	bool Full() const {//判断栈是否已满
		return top == size;
	}
	bool Enter(const TypeStack& item) {//入栈
		if (top < size) {//判断栈是否已经满了
			items[top++] = item;//将要入栈的元素存入栈，并top++
			return true;
		}
		return false;
	}
	bool Out(TypeStack& item) {//出栈
		if (0 < top) {//判断栈是否为空
			item = items[--top];//将要出栈的元素出栈，并top--
			return true;
		}
		return false;
	}
	int Extent_size() const {//获取长度
		return size;
	}
	int Extent() const {
		return top;
	}
};


int main() {
	//Stack<int> a;//栈的基本用法
	//for (int i = 0, size = a.Extent_size(); i < size; i++) {
	//	a.Enter(i);
	//}
	//for (int i = 0, size = a.Extent_size(); 0 < size; size--) {
	//	a.Out(i);
	//	std::cout << i << std::endl;
	//}
	//Stack<int>* b = new Stack<int>;//深拷贝
	//*b = a;
	//delete b ;
	
	//Vector<int> c;//自动数组的基本用法
	//for (int i = 0; i < 5; i++) {
	//	c[i] = i;
	//}
	//for (int i = 0; i < c.Extent_size();i++) {
	//	std::cout << c[i] << std::endl;
	//}

	//Vector<Stack<std::string>> vs;//自动数组栈 Vector默认长度2   Stack默认长度3
	//vs[0].Enter("yang");//自动数组中的栈
	//vs[0].Enter("ye");

	//vs[1].Enter("q");//自动数组中的栈
	//vs[1].Enter("j");
	//vs[1].Enter("j");

	//vs[2].Enter("t");//通过自动数组增长的栈
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

	//Stack<Vector<std::string>> sv;//栈自动数组 Stack默认3 Vector默认长度2
	//Vector<std::string> tem;
	//tem[0] = "yang";//自动数组元素
	//tem[1] = "ye";
	//sv.Enter(tem);//入栈
	//tem[0] = "qu";
	//tem[1] = "jun";
	//tem[2] = "jie";//自动增长的数组元素
	//sv.Enter(tem);//入栈
	//tem[0] = "tan";
	//tem[1] = "hao";
	//tem[2] = "yuan";//自动增长的数组元素
	//sv.Enter(tem);//入栈
	//while (sv.Empty() == false) {
	//	sv.Out(tem);
	//	for (int i = 0; i < tem.Extent_size(); i++) {
	//		std::cout << tem[i];
	//	}
	//	std::cout << std::endl;
	//}

	Vector<Vector<std::string>> vv;//自动增长二维数组 Vector皆是默认长度2
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