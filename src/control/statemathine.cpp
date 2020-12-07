#include "statemathine.h"
#include "state/loginstate.h"
#include "state/adduserstate.h"
#include "state/changepasswdstate.h"
#include "out/textout.h"
#include "data/configuration.h"

stateMathine* stateMathine::_stateMathine = nullptr;

stateMathine::stateMathine(){
    qRegisterMetaType<interfaceState*>("interfaceState*");
}

stateMathine* stateMathine::getInstance(){
    if(stateMathine::_stateMathine == nullptr){
        stateMathine::_stateMathine = new stateMathine();
    }
    return stateMathine::_stateMathine;
}

bool stateMathine::commandDiscriminate(QString para,QString* outString){
    bool stage = false;
    if(para.size() > 0){
        if(para[0] == ">"){
            stage = true;
            QString command = para.mid(1,para.size()-1);
            if(command == "user"){
                *outString = INFORMATION_HEAD + tr("you will operate for ") +
                        configuration::getInstance()->getLoginUser().name + tr(", laset login time is : ") +
                        configuration::getInstance()->getLoginUser().loginTime + COMMAND_END;
            }
            else if (command == "login"){
                interfaceState* state = (interfaceState*)new loginState(outString);
                this->stateChanged(state);
            }
            else if(command == "adduser"){
                interfaceState* state = (interfaceState*)new adduserState(outString);
                this->stateChanged(state);
            }
            else if(command == "passwd"){
                interfaceState* state = (interfaceState*)new changePasswdState(outString);
                this->stateChanged(state);
            }
        }
    }
    return stage;
}

QString stateMathine::commandDeal(QString para){
    QString temp = "";
    if(!this->commandDiscriminate(para, &temp)){
        if(this->currentState != nullptr){
            temp = this->currentState->deal(para);
        }
    }
    return temp;
}

void stateMathine::stateChanged(interfaceState* nextState){
    if(this->currentState != nullptr){
        disconnect(this->currentState,SIGNAL(changeState(interfaceState*)),this,SLOT(stateChanged(interfaceState*)));
        delete this->currentState;
    }
    this->currentState = nextState;
    connect(this->currentState,SIGNAL(changeState(interfaceState*)),this,SLOT(stateChanged(interfaceState*)));
}
