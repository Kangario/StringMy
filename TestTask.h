#include <stdio.h>
class String{
	private:
    char* data_;
    int size_;
	public:
	char* GetData() const;
	bool SetData(char* value);
	int GetSize() const;
	bool SetSize(int value);
	 String();
	 String(const char* str);
	 String(const String& other);
	 String(String&& other) noexcept;
	 String& operator=(const String& other);
	 String& operator=(String&& other) noexcept;
	 ~String();
	 String& operator=(const char* str);
	 String& operator+=(const char* str);
	 String& operator+=(const String& str);
	int StrLen(const char* str);
	int StrLen(char* str);
    const char* CopyStr (char* data_,const char* str);
    const char* CopyStr (char* data_,char* str);
    char* AddStr (char* newData_,const char* str);
   
    
};
String operator+(const String& lhs, const String& rhs);
String operator+(const char* lhs, const String& rhs);
String operator+(const String& lhs, const char* rhs);


String* sortStrings(String inputWords[], int size);
char toUpper(char c);
int compareIgnoreCase(const char* str1, const char* str2);
void swap(String& str1, String& str2);
void Print(String inputWords[], int size);
