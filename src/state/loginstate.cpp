#include "loginstate.h"
#include "state/userdommanddealstate.h"
#include "state/admincommanddealstate.h"
loginState::loginState(){

}

QString loginState::waitPara1Deal(QString para){
    QString tempString = COMMAND_ERRO;
    if(checkUserExist(para)){
        this->user.name = para;
        tempString = QObject::tr("enter passwd.");
        this->stage = WAIT_NEXT_PARA_STATE::wait_para2;
    }
    else{
        tempString = QObject::tr("user does not exist,please enter agian.");
    }
    return tempString;
}

QString loginState::waitPara2Deal(QString para){
    QString tempString = COMMAND_ERRO;
    this->user.hashPasswd = getHash(para);
    if(userLogin(&this->user)){
        tempString = tr("you will operate for ") + this->user.name + tr(", laset login time is : ") + this->user.loginTime;
        interfaceState* state = nullptr;
        if(user.name != ADMIN_DEFAULT_NAME){
            state = (interfaceState*)new userCommandDealstate();
        }
        else{
            state = (interfaceState*)new adminCommandDealState();
        }
        clearTerminal();
        emit changeState(state);
    }
    else{
        tempString = QObject::tr("passwd erro.");
    }
    return tempString;
}
