//
// Created by Mac on 2024/6/27.
//
#include "manager.h"

//默认构造
Manager::Manager() {

}

//有参构造
Manager::Manager(string name, string pwd) {
    //初始化管理员信息
    this->m_Name = name;
    this->m_pwd = pwd;
    //初始化容器 获取到所有文件中 信息
    this->initVector();
    //初始化机房
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
        vCom.push_back(com);
    }
    ifs.close();
    cout << "机房的数量:" << vCom.size() << endl;
}

//菜单界面
void Manager::openMenu() {
    cout << "欢迎管理员:" << this->m_Name << "登陆!" << endl;
    cout << "\t\t------------------------\n";
    cout << "\t\t|                       |\n";
    cout << "\t\t|          1.添加账号    |\n";
    cout << "\t\t|                       |\n";
    cout << "\t\t|          2.查看账号     |\n";
    cout << "\t\t|                       |\n";
    cout << "\t\t|          3.查看机房      |\n";
    cout << "\t\t|                       |\n";
    cout << "\t\t|          4.清空预约    |\n";
    cout << "\t\t|                       |\n";
    cout << "\t\t|          0.退出        |\n";
    cout << "\t\t|                       |\n";
    cout << "\t\t------------------------\n";
    cout << "输入您的选择:";
}

//添加账号
void Manager::addPerson() {
    //提示
    cout << "请输入添加账号类型" << endl;
    cout << "1.student" << endl;
    cout << "2.teacher" << endl;
    string fileName; //操作文件名
    string tip; //提示id号
    ofstream ofs;//文件操作对象
    string errorTip;//错误提示

    int select = 0;
    cin >> select; //接受
    if (select == 1) {
        //添加的是学生
        fileName = STUDENT_FILE;
        tip = "请输入学号:";
        errorTip = "学号重复";
    } else {
        fileName = TEACHER_FILE;
        tip = "请输入职工编号:";
        errorTip = "职工号重复";
    }
    ofs.open(fileName, ios::out | ios::app); //利用追加写文件
    int id; //学号 /职工号
    string name, pwd;
    cout << tip << endl;
    while (true) {
        cin >> id;
        bool ret = checkRepeat(id, select);
        if (ret) //有重复
        {
            cout << errorTip << endl;
        } else {
            break;
        }
    }
    cout << "请输入姓名:" << endl;
    cin >> name;
    cout << "请输入密码:" << endl;
    cin >> pwd;
    //像文件中添加数据
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;
    system("clear");
    ofs.close();//对象操作完关闭
    this->initVector(); //重新获取文件中的数据
}

void printStudent(Student &s) {
    cout << "学号:" << s.m_Id << endl;
    cout << "姓名:" << s.m_Name << endl;
    cout << "密码:" << s.m_pwd << endl;
}

void printTeacher(Teacher &t) {
    cout << "职工号:" << t.m_EmpId << endl;
    cout << "姓名:" << t.m_Name << endl;
    cout << "密码:" << t.m_pwd << endl;
}

//查看账号
void Manager::showPerson() {
    cout << "请选择要查看内容:" << endl;
    cout << "1.查看所有学生" << endl;
    cout << "2.查看所有老师" << endl;
    int select = 0;//接受用户选择
    cin >> select;
    if (select == 1) {
        //查看学生
        cout << "所有学生信息如下:" << endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    } else {
        //查看老师
        cout << "所有老师信息如下:" << endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }
    system("read");  //类似于windows pause
    system("clear");
}

//查看机房信息
void Manager::showComputer() {
    cout << "机房的信息" << endl;
    for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
        cout << "机房编号" << it->m_ComId << "机房容量" << it->m_MaxNum << endl;
    }
    system("read");
    system("clear");
}

//清空预约记录
void Manager::cleanFile() {
    ofstream ofs(ORDER_FILE, ios::trunc); //trunc 清空重新创建
    ofs.close();
    cout << "success" << endl;
    system("read");
    system("cls");
}

//初始化容器
void Manager::initVector() {
    vStu.clear(); //确保文件清空状态
    vTea.clear();
    //读取信息
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件读取失败" << endl;
        return;
    }
    Student s;
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_pwd) {
        vStu.push_back(s);
    }
    cout << "当前学生数量:" << vStu.size() << endl;
    ifs.close();
    //读取老师
    ifs.open(TEACHER_FILE, ios::in);
    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_pwd) {
        vTea.push_back(t);
        cout << "当前老师数量:" << vTea.size() << endl;
    }
}

//去重复
bool Manager::checkRepeat(int id, int type) {
    if (type == 1) {
        //检测学生
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
            if (id == it->m_Id) {
                return true;
            }
        }
    } else {
        //检测老师
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
            if (id == it->m_EmpId) {
                return true;
            }
        }
    }
    return false;
}
