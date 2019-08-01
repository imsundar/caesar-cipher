#include <iostream>
#include <string>

using namespace std;

string keyselection(string cipherkey, int ciphermode)
{
    int count{0};
    string key;

    for(int x=ciphermode ; x<26;  x++)
    {
        key[count] = cipherkey[x];
        count++;
    }

    int control = 0;
    for(int x=count; x<26; x++)
    {
        key[count] = cipherkey[control];
        count++;
        control++;
    }

    key[count] = ' ';
    return key;
}

void cipher(string input, int ciphermode)
{
    string message ;
    string cipherkey = "abcdefghijklmnopqrstuvwxyz ";
    static const string key = keyselection(cipherkey, ciphermode);

    int flag;
    for( int x=0; x<input.length() ; x++ )
    {
        flag=0;
        for (int y=0; y<cipherkey.length() ; y++)
        {
            if(flag==0)
            {
              if(cipherkey[y]==input[x])
                {

                  message[x] = key[y];
                  flag=1;
                }
            }
		 }

	 }

         cout<<"Encrypted Message is " << endl;
         for(int z=0; z<input.length() ; z++)
         {
             cout<< message[z] ;
         }
         cout<<endl;
}

int main()
{
    int ciphermode;
    string input;
    cout<<"***Cipher Messages***" << endl;
    cout<<"Enter cipher key : " << endl ;
    cin >> ciphermode;
    cout<<"Enter the message : " << endl;
    cin.ignore();
    getline(cin,input);
    cipher(input, ciphermode);

    return 0;
}

