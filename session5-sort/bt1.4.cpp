#include <stdio.h>
#include <string.h>

const int M = 10;//chiều dài tối đa của một từ

void swap(char a[][M], int i, int j)
{
    char temp[M];
    strcpy(temp, a[i]);
    strcpy(a[i], a[j]);
    strcpy(a[j], temp);
}

void interchange_sort(char a[][M], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[i], a[j])>0)
            {
                swap(a, i, j);
            }
        }
    }
}

//đếm số từ trong câu
int count_words(char s[]){
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if(s[i]==' ') ++count;
    }
    return ++count;
}

//tách một câu thành các từ
void split(char s[], char words[][M]) {
    char delim[] = " "; // Ký tự phân cách là khoảng trắng
    char *token;
    int i = 0;

    token = strtok(s, delim);    
    while (token != NULL) {
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, delim);
    }
}

//nối n từ thành câu
void join(char words[][M], int n, char s[]){
    int i;
    for (i = 0; i < n - 1; i++)
    {
        strcat(s, words[i]);
        strcat(s, " ");
    }
    strcat(s, words[i]);
}

int main()
{
    char s[] = "toi di hoc suot tuan";
    char result[100];//chứa kết quả
    int n = count_words(s);//đếm số từ trong s
    char words[n][M];//khai báo array chứa các từ
    split(s, words);//tách câu s thành các từ
    interchange_sort(words, n);//sắp thứ tự
    join(words, n, result);//nối n từ thành câu result
    printf(result);
    
    return 0;
}