#include "loginstate.h"
#include "out/textout.h"
#include "data/configuration.h"

loginState::loginState(QString* cout){
    *cout = INFORMATION_HEAD + tr("please enter user name.");
}

QString loginState::waitPara1Deal(QString para){
    QString tempString = COMMAND_ERRO;
    if(checkUserExist(para)){
        this->user.name = para;
        tempString = INFORMATION_HEAD + tr("enter passwd.");
        this->stage = WAIT_NEXT_PARA_STATE::wait_para2;
    }
    else{
        tempString = WANNING_HEAD + tr("user does not exist,please enter agian.");
    }
    return tempString;
}

QString loginState::waitPara2Deal(QString para){
    QString tempString = COMMAND_ERRO;
    this->user.hashPasswd = getHash(para);
    if(userLogin(&this->user)){
        configuration::getInstance()->setLoginUser(this->user);
        tempString = INFORMATION_HEAD + tr("you will operate for ") + this->user.name + tr(", laset login time is : ") + this->user.loginTime + COMMAND_END;
    }
    else{
        tempString = WANNING_HEAD + tr("passwd erro.");
    }
    return tempString;
}
