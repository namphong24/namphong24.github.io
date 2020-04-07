#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhap_mang(int **arr, int a, int b, int c)
{
    // Nhập từng phần tử
    int x = 1;
    // 0 0 0...0
    for (int i = 0; i < a; i++)
    {
        for (int j = i; j < b; j++)
        {
            // Nhập dữ liệu vào dòng i
            
                arr[i][j] = x;
                x ++;    
            
            // 1 2 3...a  arr[0][b]
            // Nếu j = b - 1, nhập dữ liệu vào cột b - 1
            if (j == b  - 1)
            { 
                for (int k = i + 1; k < a; k++)
                {
                    
                    arr[k][b - 1] = x ;
                    x ++;
                }    
                //     1 2 3...b     arr[0][j]  j->b
                //             b+1   arr[1][b]
                //      ...
                //             b+a-1 arr[a][b] 
                // Kết thúc, bớt đi 1 cột.
            } 
        }
        b = b - 1;
        // Sau đó nhập dữ liệu vào dòng a-1;
        if( i != b - 1 && x <= c) break;
        else
        {
            for (int n = b - 1; n >= i;n -- )
            {
                arr[a - 1][n] = x;
                x ++;  
            }
        }
            // Kết thúc, bớt đi 1 dòng
            a = a - 1;
            // Nhập dữ liệu vào cột i
            for (int m = a - 1; m > i;m -- )
            {
                arr[m][i] = x;
                x++;
            }
        
    }
}
void sap_xep(int **arr, int a, int b)
{
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    // Sắp xếp dãy số theo hình xoắn ốc.
    // 1. Nhập x, y.
    // 2. Nhập từng phần tử
    // 3. Sắp xếp thành hình xoắn ốc.
    // 4. In ra.
    int a,b,c;
    c = a*b;
    int **arr;
     scanf("%d %d",&a,&b);
    // Tạo mảng 2 chiều arr[a][b]
    arr = (int **) malloc (a * sizeof (int *));
    for (int i = 0; i < a; i++)
    {
        arr[i] = (int *) malloc (b * sizeof (int));
    }
    nhap_mang(arr,a,b,c); 
    sap_xep(arr,a,b);
    return 0;
}
