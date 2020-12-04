#include "userdommanddealstate.h"
#include "state/changepasswdstate.h"

userCommandDealstate::userCommandDealstate(){

}
QString userCommandDealstate::waitPara1Deal(QString para){
    QString temp = COMMAND_ERRO;
    if(para == CHANGE_PASSWD){
       temp = tr("please enter your name:");
       interfaceState* state = (interfaceState*)new changePasswdState();
       clearTerminal();
       emit changeState(state);
    }
     return temp;
}
