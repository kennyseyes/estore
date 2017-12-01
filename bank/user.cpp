#include "user.h"
//private成员设置接口
void user::set_name(string _name){name=_name;}
string user::get_name(){return name;}
void user::set_id(string _id) {id=_id;}
string user::get_id(){return id;}
void user::set_pw(string _pw){passwd=_pw;}
string user::get_pw(){return passwd;}
void user::set_bknm(string _bknm){bank_name=_bknm;}
string user::get_bknm(){return bank_name;}
void user::set_ques(string _ques){question=_ques;}
string user::get_ques() {return question;}
void user::set_ans(string _ans) {answer=_ans;}
string user::get_ans(){return answer;}
void user::set_money(float _money){money=_money;}
float user::get_money(){return money;}
void user::set_log(string _log){log=_log;}
string user::get_log(){return log;}
void user::set_phone(string _phone){phone=_phone;}
string user::get_phone(){return phone;}
void user::set_card_no(string _card_no){card_no=_card_no;}
string user::get_card_no(){return card_no;}
