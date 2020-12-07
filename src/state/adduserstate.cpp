#include "adduserstate.h"
#include "out/textout.h"
#include "data/configuration.h"

adduserState::adduserState(QString* cout){
    *cout = INFORMATION_HEAD + tr("please enter user name.");
}

QString adduserState::waitPara1Deal(QString para)
{
    QString temp = COMMAND_ERRO;
    if(configuration::getInstance()->getLoginUser().name == ADMIN_DEFAULT_NAME){
        if(!checkUserExist(para)){
            this->newUser.name = para;
            temp = INFORMATION_HEAD + tr("please enter password.");
            this->stage = WAIT_NEXT_PARA_STATE::wait_para2;
        }
        else{
            temp = WANNING_HEAD + tr("user is exist please try again.");
        }
    }
    else{
        temp = ERRO_HEAD + tr("you are not admin !");
    }
    return temp;
}

QString adduserState::waitPara2Deal(QString para){
    QString temp = COMMAND_ERRO;
    this->newUser.hashPasswd  = getHash(para);
    temp = INFORMATION_HEAD + tr("add user is complete.") + COMMAND_END;
    addUser(this->newUser);
    return temp;
}
