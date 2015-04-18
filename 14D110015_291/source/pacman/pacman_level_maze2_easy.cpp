#include<simplecpp>
#include<cstdlib> //To include rand()
#include<ctime> //To include srand()

namespace medium_maze{
class Ghost{//Creating a Ghost class for the ghosts.
    public:
    Circle g;

    Ghost(int p,int q,int r) //p,q,r denotes RGB values and used to give colour to the ghost
    {
        g.init(500,385,20);
        g.setColor(COLOR(p,q,r));
        g.setFill(true);

    }

void ghostKill(Circle c1){ //function of pacman killing ghost called after power dot is eaten.
    c1.setColor(COLOR("red"));
    c1.setFill(true);

    if ((abs(c1.getX()-g.getX())<=40) && (abs(c1.getY()-g.getY())<=40))
        {
            g.moveTo(500,385);
            wait(1);}
            //The ghost when captured by pacman moves  to its initial position and waits some time before starting again.
        }


bool ghostCapture(Circle c1,int &life,int &shift)
    {
        if(//Using distance formula
            sqrt(pow((c1.getX()-g.getX()),2) + pow((c1.getY()-g.getY()),2))<=40
            )
            {if(life==0) {return true;}
             else if (life>0){life=life-1;shift=1;wait(2);return false;}}
        else {return false;}
        //The ghost when captures the pacman returns true.
        //Capture is detected by checking the distance between their centers.
    }


void ghostMove(int x,int &fx,int &fy) //function of moving the ghost.
    {
        if(x==0){fx=-1;fy=0;}
        else if(x==1){fx=0;fy=-1;}
        else if(x==2){fx=1;fy=0;}
        else if(x==3){fx=0;fy=1;}
        //Corresponding to the value generated,move in a predegined direction.
    }

void ghost_random(int &fx,int &fy)
    {//Function to generate random movement of ghost.
        int x;
now:
            if(//first line
                    (g.getX()==30 && g.getY()==30) || (g.getX()==170 && g.getY()==30) || (g.getX()==500 && g.getY()==30) ||
                    (g.getX()==830 && g.getY()==30) || (g.getX()==970 && g.getY()==30) ||

               //last line
               (g.getX()==30 && g.getY()==470)||(g.getX()==170 && g.getY()==470)||(g.getX()==500 && g.getY()==470)||
               (g.getX()==830 && g.getY()==470)||(g.getX()==970 && g.getY()==470)

               //second line
               ||(g.getX()==30 && g.getY()==115)||(g.getX()==170 && g.getY()==115) ||(g.getX()==830 && g.getY()==115) ||
               (g.getX()==970 && g.getY()==115) ||

               //second last
               (g.getX()==30 && g.getY()==385)||(g.getX()==170 && g.getY()==385)||(g.getX()==830 && g.getY()==385)||
               (g.getX()==970 && g.getY()==385))

               {
               x=rand()%4;
               ghostMove(x,fx,fy);
               //Random number generated and moved in corresponding predefined direction.

               }

            //left constraint i.e. points where moving left is restricted.
            if((g.getX()==255 && g.getY()==207.5)||(g.getX()==255 && g.getY()==292.5)||(g.getX()==830 && g.getY()==165)||
                 (g.getX()==830 && g.getY()==250)||(g.getX()==830 && g.getY()==335))

                 {
                    x=rand()%4;
                    if(x==0){goto now;}
                    else ghostMove(x,fx,fy);
                    //If number corresponding to left movement is generated,
                    //goes to start of function and and asks value again till other value is given.
                }

            //right constraint
            if ((g.getX()==170 && g.getY()==165) ||(g.getX()==170 && g.getY()==250) ||(g.getX()==170 && g.getY()==335)||
                (g.getX()==745 && g.getY()==207.5) ||(g.getX()==745 && g.getY()==292.5))

                {
                    x=rand()%4;
                    if(x==2){goto now;}
                    else ghostMove(x,fx,fy);
                    //If number corresponding to right movement is generated,
                    //goes to start of function and and asks value again till other value is given.
                }

            //upward constraint
            if((g.getX()==500 && g.getY()==385)||(g.getX()==30 && g.getY()==335)||(g.getX()==970 && g.getY()==335)||
                (g.getX()==255 && g.getY()==115)||(g.getX()==745 && g.getY()==115))

                {
                    x=rand()%4;
                    if(x==1){goto now;}
                    else ghostMove(x,fx,fy);
                    //If number corresponding to upward movement is generated,
                    //goes to start of function and and asks value again till other value is given.
                }

            //downward constraint
            if((g.getX()==500 && g.getY()==115)||(g.getX()==30 && g.getY()==165)||(g.getX()==970 && g.getY()==165)||
                (g.getX()==255 && g.getY()==385)||(g.getX()==745 && g.getY()==385))

                {
                    x=rand()%4;
                    if(x==3){goto now;}
                    else ghostMove(x,fx,fy);
                    //If number corresponding to downward movement is generated,
                    //goes to start of function and and asks value again till other value is given.
                }

            if((g.getX()==30 && g.getY()==250) ||(g.getX()==970 && g.getY()==250))

            {
                    x=rand()%4;
                    if(x==1 || x==3){goto now;}
                    else ghostMove(x,fx,fy);
                    //If number corresponding to upward or downward movement is generated,
                    //goes to start of function and and asks value again till other value is given.
            }



            //Outside Border constraints.

            if(g.getY()==470 && fy>0){goto now;}
            else if (g.getY()==30 && fy<0){goto now;}
            else if(g.getX()>=970 && fx>0){goto now;}
            else if(g.getX()==30 && fx<0) {goto now;}


            g.move(fx,fy); //If all constraints are satisfied than only ghost will move.


            //Thru channel for Ghost.

            if (g.getX()<=971 && g.getX()>=969 && g.getY()<=251 && g.getY()>=249 && fx>0){g.moveTo(30,250);}
            else if (g.getX()<=31 && g.getX()>=29 && g.getY()<=251 && g.getY()>=249 && fx<0){g.moveTo(970,250);}

            }


};//End of class Ghost.




void pacMove(char c,int &dx,int &dy) //movement of pacman
    {
        switch(c){
            case 'a':dx=-1;dy=0; break;
            case 'w':dx=0;dy=-1; break;
            case 'd':dx=1;dy=0; break;
            case 's':dx=0;dy=1; break;
                 }

    }



int medium_maze(){

std::srand(time(0)); //srand to ensure same random number is not generated each time.

int dx=0,dy=0,fx=0,fy=0,fx1=0,fy1=0,fx2=0,fy2=0;  //corresponding to movement of pacman and ghosts.
int kill_1=1,kill_2=1,kill_3=1,kill_4=1;  //correspondint to special dots.
int counter_1=0,counter_2=0,counter_3=0,counter_4=0; //correspondint to special dots.
int life=2,shift=0; //Lives of pacman
int score=0; //Corresponding to score

char dd,c='d'; //c is the input taken.dd for movement constraints.

//initCanvas("PACMAN",1000,530);
Rectangle b(500,250,980,480);//border

Rectangle blocks[23];
blocks[0].init(100,72.5,100,45);

/*Rectangle b2(100,72.5,100,45);//top left*/
blocks[1].init(100,140,100,10);//top left 1 down
blocks[2].init(80,207.5,140,45);//top left 2 down
blocks[3].init(80,292.5,140,45);//bottom left 2 up
blocks[4].init(100,360,100,10);//bottom left 1 up
blocks[5].init(100,427.5,100,45);//bottom left

blocks[6].init(335,72.5,290,45);//top left 1 right
blocks[7].init(665,72.5,290,45);//top right 1 left

blocks[8].init(900,72.5,100,45);//top right
blocks[9].init(900,140,100,10);//top right 1 down
blocks[10].init(920,207.5,140,45);//top right 2 down
blocks[11].init(920,292.5,140,45);//bottom right 2 up
blocks[13].init(900,360,100,10);//bottom right 1 up
blocks[14].init(900,427.5,100,45);//bottom right


blocks[15].init(335,427.5,290,45);//bottom left 1 right
blocks[16].init(665,427.5,290,45);//bottom right 1 left

blocks[17].init(212.5,250,45,230);//middle 1 left
blocks[18].init(787.5,250,45,230);//middle 1 right

blocks[19].init(500,250,450,45);//middle

blocks[20].init(500,161.25,450,52.5);//middle 1 up
blocks[21].init(500,338.75,450,52.5);//middle 1 down

b.setColor(COLOR("black"));
b.setFill(true);

for(int i=0;i<=21;i++){
blocks[i].setColor(COLOR("blue"));
}

//Pac-man
Circle c1;
c1.init(500,30,20);
c1.setColor(COLOR("yellow"));
c1.setFill(true);

//cherry
Circle cherry(500,292.5,6);
cherry.setColor(COLOR("red"));
cherry.setFill(true);

//Arrays defined for pac-dots.
Circle h1[25],h2[25],h3_1[15],h3_2[15],h4[15],h5_1[15],h5_2[15],h6[15],h7_1[15],h7_2[15],h8[25],h9[25];
    //Number of dots in each array.
      //20     20      5         5       15     5        5         15    5        5       20      20

//pacdots

for(int i=0;i<=970;i=i+47)
    {h1[i/47].init(30+i,30,3);
     h1[i/47].setColor(COLOR("yellow"));
     h1[i/47].setFill(true);
    }


for (int i=0;i<=970;i+=47)
    {h2[i/47].init(30+i,115,3);
     h2[i/47].setColor(COLOR("yellow"));
     h2[i/47].setFill(true);
    }

for (int i=0;i<=170;i+=35)
    {h3_1[i/35].init(30+i,165,3);
     h3_1[i/35].setColor(COLOR("yellow"));
     h3_1[i/35].setFill(true);
    }

for (int i=0;i<=140;i+=35)
    {h3_2[i/35].init(830+i,165,3);
     h3_2[i/35].setColor(COLOR("yellow"));
     h3_2[i/35].setFill(true);
    }

for (int i=0;i<=490;i+=35)
    {h4[i/35].init(255+i,207.5,3);
     h4[i/35].setColor(COLOR("yellow"));
     h4[i/35].setFill(true);
    }

for (int i=0;i<=170;i+=35)
    {h5_1[i/35].init(30+i,250,3);
     h5_1[i/35].setColor(COLOR("yellow"));
     h5_1[i/35].setFill(true);
    }

for (int i=0;i<=140;i+=35)
    {h5_2[i/35].init(830+i,250,3);
     h5_2[i/35].setColor(COLOR("yellow"));
     h5_2[i/35].setFill(true);
    }

for (int i=0;i<=490;i+=35)
    {h6[i/35].init(255+i,292.5,3);
     h6[i/35].setColor(COLOR("yellow"));
     h6[i/35].setFill(true);
    }
    h6[7].hide(); //Hiding dot corresponding to cherry position.


for (int i=0;i<=170;i+=35)
    {h7_1[i/35].init(30+i,335,3);
     h7_1[i/35].setColor(COLOR("yellow"));
     h7_1[i/35].setFill(true);
    }

for (int i=0;i<=140;i+=35)
    {h7_2[i/35].init(830+i,335,3);
     h7_2[i/35].setColor(COLOR("yellow"));
     h7_2[i/35].setFill(true);
    }

for (int i=0;i<=970;i+=47)
    {h8[i/47].init(30+i,385,3);
     h8[i/47].setColor(COLOR("yellow"));
     h8[i/47].setFill(true);
    }

for (int i=0;i<=970;i+=47)
    {h9[i/47].init(30+i,470,3);
     h9[i/47].setColor(COLOR("yellow"));
     h9[i/47].setFill(true);
    }

//Special dots
h1[0].setColor(COLOR("white"));
h1[0].setFill(true);

h1[20].setColor(COLOR("white"));
h1[20].setFill(true);

h9[0].setColor(COLOR("white"));
h9[0].setFill(true);

h9[20].setColor(COLOR("white"));
h9[20].setFill(true);


wait(1);


//Three objects of class Ghost called

Ghost g1(255,0,0);
Ghost g2(0,255,0);
Ghost g3(255,0,127);

XEvent event; //Using XEvent class.

while(true)
{

            if(checkEvent(event) && keyPressEvent(event))
            {
            //char c;
            dd=c; //initializing dd to c
            c = charFromEvent(event); //Recording character pressed in c
            //c=dd;
            pacMove(c,dx,dy); //function calling
            }

            wait(0.01);

            g1.ghost_random(fx,fy);//calling random movement function for object g1

            g2.ghost_random(fx1,fy1);

            g3.ghost_random(fx2,fy2);

            //Border constraints on pacman.

            if(c1.getY()>=470 && dy>0){c=dd;pacMove(c,dx,dy);}
            else if (c1.getY()<=30 && dy<0){c=dd;pacMove(c,dx,dy);}
            else if (c1.getX()>=970 && dx>0){c=dd;pacMove(c,dx,dy);}
            else if (c1.getX()<=30 && dx<0){c=dd;pacMove(c,dx,dy);}


            //Constraints of Junctions.(To avoid passing thru and bouncing back)

            if((c1.getY()>=29 && c1.getY()<=31 && c1.getX()<=31 && c1.getX()>=29 && dy<0) ||
            (c1.getY()>=29 && c1.getY()<=31 && c1.getX()<=31 && c1.getX()>=29 && dx<0)){continue;}

            else if(c1.getY()>=29 && c1.getY()<=31 && c1.getX()<=171 && c1.getX()>=169 && dy<0){continue;}

            else if(c1.getY()>=114 && c1.getY()<=116 && c1.getX()<=31 && c1.getX()>=29 && dx<0){continue;}

            else if((c1.getY()>=164 && c1.getY()<=166 && c1.getX()<=31 && c1.getX()>=29 && dy>0) ||
            (c1.getY()>=164 && c1.getY()<=166 && c1.getX()<=31 && c1.getX()>=29 && dx<0)){continue;}

            else if(c1.getY()>=164 && c1.getY()<=166 && c1.getX()<=171 && c1.getX()>=169 && dx>0){continue;}

            else if(c1.getY()>=249 && c1.getY()<=251 && c1.getX()<=171 && c1.getX()>=169 && dx>0){continue;}

            else if(c1.getY()>=334 && c1.getY()<=336 && c1.getX()<=171 && c1.getX()>=169 && dx>0){continue;}

            else if(c1.getY()>=469 && c1.getY()<=471 && c1.getX()<=171 && c1.getX()>=169 && dy>0){continue;}

            else if(c1.getY()>=384 && c1.getY()<=386 && c1.getX()<=31 && c1.getX()>=29 && dx<0){continue;}

            else if((c1.getY()>=469 && c1.getY()<=471 && c1.getX()<=31 && c1.getX()>=29 && dx<0) ||
            (c1.getY()>=469 && c1.getY()<=471 && c1.getX()<=31 && c1.getX()>=29 && dy>0)){continue;}

            else if((c1.getY()>=334 && c1.getY()<=336 && c1.getX()<=31 && c1.getX()>=29 && dy<0) ||
            (c1.getY()>=334 && c1.getY()<=336 && c1.getX()<=31 && c1.getX()>=29 && dx<0)){continue;}

          /* Hidden to activate thru channel
            else if((c1.getY()>=249 && c1.getY()<=251 && c1.getX()<=31 && c1.getX()>=29 && dx<0) ||
            (c1.getY()>=249 && c1.getY()<=251 && c1.getX()<=31 && c1.getX()>=29 && dy>0) ||
            (c1.getY()>=249 && c1.getY()<=251 && c1.getX()<=31 && c1.getX()>=29 && dy<0)){continue;} */

            else if((c1.getY()>=114 && c1.getY()<=116 && c1.getX()<=256 && c1.getX()>=254 && dy<0)){continue;}

            else if(c1.getY()>=206.5 && c1.getY()<=208.5 && c1.getX()<=256 && c1.getX()>=254 && dx<0){continue;}

            else if(c1.getY()>=291.5 && c1.getY()<=293.5 && c1.getX()<=256 && c1.getX()>=254 && dx<0){continue;}

            else if(c1.getY()>=384 && c1.getY()<=386 && c1.getX()<=256 && c1.getX()>=254 && dy>0){continue;}

            else if(c1.getY()>=29 && c1.getY()<=31 && c1.getX()<=501 && c1.getX()>=499 && dy<0){continue;}

            else if(c1.getY()>=114 && c1.getY()<=116 && c1.getX()<=501 && c1.getX()>=499 && dy>0){continue;}

            else if(c1.getY()>=384 && c1.getY()<=386 && c1.getX()<=501 && c1.getX()>=499 && dy<0){continue;}

            else if(c1.getY()>=469 && c1.getY()<=471 && c1.getX()<=501 && c1.getX()>=499 && dy>0){continue;}

            else if(c1.getY()>=114 && c1.getY()<=116 && c1.getX()<=746 && c1.getX()>=744 && dy<0){continue;}

            else if(c1.getY()>=206.5 && c1.getY()<=208.5 && c1.getX()<=746 && c1.getX()>=745 && dx>0){continue;}

            else if(c1.getY()>=291.5 && c1.getY()<=293.5 && c1.getX()<=746 && c1.getX()>=745 && dx>0){continue;}

            else if(c1.getY()>=384 && c1.getY()<=386 && c1.getX()<=746 && c1.getX()>=744 && dy>0){continue;}

            else if(c1.getY()>=29 && c1.getY()<=31 && c1.getX()<=831 && c1.getX()>=829 && dy<0){continue;}

            else if(c1.getY()>=164 && c1.getY()<=166 && c1.getX()<=831 && c1.getX()>=829 && dx<0){continue;}

            else if(c1.getY()>=249 && c1.getY()<=251 && c1.getX()<=831 && c1.getX()>=829 && dx<0){continue;}

            else if(c1.getY()>=334 && c1.getY()<=336 && c1.getX()<=831 && c1.getX()>=829 && dx<0){continue;}

            else if(c1.getY()>=469 && c1.getY()<=471 && c1.getX()<=831 && c1.getX()>=829 && dy>0){continue;}

            else if((c1.getY()>=29 && c1.getY()<=31 && c1.getX()<=971 && c1.getX()>=969 && dy<0) ||
            (c1.getY()>=29 && c1.getY()<=31 && c1.getX()<=971 && c1.getX()>=969 && dx>0)){continue;}

            else if((c1.getY()>=114 && c1.getY()<=116 && c1.getX()<=971 && c1.getX()>=969 && dx>0)){continue;}

            else if((c1.getY()>=164 && c1.getY()<=166 && c1.getX()<=971 && c1.getX()>=969 && dy>0) ||
            (c1.getY()>=164 && c1.getY()<=166 && c1.getX()<=971 && c1.getX()>=969 && dx>0)){continue;}

        /*  Hidden to activate thru channel
            else if((c1.getY()>=249 && c1.getY()<=251 && c1.getX()<=971 && c1.getX()>=969 && dx>0) ||
            (c1.getY()>=249 && c1.getY()<=251 && c1.getX()<=971 && c1.getX()>=969 && dy>0) ||
            (c1.getY()>=249 && c1.getY()<=251 && c1.getX()<=971 && c1.getX()>=969 && dy<0)){continue;} */

            else if(c1.getY()>=334 && c1.getY()<=336 && c1.getX()<=971 && c1.getX()>=969 && dx>0){continue;}

            else if(c1.getY()>=384 && c1.getY()<=385 && c1.getX()<=971 && c1.getX()>=969 && dx>0){continue;}

            else if((c1.getY()>=469 && c1.getY()<=471 && c1.getX()<=971 && c1.getX()>=969 && dx>0) ||
            (c1.getY()>=469 && c1.getY()<=471 && c1.getX()<=971 && c1.getX()>=969 && dy>0)){continue;}


            //Constraints on pacman to not pass thru blocks.

            //b2
            if(c1.getY()>=29 && c1.getY()<=31 && dy>0 && 31<c1.getX() && c1.getX()<169){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()>=114 && c1.getY()<=116 && dy<0 && 31<c1.getX() && c1.getX()<169){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=29 && c1.getX()<=31 && dx>0 && 31<c1.getY() && c1.getY()<114){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=169 && c1.getX()<=171 && dx<0 && 31<c1.getY() && c1.getY()<114){c=dd;pacMove(c,dx,dy);}

            //b3
            if(c1.getY()>=114 && c1.getY()<=116 && dy>0 && 31<c1.getX() && c1.getX()<169){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()>=164 && c1.getY()<=166 && dy<0 && 31<c1.getX() && c1.getX()<169){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=29 && c1.getX()<=31 && dx>0 && 116<c1.getY() && c1.getY()<164){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=169 && c1.getX()<=171 && dx<0 && 116<c1.getY() && c1.getY()<164){c=dd;pacMove(c,dx,dy);}

            //b4
            if(c1.getY()>=164 && c1.getY()<=166 && dy>0 && 11<c1.getX() && c1.getX()<169){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()>=249 && c1.getY()<=251 && dy<0 && 11<c1.getX() && c1.getX()<169){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=9 && c1.getX()<=11 && dx>0 && 166<c1.getY() && c1.getY()<249){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=169 && c1.getX()<=171 && dx<0 && 166<c1.getY() && c1.getY()<249){c=dd;pacMove(c,dx,dy);}

            //b5
            if(c1.getY()>=249 && c1.getY()<=251 && dy>0 && 11<c1.getX() && c1.getX()<169){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=336 && c1.getY()>=334 && dy<0 && 11<c1.getX() && c1.getX()<169){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=9 && c1.getX()<=11 && dx>0 && 251<c1.getY() && c1.getY()<334){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=171 && c1.getX()>=169 && dx<0 && 251<c1.getY() && c1.getY()<334){c=dd;pacMove(c,dx,dy);}

            //b6
            if(c1.getY()>=334 && c1.getY()<=336 && dy>0 && 31<c1.getX() && c1.getX()<169){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=386 && c1.getY()>=384 && dy<0 && 31<c1.getX() && c1.getX()<169){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=29 && c1.getX()<=31 && dx>0 && 336<c1.getY() && c1.getY()<384){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=171 && c1.getX()>=169 && dx<0 && 336<c1.getY() && c1.getY()<384){c=dd;pacMove(c,dx,dy);}

            //b7
            if(c1.getY()>=384 && c1.getY()<=386  && dy>0 && 31<c1.getX() && c1.getX()<169){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=471 && c1.getY()>=469 && dy<0 && 31<c1.getX() && c1.getX()<169){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=29 && c1.getX()<=31 && dx>0 && 386<c1.getY() && c1.getY()<469){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=171 && c1.getX()>=169 && dx<0 && 386<c1.getY() && c1.getY()<469){c=dd;pacMove(c,dx,dy);}

            //b8
            if(c1.getY()>=29 && c1.getY()<=31 && dy>0 && 171<c1.getX() && c1.getX()<499){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()>=114 && c1.getY()<=116 && dy<0 && 171<c1.getX() && c1.getX()<499){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=169 && c1.getX()<=171 && dx>0 && 31<c1.getY() && c1.getY()<114){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=499 && c1.getX()<=501 && dx<0 && 31<c1.getY() && c1.getY()<114){c=dd;pacMove(c,dx,dy);}

            //b9
            if(c1.getY()>=29 && c1.getY()<=31 && dy>0 && 501<c1.getX() && c1.getX()<829){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=116 && c1.getY()>=114 && dy<0 && 501<c1.getX() && c1.getX()<829){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=499 && c1.getX()<=501 && dx>0 && 31<c1.getY() && c1.getY()<114){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=831 && c1.getX()>=829 && dx<0 && 31<c1.getY() && c1.getY()<114){c=dd;pacMove(c,dx,dy);}

            //b10
            if(c1.getY()>=29 && c1.getY()<=31 && dy>0 && 831<c1.getX() && c1.getX()<969){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=116 && c1.getY()>=114 && dy<0 && 831<c1.getX() && c1.getX()<969){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=829 && c1.getX()<=831 && dx>0 && 31<c1.getY() && c1.getY()<114){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=971 && c1.getX()>=969 && dx<0 && 31<c1.getY() && c1.getY()<114){c=dd;pacMove(c,dx,dy);}

            //b11
            if(c1.getY()>=114 && c1.getY()<=116 && dy>0 && 831<c1.getX() && c1.getX()<969){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=166 && c1.getY()>=164 && dy<0 && 831<c1.getX() && c1.getX()<969){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=829 && c1.getX()<=831 && dx>0 && 116<c1.getY() && c1.getY()<164){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=971 && c1.getX()>=969 && dx<0 && 116<c1.getY() && c1.getY()<164){c=dd;pacMove(c,dx,dy);}

            //b12
            if(c1.getY()>=164 && c1.getY()<=166 && dy>0 && 831<c1.getX() && c1.getX()<989){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=251 && c1.getY()>=249 && dy<0 && 831<c1.getX() && c1.getX()<989){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=829 && c1.getX()<=831 && dx>0 && 166<c1.getY() && c1.getY()<249){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=991 && c1.getX()>=989 && dx<0 && 166<c1.getY() && c1.getY()<249){c=dd;pacMove(c,dx,dy);}

            //b13
            if(c1.getY()>=249 && c1.getY()<=251 && dy>0 && 831<c1.getX() && c1.getX()<989){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=336 && c1.getY()>=334 && dy<0 && 831<c1.getX() && c1.getX()<989){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=829 && c1.getX()<=831 && dx>0 && 251<c1.getY() && c1.getY()<334){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=991 && c1.getX()>=989 && dx<0 && 251<c1.getY() && c1.getY()<334){c=dd;pacMove(c,dx,dy);}

            //b14
            if(c1.getY()>=334 && c1.getY()<=336 && dy>0 && 831<c1.getX() && c1.getX()<969){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=386 && c1.getY()>=384 && dy<0 && 831<c1.getX() && c1.getX()<969){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=829 && c1.getX()<=831 && dx>0 && 336<c1.getY() && c1.getY()<384){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=971 && c1.getX()>=969 && dx<0 && 336<c1.getY() && c1.getY()<384){c=dd;pacMove(c,dx,dy);}

            //b15
            if(c1.getY()>=384 && c1.getY()<=386 && dy>0 && 831<c1.getX() && c1.getX()<969){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=471 && c1.getY()>=469 && dy<0 && 831<c1.getX() && c1.getX()<969){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=829 && c1.getX()<=831 && dx>0 && 386<c1.getY() && c1.getY()<469){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=971 && c1.getX()>=969 && dx<0 && 386<c1.getY() && c1.getY()<469){c=dd;pacMove(c,dx,dy);}

            //b16
            if(c1.getY()>=384 && c1.getY()<=386 && dy>0 && 171<c1.getX() && c1.getX()<499){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=471 && c1.getY()>=469 && dy<0 && 171<c1.getX() && c1.getX()<499){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=169 && c1.getX()<=171 && dx>0 && 386<c1.getY() && c1.getY()<469){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=501 && c1.getX()>=499 && dx<0 && 386<c1.getY() && c1.getY()<469){c=dd;pacMove(c,dx,dy);}

            //b17
            if(c1.getY()>=384 && c1.getY()<=386 && dy>0 && 501<c1.getX() && c1.getX()<829){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=471 && c1.getY()>=469 && dy<0 && 501<c1.getX() && c1.getX()<829){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=499 && c1.getX()<=501 && dx>0 && 386<c1.getY() && c1.getY()<469){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=831 && c1.getX()>=829 && dx<0 && 386<c1.getY() && c1.getY()<469){c=dd;pacMove(c,dx,dy);}

            //b18
            if(c1.getY()>=114 && c1.getY()<=116 && dy>0 && 171<c1.getX() && c1.getX()<254){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=386 && c1.getY()>=384 && dy<0 && 171<c1.getX() && c1.getX()<254){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=169 && c1.getX()<=171 && dx>0 && 116<c1.getY() && c1.getY()<384){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=256 && c1.getX()>=254 && dx<0 && 116<c1.getY() && c1.getY()<384){c=dd;pacMove(c,dx,dy);}

            //b19
            if(c1.getY()>=114 && c1.getY()<=116 && dy>0 && 746<c1.getX() && c1.getX()<829){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=386 && c1.getY()>=384 && dy<0 && 746<c1.getX() && c1.getX()<829){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=744 && c1.getX()<=746 && dx>0 && 116<c1.getY() && c1.getY()<384){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=831 && c1.getX()>=829 && dx<0 && 116<c1.getY() && c1.getY()<384){c=dd;pacMove(c,dx,dy);}

            //b20
            if(c1.getY()<=208.5 && c1.getY()>=206.5 && dy>0 && 256<c1.getX() && c1.getX()<744){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=293.5 && c1.getY()>=291.5 && dy<0 && 256<c1.getX() && c1.getX()<744){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=254 && c1.getX()<=256 && dx>0 && 208.5<c1.getY() && c1.getY()<291.5){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=746 && c1.getX()>=744 && dx<0 && 208.5<c1.getY() && c1.getY()<291.5){c=dd;pacMove(c,dx,dy);}

            //b21
            if(c1.getY()>=114 && c1.getY()<=116 && dy>0 && 256<c1.getX() && c1.getX()<744){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=208.5 && c1.getY()>=206.5 && dy<0 && 256<c1.getX() && c1.getX()<744){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=254 && c1.getX()<=256 && dx>0 && 116<c1.getY() && c1.getY()<206.5){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=746 && c1.getX()>=744 && dx<0 && 116<c1.getY() && c1.getY()<206.5){c=dd;pacMove(c,dx,dy);}

            //b22
            if(c1.getY()>=291.5 && c1.getY()<=293.5 && dy>0 && 256<c1.getX() && c1.getX()<744){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=386 && c1.getY()>=384 && dy<0 && 256<c1.getX() && c1.getX()<744){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=254 && c1.getX()<=256 && dx>0 && 293.5<c1.getY() && c1.getY()<384){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=746 && c1.getX()>=744 && dx<0 && 293.5<c1.getY() && c1.getY()<384){c=dd;pacMove(c,dx,dy);}

            //thru channel for pacman
            if (c1.getX()<=971 && c1.getX()>=969 && c1.getY()<=251 && c1.getY()>=249 && dx>0){c1.moveTo(30,250);continue;}
            else if (c1.getX()<=31 && c1.getX()>=29 && c1.getY()<=251 && c1.getY()>=249 && dx<0){c1.moveTo(970,250);continue;}

            c1.move(dx,dy);//pacman moved by fx,fy defined earlier.


            //pacdots eating
            for(int i=0;i<=970;i+=47)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=31 && c1.getY()>=29) {h1[i/47].hide();}
                    }
            for(int i=0;i<=970;i+=47)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=116 && c1.getY()>=114) {h2[i/47].hide();}
                    }
            for(int i=0;i<=170;i+=35)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=166 && c1.getY()>=164) {h3_1[i/35].hide();}
                    }
            for(int i=0;i<=140;i+=35)
                {if (c1.getX()<=831+i && c1.getX()>=829+i && c1.getY()<=166 && c1.getY()>=164) {h3_2[i/35].hide();}
                    }
            for(int i=0;i<=490;i+=35)
                {if (c1.getX()<=256+i && c1.getX()>=254+i && c1.getY()<=208.5 && c1.getY()>=206.5) {h4[i/35].hide();}
                    }
            for(int i=0;i<=170;i+=35)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=251 && c1.getY()>=249) {h5_1[i/35].hide();}
                    }
            for(int i=0;i<=140;i+=35)
                {if (c1.getX()<=831+i && c1.getX()>=829+i && c1.getY()<=251 && c1.getY()>=249) {h5_2[i/35].hide();}
                    }
            for(int i=0;i<=490;i+=35)
                {if (c1.getX()<=256+i && c1.getX()>=254+i && c1.getY()<=293.5 && c1.getY()>=291.5) {h6[i/35].hide();}
                    }
            for(int i=0;i<=170;i+=35)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=336 && c1.getY()>=334) {h7_1[i/35].hide();}
                    }
            for(int i=0;i<=140;i+=35)
                {if (c1.getX()<=831+i && c1.getX()>=829+i && c1.getY()<=336 && c1.getY()>=334) {h7_2[i/35].hide();}
                    }
            for(int i=0;i<=970;i+=47)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=386 && c1.getY()>=384) {h8[i/47].hide();}
                    }
            for(int i=0;i<=970;i+=47)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=471 && c1.getY()>=469) {h9[i/47].hide();}
                    }

            //cherry eating
            if(c1.getX()<=501 && c1.getX()>=499 && c1.getY()>=291.5 && c1.getY()<=293.5){cherry.hide();}


          //score
            for(int i=0;i<=970;i+=47)
                {if (c1.getX()==30+i && c1.getY()==30+i) {score+=5;continue;}
                    }

            for(int i=0;i<=970;i+=47)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=116 && c1.getY()>=114) {h2[i/47].hide(); score+=5;}
                    }

            for(int i=0;i<=170;i+=35)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=166 && c1.getY()>=164) {h3_1[i/35].hide(); score+=5;}
                    }

            for(int i=0;i<=140;i+=35)
                {if (c1.getX()<=831+i && c1.getX()>=829+i && c1.getY()<=166 && c1.getY()>=164) {h3_2[i/35].hide(); score+=5;}
                    }

            for(int i=0;i<=490;i+=35)
                {if (c1.getX()<=256+i && c1.getX()>=254+i && c1.getY()<=208.5 && c1.getY()>=206.5) {h4[i/35].hide(); score+=5;}
                    }

            for(int i=0;i<=170;i+=35)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=251 && c1.getY()>=249) {h5_1[i/35].hide(); score+=5;}
                    }

            for(int i=0;i<=140;i+=35)
                {if (c1.getX()<=831+i && c1.getX()>=829+i && c1.getY()<=251 && c1.getY()>=249) {h5_2[i/35].hide(); score+=5;}
                    }

            for(int i=0;i<=490;i+=35)
                {if (c1.getX()<=256+i && c1.getX()>=254+i && c1.getY()<=293.5 && c1.getY()>=291.5) {h6[i/35].hide(); score+=5;}
                    }

            for(int i=0;i<=170;i+=35)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=336 && c1.getY()>=334) {h7_1[i/35].hide(); score+=5;}
                    }

            for(int i=0;i<=140;i+=35)
                {if (c1.getX()<=831+i && c1.getX()>=829+i && c1.getY()<=336 && c1.getY()>=334) {h7_2[i/35].hide(); score+=5;}
                    }

            for(int i=0;i<=970;i+=47)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=386 && c1.getY()>=384) {h8[i/47].hide(); score+=5;}
                    }

            for(int i=0;i<=970;i+=47)
                {if (c1.getX()<=31+i && c1.getX()>=29+i && c1.getY()<=471 && c1.getY()>=469) {h9[i/47].hide(); score+=5;}
                    }


            //Special Dots

      //top left corner
             if (c1.getX()<=31 && c1.getX()>=29 && c1.getY()<=31 && c1.getY()>=29)
                {h1[0].hide();counter_1=1;}

      //top right corner
             if (c1.getX()<=971 && c1.getX()>=969 && c1.getY()<=31 && c1.getY()>=29)
                {h1[20].hide();counter_2=1;}

      //bottom left corner
             if (c1.getX()<=31 && c1.getX()>=29 && c1.getY()<=471 && c1.getY()>=469)
                {h9[0].hide();counter_3=1;}

      //bottom right corner
             if (c1.getX()<=971 && c1.getX()>=969 && c1.getY()<=471 && c1.getY()>=469)
                {h9[20].hide();counter_4=1;}


           //Time constraint of how long we possess the power.
            if (counter_1==1 && kill_1>0 && kill_1<=500 )

              {
                 kill_1+=1;

                 g1.ghostKill(c1);
                 g2.ghostKill(c1);
                 g3.ghostKill(c1);
              }

          else if(counter_2==1 && kill_2>0 && kill_2<=500)

              {
                 kill_2+=1;

                 g1.ghostKill(c1);
                 g2.ghostKill(c1);
                 g3.ghostKill(c1);
              }


          else if(counter_3==1 && kill_2>0 && kill_3<=500 )

              {
                 kill_3+=1;

                 g1.ghostKill(c1);
                 g2.ghostKill(c1);
                 g3.ghostKill(c1);
              }

          else if(counter_4==1 && kill_4>0 && kill_4<=500 )

              {
                 kill_4+=1;

                 g1.ghostKill(c1);
                 g2.ghostKill(c1);
                 g3.ghostKill(c1);
              }

          //For lifes.That is,Pacman has only 2 lives and after that game ends.
          else {if (g1.ghostCapture(c1,life,shift)){break;}
                    else{
                        if (shift==1)
                        {shift=0;c1.moveTo(30,30);}
                        }

                if (g2.ghostCapture(c1,life,shift)){break;}
                    else{
                        if (shift==1)
                        {shift=0;c1.moveTo(30,30);}
                        }

                if (g3.ghostCapture(c1,life,shift)){break;}
                    else{
                        if (shift==1)
                        {shift=0;c1.moveTo(30,30);}
                        }
               }

        wait(0.005);


}
//will print score
Text t1(450,500,"SCORE-");
Text t2(530,500,score);

wait(5);
}
}
