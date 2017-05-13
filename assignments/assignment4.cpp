#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
using namespace std;

void ascii_to_bin(const char *argv[], int x, unsigned long y);
void bin_to_ascii(const char *argv[], int x, unsigned long y);
int check_dec_number(string);

/**********************************
 *为了让user input 在comman里运行
 *prarmater：argv［］
 *pre－conditions：只可以输入－a －b，不管顺序
＊pro－conditions：none 
 **********************************/ 
void user_input(const char *argv[])
{
  unsigned long Input1 = strlen(argv[2]), Input2 = strlen(argv[4]);
  //验错：argv［1］and argv［3］必须是－a or －b
  //可以使用2D Array去提取每一个位置的字符
  if (argv[1][0] == '-' && argv[1][1] == 'a')//第一个指令执行字符串转换二进制
  {
     cout << "Your first Input1 convert to Binary is: ";
     ascii_to_bin(argv, 2, Input1);
     cout << endl;
  }
  if(argv[1][0] == '-' && argv[1][1] == 'b')//第一个指令执行二进制转换字符串
  {
     cout << "Your first Input1 convert to ASCII Values is: ";
     bin_to_ascii(argv, 2, Input1);
     cout << endl;
  }
  if(argv[3][0] == '-' && argv[3][1] == 'a')//第二个指令执行字符转换二进制
  {
     cout << "Your second Input2 convert to Binary is: ";
     ascii_to_bin(argv, 4, Input2);
     cout << endl;
  }
  if(argv[3][0] == '-' && argv[3][1] == 'b')//第二个指令执行二进制转换字符串
  {
     cout << "Your second Input2 convert to ASCII Values is: ";
     bin_to_ascii(argv, 4, Input2);
     cout << endl;
  }
}


/***********************************
 *将十进制转换成二进制公式（其中用到了recursion)
 *prarmater: x
 **********************************/
void dec_to_bin(int x){
  if (x >= 2)
  {
     dec_to_bin(x / 2);
     cout << x % 2;
  }
  if (x < 2)
     cout << x;
}

/***********************************
 *string 转换成 binary
 *paramater: argv x, y
 ***********************************/
void ascii_to_bin(const char *argv[], int x, unsigned long y)//x：哪一个输入被转换； y：输入的长度
{
  for(int i = 0; i < y; i++)
  {
     cout << "0";
     if (int(argv[x][i] >= 2))
     {
        dec_to_bin(argv[x][i] / 2);
        cout << argv[x][i] % 2;
     }
     if (int(argv[x][i]) < 2)
	cout << argv[x][i];
  }
}

/**************************************
* paramater:str
* pre-conditions: 1s and 0s only.
* post-conditions: the length of Input2 % 8 is equal to 0, and after transfer to decimal have to be 0 < dec < 127.
 ***************************************/
int check_bin_number(string str){
   int check = 1;
   for (int i = 0; i < str.length(); i++) //checking if 1s and 0s only
   { 
      if (str.at(i) != '0' || str.at(i) != '1')
       {
          check = 0;
       }	  
       else
	  check = 1;
   }
   if (str.length() % 8 != 0)
      check = 0;
   else check = 1;
   
   return check;
}

/**************************************
＊将 binary 转换成 ASCII Values
＊parameters：argv x， y
＊pre－conditions：check ＝＝ 1
* pro－conditions：none
**************************************/
void bin_to_ascii(const char *argv[], int x, unsigned long y){
   string str = argv[x];
   int check;
   do {
   check = check_bin_number(str);
    if(check == 1) {
       check = check_dec_number(str);
    	if(check != 1) {
	   cout << "Invlaid input, please re-enter: ";
	   cin >> str;
	} 
	}else {
	   cout << "Invlaid input, please re-enter: ";
	   cin >> str;
    	}
    }while(check == 0);
       
    int j = 0, position = j;
    while (j < str.length()){
        int dec = 0;
	for(int i = 7; i >= 0; i--){
        int number = (int)(str.at(position) - '0');//'0' or 48
	position++;
	dec += pow(2,i) * number;
	}
        j=j+8;
	cout << char(dec);
    }
}

/******************************** 
 ** 检查每一个dec是否在0到127之间
 ** Parameters:x,y
 ** Pre-conditions:dec在0到127之间
 ** Post-conditions:none
*********************************/
int check_dec_number(string str){
   int j = 0, position=0, check = 1;
   while (j < str.length()){
      int dec = 0;
      for(int i = 7; i >= 0; i--){
         int number = (int)(str.at(position) - '0');//'0' or 48
         position++;
         dec += pow(2,i) * number;
      }
      if(dec < 0 || dec > 127){
	 check = 0;
      }
      j=j+8;
   }
   return check;
}

int main(int argc, const char * argv[]){
   if (argc == 1)
   {
      cerr << "No Argument provided.\n";
      exit(0);
   }
   else if (argc != 5)
   {
      cerr << "Missing Options and Arguments.\n";
      exit(1);
   }	       
   else if (argv[1][0] != '-' || argv[3][0] != '-')
   {
      cerr << "Invalid Indication (-a: string to binary; -b: binary to string).\n";
      exit(2);
   }	           
   else if ((argv[1][1] != 'a' && argv[1][1] != 'b') && (argv[3][1] != 'a' && argv[3][1] != 'b'))
   {
      cerr << "Invalid Indication (-a: string to binary; -b: binary to string).\n";
      exit(3);
   }
   else
   {
      user_input(argv);
   }

   return 0;
}




