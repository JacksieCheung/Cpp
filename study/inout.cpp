#include <iostream>

int main() {
    char answer;
    std :: cout << "是否执行更新操作？【Y/N】" << std :: endl;
    std :: cin >> answer;
    
    switch( answer ) {
        case 'y':
        case 'Y':
            std :: cout << "执行成功" << std :: endl;
            break;

        case 'n':
        case 'N':
            std :: cout << "收到" << std :: endl;
            break;

        default:
            std :: cout << "请正确输入规定字符" << std :: endl;
            break;
        }

    std :: cout << "PRESS ANY BOUTTON EXIT THE PROGRAMME";
    std :: cin.ignore(100,'\n');
    std :: cin.get();
    return 0;
}
