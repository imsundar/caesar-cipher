// console app1.cpp : Defines the entry point for the console application.

//Caesar cipher - 
//Implement a Caesar cipher, both encoding and decoding. The key is an integer from 1 to 25. This cipher 
//rotates the letters of the alphabet (A to Z). The encoding replaces each letter with the 1st to 25th next letter in the alphabet (wrapping Z to A). 
//So key 2 encrypts "HI" to "JK", but key 20 encrypts "HI" to "BC". This simple "monoalphabetic substitution 
//cipher" provides almost no security, because an attacker who has the encoded message can either use frequency analysis to guess the key, 
//or just try all 25 keys.

//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector <char> message;  // global variable to store coded message; 

// Keyselection function, based on user selected cipher mode sets the key for the process of encoding message. 

vector<char> keyselection (vector<char> vcipherkey, int ciphermode)
{
    
    vector<char> key; 

    for(int x=ciphermode ; x<vcipherkey.size();  x++)
    {	
        key.push_back(vcipherkey[x]); 
    }
    int control = 0;
    for(int x=0; x<ciphermode; x++)
    {
        key.push_back(vcipherkey[control]);         
        control++;
    }
    key.push_back(' '); //to include space in the key. 
    return key;
    
}    

//cipher function - performs the main role of encoding message based on key received. 
void cipher(vector<char> input, int ciphermode)
{
    
   string cipherkey = "abcdefghijklmnopqrstuvwxyz";
   vector <char> vcipherkey;    

	  for(int x=0; x<cipherkey.length(); x++)
	  {
		  vcipherkey.push_back(cipherkey[x]);
	  }

    static const vector<char> key = keyselection(vcipherkey, ciphermode);
    vcipherkey.push_back(' ');
  
    int flag;
    for( int x=0; x<input.size() ; x++ )
    {
       flag=0;
        for (int y=0; y<vcipherkey.size() ; y++)
        {
           
            if(flag==0)
            {
              if(vcipherkey[y]==input[x])
                {
                  message.push_back(key[y]);
                  flag=1;
                }
            }
	}

     }

         cout<<"\nEncrypted Message is " << endl;
         for(int z=0; z<message.size() ; z++)
         {
             cout<< message[z] ;
         }
         cout<<endl;
}

void decipher(vector<char> message, int ciphermode)
{
   string cipherkey = "abcdefghijklmnopqrstuvwxyz";
   vector <char>decodedmessage; 
   vector <char> vcipherkey;    

	  for(int x=0; x<cipherkey.length(); x++)
	  {
		  vcipherkey.push_back(cipherkey[x]);
	  }

    static const vector<char> key = keyselection(vcipherkey, ciphermode);
    vcipherkey.push_back(' ');
  
    int flag;
    for( int x=0; x<message.size() ; x++ )
    {
       flag=0;
        for (int y=0; y<key.size() ; y++)
        {
           
            if(flag==0)
            {
              if(key[y]==message[x])
                {
                  decodedmessage.push_back(vcipherkey[y]);
                  flag=1;
                }
            }
		 }

	 }

         cout<<"\nDecoded Message is " << endl;
         for(int z=0; z<decodedmessage.size() ; z++)
         {
             cout<< decodedmessage[z] ;
         }
         cout<<endl;
}

     


int main()
{
    int ciphermode;
	int decodechoice; 
	string userinput; 
    vector <char> input; 
    cout<<"***Cipher Messages***" << endl;
    cout<<"Enter cipher key : " << endl ;
    cin >> ciphermode;
    cout<<"Enter the message : " << endl;
    cin.ignore();
    getline(cin,userinput);
	
	for(int x=0; x<userinput.length(); x++)
	{
		input.push_back(userinput[x]);
	}

    cipher(input, ciphermode);
	cout<<endl; 
	
	cout<<"to decode back press 1 : " << endl; 
	cin>>decodechoice; 	
	if(decodechoice==1)
	decipher(message, ciphermode); 

	system("pause");
	
    return 0;
}
