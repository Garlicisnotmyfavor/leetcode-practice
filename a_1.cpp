#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    int zjn[m*n]={0};
    int all_num;
    scanf("%d", &all_num);
    for(int i=0; i<all_num; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if(zjn[a] == 0 && zjn[b] == 0){
            zjn[b] = b;
            zjn[a] = b;
            continue;
        }
        if(zjn[a] == 0){
            zjn[a] = zjn[b];
            continue;
        }
        if(zjn[b] == 0){
            zjn[b] = zjn[a];
            continue;
        }
        if(zjn[a]!=0 && zjn[b]!=0){
            for(int j=0; j<n*m; j++){
                if(zjn[j] == zjn[a] && j != a){
                    zjn[j] = zjn[b];
                }
            }
            zjn[a] = zjn[b];
        }
    }
    int result[m*n] = {0};
    int ret=0;
    for(int i=0; i<m*n; i++){
        //printf("%d ", zjn[i]);
        if(result[zjn[i]] == 0){
            result[zjn[i]]++;
            ret++;
        }else{
            result[zjn[i]]++;
        }
    } 
    printf("%d", ret+result[0]-1);
}