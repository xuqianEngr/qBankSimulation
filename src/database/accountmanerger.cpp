#include "accountmanerger.h"
accountManerger::accountManerger(LOGIN_MESSAGE user){
    this->user = user;
}

void accountManerger::checkoutdbconn(QSqlDatabase* dbconn){
    QString filePath = ACCOUNT_PATH+"/"+user.name+".db";
    if (QSqlDatabase::contains(ACCOUNT_CONNECT_NAME)){
        *dbconn = QSqlDatabase::database(ACCOUNT_CONNECT_NAME);
    }
    else{
        *dbconn=QSqlDatabase::addDatabase(DATABASE_TYPE, ACCOUNT_CONNECT_NAME);
    }
    dbconn->setDatabaseName(filePath);
}

bool accountManerger::creatAccount(){
    bool stage = false;
    QString filePath = ACCOUNT_PATH+"/"+user.name+".db";
    if(QDir().exists(filePath)){
        stage = true;
        QSqlDatabase dbconn;
        this->checkoutdbconn(&dbconn);
        QSqlQuery query(dbconn);
        if(dbconn.open()){
        dbconn.transaction();
        query.exec("CREATE TABLE  survey(\
                            id INTEGER PRIMARY KEY AUTOINCREMENT,\
                            date VARCHAR(50), \
                            regular VARCHAR(50), \
                            remain VARCHAR(50), \
                            tag VARCHAR(100)) "
                        );
        query.exec("CREATE TABLE  income(\
                            id INTEGER PRIMARY KEY AUTOINCREMENT,\
                            date VARCHAR(50), \
                            money VARCHAR(50), \
                            tag VARCHAR(100)) "
                        );
        query.exec("CREATE TABLE  expend(\
                            id INTEGER PRIMARY KEY AUTOINCREMENT,\
                            date VARCHAR(50), \
                            money VARCHAR(50), \
                            tag VARCHAR(100)) "
                        );
        query.exec("CREATE TABLE  regular(\
                            user VARCHAR(50) PRIMARY KEY, \
                            startDate VARCHAR(50), \
                            endDate VARCHAR(50), \
                            money VARCHAR(50), \
                            tag VARCHAR(100)) "
                        );
        dbconn.commit();
        dbconn.close();
        }
    }
    return  stage;
}

USER_SURVEY accountManerger::getSurvey(){
    QSqlDatabase dbconn;
    USER_SURVEY userSurvey;
    this->checkoutdbconn(&dbconn);
    QSqlQuery query(dbconn);
    if(dbconn.open()){
        dbconn.transaction();
        query.exec("select * from survey");
        if(query.first())
        {
            userSurvey.freshDate = query.value(0).toString();
            userSurvey.regular = query.value(1).toString();
            userSurvey.remain = query.value(2).toString();
        }
        dbconn.close();
    }
    return userSurvey;
}

bool accountManerger::income(QString money, QString tag){
    bool stage = false;
    USER_SURVEY survey = this->getSurvey();
    QSqlDatabase dbconn;
    this->checkoutdbconn(&dbconn);
    QSqlQuery query(dbconn);
    QString date = QDate::currentDate().toString("yyyy/MM/dd");
    if(dbconn.open()){
        dbconn.transaction();
        query.prepare("INSERT INTO income (date,money,tag)\
                                    VALUES ( :date,:money,:tag)");
        query.bindValue(":date",date);
        query.bindValue(":money" ,money);
        query.bindValue(":loginTime" ,tag);
        query.exec();
        QString cmd = "UPDATE survey SET remain = '" + QString::number(survey.remain.toInt() + money.toInt())\
                                    + "' date = '" + date \
                                    + "' WHERE user = '" + this->user.name+"'";
        query.exec(cmd);
        dbconn.commit();
        dbconn.close();
        stage = true;
    }
    return stage;
}

bool accountManerger::expend(QString money, QString tag){
    bool stage = false;
    USER_SURVEY survey = this->getSurvey();
    QSqlDatabase dbconn;
    this->checkoutdbconn(&dbconn);
    QSqlQuery query(dbconn);
    QString date = QDate::currentDate().toString("yyyy/MM/dd");
    if(dbconn.open()){
        dbconn.transaction();
        query.prepare("INSERT INTO income (date,money,tag)\
                                    VALUES ( :date,:money,:tag)");
        query.bindValue(":date",date);
        query.bindValue(":money" ,money);
        query.bindValue(":loginTime" ,tag);
        query.exec();
        QString cmd = "UPDATE survey SET remain = '" + QString::number(survey.remain.toInt() - money.toInt())\
                                    + "' date = '" + date \
                                    + "' WHERE user = '" + this->user.name+"'";
        query.exec(cmd);
        dbconn.commit();
        dbconn.close();
        stage = true;
    }
    return stage;
}
