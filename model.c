/*mehmet hafif ARSAY
 * model.c
 * provides the grid (model) 
 * and functions to handle the grid for the game of life
 */

#include "gameoflife.h"
/*glider şeklini oluşturan fonksiyon*/
void initGridWithGlider(){
	int i=0,j=0;
	while(i<M&&j<N){
		grid[i+3][j+4]=1;
		grid[i+4][j+4]=1;
		grid[i+5][j+4]=1;
		grid[i+5][j+3]=1;
		grid[i+4][j+2]=1;
		i=i+10;
		j=j+10;
	}
}	
/*blinker şeklini oluşturan fonksiyon*/
void  initGridWithBlinker(){
	int i=0, j=0;
	while(i<M&&j<N){
		
			grid[i+3][j+4]=1;
			grid[i+4][j+4]=1;
			grid[i+5][j+4]=1;
			i=i+10;
			j=j+10;
	
	}
}
int grid[M][N] = {0}; 	/*M and N are constants defined in gameOfLife.h*/

/*oluşturulan şekilellerin fonksiyonlarını çağırır*/
int initGrid(int initialState){
	if(initialState==1){
		initGridWithBlinker();
	}
	else if(initialState==2){
		initGridWithGlider();
	}
return initialState;
}
/*canlı komşu sayısını bulan fonksiyon*/
int getNumberOfLiveNeighbors(int x, int y){
	int m = 0;
    for (int i = x-1; i <= x+1; i++){
        for(int j = y-1; j <= y+1; j++){
            if (! (i == x&& j ==y) ){
				if(i < M && j < N && i >= 0 && j >= 0){
					if (grid[i][j] == 1){
						m++;    
					}
				}
			}
        }
    }
return m;
}

/*
 * 
-Bir canlı hücrenin bir tane veya hiç komşusu yoksa bu hücre ölür. .
-Bir canlı hücrenin iki veya üç tane komşusu canlı ise bu hücre yaşamaya devam eder. 
-Bir canlı hücrenin üçten daha fazla canlı komşusu varsa bu hücre ölür. 
-Ölü bir hücre tam olarak üç tane canlı komşusu varsa bu hücre canlı olur. 
 */
int updateGrid(){
	int neighbor[M][N]={0};
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			neighbor[i][j]=getNumberOfLiveNeighbors(i, j);
		}
	}
	for(int x=0;x<N;x++){
		for(int y=0;y<M;y++){
			if(neighbor[x][y]<=1){
				grid[x][y]=0;
			}
			else if( (grid[x][y]==1) &&( neighbor[x][y]==2) ||( neighbor[x][y]==3)){
				grid[x][y]=1;
			}
			else if(grid[x][y]==1&&neighbor[x][y]>=3){
				grid[x][y]=0;
			}
			else if(grid[x][y]==0&&neighbor[x][y]==3){
				grid[x][y]=1;
			}
		}
	}
	return 0;
}

