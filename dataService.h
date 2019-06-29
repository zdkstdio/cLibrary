#pragma once
#include"pch.h"
#include"const.h"
struct TBook{
	int id;
	int num;
	WCHAR name[MAX_LOADSTRING];
	WCHAR isbn[MAX_LOADSTRING];
	WCHAR auth[MAX_LOADSTRING];
	WCHAR publ[MAX_LOADSTRING];
	WCHAR posi[MAX_LOADSTRING];
	TBook();
	LPCWSTR print();
};
struct TDate{
	int yy,mm,dd;
	TDate();
	TDate(int);
	LPCWSTR print();
};
struct TUser{
	int id;
	int type;
	WCHAR name[MAX_LOADSTRING];
	WCHAR pswd[MAX_LOADSTRING];
	std::vector<std::pair<int,TDate>>borw;
	TUser();
	LPCWSTR print();
};

bool isUsed(LPCWSTR);
bool isAdmin();
bool isTeacher();
bool Login(LPCWSTR,LPCWSTR);
bool Logout();
bool Signup(LPCWSTR,LPCWSTR);
bool ChangePassword(LPCWSTR);
std::vector<LPCWSTR>GetBookList();
std::vector<LPCWSTR>FindBook(LPCWSTR);
int ChkBookId(int);
LPCWSTR FindBook(int);
int GetBookId(LPCWSTR);
bool isAvaliable(int);
std::vector<LPCWSTR>GetReturnList();
bool Borrow(int);
bool Return(int);
bool AddSubscribe(LPCWSTR);
std::vector<LPCWSTR>GetSubscribeList();
bool DelSubscribe(int);
std::vector<LPCWSTR>GetUserList();
bool DelUser(int);
bool DelBook(int);
bool SetUserTeacher(int);
bool Save();
