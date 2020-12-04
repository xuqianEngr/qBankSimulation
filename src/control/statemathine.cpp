#include "statemathine.h"
#include "state/loginstate.h"

stateMathine* stateMathine::_stateMathine = nullptr;

stateMathine::stateMathine(){
    qRegisterMetaType<interfaceState*>("interfaceState*");
    this->currentState = (interfaceState*)new loginState();
    connect(this->currentState,SIGNAL(changeState(interfaceState*)),this,SLOT(stateChanged(interfaceState*)));
}

stateMathine* stateMathine::getInstance(){
    if(stateMathine::_stateMathine == nullptr){
        stateMathine::_stateMathine = new stateMathine();
    }
    return stateMathine::_stateMathine;
}

QString stateMathine::commandDeal(QString para){
    return this->currentState->deal(para);
}

void stateMathine::stateChanged(interfaceState* nextState){
    disconnect(this->currentState,SIGNAL(changeState(interfaceState*)),this,SLOT(stateChanged(interfaceState*)));
    delete this->currentState;
    this->currentState = nextState;
    connect(this->currentState,SIGNAL(changeState(interfaceState*)),this,SLOT(stateChanged(interfaceState*)));
}
