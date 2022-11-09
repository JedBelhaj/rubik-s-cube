#include <stdio.h>
//cube global declaration with r g o b w y being colors and the number is the orientation
//corners have 3 values of orientation being 0 1 2 while edges have either 0 or 1
//top and bottom edged will have orientation value of 0 if the color representing either the white or yellow
//centers is in the right position or 1 if not
//corners will do the same but if the color is on the right it will have a value of 1 and on the left a value of 2
//relative to the contraint of the white side being on the bottom
char cube_corners[8][4]={{'r','g','w','0'},{'g','o','w','0'},{'o','b','w','0'},{'b','r','w','0'},
{'r','g','y','0'},{'g','o','y','0'},{'o','b','y','0'},{'b','r','y','0'}};
char cube_edges[12][3]={{'g','w','0'},{'o','w','0'},{'b','w','0'},{'r','w','0'},{'r','g','0'},{'g','o','0'},{'o','b','0'}
,{'b','r','0'},{'g','y','0'},{'o','y','0'},{'b','y','0'},{'r','y','0'}};


//piece finding function will return the position of the piece relative to the table above
int find_piece(char piece_type, char colors[]){
    int i=0;
    if (piece_type=='e'){
        while(i<12){
            if (cube_edges[i][0]==colors[0] && cube_edges[i][1]==colors[1]){
                return i;
            }
            i++;
        }
    }
    if (piece_type=='c'){
        while(i<8){
            if (cube_corners[i][0]==colors[0] && cube_corners[i][1]==colors[1] && cube_corners[i][2]==colors[2]){
                return i;
            }
            i++;
        }
    }
    return -1;
}


int main(){
    char colors[2]={'r','r'};
    int b=find_piece('e',colors);
    printf("%d\n",b);
    printf("WORKING");
}