#include"workerManager.h"
WorkerManager::WorkerManager() {
	//初始化属性
	this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
}
void WorkerManager::show_Menu() {
    cout << "*************************************" << endl;
    cout << "******* 欢迎使用职工管理系统  *******" << endl;
    cout << "*********  0. 退出管理程序  *********" << endl;
    cout << "*********  1. 增加职工信息  *********" << endl;
    cout << "*********  2. 显示职工信息  *********" << endl;
    cout << "*********  3. 删除离职职工  *********" << endl;
    cout << "*********  4. 修改职工信息  *********" << endl;
    cout << "*********  5. 查找职工信息  *********" << endl;
    cout << "*********  6. 按照编号排序  *********" << endl;
    cout << "*********  7. 清空所有文档  *********" << endl;
    cout << "*************************************" << endl;
    cout << endl;

}
void WorkerManager::ExistSystem() {
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);//退出系统

}
void WorkerManager::Add_Emp() {
	cout << "请输入添加职工人数：" << endl;
	int addNum = 0;//记录添加职工人数
	cin >> addNum;
    if (addNum > 0) {
        //添加
        //计算添加新空间大小
        int newSize = this->m_EmpNum + addNum;
        //开辟新空间
		Worker ** newSpace=new Worker* [newSize];
		//将原有数据存放到新空间下
        if (this->m_EmpArray != NULL) {
            for (int i = 0;i < this->m_EmpNum;i++) {
				newSpace[i] = this->m_EmpArray[i];
            }
        }
        //批量添加新数据
        for(int i=0;i<addNum;i++) {
            // 这里可以调用具体的职工类的构造函数来创建职工对象
            int id;
            string name;
            int dSelect;
			cout << "请输入第" << i + 1 << "个新职工的编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名：" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
            cout << "3.总裁" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
            switch (dSelect) {
            case 1:
                worker = new Employee(id, name,1);
                break;
            case 2:
                worker = new Manager(id, name,2);
                break;
            case 3:
                worker = new Boss(id, name,3);
                break;
            default:
                cout << "输入有误，请重新输入！" << endl;
                break;
            }
            //创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
        }
        //释放原有空间
        delete[] this->m_EmpArray;
        //更新新空间指针
        this->m_EmpArray = newSpace;
        //更新职工数量
        this->m_EmpNum = newSize;

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;
    }
    else {
		cout << "输入有误，请重新输入！" << endl;
    }
	system("pause");//按任意键继续
	system("cls");//清屏
}
WorkerManager::~WorkerManager() {

}