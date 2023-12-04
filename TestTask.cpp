#include "TestTask.h"
//Дефолтный	 конструктор класса
String::String(): data_(nullptr), size_(0){
	
}
//Конструкторы класса с определенными параметрами
String::String(const char* str): data_(nullptr), size_(0) {
	size_ = StrLen(str);
	data_ = new char[size_ + 1];
	CopyStr(data_, str);
}
String::String(String&& other) noexcept  : data_(other.data_), size_(other.size_){
	other.size_ = 0;
	other.data_ = nullptr;
}
String::String(const String& other) : size_(other.size_){

	data_ = new char[size_ + 1];
	CopyStr(data_,other.data_);
}
 String::~String() {
 	delete[] data_;
 }
//Внутренние операторы присваивания и сложения
String& String::operator=(String&& other) noexcept {
	if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.size_ = 0;
		}
}

String& String::operator=(const String& other)  {
	if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = new char[size_ + 1];
        CopyStr(data_, other.data_);
    }
    return *this;
}
String& String::operator=(const char* str){
delete[] data_;
size_ = StrLen(str);
data_ = new char[size_ + 1];
CopyStr(data_, str);
return *this;
 }
 //Операторы прибавь-присвой 
 String& String::operator+=(const char* str)
 {
 int size2_ = StrLen(str);
 char* newData_ = new char[size_ + size2_+1];
 newData_ = AddStr(newData_, str);
 delete[] data_;
 data_ = newData_;
 return *this;
 }
 
 String& String::operator+=(const String& str)
 {
 	char* newData = new char[size_ + str.GetSize() +1];
 	newData = AddStr(newData,str.GetData());
 	delete[] data_;
 	data_ = newData;
 	return *this;
 	
 	
 }
 //Функции для подчета длины массива символов
 int String::StrLen(const char* str){
 	int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
 }
  int String::StrLen(char* str){
 	int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
 }
 //Функции для копирования массивов символов
 const char* String::CopyStr (char* data_,const char* str){
 	int length = 0;
 	while (str[length] !='\0'){
 		data_[length] = str[length];
 		++length;
	 }
	 return data_;
 }
 const char* String::CopyStr (char* data_,char* str){
 	int length = 0;
 	while (str[length] !='\0'){
 		data_[length] = str[length];
 		++length;
	 }
	 return data_;
 }
//Функция для добавления к сущесвующему массиву символов еще одного.
	char* String::AddStr (char* newData_,const char* str){
 	int length1 = 0;
	int length = 0;
 	while (data_[length] != '\0'){
 		newData_[length] = data_[length];
 		++length;
	 }
 	while (str[length1] !='\0'){
 		newData_[length] = str[length1];
 		++length;
 		++length1;
	 }
	   newData_[length] = '\0';
	 return newData_;
 }
//Геттеры и сеттеры для приватных полей.
char* String::GetData() const{
	return data_;
}
bool String::SetData(char* value){
	data_ = value;
	size_ = StrLen(data_);
	if (data_ == value){	
	
	return true;
}else{
	return false;
}
}
int String::GetSize() const{
	return size_;
}
bool String::SetSize(int value){
	size_ = value;
	if (size_==value){
		return true;
	}else{
		return false;
	}
}

//Внешние операторы сложения.
String operator+(const String& lhs, const String& rhs) {
  String result = "";
  result.SetSize(lhs.GetSize() + rhs.GetSize());
  result.SetData(new char[result.GetSize()+1]);
  result.CopyStr(result.GetData(),lhs.GetData());
  result.SetData(result.AddStr(result.GetData(),rhs.GetData()));
  char* newData = result.GetData();
  newData[result.GetSize()+1] = '\0';
  result.SetData(newData);
  return result;
}
String operator+(const char* lhs, const String& rhs) {
  String result = "";
  int sizeLhs = result.StrLen(lhs);
  result.SetSize(sizeLhs + rhs.GetSize());
  result.SetData(new char[result.GetSize()+1]);
  result.CopyStr(result.GetData(),lhs);
  result.SetData(result.AddStr(result.GetData(),rhs.GetData()));
  return result;
}
String operator+(const String&  lhs, const char* rhs) {
  String result = "";
  int sizeRhs = result.StrLen(rhs);
  result.SetSize(sizeRhs + lhs.GetSize());
  result.SetData(new char[result.GetSize()+1]);
  result.CopyStr(result.GetData(),lhs.GetData());
  result.SetData(result.AddStr(result.GetData(),rhs));
  return result;
}
//Присвоение символов к верхнему регистру для сравнения строк без учета регистра 
char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}
//Сравнение строк без учета регистра -1 если первая строка выше второй и аналогично 1 если ниже
int compareIgnoreCase(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (toUpper(*str1) < toUpper(*str2)) {
            return -1;
        } else if (toUpper(*str1) > toUpper(*str2)) {
            return 1;
        }
        ++str1;
        ++str2;
    }
    return 0;
}
//Обмен мест строк в массиве 
void swap(String& str1, String& str2) {
    char* tempData = str1.GetData();
    str1.SetData(str2.GetData());
    str2.SetData(tempData);
}
//Ну и сам метод который перебирает массив строк.
String* sortStrings(String inputWords[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (compareIgnoreCase(inputWords[i].GetData(), inputWords[j].GetData()) < 0) {
                swap(inputWords[i], inputWords[j]);
            }
        }
    }
    return inputWords;
}
//Метод для вывода в консоль результата.
void Print(String inputWords[], int size){
	for (int i =0; i<size; ++i){
		char* tempData = inputWords[i].GetData();
		 for (int j = 0; tempData[j] != '\0'; ++j) {
        putchar(tempData[j]);
    }
    putchar('\n');
	}
}
int main(int argc, char** argv) {
	String words[7];
	words[0].SetData("Algoritm");
	words[1].SetData("Background");
	words[2].SetData("Z-Index");
	words[3].SetData("Java");
	words[4].SetData("List");
	words[5].SetData("Volt-mer");
	words[6].SetData("Akord");	
	sortStrings(words,7);
	Print(words,7);
	return 0;
}

