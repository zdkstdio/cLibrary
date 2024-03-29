﻿/************************************************************
*       $$$$$$$$$$$$$$$$$$$$      $$$$$$$$$$$$$$$$$$%.      *
*     $$                   &$   =$                   $      *
*     $                     $$$$$=                   @&     *
*  B#$$                     $$$$$                     %%$=  *
*  $$$$        +1s          $$-$$         +1s         $$$   *
*  $$$$                     $-  $                     $$$   *
*     $                     $   $                     .B    *
*     $                     @   $                    .=     *
*      $                   $     $                   %      *
*       $                -$       -$                @%      *
*        #$$$$$$$$$$$$$$$           -@$$$$$$$$$$$$$         *
*                                                           *
*       				莫生      莫生                      *
*       				 气        气                       *
*                                                           *
*						代码垃圾非我意,                     *
*						自己动手分田地;                     *
*						你若气死谁如意?                     *
*						谈笑风生活长命.                     *
************************************************************/
#include"pch.h"
#include"framework.h"
#include"Project1.h"
#include"const.h"
#include"globalVariables.h"
#include"dataService.h"
//#define NDEBUG

HINSTANCE hInst;// 当前实例
#pragma region 前向声明
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//  目标: 处理主窗口的消息。
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
// “关于”框的消息处理程序。
INT_PTR CALLBACK WndAboutProc(HWND,UINT,WPARAM,LPARAM);
// “登录”框的消息处理程序。
INT_PTR CALLBACK WndLoginProc(HWND,UINT,WPARAM,LPARAM);
// “注册”框的消息处理程序。
INT_PTR CALLBACK WndSignupProc(HWND,UINT,WPARAM,LPARAM);
// “浏览”框的消息处理程序。
INT_PTR CALLBACK WndBrowseProc(HWND,UINT,WPARAM,LPARAM);
// “查询”框的消息处理程序。
INT_PTR CALLBACK WndFindProc(HWND,UINT,WPARAM,LPARAM);
// “借阅”框的消息处理程序。
INT_PTR CALLBACK WndBorrowProc(HWND,UINT,WPARAM,LPARAM);
// “归还”框的消息处理程序。
INT_PTR CALLBACK WndReturnProc(HWND,UINT,WPARAM,LPARAM);
// “预订”框的消息处理程序。
INT_PTR CALLBACK WndSubscribeProc(HWND,UINT,WPARAM,LPARAM);
// “管理员入口”框的消息处理程序。
INT_PTR CALLBACK WndAdminProc(HWND,UINT,WPARAM,LPARAM);
// “管理员选项”框的消息处理程序。
INT_PTR CALLBACK WndAdminSelectProc(HWND,UINT,WPARAM,LPARAM);
// “预订列表”框的消息处理程序。
INT_PTR CALLBACK WndAdminSubscribeProc(HWND,UINT,WPARAM,LPARAM);
// “用户列表”框的消息处理程序。
INT_PTR CALLBACK WndAdminUserProc(HWND,UINT,WPARAM,LPARAM);
#pragma endregion

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPWSTR lpCmdLine,_In_ int nCmdShow){
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	WCHAR szTitle[MAX_LOADSTRING];
	WCHAR szWindowClass[MAX_LOADSTRING];
	LoadStringW(hInstance,IDS_APP_TITLE,szTitle,MAX_LOADSTRING);
	LoadStringW(hInstance,IDC_PROJECT1,szWindowClass,MAX_LOADSTRING);
	//注册窗口类。
	WNDCLASSEXW wcex;
	wcex.cbSize=sizeof(WNDCLASSEX);
	wcex.style=CS_HREDRAW|CS_VREDRAW;
	wcex.lpfnWndProc=WndProc;
	wcex.cbClsExtra=0;
	wcex.cbWndExtra=0;
	wcex.hInstance=hInstance;
	wcex.hIcon=LoadIcon(hInstance,MAKEINTRESOURCE(IDI_PROJECT1));
	wcex.hCursor=LoadCursor(nullptr,IDC_ARROW);
	wcex.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName=MAKEINTRESOURCEW(IDC_PROJECT1);
	wcex.lpszClassName=szWindowClass;
	wcex.hIconSm=LoadIcon(wcex.hInstance,MAKEINTRESOURCE(IDI_SMALL));
	RegisterClassExW(&wcex);
	//保存实例句柄并创建主窗口
	hInst=hInstance; // 将实例句柄存储在全局变量
	HWND hWnd=CreateWindowW(szWindowClass,szTitle,WS_OVERLAPPEDWINDOW,
							CW_USEDEFAULT,0,CW_USEDEFAULT,0,nullptr,nullptr,hInstance,nullptr);
	if(!hWnd){
		return 0;
	}
	ShowWindow(hWnd,nCmdShow);
	MoveWindow(hWnd,100,100,350,600,true);
	HACCEL hAccelTable=LoadAccelerators(hInstance,MAKEINTRESOURCE(IDC_PROJECT1));
	MSG msg;
	while(GetMessage(&msg,nullptr,0,0)){
		if(!TranslateAccelerator(msg.hwnd,hAccelTable,&msg)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return(int)msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam){
	switch(message){
		case WM_CREATE:
			{
				HWND hWndBtnLogin=CreateWindow(
					L"BUTTON",L"登录",
					WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
					50,50,100,50,hWnd,(HMENU)ID_BTN_LOGIN,hInst,NULL);
				HWND hWndBtnSignup=CreateWindow(
					L"BUTTON",L"注册",
					WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
					200,50,100,50,hWnd,(HMENU)ID_BTN_SIGNUP,hInst,NULL);
				HWND hWndBtnBrowse=CreateWindow(
					L"BUTTON",L"浏览",
					WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
					50,150,100,50,hWnd,(HMENU)ID_BTN_BROWSE,hInst,NULL);
				HWND hWndBtnFind=CreateWindow(
					L"BUTTON",L"查询",
					WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
					200,150,100,50,hWnd,(HMENU)ID_BTN_FIND,hInst,NULL);
				HWND hWndBtnBorrow=CreateWindow(
					L"BUTTON",L"借阅",
					WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
					50,250,100,50,hWnd,(HMENU)ID_BTN_BORROW,hInst,NULL);
				HWND hWndBtnReturn=CreateWindow(
					L"BUTTON",L"归还",
					WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
					200,250,100,50,hWnd,(HMENU)ID_BTN_RETURN,hInst,NULL);
				HWND hWndBtnSubscribe=CreateWindow(
					L"BUTTON",L"预订",
					WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
					50,350,100,50,hWnd,(HMENU)ID_BTN_SUBSCRIBE,hInst,NULL);
				HWND hWndBtnLogout=CreateWindow(
					L"BUTTON",L"注销",
					WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
					200,350,100,50,hWnd,(HMENU)ID_BTN_LOGOUT,hInst,NULL);
				HWND hWndBtnCngpsd=CreateWindow(
					L"BUTTON",L"更改密码",
					WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
					50,450,100,50,hWnd,(HMENU)ID_BTN_CNGPSD,hInst,NULL);
				HWND hWndBtnAdmin=CreateWindow(
					L"BUTTON",L"管理员入口",
					WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
					200,450,100,50,hWnd,(HMENU)ID_BTN_ADMIN,hInst,NULL);
			}
			break;
		case WM_COMMAND:
			{
				switch(LOWORD(wParam)){
					case IDM_ABOUT:
						DialogBox(hInst,MAKEINTRESOURCE(IDD_ABOUTBOX),hWnd,WndAboutProc);
						break;
					case IDM_EXIT:
						DestroyWindow(hWnd);
						break;
					case ID_BTN_LOGIN:
						//SendMessage((HWND)lParam,WM_SETTEXT,(WPARAM)NULL,(LPARAM)L"登陆中..");
						DialogBox(hInst,MAKEINTRESOURCE(IDD_LOGIN),hWnd,WndLoginProc);
						break;
					case ID_BTN_SIGNUP:
						DialogBox(hInst,MAKEINTRESOURCE(IDD_SIGNUP),hWnd,WndSignupProc);
						break;
					case ID_BTN_BROWSE:
						DialogBox(hInst,MAKEINTRESOURCE(IDD_BROWSE),hWnd,WndBrowseProc);
						break;
					case ID_BTN_FIND:
						DialogBox(hInst,MAKEINTRESOURCE(IDD_FIND),hWnd,WndFindProc);
						break;
					case ID_BTN_BORROW:
						DialogBox(hInst,MAKEINTRESOURCE(IDD_BORROW),hWnd,WndBorrowProc);
						break;
					case ID_BTN_RETURN:
						DialogBox(hInst,MAKEINTRESOURCE(IDD_RETURN),hWnd,WndReturnProc);
						break;
					case ID_BTN_SUBSCRIBE:
						if(isTeacher()){
							DialogBox(hInst,MAKEINTRESOURCE(IDD_SUBSCRIBE),hWnd,WndSubscribeProc);
						} else{
							MessageBox(hWnd,L"没有权限！",L"没有权限",MB_OK);
						}
						break;
					case ID_BTN_LOGOUT:
						if(Logout()){
							MessageBox(hWnd,L"注销成功！",L"注销",MB_OK);
						} else{
							MessageBox(hWnd,L"注销失败！",L"注销",MB_OK);
						}
						break;
					case ID_BTN_CNGPSD:

						break;
					case ID_BTN_ADMIN:
						if(isAdmin()){
							DialogBox(hInst,MAKEINTRESOURCE(IDD_ADMIN),hWnd,WndAdminProc);
						} else{
							MessageBox(hWnd,L"没有权限！",L"没有权限",MB_OK);
						}
						break;
					default:
						return DefWindowProc(hWnd,message,wParam,lParam);
				}
			}
			break;
		case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc=BeginPaint(hWnd,&ps);
				// TODO: 在此处添加使用 hdc 的任何绘图代码...
			//	FillRect(hdc,&ps.rcPaint,(HBRUSH)(rand()%15+1));
				EndPaint(hWnd,&ps);
			}
			break;
		case WM_DESTROY:
			Save();
			PostQuitMessage(0);
			break;
		case WM_LBUTTONDOWN:
		//	DialogBox(hInst,MAKEINTRESOURCE(IDD_LOGIN),hWnd,WndLoginProc);
		//	MessageBox(hWnd,L"鼠标左键",L"哈哈",MB_YESNO|MB_ICONQUESTION);
			break;
		default:
			return DefWindowProc(hWnd,message,wParam,lParam);
	}
	return 0;
}
INT_PTR CALLBACK WndAboutProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			if(LOWORD(wParam)==IDOK||LOWORD(wParam)==IDCANCEL){
				EndDialog(hDlg,LOWORD(wParam));
			}
			return (INT_PTR)TRUE;
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK WndLoginProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDCANCEL:
					EndDialog(hDlg,LOWORD(wParam));
					return (INT_PTR)TRUE;
				case IDOK:
					{
						WCHAR userName[MAX_LOADSTRING];
						WCHAR passWord[MAX_LOADSTRING];
						GetDlgItemText(hDlg,IDC_LOGIN_USERNAME,userName,MAX_LOADSTRING);
						GetDlgItemText(hDlg,IDC_LOGIN_PASSWORD,passWord,MAX_LOADSTRING);
						if(!isUsed(userName)){
							MessageBox(hDlg,L"用户名不存在！",L"登录",MB_OK);
						} else if(Login(userName,passWord)){
							EndDialog(hDlg,LOWORD(wParam));
							MessageBox(hDlg,L"登陆成功！",L"登录",MB_OK);
						} else{
							MessageBox(hDlg,L"密码错误！",L"登录",MB_OK);
						}
					}
					return (INT_PTR)TRUE;
			}
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK WndSignupProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDCANCEL:
					EndDialog(hDlg,LOWORD(wParam));
					return (INT_PTR)TRUE;
				case IDOK:
					{
						WCHAR userName[MAX_LOADSTRING];
						WCHAR passWord[MAX_LOADSTRING];
						WCHAR passWord2[MAX_LOADSTRING];
						GetDlgItemText(hDlg,IDC_SIGNUP_USERNAME,userName,MAX_LOADSTRING);
						GetDlgItemText(hDlg,IDC_SIGNUP_PASSWORD,passWord,MAX_LOADSTRING);
						GetDlgItemText(hDlg,IDC_SIGNUP_PASSWORD2,passWord2,MAX_LOADSTRING);
						if(userName[0]==L'\0'){
							MessageBox(hDlg,L"用户名不能为空！",L"注册",MB_OK);
						}else if(wcscmp(passWord,passWord2)!=0){
							MessageBox(hDlg,L"两次密码不一致！",L"注册",MB_OK);
						} else if(isUsed(userName)){
							MessageBox(hDlg,L"用户名已被使用！",L"注册",MB_OK);
						} else if(Signup(userName,passWord)){
							EndDialog(hDlg,LOWORD(wParam));
							MessageBox(hDlg,L"注册成功！",L"注册",MB_OK);
						} else{
							MessageBox(hDlg,L"注册失败！",L"注册",MB_OK);
						}
					}
					return (INT_PTR)TRUE;
			}
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK WndBrowseProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			{
				std::vector<LPCWSTR>books=GetBookList();
				std::for_each(books.begin(),books.end(),[=](auto x){SendDlgItemMessage(hDlg,IDC_BROWSE_LIST,LB_ADDSTRING,0,(LPARAM)x);});
			}
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDCANCEL:
					EndDialog(hDlg,LOWORD(wParam));
					return (INT_PTR)TRUE;
				case IDC_BROWSE_LIST:
					switch(HIWORD(wParam)){
						case LBN_DBLCLK:
							{
								int lbItem=(int)SendDlgItemMessage(hDlg,IDC_BROWSE_LIST,LB_GETCURSEL,0,0);
								WCHAR buf[MAX_LOADLONGSTRING]={0};
								SendDlgItemMessage(hDlg,IDC_BROWSE_LIST,LB_GETTEXT,lbItem,(LPARAM)buf);
								buf[IDLEN]=L'\0';
								int bookId=_wtoi(buf);
								if(!isAvaliable(bookId)){
									MessageBox(hDlg,L"此书不可借阅！",L"借阅",MB_OK);
								} else if(MessageBox(hDlg,L"确认借阅此书？",L"借阅",MB_OKCANCEL)==1){
									if(Borrow(bookId)){
										MessageBox(hDlg,L"借阅成功！",L"借阅",MB_OK);
										SendDlgItemMessage(hDlg,IDC_BROWSE_LIST,LB_RESETCONTENT,0,0);
										std::vector<LPCWSTR>books=GetBookList();
										std::for_each(books.begin(),books.end(),[=](auto x){SendDlgItemMessage(hDlg,IDC_BROWSE_LIST,LB_ADDSTRING,0,(LPARAM)x);});
									} else{
										MessageBox(hDlg,L"借阅失败！",L"借阅",MB_OK);
									}
								}
							}
							return (INT_PTR)TRUE;
					}
			}
			break;
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK WndFindProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDOK:
					{
						WCHAR inputText[MAX_LOADSTRING];
						GetDlgItemText(hDlg,IDC_FIND_TEXT,inputText,MAX_LOADSTRING);
						SendDlgItemMessage(hDlg,IDC_FIND_LIST,LB_RESETCONTENT,0,0);
						if(IsDlgButtonChecked(hDlg,IDC_FIND_BOOKID)){
							SendDlgItemMessage(hDlg,IDC_FIND_LIST,LB_ADDSTRING,0,(LPARAM)FindBook(_wtoi(inputText)));
						} else if(IsDlgButtonChecked(hDlg,IDC_FIND_BOOKNAME)){
							std::vector<LPCWSTR>showInfo=FindBook(inputText);
							std::for_each(showInfo.begin(),showInfo.end(),[=](auto x){SendDlgItemMessage(hDlg,IDC_FIND_LIST,LB_ADDSTRING,0,(LPARAM)x);});
						} else{
							MessageBox(hDlg,L"请选择输入类型！",L"查询",MB_OK);
						}
					}
					return (INT_PTR)TRUE;
				case IDCANCEL:
					EndDialog(hDlg,LOWORD(wParam));
					return (INT_PTR)TRUE;
				case IDC_BROWSE_LIST:
					switch(HIWORD(wParam)){
						case LBN_DBLCLK:
							{
								int lbItem=(int)SendDlgItemMessage(hDlg,IDC_FIND_LIST,LB_GETCURSEL,0,0);
								WCHAR buf[MAX_LOADLONGSTRING]={0};
								SendDlgItemMessage(hDlg,IDC_FIND_LIST,LB_GETTEXT,lbItem,(LPARAM)buf);
								buf[IDLEN]=L'\0';
								int bookId=_wtoi(buf);
								if(!isAvaliable(bookId)){
									MessageBox(hDlg,L"此书不可借阅！",L"借阅",MB_OK);
								} else if(MessageBox(hDlg,L"确认借阅此书？",L"借阅",MB_OKCANCEL)==1){
									if(Borrow(bookId)){
										MessageBox(hDlg,L"借阅成功！",L"借阅",MB_OK);
										SendDlgItemMessage(hDlg,IDC_FIND_LIST,LB_RESETCONTENT,0,0);
									} else{
										MessageBox(hDlg,L"借阅失败！",L"借阅",MB_OK);
									}
								}
							}
							return (INT_PTR)TRUE;
					}
			}
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK WndBorrowProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDOK:
					{
						int bookId=ERR;
						WCHAR inputText[MAX_LOADSTRING];
						GetDlgItemText(hDlg,IDC_BORROW_TEXT,inputText,MAX_LOADSTRING);
						if(IsDlgButtonChecked(hDlg,IDC_BORROW_BOOKID)){
							bookId=ChkBookId(_wtoi(inputText));
						} else if(IsDlgButtonChecked(hDlg,IDC_BORROW_BOOKNAME)){
							bookId=GetBookId(inputText);
						} else{
							MessageBox(hDlg,L"请选择输入类型！",L"借阅",MB_OK);
						}
						if(bookId==ERR){
							MessageBox(hDlg,L"书本不存在！",L"借阅",MB_OK);
						} else if(!isAvaliable(bookId)){
							MessageBox(hDlg,L"此书不可借阅！",L"借阅",MB_OK);
						} else if(MessageBox(hDlg,L"确认借阅此书？",L"借阅",MB_OKCANCEL)==1){
							if(Borrow(bookId)){
								EndDialog(hDlg,LOWORD(wParam));
								MessageBox(hDlg,L"借阅成功！",L"借阅",MB_OK);
							} else{
								MessageBox(hDlg,L"借阅失败！",L"借阅",MB_OK);
							}
						}
					}
					return (INT_PTR)TRUE;
				case IDCANCEL:
					EndDialog(hDlg,LOWORD(wParam));
					return (INT_PTR)TRUE;
			}
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK WndReturnProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			{
				std::vector<LPCWSTR>returnList=GetReturnList();
				std::for_each(returnList.begin(),returnList.end(),[=](auto x){SendDlgItemMessage(hDlg,IDC_RETURN_LIST,LB_ADDSTRING,0,(LPARAM)x);});
			}
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDCANCEL:
					EndDialog(hDlg,LOWORD(wParam));
					return (INT_PTR)TRUE;
				case IDC_RETURN_LIST:
					switch(HIWORD(wParam)){
						case LBN_DBLCLK:
							{
								int lbItem=(int)SendDlgItemMessage(hDlg,IDC_RETURN_LIST,LB_GETCURSEL,0,0);
								WCHAR buf[MAX_LOADLONGSTRING]={0};
								SendDlgItemMessage(hDlg,IDC_RETURN_LIST,LB_GETTEXT,lbItem,(LPARAM)buf);
								buf[IDLEN]=L'\0';
								int bookId=_wtoi(buf);
								if(MessageBox(hDlg,L"确认归还此书？",L"归还",MB_OKCANCEL)==1){
									if(Return(bookId)){
										MessageBox(hDlg,L"归还成功！",L"归还",MB_OK);
										SendDlgItemMessage(hDlg,IDC_RETURN_LIST,LB_RESETCONTENT,0,0);
										std::vector<LPCWSTR>returnList=GetReturnList();
										std::for_each(returnList.begin(),returnList.end(),[=](auto x){SendDlgItemMessage(hDlg,IDC_RETURN_LIST,LB_ADDSTRING,0,(LPARAM)x);});
									} else{
										MessageBox(hDlg,L"归还失败！",L"归还",MB_OK);
									}
								}
							}
							return (INT_PTR)TRUE;
					}
			}
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK WndSubscribeProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDOK:
					{
						WCHAR inputText[MAX_LOADLONGSTRING];
						GetDlgItemText(hDlg,IDC_SUBSCRIBE_TEXT,inputText,MAX_LOADLONGSTRING);
						if(MessageBox(hDlg,L"确认提交？",L"预订",MB_OKCANCEL)==1){
							if(AddSubscribe(inputText)){
								EndDialog(hDlg,LOWORD(wParam));
								MessageBox(hDlg,L"提交成功！",L"预订",MB_OK);
							} else{
								MessageBox(hDlg,L"提交失败！",L"预订",MB_OK);
							}
						}
					}
					return (INT_PTR)TRUE;
				case IDCANCEL:
					EndDialog(hDlg,LOWORD(wParam));
					return (INT_PTR)TRUE;
			}
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK WndAdminProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			{
				std::vector<LPCWSTR>books=GetBookList();
				std::for_each(books.begin(),books.end(),[=](auto x){SendDlgItemMessage(hDlg,IDC_ADMIN_LIST,LB_ADDSTRING,0,(LPARAM)x);});
			}
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDCANCEL:
					EndDialog(hDlg,LOWORD(wParam));
					return (INT_PTR)TRUE;
				case IDC_ADMIN_LIST:
					switch(HIWORD(wParam)){
						case LBN_DBLCLK:
							DialogBox(hInst,MAKEINTRESOURCE(IDD_ADMIN_SELECT),hDlg,WndAdminSelectProc);
					}
					return (INT_PTR)TRUE;
				case IDC_ADMIN_SUBSCRIBEBTN:
					DialogBox(hInst,MAKEINTRESOURCE(IDD_ADMIN_SUBSCRIBE),hDlg,WndAdminSubscribeProc);
					return (INT_PTR)TRUE;
				case IDC_ADMIN_USERBTN:
					DialogBox(hInst,MAKEINTRESOURCE(IDD_ADMIN_USER),hDlg,WndAdminUserProc);
					return (INT_PTR)TRUE;
			}
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK WndAdminSelectProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDCANCEL:
					EndDialog(hDlg,LOWORD(wParam));
					return (INT_PTR)TRUE;
				case IDC_ADMIN_SELECT_ADD:
					return (INT_PTR)TRUE;
				case IDC_ADMIN_SELECT_DEL:
					{
						HWND hPreWnd=GetParent(hDlg);
						int lbItem=(int)SendDlgItemMessage(hPreWnd,IDC_ADMIN_LIST,LB_GETCURSEL,0,0);
						WCHAR buf[MAX_LOADLONGSTRING]={0};
						SendDlgItemMessage(hPreWnd,IDC_ADMIN_LIST,LB_GETTEXT,lbItem,(LPARAM)buf);
						buf[IDLEN]=L'\0';
						int bookId=_wtoi(buf);
						if(MessageBox(hDlg,L"确认删除此项？",L"删除书本",MB_OKCANCEL)==1){
							if(DelBook(bookId)){
								MessageBox(hDlg,L"删除成功！",L"删除书本",MB_OK);
								SendDlgItemMessage(hPreWnd,IDC_ADMIN_LIST,LB_RESETCONTENT,0,0);
								std::vector<LPCWSTR>books=GetBookList();
								std::for_each(books.begin(),books.end(),[=](auto x){SendDlgItemMessage(hPreWnd,IDC_ADMIN_LIST,LB_ADDSTRING,0,(LPARAM)x);});
							} else{
								MessageBox(hDlg,L"删除失败！",L"删除书本",MB_OK);
							}
						}
					}
					return (INT_PTR)TRUE;
				case IDC_ADMIN_SELECT_EDIT:
					return (INT_PTR)TRUE;
			}
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK WndAdminSubscribeProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			{
				std::vector<LPCWSTR>subscribeList=GetSubscribeList();
				std::for_each(subscribeList.begin(),subscribeList.end(),[=](auto x){SendDlgItemMessage(hDlg,IDC_ADMIN_SUBSCRIBE_LIST,LB_ADDSTRING,0,(LPARAM)x);});
			}
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDCANCEL:
					EndDialog(hDlg,LOWORD(wParam));
					return (INT_PTR)TRUE;
				case IDC_ADMIN_SUBSCRIBE_LIST:
					switch(HIWORD(wParam)){
						case LBN_DBLCLK:
							{
								int lbItem=(int)SendDlgItemMessage(hDlg,IDC_ADMIN_SUBSCRIBE_LIST,LB_GETCURSEL,0,0);
								if(MessageBox(hDlg,L"确认删除此项？",L"删除记录",MB_OKCANCEL)==1){
									if(DelSubscribe(lbItem)){
										MessageBox(hDlg,L"删除成功！",L"删除记录",MB_OK);
										SendDlgItemMessage(hDlg,IDC_ADMIN_SUBSCRIBE_LIST,LB_RESETCONTENT,0,0);
										std::vector<LPCWSTR>subscribeList=GetSubscribeList();
										std::for_each(subscribeList.begin(),subscribeList.end(),[=](auto x){SendDlgItemMessage(hDlg,IDC_ADMIN_SUBSCRIBE_LIST,LB_ADDSTRING,0,(LPARAM)x);});
									} else{
										MessageBox(hDlg,L"删除失败！",L"删除记录",MB_OK);
									}
								}
							}
							return (INT_PTR)TRUE;
					}
			}
			break;
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK WndAdminUserProc(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			{
				std::vector<LPCWSTR>userList=GetUserList();
				std::for_each(userList.begin(),userList.end(),[=](auto x){SendDlgItemMessage(hDlg,IDC_ADMIN_USER_LIST,LB_ADDSTRING,0,(LPARAM)x);});
			}
			return (INT_PTR)TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDCANCEL:
					EndDialog(hDlg,LOWORD(wParam));
					return (INT_PTR)TRUE;
				case IDC_ADMIN_USER_LIST:
					switch(HIWORD(wParam)){
						case LBN_DBLCLK:
							{
								int lbItem=(int)SendDlgItemMessage(hDlg,IDC_ADMIN_USER_LIST,LB_GETCURSEL,0,0);
								if(MessageBox(hDlg,L"确认删除此项？",L"删除用户",MB_OKCANCEL)==1){
									if(DelUser(lbItem)){
										MessageBox(hDlg,L"删除成功！",L"删除用户",MB_OK);
										SendDlgItemMessage(hDlg,IDC_ADMIN_USER_LIST,LB_RESETCONTENT,0,0);
										std::vector<LPCWSTR>userList=GetUserList();
										std::for_each(userList.begin(),userList.end(),[=](auto x){SendDlgItemMessage(hDlg,IDC_ADMIN_USER_LIST,LB_ADDSTRING,0,(LPARAM)x);});
									} else{
										MessageBox(hDlg,L"删除失败！",L"删除用户",MB_OK);
									}
								}
							}
							return (INT_PTR)TRUE;
					}
			}
			break;
	}
	return (INT_PTR)FALSE;
}