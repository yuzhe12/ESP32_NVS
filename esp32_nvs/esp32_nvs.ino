#include "PreferencesHelper.h"
const char *NVS_Name = "myNVS";//创建一个nvs键空间名字为myNVS
String num = "aaa"; //创建要存入nvs的字符变量
int Num_Int = 666; //创建要存入nvs的整数变量
void setup() {
  Serial.begin(115200);//打开串口，并设置波特率为115200
  NVSINIT(NVS_Name);//初始化穿创建一个以myNVS为名字的nvs键空间
  Input_NVSString(NVS_Name, "MyString", num);//将"num"字符串存入创建的nvs空间，并取键名为MyString
  Input_NVSInt(NVS_Name, "MyINT", Num_Int);//将Num_Int变量的数值存入创建的nvs空间，并取键名为MyINT
  
}

void loop() {
  String myname = Output_NVSString(NVS_Name, "MyString");//读取nvs空间中键名为"MyString"的内容
  int myVariable = Output_NVSInt(NVS_Name, "MyINT");//读取nvs空间中键名为"MyINT"的内容
  // 打印对应数值
  Serial.println("My name from NVS: " + myname);
  Serial.println("My variable from NVS: " + String(myVariable));
  // 延时一段时间
  delay(1000);
}
