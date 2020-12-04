#include "changepasswdstate.h"
#include "state/loginstate.h"

changePasswdState::changePasswdState()
{

}
QString changePasswdState::waitPara1Deal(QString para){
    QString tempString = COMMAND_ERRO;
    if(checkUserExist(para)){
        this->user.name = para;
        tempString = tr("please enter password.");
        this->stage = WAIT_NEXT_PARA_STATE::wait_para2;
    }
    else{
        tempString = tr("user is not exist, please try again.");
    }
    return tempString;
}

QString changePasswdState::waitPara2Deal(QString para){
    QString tempString = COMMAND_ERRO;
    this->user.hashPasswd = getHash(para);
    if(userLogin(&this->user)){
        tempString = tr("please enter new password.");
        this->stage = WAIT_NEXT_PARA_STATE::wait_para3;
    }
    else{
        tempString = tr("password is erro, please try again.");
    }
    return tempString;
}

QString changePasswdState::waitPara3Deal(QString para){
    QString temp = COMMAND_ERRO;
    this->user.hashPasswd  = getHash(para);
    temp = tr("please enter new password again.");
    this->stage = WAIT_NEXT_PARA_STATE::wait_para4;
    return temp;
}

QString changePasswdState::waitPara4Deal(QString para){
    QString temp = COMMAND_ERRO;
    if(this->user.hashPasswd  == getHash(para)){
        temp = tr("password is changed, please login again, enter name:");
        changePasswd(this->user);
        interfaceState* state = (interfaceState*)new loginState();
        clearTerminal();
        emit changeState(state);
    }
    else{
        temp = tr("password is different, plese enter again.");
        this->stage = WAIT_NEXT_PARA_STATE::wait_para3;
    }
    return temp;
}
