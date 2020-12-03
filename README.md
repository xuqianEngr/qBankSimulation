# qBankSimulation  
银行账户模拟系统  
   
## 项目描述    
* 为培养小孩良好的金融认识，而开发的零花钱管理系统   
* admin账户不可直接对账户上的金额进行修改，需要用户提交取出余额请求，才能确认。保证用户财产不受管理员自我意愿进行修改   
* 暂定命令行操作，GUI界面后期开发   
   
## 参数描述   
__qbank command  <-option>  [description] ["message"]__     
* __command__    user  _使用客户账户登录_  
> __command  <-option>  [description]__   
> * __command__    log   _查询账户收支明细_  
> __<-option>__  -today   _查询今日明细_  
> __<-option>__  -tomonth   _查询当月明细_  
> __<-option>__  -toyear   _查询当年明细_  
> __<-option>__  -year/month/day    _查询指定日期明细_  
> __[description]__     _eg.  2020/12/2     查询2020/12/2日存取明细_  
> __<-option>__  -year/month   _查询指定月份明细_  
> __[description]__     _eg.  2020/12     查询2020/12月存取明细_  
> __<-option>__ -year   _查询指定年度明细_  
> __[description]__     _eg.  2020     查询2020日存取明细_   
> * __command__    balance   _查询余额_  
> * __command__    interest    _查询利率_  
> * __command__    deposit    _定期存款操作_  
> __<-option>__   -log   _查询定期存款_   
> __<-option>__   -add   _增加定期存款_  
> __[description]__    _eg.  200     存入定期200元_  
> __<-option>__   -withdraw   _到期取出存款_  
> __[description]__    _eg.  1 到期取出id值为1的存款至余额_      
> _command_      takeout  _取出余额_   
> __[description]__    _eg.  200     取出200元_  
> __["message"]__    _eg. "我要买游戏机" 打上需要取出余额的理由_   
     
* __command__    admin  _使用管理员账户登录_   
> * __command  <-option> [description]__   
> * __command__  interest  _利率操作_   
> __<-option>__  -setdeposit  _设置定期存款_    
> __<-option>__  -setbalance  _设置定期存款_   
> __[description]__     _eg.  4.9     设定年化率4.9的利息_   
> * __command__  checkout  _查询用户账户情况_    
> __<-option>__  user    _指定账户_    
> __[description]__    _eg.  xuqian     _查询账户名称为xuqian的账户明细  //此时可以使用log命令查询明细_
> * __command__  confirm  _确认取出请求_   
> * __command__  reject     _请求驳回_    
> * __command__   history   _查询admin账户操作历史_