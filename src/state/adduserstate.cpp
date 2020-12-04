#include "adduserstate.h"
#include "state/admincommanddealstate.h"

adduserState::adduserState()
{

}
QString adduserState::waitPara1Deal(QString para)
{
    QString temp = COMMAND_ERRO;
    if(!checkUserExist(para)){
        this->newUser.name = para;
        temp = tr("please enter password.");
        this->stage = WAIT_NEXT_PARA_STATE::wait_para2;
    }
    else{
        temp = tr("user is exist please try again.");
    }
    return temp;
}

QString adduserState::waitPara2Deal(QString para){
    QString temp = COMMAND_ERRO;
    this->newUser.hashPasswd  = getHash(para);
    temp = tr("please enter password again.");
    this->stage = WAIT_NEXT_PARA_STATE::wait_para3;
    return temp;
}

QString adduserState::waitPara3Deal(QString para){
    QString temp = COMMAND_ERRO;
    if(this->newUser.hashPasswd  == getHash(para)){
        temp = tr("add user is complete.");
        addUser(this->newUser);
        interfaceState* state = (interfaceState*)new adminCommandDealState();
        clearTerminal();
        emit changeState(state);
    }
    else{
        temp = tr("password is different, plese enter again.");
        this->stage = WAIT_NEXT_PARA_STATE::wait_para2;
    }
    return temp;
}
