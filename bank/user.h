#ifndef USER_H
#define USER_H


#include <string>


using namespace std;


class user
{

public:

    void set_name(string _name);
    string get_name();
    void set_id(string _id);
    string get_id();
    void set_pw(string _pw);
    string get_pw();
    void set_bknm(string _bknm);
    string get_bknm();
    void set_ques(string _ques);
    string get_ques();
    void set_ans(string _ans);
    string get_ans();
    void set_money(float _money);
    float get_money();
    void set_log(string _log);
    string get_log();
    void set_phone(string _phone);
    string get_phone();
    void set_card_no(string _card_no);
    string get_card_no();

private:
    string name;//姓名
    string id;//身份证号
    string passwd;//密码
    string bank_name;//银行名称
    string question;//密码问题
    string answer;//问题答案
    float money;//余额
    string log;//日志
    string phone;//手机，11位
    string card_no;//卡号，4位
};

#endif // USER_H
