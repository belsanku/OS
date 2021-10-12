#include <windows.h>
#include <ImageHlp.h>
#include <stdio.h>
#include <delayimp.h>
#include <string>
#include <iostream>

using namespace std;

string replace(string name)
{
    string temp = "";
    for (int i = 2; i<name.length(); ++i)
    {
        temp+=name[i];
    }
    return temp;
}
 
int main( int narg, char *argv[] )
{
    LOADED_IMAGE                LoadedImage;
    PUCHAR                      BaseAddress;
    DWORD                       RVAExpDir, VAExpAddress, RVAImpDir, VAImpAddress;
    IMAGE_EXPORT_DIRECTORY *    ExpTable;
    IMAGE_IMPORT_DESCRIPTOR *   ImpTable;
    char *                      sName;
    DWORD                       nNames;
    char *                      pName;
    char **                     pNames;
    DWORD                     i;
 
    if ( narg != 2 ) return 1;
 
    if ( !MapAndLoad( argv[1], NULL, &LoadedImage, TRUE, TRUE ) ) {
        cout<<"Something wrong!"<<endl;
        exit( 1 );
    }
    BaseAddress = LoadedImage.MappedAddress;
    printf( "0x%1x - Base Address\n", (unsigned)BaseAddress ); 
    if ( LoadedImage.FileHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size) {
        RVAExpDir = LoadedImage.FileHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
        cout<<"RVA - "<<(unsigned)RVAExpDir<<endl;

        VAExpAddress = (DWORD)ImageRvaToVa( LoadedImage.FileHeader, BaseAddress, RVAExpDir, NULL );
        cout<<"VA - "<<(unsigned)VAExpAddress<<endl;
 
        ExpTable = (IMAGE_EXPORT_DIRECTORY *)VAExpAddress;
        sName = (char *)ImageRvaToVa( LoadedImage.FileHeader, BaseAddress, ExpTable->Name, NULL );
        cout<<"Name of PEF: "<<sName<<endl;
 
        pNames = (char **)ImageRvaToVa( LoadedImage.FileHeader, BaseAddress, ExpTable->AddressOfNames, NULL );
        nNames = ExpTable->NumberOfNames;
        cout<<"Exported data:"<<endl;
 
        for ( unsigned i = 0; i < nNames; i++ ) {
            pName = (char *)ImageRvaToVa( LoadedImage.FileHeader, BaseAddress, (DWORD)*pNames, NULL );
            cout<<pName<<endl;
            *pNames++;
        }
    } else if (LoadedImage.FileHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size){
        
        RVAImpDir = LoadedImage.FileHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        cout<<"RVA - "<<(unsigned)RVAImpDir<<endl;
 
        VAImpAddress = (DWORD)ImageRvaToVa( LoadedImage.FileHeader, BaseAddress, RVAImpDir, NULL );
        cout<<"VA - "<<(unsigned)VAImpAddress<<endl;
 
        ImpTable = (IMAGE_IMPORT_DESCRIPTOR *)VAImpAddress;
        sName = (char *)ImageRvaToVa( LoadedImage.FileHeader, BaseAddress, ImpTable->Name, NULL );
        cout<<"Name of PEF: "<<sName<<endl;
 
        pNames = (char **)ImageRvaToVa( LoadedImage.FileHeader, BaseAddress, ImpTable->OriginalFirstThunk, NULL );
        nNames = ImpTable->FirstThunk;
        cout<<"Imported data:"<<endl;

        for (unsigned i = 0; i < nNames; i++ ) {
            pName = (char *)ImageRvaToVa( LoadedImage.FileHeader, BaseAddress, (DWORD)*pNames, NULL );
            string temp = replace(pName);
            if (temp != "") cout<<temp<<endl;
            *pNames++;
        }
    }else {
        cout<<"No import and export data\n";
    }
    UnMapAndLoad( &LoadedImage );
    return 0;
}