#include <QCoreApplication>
#include <QTextStream>
#include "database/usermanerger.h"
#include "control/statemathine.h"

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    if(initUserDatabse()){
        qout<<QObject::tr("systerm is init, account:'admin' password:'123456'.")<<endl;
    }else{
        qout<<QObject::tr("please enter user name:")<<endl;
    }
    while (1) {
        QString command = "";
        qin>>command;
        qout << stateMathine::getInstance()->commandDeal(command)<<endl;
    }
    return a.exec();
}
