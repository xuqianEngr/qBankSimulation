#include "interfacestate.h"
#include "QObject"

QString interfaceState::deal(QString para)
{
    QString tempString = QObject::tr("Systerm erro");
    switch (this->stage) {
    case WAIT_NEXT_PARA_STATE::wait_para1:
        tempString = this->waitPara1Deal(para);
        break;
    case WAIT_NEXT_PARA_STATE::wait_para2:
        tempString = this->waitPara2Deal(para);
        break;
    case WAIT_NEXT_PARA_STATE::wait_para3:
        tempString = this->waitPara3Deal(para);
        break;
    case WAIT_NEXT_PARA_STATE::wait_para4 :
        tempString = this->waitPara4Deal(para);
        break;
    default:
        break;
    }
    return tempString;
}

QString interfaceState::waitPara1Deal(QString para){
    Q_UNUSED(para)
    return "no para";
}

QString interfaceState::waitPara2Deal(QString para){
    Q_UNUSED(para)
    return "no para";
}

QString interfaceState::waitPara3Deal(QString para){
    Q_UNUSED(para)
    return "no para";
}

QString interfaceState::waitPara4Deal(QString para){
    Q_UNUSED(para)
    return "no para";
}
