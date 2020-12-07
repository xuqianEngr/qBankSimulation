#include "configuration.h"

configuration* configuration::_configuration = nullptr;

configuration::configuration(){
}

configuration* configuration::getInstance(){
    if(configuration::_configuration == nullptr){
        configuration::_configuration = new configuration();
    }
    return configuration::_configuration;
}

LOGIN_MESSAGE configuration::getLoginUser(){
    return  this->loginUser;
}

void configuration::setLoginUser(LOGIN_MESSAGE user){
    this->loginUser = user;
}

void configuration::loginOut(){
    this->loginUser.name = "";
    this->loginUser.hashPasswd = "";
    this->loginUser.buildTime = "";
    this->loginUser.loginTime = "";
}
