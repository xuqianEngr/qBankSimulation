#include "changepasswdstate.h"
#include "out/textout.h"
#include "data/configuration.h"

changePasswdState::changePasswdState(QString* cout){
    *cout = INFORMATION_HEAD + tr("please enter password.");
}
QString changePasswdState::waitPara1Deal(QString para){
    QString tempString = COMMAND_ERRO;
    if(configuration::getInstance()->getLoginUser().name != ""){
        this->user.name = configuration::getInstance()->getLoginUser().name;
        this->user.hashPasswd = getHash(para);
        if(configuration::getInstance()->getLoginUser().hashPasswd == this->user.hashPasswd){
            tempString = INFORMATION_HEAD + tr("please enter new password.");
            this->stage = WAIT_NEXT_PARA_STATE::wait_para2;
        }
        else{
            tempString = WANNING_HEAD + tr("password is erro.");
        }
    }
    else{
        tempString = WANNING_HEAD + tr("please login.");
    }
    return tempString;
}

QString changePasswdState::waitPara2Deal(QString para){
    QString tempString = COMMAND_ERRO;
    this->user.hashPasswd = getHash(para);
    changePasswd(this->user);
    configuration::getInstance()->loginOut();
    tempString = INFORMATION_HEAD + tr("change password ok, please login again.") + COMMAND_END;
    return tempString;
}

