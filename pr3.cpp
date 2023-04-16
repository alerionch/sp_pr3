#include <iostream>
using namespace std;
int main()
{
    int n = 8; 
    int matrix[n][n]; 
    int i = 0;
    while (i < n) 
    {
        for (int j = 0; j < n; j++)
        {
           asm(
    "mov %[i], %%eax\n\t" 
    "mov %[j], %%ebx\n\t" 
    "mov %[n], %%ecx\n\t" 
    "subl $1, %%ecx\n\t"   
    "cmp %%eax, %%ebx\n\t" 
    "je set_one\n\t"       
    "addl %%eax, %%ebx\n\t"
    "cmp %%ecx, %%ebx\n\t" 
    "jne set_zero\n\t"     
    "set_one:\n\t"         
    "movl $1, %[val]\n\t"   
    "jmp end_set\n\t"     
    "set_zero:\n\t"        
    "movl $0, %[val]\n\t"   
    "end_set:\n\t"     
    :[val]"=m"(matrix[i][j]) 
    :[i]"m"(i), [j]"m"(j), [n]"m"(n) 
    :"%eax","%ebx","%ecx"
    );
	cout << matrix[i][j] << " " ;
    }
    cout << endl ;
    i++;
    }
    return 0;
}
