 #include<simplecpp>
 #include<cstdlib>
 #include<ctime>
 #include<iostream>
 #include "easy_maze_only.h"
 #include "pacman_level_maze2_easy.h"

 #define KEY_UP 72
 #define KEY_DOWN 80
 #define KEY_LEFT 75
 #define KEY_RIGHT 77


namespace help{
    void help(){//when you click on help

    Rectangle b(500,250,980,480);//border
    b.setColor(COLOR("black"));
    b.setFill(true);

    Text t(500,200,"Use w,a,s,d to navigate Pacman around the maze.");
    Text t1(500,225,"complete the level by eating all the dots.");
    Text t2(500,250,"Eating cherry will earn you more points.");
    Text t3(500,275,"Avoid the monsters,if they catch you you will lose a life.");
    Text t4(500,300,"Eat the big power dots, and the Pacman will oscillate between red and blue,");
    Text t5(500,325,"meaning that you can now eat the ghosts for a short time.");

    t.setColor(COLOR("blue"));
    t1.setColor(COLOR("blue"));
    t2.setColor(COLOR("blue"));
    t3.setColor(COLOR("blue"));
    t4.setColor(COLOR("blue"));
    t5.setColor(COLOR("blue"));

    Rectangle b1(500,400,175,50);
    b1.setColor(COLOR("blue"));

    Text t6(500,400,"BACK");
    t6.setColor(COLOR("blue"));

    bool back_check=false;



        bool check;

            do{
                check=true;

                int userclick=getClick();
                int x=userclick/65536, y=userclick%65536;


                if(x>412.5 && x<587.5 && y>375 && y<425){
                   check=false; back_check=true;
                   }


                } while(check);
    }
}





namespace about{//When you click on about
    void about(){

        Rectangle b(500,250,980,480);//border
        b.setColor(COLOR("black"));
        b.setFill(true);



    Text t(500,125,"This game is developed as our CS101 project,");
    Text t1(500,150,"Made by our team members -");
    Text t2(500,175,"Aditya Agarwal");
    Text t3(500,200,"Rishabh Jain");
    Text t4(500,225,"Rishabh Dosi");
    Text t5(500,250,"Harshita Motwani");
    Text t7(500,300,"Mentored by -");
    Text t8(500,325,"Mohit Singh");

    t.setColor(COLOR("blue"));
    t1.setColor(COLOR("blue"));
    t2.setColor(COLOR("blue"));
    t3.setColor(COLOR("blue"));
    t4.setColor(COLOR("blue"));
    t5.setColor(COLOR("blue"));
    t7.setColor(COLOR("red"));
    t8.setColor(COLOR("red"));

    Rectangle b1(500,400,175,50);
    b1.setColor(COLOR("blue"));

    Text t6(500,400,"BACK");
    t6.setColor(COLOR("blue"));


    bool back_check=false;



            bool check;

                do{
                    check=true;

                    int userclick=getClick();
                    int x=userclick/65536, y=userclick%65536;


                    if(x>412.5 && x<587.5 && y>375 && y<425){
                       check=false; back_check=true;
                       }


                    } while(check);

    }
}

namespace mazes{//For the two mazes
int mazes(){

Rectangle b(500,250,980,480);//border
b.setColor(COLOR("black"));
b.setFill(true);

Rectangle b1(500,150,175,50);
b1.setColor(COLOR("blue"));
Rectangle b3(500,310,175,50);
b3.setColor(COLOR("blue"));
Rectangle b2(500,215,175,50);
b2.setColor(COLOR("blue"));


Text t(500,50,"PACMAN");
t.setColor(COLOR("blue"));
Text t1(500,150,"EASY LEVEL");
t1.setColor(COLOR("blue"));
Text t2(500,215,"HARD LEVEL");
t2.setColor(COLOR("blue"));
Text t3(500,310,"BACK");
t3.setColor(COLOR("blue"));
wait(1);

bool maze_1=false;
bool maze_2=false;
bool back1=false;
{


bool check;

do{
    check=true;

    int userclick=getClick();
    int x=userclick/65536, y=userclick%65536;

    if(x>412.5 && x<587.5 && y>125 && y<175){
       check=false; maze_1=true;
    }

    if(x>412.5 && x<587.5 && y>285 && y<335){
      check=false; back1=true;
    }

    if(x>412.5 && x<587.5 && y>190 && y<240){
       check=false; maze_2=true;
    }

}while(check);
}

if(maze_1==true){easy_maze::easy_maze();return 0;}
if(maze_2==true){medium_maze::medium_maze();return 0;}

wait(0.05);

}
}

int loop(){

        bool play_check=false;
        bool exit_check=false;
        bool help_check=false;
        bool about_check=false;


        bool check;

        do{
            check=true;

            int userclick=getClick();
            int x=userclick/65536, y=userclick%65536;

            if(x>412.5 && x<587.5 && y>125 && y<175){
               check=false; play_check=true;
               }
            if(x>412.5 && x<587.5 && y>320 && y<370){
               check=false; exit_check=true;
               }
            if(x>412.5 && x<587.5 && y>190 && y<240){
               check=false; help_check=true;
               }
            if(x>412.5 && x<587.5 && y>255 && y<305){
               check=false; about_check=true;
               }


        } while(check);


        if(play_check==true){mazes::mazes();play_check=false;}
        if(exit_check==true){wait(0.5);exit_check=false;return -1;}
        if(help_check==true){help::help();help_check=false;}
        if(about_check==true){about::about();about_check=false;}
        return 0;

}

main_program{

    initCanvas("PACMAN",1000,530);
     Rectangle b(500,250,980,480);//border
        b.setColor(COLOR("black"));
        b.setFill(true);

        Rectangle b1(500,150,175,50);
        b1.setColor(COLOR("blue"));
        Rectangle b2(500,215,175,50);
        b2.setColor(COLOR("blue"));
        Rectangle b3(500,280,175,50);
        b3.setColor(COLOR("blue"));
        Rectangle b4(500,345,175,50);
        b4.setColor(COLOR("blue"));


        Text t(500,50,"PACMAN");
        t.setColor(COLOR("blue"));
        Text t1(500,150,"PLAY");
        t1.setColor(COLOR("blue"));
        Text t2(500,215,"HELP");
        t2.setColor(COLOR("blue"));
        Text t3(500,280,"ABOUT");
        t3.setColor(COLOR("blue"));
        Text t4(500,345,"EXIT");
        t4.setColor(COLOR("blue"));

    while(1)
      {
        if(loop()<0)break;
      }

    wait(0.5);
}


