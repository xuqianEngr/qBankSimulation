#include "usermanerger.h"
#include "control/workpath.h"
#include "QDate"
#include "QTime"

QString getHash(QString string){
    std::string stdString = string.toStdString();
    QString hashString;
    std::hash<std::string> hash_fn;
    size_t hash = hash_fn(stdString);
    hashString = QString::number(hash,10);
    return hashString;
}

void checkoutdbconn(QSqlDatabase* dbconn){
    QString filePath = DATABSE_PATH+"/"+USERS_FILE_NAME;
    if (QSqlDatabase::contains(CONNECT_NAME)){
        *dbconn = QSqlDatabase::database(CONNECT_NAME);
    }
    else{
        *dbconn=QSqlDatabase::addDatabase(DATABASE_TYPE, CONNECT_NAME);
    }
    dbconn->setDatabaseName(filePath);
}

void creatUserDatabase(){
    QSqlDatabase dbconn;
    checkoutdbconn(&dbconn);
    QSqlQuery query(dbconn);
    if(dbconn.open()){
        dbconn.transaction();
        query.exec("CREATE TABLE  userList(\
                                user VARCHAR(50) PRIMARY KEY, \
                                passwdHash VARCHAR(50), \
                                buildTime VARCHAR(50), \
                                loginTime VARCHAR(50)) "
                            );
            dbconn.commit();
            dbconn.close();
    }
}

void initUserDatabse(){
    QString filePath = DATABSE_PATH+"/"+USERS_FILE_NAME;
    if(!QDir().exists(filePath)){
        LOGIN_MESSAGE userAdmin;
        creatUserDatabase();
        userAdmin.name = ADMIN_DEFAULT_NAME;
        userAdmin.hashPasswd = getHash(ADMIN_DEFAULT_PASSWD);
    }
}

bool checkUserExist(QString userName){
    bool stage = false;
    QString checkName;
    QSqlDatabase dbconn;
    checkoutdbconn(&dbconn);
    QSqlQuery query(dbconn);
    if(dbconn.open()){
       query.exec("select * from userList where user='"+ userName + "'");
       if(query.first()){
           checkName= query.value(0).toString();
       }
       dbconn.close();
    }
    if(checkName == userName){
        stage = true;
    }
    return stage;
}

bool addUser(LOGIN_MESSAGE user){
    bool stage = false;
    QSqlDatabase dbconn;
    checkoutdbconn(&dbconn);
    QSqlQuery query(dbconn);
    if(dbconn.open()){
        dbconn.transaction();
        query.prepare("INSERT INTO userList (user,passwdHash,buildTime,loginTime)\
                                    VALUES ( :user,:passwdHash,:buildTime,:loginTime)");
        query.bindValue(":user",user.name);
        query.bindValue(":passwdHash" ,user.hashPasswd);
        query.bindValue(":buildTime" ,QDate::currentDate().toString("yyyy/MM/dd") + " " +QTime::currentTime().toString("hh:mm:ss"));
        query.bindValue(":loginTime" ,user.loginTime);
        query.exec();
        dbconn.commit();
        dbconn.close();
        stage = true;
    }
    return stage;
}

bool changePasswd(LOGIN_MESSAGE user){
    bool stage = false;
    QSqlDatabase dbconn;
    checkoutdbconn(&dbconn);
    QSqlQuery query(dbconn);
    if(dbconn.open()){
        QSqlQuery query(dbconn);
        QString commandString = "UPDATE userList SET passwdHash = '"+user.hashPasswd +"' WHERE user = "+ user.name;
        query.exec(commandString);
        stage = true;
        dbconn.close();
    }
    return stage;
}

bool userLogin(LOGIN_MESSAGE* user){
    bool stage = false;
    LOGIN_MESSAGE databaseUser;
    QSqlDatabase dbconn;
    checkoutdbconn(&dbconn);
    QSqlQuery query(dbconn);
    if(dbconn.open()){
       query.exec("select * from userList where user='"+ user->name+"'");
       if(query.next()){
           databaseUser.name= query.value(0).toString();
           databaseUser.hashPasswd = query.value(1).toString();
           databaseUser.buildTime = query.value(2).toString();
           databaseUser.loginTime = query.value(3).toString();
       }
       if((user->name == databaseUser.name)&&(user->hashPasswd == databaseUser.hashPasswd)){
           stage = true;
           QString commandString = "UPDATE userList SET loginTime = '"\
                   + QDate::currentDate().toString("yyyy/MM/dd") + " " +QTime::currentTime().toString("hh:mm:ss")+"' WHERE user ='"+ user->name+"'";
           query.exec(commandString);
       }
        dbconn.close();
    }
    return stage;
}
