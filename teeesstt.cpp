#include<bits/stdc++.h>
#include <windows.h>
#include <Commdlg.h>
#include <shlobj.h>
using namespace std;
void GUI()
{
	cout<<"GUI"<<endl;
}
int Select(char *path)// choose file
{
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn); 
    ofn.lpstrFile = path; 
    ofn.nMaxFile = MAX_PATH; 
    ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0"; 
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	return GetOpenFileName(&ofn);
}
int Select2(char *path)//choose compress feil save place 
{
	BROWSEINFO bi;   
	ZeroMemory(&bi,sizeof(BROWSEINFO));   
	bi.hwndOwner = NULL;   
	bi.pszDisplayName = path;   
	bi.lpszTitle = ("compress file will save at:");   
	bi.ulFlags = BIF_RETURNFSANCESTORS;   
	LPITEMIDLIST idl = SHBrowseForFolder(&bi);   
	SHGetPathFromIDList(idl,path); 
    if(NULL==idl)
    {
        return 0;
    }  
    else
    {
        return 1;
    }  
}
void fidd(char *szFile,int n)
{
    if(n==1)
    {
        	//char szFile[MAX_PATH] = {0};
        if(Select(szFile))
        {
        	cout<<szFile<<endl;
            return;
        }
        else 
        {
            cout<<"Something wrong put any button back main muen"<<endl;
            getchar();
            system("cls") ;
            GUI();
        }
    }
    if(n==2)
    {

        if(Select2(szFile));
        {
            cout<<szFile<<endl;
            return;
        }
        if(Select2(szFile)==0)
        {
            cout<<"Something wrong put any button back main muen"<<endl;
            GUI();
        }
        
    }
    return ;
}  
int main()
{
	int n;
	char s[MAX_PATH]={0};
	cin>>n;
	fidd(s,n);	
	return 0;
}

