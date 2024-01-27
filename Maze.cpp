#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define N 4
#define M 5

class node {
public:
   int x, y;
   int dir;

   node(int i, int j)
   {
       x = i;
       y = j;
       dir = 0;
   }
};


int n = N, m = M;

int fx, fy;
bool visited[N][M];

bool isReachable(int maze[N][M])
{

   int i = 0, j = 0;
  
   stack<node> s;
  
   node temp(i, j);
  
   s.push(temp);

   while (!s.empty()) {

         
       temp = s.top();
       int d = temp.dir;
       i = temp.x, j = temp.y;

       temp.dir++;
       s.pop();
       s.push(temp);

      
       if (i == fx and j == fy) {
           return true;
       }

       if (d == 0) {
           if (i - 1 >= 0 and maze[i - 1][j] and
                                   visited[i - 1][j]) {
               node temp1(i - 1, j);
               visited[i - 1][j] = false;
               s.push(temp1);
           }
       }

       else if (d == 1) {
           if (j - 1 >= 0 and maze[i][j - 1] and
                                   visited[i][j - 1]) {
               node temp1(i, j - 1);
               visited[i][j - 1] = false;
               s.push(temp1);
           }
       }

       else if (d == 2) {
           if (i + 1 < n and maze[i + 1][j] and
                                   visited[i + 1][j]) {
               node temp1(i + 1, j);
               visited[i + 1][j] = false;
               s.push(temp1);
           }
       }

       else if (d == 3) {
           if (j + 1 < m and maze[i][j + 1] and
                                   visited[i][j + 1]) {
               node temp1(i, j + 1);
               visited[i][j + 1] = false;
               s.push(temp1);
           }
       }

  
       else {
           visited[temp.x][temp.y] = true;
           s.pop();
       }
   }


   return false;
}


int main()
{
     
   memset(visited, true, sizeof(visited));
  

   int maze[N][M] = {
       { 1, 0, 1, 1, 1 },
       { 1, 1, 1, 0, 1 },
       { 0, 0, 0, 0, 1 },
       { 1, 1, 1, 0, 1 }
   };

   cout<<"Input\n"<<N<<" "<<M<<"\n"<<endl;
int i,j;
for(i=0;i<N;i++){
for(j=0;j<M;j++){
if(j!=M-1){
cout<<maze[i][j]<<", ";
}
else{
cout<<maze[i][j];
}
}
cout<<endl;
}

   fx = 3;
   fy = 2;

cout<<endl<<fx<<" "<<fy<<"\n";

   if (isReachable(maze)) {
       cout << "\nPath Found" << '\n';
   }
   else
       cout << "\nNo Path Found" << '\n';
      
   return 0;
}
