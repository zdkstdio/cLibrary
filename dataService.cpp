#include"pch.h"
#include"dataService.h"

std::vector<TBook>books;
//std::vector<int>mapBooks;
std::vector<TUser>users;
//std::vector<int>mapUsers;
//int mBookHash,mUserHash;
TUser user;
std::vector<LPCWSTR>subscribes;
TBook::TBook(){
	id=num=ERR;
	memset(name,0,sizeof name);
	memset(isbn,0,sizeof isbn);
	memset(auth,0,sizeof auth);
	memset(publ,0,sizeof publ);
	memset(posi,0,sizeof posi);
}
LPCWSTR TBook::print(){
	LPWSTR ans=new WCHAR[MAX_LOADLONGSTRING];
	memset((LPVOID)ans,0,sizeof ans);
	WCHAR buf[5]={0};
	_itow_s(id,buf,10);
	lstrcat(ans,buf); lstrcat(ans,L"\t");
	lstrcat(ans,name);lstrcat(ans,L"\t");
	lstrcat(ans,isbn);lstrcat(ans,L"\t");
	lstrcat(ans,auth);lstrcat(ans,L"\t");
	lstrcat(ans,publ);lstrcat(ans,L"\t");
	lstrcat(ans,posi);
	return ans;
}
TDate::TDate(){
	time_t timeSec=time(NULL);
	tm*ptm=new tm;
	localtime_s(ptm,&timeSec);
	yy=ptm->tm_year;
	mm=ptm->tm_mon;
	dd=ptm->tm_mday;
}
TDate::TDate(int x){
	TDate();
	mm+=x;
	yy+=mm/12;
	mm%=12;
}
LPCWSTR TDate::print(){
	LPWSTR ans=new WCHAR[MAX_LOADSTRING];
	memset((LPVOID)ans,0,sizeof ans);
	WCHAR buf[5]={0};
	_itow_s(yy,buf,10);
	lstrcat(ans,buf);
	lstrcat(ans,L"/");
	_itow_s(mm,buf,10);
	lstrcat(ans,buf);
	lstrcat(ans,L"/");
	_itow_s(dd,buf,10);
	lstrcat(ans,buf);
	lstrcat(ans,L"/");
	return ans;
}
TUser::TUser(){
	id=type=ERR;
	memset(name,0,sizeof name);
	memset(pswd,0,sizeof pswd);
	borw.clear();
}
LPCWSTR TUser::print(){
	LPWSTR ans=new WCHAR[MAX_LOADLONGSTRING];
	memset((LPVOID)ans,0,sizeof ans);
	WCHAR buf[5]={0};
	_itow_s(id,buf,10);
	lstrcat(ans,buf); lstrcat(ans,L"\t");
	lstrcat(ans,name);lstrcat(ans,L"\t");
	_itow_s((int)borw.size(),buf,10);
	lstrcat(ans,buf);
	return ans;
}
bool isUsed(LPCWSTR){
	return false;
}
bool isAdmin(){
	return true;
}
bool isTeacher(){
	return true;
}
bool Login(LPCWSTR,LPCWSTR){
	return false;
}
bool Logout(){
	return true;
}
bool Signup(LPCWSTR,LPCWSTR){
	return false;
}
bool ChangePassword(LPCWSTR){
	return true;
}
std::vector<LPCWSTR>GetBookList(){
	std::vector<LPCWSTR>ans;
	ans.push_back(L"000001\t会杀的成分奶u就看这些\t被对方司机开车");
	ans.push_back(L"000002\t是跟随日本\t与西部很简");
	return ans;
}
std::vector<LPCWSTR>FindBook(LPCWSTR){
	std::vector<LPCWSTR>ans;
	ans.push_back(L"000001\t会杀的成分奶u就看这些\t被对方司机开车");
	ans.push_back(L"000002\t是跟随日本\t与西部很简");
	return ans;
}
int ChkBookId(int x){
	return x;
}
LPCWSTR FindBook(int){
	return nullptr;
}
int GetBookId(LPCWSTR){
	return ERR;
}
bool isAvaliable(int){
	return true;
}
std::vector<LPCWSTR>GetReturnList(){
	std::vector<LPCWSTR>ans;
	ans.push_back(L"000001\t会杀的成分奶u就看这些\t被对方司机开车");
	ans.push_back(L"000002\t是跟随日本\t与西部很简");
	return ans;
}
bool Borrow(int){
	return true;
}
bool Return(int){
	return true;
}
bool AddSubscribe(LPCWSTR){
	return true;
}
std::vector<LPCWSTR>GetSubscribeList(){
	std::vector<LPCWSTR>ans;
	ans.push_back(L"000001\t会杀的成分奶u就看这些\t被对方司机开车");
	ans.push_back(L"000002\t是跟随日本\t与西部很简");
	return ans;
}
bool DelSubscribe(int){
	return true;
}
std::vector<LPCWSTR>GetUserList(){
	std::vector<LPCWSTR>ans;
	ans.push_back(L"000001\t会杀的成分奶u就看这些\t被对方司机开车");
	ans.push_back(L"000002\t是跟随日本\t与西部很简");
	return ans;
}
bool DelUser(int){
	return true;
}
bool DelBook(int){
	return true;
}
bool SetUserTeacher(int){
	return true;
}
bool Save(){
	return true;
}
