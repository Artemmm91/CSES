#include <iostream>
#include <string>
using namespace std;
 
bool visited[7][7];
int len = 0;
int numb = 0;
string s;
 
void dfs(int r, int c){
    if((r == 0 || r == 6) && c > 0 && c < 6 && !visited[r][c - 1] && !visited[r][c + 1]) return;
    if((c == 0 || c == 6) && r > 0 && r < 6 && !visited[r - 1][c] && !visited[r + 1][c]) return;
    if(r > 0 && r < 6 && c > 0 && c < 6){
        if(visited[r][c + 1] && visited[r][c - 1] && !visited[r - 1][c] && !visited[r + 1][c]) return;
        if(!visited[r][c + 1] && !visited[r][c - 1] && visited[r - 1][c] && visited[r + 1][c]) return;
    }
    if(r == 6 && c == 0){
        if(len == 48){
            numb++;
        }
        return;
    }
    if(visited[r][c] == true){
        return;
    }
    visited[r][c] = true;
    if(r > 0 && !visited[r - 1][c] && (s[len] == 'U' || s[len] == '?')){
        len += 1;
        dfs(r - 1, c);
        len -= 1;
    }
    if(r < 6 && !visited[r + 1][c] && (s[len] == 'D' || s[len] == '?')){
        len += 1;
        dfs(r + 1, c);
        len -= 1;
    }
    if(c > 0 && !visited[r][c - 1] && (s[len] == 'L' || s[len] == '?')){
        len += 1;
        dfs(r, c - 1);
        len -= 1;
    }
    if(c < 6 && !visited[r][c + 1] && (s[len] == 'R' || s[len] == '?')){
        len += 1;
        dfs(r, c + 1);
        len -= 1;
    }
    visited[r][c] = false;
}
 
 
 
 
int main() {
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            visited[i][j] = false;
        }
    }
    cin >> s;
    dfs(0, 0);
    cout <<numb;
    return 0;
}

// ????????????????????????????????????????????????
