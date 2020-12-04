#include "admincommanddealstate.h"
#include "state/adduserstate.h"

adminCommandDealState::adminCommandDealState(){

}
QString adminCommandDealState::waitPara1Deal(QString para){
    QString temp = COMMAND_ERRO;
    if (para == ADD_USER_COMMAND) {
        temp = tr("enter add user's name");
        interfaceState* state = (interfaceState*)new adduserState();
        clearTerminal();
        emit changeState(state);
    }
    return temp;
}
