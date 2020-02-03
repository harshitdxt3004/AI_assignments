#include<bits/stdc++.h>
using namespace std;
typedef pair<int, vector<vector<int>>> pvi;
int check_column(vector<vector<int>> v){
  int maximum = -1;
  for(int i = 0; i < 8;i++){
    for(int j = 0; j < 8; j++){
      if(v[i][j] == 1){
        maximum = max(j,maximum);
      }
    }
  }
  return maximum+1;
}
bool isSafe(vector<vector<int>> v, int row, int col){
    int i, j;
    for (i = 0; i < col; i++)
        if (v[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (v[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < 8; i++, j--)
        if (v[i][j])
            return false;
    return true;
}
int check_queens(vector<vector<int>> v){
  int count = 0;
  for(int i = 0; i < 8;i++){
    for(int j = 0;j < 8;j++){
      if(v[i][j]) count++;
    }
  }
  return count;
}
void print_board(vector<vector<int>> v){
  for(int i = 0; i < 8;i++){
    for(int j = 0;j < 8;j++){
      cout << v[i][j] ;
    }
    cout << "\n";
  }
  cout << "\n";
}
int main(){
  priority_queue <pvi, vector<pvi>, greater<pvi>> q;
  q.push(make_pair(0, vector<vector <int>>(8, vector<int>(8,0))));
  int count = 0;
  while(!q.empty()){
    vector< vector<int>> v = q.top().second;
    //print_board(v);
    q.pop();
    int number_of_queens = check_queens(v);
    if(number_of_queens==8){
      cout<< ++count << ":\n";
      print_board(v);
    }
    else{
      int already_filled = check_column(v);
      for(int i = 0; i < 8; i++){
        if(isSafe(v, i, already_filled)){
          v[i][already_filled] = 1;
          q.push(make_pair(number_of_queens+1, v));
        }
        v[i][already_filled] = 0;
      }
    }
  }
  return 0;
}
