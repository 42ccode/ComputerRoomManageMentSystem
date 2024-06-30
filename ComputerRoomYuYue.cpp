#include "iostream"
#include "identity.h"
#include "fstream"
#include "string"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;

//进入学生子菜单界面
void studentMenu(identity *&student) {
    while (true) {
        //调用学生子菜单
        student->openMenu();
        Student *stu = (Student *) student;
        int select = 0;
        cin >> select;//接受用户选择
        if (select == 1) { //申请预约
            stu->applyOrder();
        } else if (select == 2) { //查看自身预约
            stu->showMyOrder();
        } else if (select == 3) { //查看所有人预约
            stu->showAllOrder();
        } else if (select == 4) { //取消
            stu->cancelOrder();
        } else {
            //注销
            delete student;
            cout << "注销成功" << endl;
            system("read");
            system("clear");
            return;
        }
    }
}

//进入管理员子菜单
void managerMenu(identity *&manager) {
    while (true) {
        //调用管理员子菜单
        manager->openMenu();
        //将父类指针转为子类指针,调用子类里其他接口
        Manager *man = dynamic_cast<Manager *>(manager);
        if (man == nullptr) {
            cerr << "类型转换失败" << endl;
            return;
        }
        int select = 0;
        //接受用户的选择
        cin >> select;
        if (select == 1) { //添加账号
            cout << "添加账号" << endl;
            man->addPerson();
        } else if (select == 2) { //查看账号
            cout << "查看账号" << endl;
            man->showPerson();
        } else if (select == 3) { //查看机房信息
            cout << "查看机房" << endl;
            man->showComputer();
        } else if (select == 4) {//清空
            cout << "清空预约" << endl;
            man->cleanFile();
        } else {
            delete manager; //销毁掉堆区对象
            cout << "注销成功" << endl;
            system("clear");
            return;
        }
    }
}

//登陆功能
void LoginIn(string fileName, int type) //参数1 操作文件名 参数 2 操作身份类型
{
    identity *person = NULL;  //父类指针,用于指向子类对象
    //读文件
    ifstream ifs; //文件操作
    ifs.open(fileName, ios::in);
    //判断文件是否存在
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    //准备接受用户信息
    int id = 0;
    string name;
    string pwd;
    //判断身份
    if (type == 1) { //学生
        cout << "请输入你的学号:" << endl;
        cin >> id;
    } else if (type == 2) {
        cout << "请输入您的职工号" << endl;
        cin >> id;
    }
    cout << "请输入username:" << endl;
    cin >> name;
    cout << "请输入密码:" << endl;
    cin >> pwd;

    if (type == 1) {
        //学生身份验证
        int fId;//从文件中读取的ID
        string fName;//从文件中获取姓名
        string fPwd;//文件密码
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (fId == id && fName == name && fPwd == pwd) { //验证1
                cout << "student login success" << endl;
                system("clear");
                person = new Student(id, name, pwd);
                //student _child menu
                //进入学生身份子菜单
                studentMenu(person);
                return;
            }
        }
    } else if (type == 2) {
        //教师
        int fId;//从文件中读取的ID
        string fName;//从文件中获取姓名
        string fPwd;//文件密码
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (fId == id && fName == name && fPwd == pwd) { //验证1
                cout << "teacher login success" << endl;
                system("clear");
                person = new Teacher(id, name, pwd);
                //student _child menu
                return;
            }
        }
    } else if (type == 3) {
        //管理员身份
        string fName; //从文件中获取的姓名
        string fPwd; //从文件中获取的密码
        while (ifs >> fName && ifs >> fPwd) {
            if (name == fName && pwd == fPwd) {
                cout << "manager login success" << endl;
                system("clear");
                person = new Manager(name, pwd);
                //进入管理子菜单界面#
                managerMenu(person);
                return;
            }
        }
    }
    cout << "验证登陆失败!" << endl;
    system("clear");
    return;
}

int main() {
    int select = 0; //用于接受用户的选择
    while (true) {
        cout << "===============欢迎来到王牌飞行员大学预约系统==+++==+++====+++====++" << endl;
        cout << "\t\t------------------------\n";
        cout << "\t\t|                       |\n";
        cout << "\t\t|          1.学生代表    |\n";
        cout << "\t\t|                       |\n";
        cout << "\t\t|          2.老师        |\n";
        cout << "\t\t|                       |\n";
        cout << "\t\t|          3.管理员      |\n";
        cout << "\t\t|                       |\n";
        cout << "\t\t|          0.退出        |\n";
        cout << "\t\t|                       |\n";
        cout << "\t\t------------------------\n";
        cout << "输入您的选择:";
        cin >> select;//接受选择
        switch (select) {
            case 1:  //学生身份
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2:   //老师身份
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3:   //管理身份
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0:   //退出
                cout << "欢迎下次使用" << endl;
                system("clear"); // 或者 system("cls") 如果你在Windows下
                break;
            default:
                cout << "输入有误,请重新选择!" << endl;
                system("clear");   //这里的system 可以写terminal命令
                break;
        }
    }
    return 0;
}
