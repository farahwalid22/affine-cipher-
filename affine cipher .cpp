#include <iostream>
#include <string> // string variables
#include <cctype> // to upper
using namespace std;

string affine_encryption(string &Encrypted_message,int &a,int &b,int &c,string &ciphered);
string affine_decryption(string &Decrypted_message,int &a_2,int &b_2,int &c_2,string &ciphered_2);



int main()
{
//    Variables of encryption
    int a=0, b=0,c=0 ;
    string ciphered;
    string Encrypted_message;

//    Variables of decryption
    int a_2=0, b_2=0,c_2=0 ;
    string ciphered_2 =" ";
    string Decrypted_message;

    int operation_num ;


    cout << "please choose:  1) Encryption  2)Decryption " << endl;
    cin >> operation_num;

//  check if operation is in range or not
    if (1>operation_num or operation_num > 2 or operation_num == 0)
    {
        while (1>operation_num or operation_num > 2)
        {   cout << "Try Again\nplease choose:  1) Encryption  2)Decryption " << endl;
            cin >> operation_num;
        }
    }


//  when user choose 1) encryption
    if (operation_num ==1)
    {
        cout << "please enter coefficients of encrypted equation a,b,c " << endl;
        cin >> a >> b >> c;

//      check conditions of coefficients
        if ((a * c) % 26 != 1)
        {
            while ((a * c) % 26 != 1)
            {
                cout << "please try again \n( (a * c) mod 26 ) not equal 1\n enter coefficients of encryption equation a,b,c " << endl;
                cin >> a >> b >> c;
            }

        }


        if ((a * c) % 26 == 1)
        {
            cout << "please enter your message " << endl;
            cin.ignore();
            getline(cin, Encrypted_message);


//          check all characters are alphabetic characters
            for (int k = 0 ; k < Encrypted_message.length() ; k++ )
            {

                while (isalpha(Encrypted_message[k])== 0 and  Encrypted_message[k] != ' ' )
                {
                    cout << "please enter alphabetic message only  " << endl;
                    cout << "Try Again\nplease enter Encrypted message " << endl;
                    cin.ignore();
                    getline(cin, Encrypted_message);
                }
            }

//          convert encrypted message to upper case
            for (char & k : Encrypted_message)
            {
                k = toupper(k);
            }

            cout << "the ciphered message  :" << "\n" << affine_encryption(Encrypted_message, a, b, c, ciphered) << endl;
        }
    }


//  when user choose 2) decryption
    else
    {
        cout << "please enter coefficients of decrypted equation a,b,c " << endl;
        cin >> a_2 >> b_2 >> c_2;


//      check conditions of coefficients
        if ((a_2 * c_2) % 26 != 1)
        {
            while ((a_2 * c_2) % 26 != 1)
            {
                cout <<"please try again \n( (a * c) mod 26 ) not equal 1\nenter coefficients of decrypted equation a,b,c " << endl;
                cin >> a_2 >> b_2 >> c_2;
            }
        }


        if ((a_2 * c_2) % 26 == 1)
        {
            cout <<"please enter your message " << endl;
            cin.ignore();
            getline(cin, Decrypted_message);


//          check all characters are alphabetic characters
            for (int k = 0 ; k < Decrypted_message.length() ; k++ )
            {

                while (isalpha(Decrypted_message[k])== 0 and  Decrypted_message[k] != ' ' )
                {
                    cout << "please enter alphabetic message only  " << endl;
                    cout << "Try Again\nplease enter Decrypted message " << endl;
                    cin.ignore();
                    getline(cin, Decrypted_message);
                }
            }


//          convert decrypted message to upper case
            for (char & k : Decrypted_message)
            {
                k = toupper(k);
            }


            cout << "the original message  :"<< "\n" <<affine_decryption(Decrypted_message, a_2, b_2, c_2, ciphered_2) << endl;
        }
    }
    return 0;

}

string affine_encryption(string &Encrypted_message,int &a,int &b,int &c,string &ciphered)
{
//  loop on the statement
    for(char i : Encrypted_message)
    {
//      check char is letter or not
        if(i != ' ')
        {

            ciphered += char((((a * ( i - 'A' ) )+ b ) % 26 ) + 'A' ) ;

        }

//      append  spaces to ciphered statement
        else
            ciphered  += i;
    }

    return ciphered;
}

string affine_decryption(string &Decrypted_message,int &a_2,int &b_2,int &c_2,string &ciphered_2)
{
    for(char j : Decrypted_message)
    {
//      check char is letter or not

        if(j != ' ')
        {
            int x = ( c_2 * ((j - 65) - b_2)) % 26;

//          check when x is -ve bec % cannot apply on negative numbers
            if (x < 0)
            {
                x += 26;
                x += 65;        // to get the right ascii code of letter after convert
                ciphered_2 += char(x);
            }

            else
            {
                x += 65;        // to get the right ascii code of letter after convert
                ciphered_2 += char(x);

            }
        }

//      append spaces to ciphered statement
        else
        {
            ciphered_2 += j;
        }

    }

    return ciphered_2;

}