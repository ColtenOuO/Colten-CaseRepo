#include <stdio.h>
#include <string.h>
char buffer[8000001];
int main() {
    FILE *file;
    char* filename[] = { "A.c", "B.c", "C.c", "D.c" };
    int answer[4] = {};

    for(int i=0;i<4;i++) {
        file = fopen(filename[i],"r");
        int ans = 0;
        while( fgets(buffer,8000001,file) != NULL ) {
            int sz = strlen(buffer);
            for(int j=0;j<sz;j++) {
                if( buffer[j] == '[' || buffer[j] == ']' ) ans++;
            }
        }

        answer[i] = ans;
    }

    fclose(file);
    file = fopen("ans.txt","w");
    for(int i=0;i<4;i++) {
        fprintf(file,"%d",answer[i]);
        if( i != 3 ) fprintf(file," ");
    }
    fclose(file);

    return 0;
}