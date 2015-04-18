 #include<simplecpp>
 #include<cstdlib>
 #include<ctime>
 #include<iostream>

 #define KEY_UP 72
 #define KEY_DOWN 80
 #define KEY_LEFT 75
 #define KEY_RIGHT 77


namespace easy_maze{

class Ghost{
    public:
    Circle g;

    Ghost(int p,int q,int r)
    {
        g.init(500,480,10);
        g.setColor(COLOR(p,q,r));
        g.setFill(true);
    }

void ghostKill(Circle c1)
        { //function of pacman killing ghost called after power dot is eaten.
    c1.setColor(COLOR("red"));
    c1.setFill(true);

    if (sqrt(pow((c1.getX()-g.getX()),2) + pow((c1.getY()-g.getY()),2))<=20)
      {
        g.moveTo(500,480);
        wait(1);
      }
        //The ghost when captured by pacman moves  to its initial position and waits some time before starting again.
         }
bool ghostCapture(Circle c1,int &life,int &shift)
    {
        if(//Using distance formula
            sqrt(pow((c1.getX()-g.getX()),2) + pow((c1.getY()-g.getY()),2))<=20
          )
            {if(life==0) {return true;}
             else if (life>0){life=life-1;shift=1;wait(2);return false;}}
        else {return false;}
        //The ghost when captures the pacman returns true.
        //Capture is detected by checking the distance between their centers.
    }


void ghostMove(int x,int &fx,int &fy)
{
    if(x==0){fx=-1;fy=0;}
    else if(x==1){fx=0;fy=-1;}
    else if(x==2){fx=1;fy=0;}
    else if(x==3){fx=0;fy=1;}
}

void ghost_random(int &fx,int &fy){

        int x;

now:   if((g.getX()==20 && g.getY()==20) || (g.getX()==500 && g.getY()==20) || (g.getX()==980 && g.getY()==20) ||
               (g.getX()==20 && g.getY()==250) || (g.getX()==500 && g.getY()==250) || (g.getX()==980 && g.getY()==250)||
               (g.getX()==20 && g.getY()==480) || (g.getX()==500 && g.getY()==480) || (g.getX()==980 && g.getY()==480))

               {

               x=rand()%4;
               ghostMove(x,fx,fy);
               }

         if(g.getY()==480 && fy>0){goto now;}
            else if (g.getY()==20 && fy<0){goto now;}
            else if(g.getX()>=980 && fx>0){goto now;}
            else if(g.getX()==20 && fx<0) {goto now;}

          g.move(fx,fy);

          if (g.getX()<=981 && g.getX()>=979 && g.getY()<=251 && g.getY()>=249 && fx>0){g.moveTo(20,250);}
             else if (g.getX()<=21 && g.getX()>=19 && g.getY()<=251 && g.getY()>=249 && fx<0){g.moveTo(980,250);}

 }
 };
void pacMove(char c,int &dx,int &dy)
{

    switch(c){//both w,a,s,d and arrow keys can be used to move the pacman.
              //In Ubuntu,arrow keys do not seem to word so use w,a,s,d.
            case 75:dx=-1;dy=0; break;
            case 72:dx=0;dy=-1; break;
            case 77:dx=1;dy=0; break;
            case 80:dx=0;dy=1; break;

            case 'a':dx=-1;dy=0; break;
            case 'w':dx=0;dy=-1; break;
            case 'd':dx=1;dy=0; break;
            case 's':dx=0;dy=1; break;

        }

}

void easy_maze(){


std::srand(time(0));
int dx=0,dy=0,fx=0,fy=0,fx1=0,fy1=0;
char dd,c='d';
int counter=0;
int kill=1;
int shift=0;
int life=2;

//Write your code here
//initCanvas("PACMAN",1000,500);
Rectangle r(500,250,980,480);
r.setColor(COLOR("black"));
r.setFill(true);

Rectangle r4(260,135,460,210);
r4.setColor(COLOR("blue"));

Rectangle r1(740,135,460,210);
r1.setColor(COLOR("blue"));

Rectangle r2(260,365,460,210);
r2.setColor(COLOR("blue"));

Rectangle r3(740,365,460,210);
r3.setColor(COLOR("blue"));

Circle c1(500,20,10);
c1.setColor(COLOR("yellow"));
c1.setFill(true);

Circle h1[25],h2[25],h3[25],v1[25],v2[25],v3[25];

for(int i=0;i<=960;i=i+40)
    {h1[i/40].init(20+i,20,3);
     h1[i/40].setColor(COLOR("yellow"));
     h1[i/40].setFill(true);
    }

for (int i=0;i<=960;i+=40)
    {h2[i/40].init(20+i,250,3);
     h2[i/40].setColor(COLOR("yellow"));
     h2[i/40].setFill(true);
    }
    //power dot


for (int i=0;i<=960;i+=40)
    {h3[i/40].init(20+i,480,3);
     h3[i/40].setColor(COLOR("yellow"));
     h3[i/40].setFill(true);
    }

for (int i=0;i<=460;i+=46)
    {v1[i/46].init(20,20+i,3);
     v1[i/46].setColor(COLOR("yellow"));
     v1[i/46].setFill(true);
    }

for (int i=0;i<=460;i+=46)
    {v2[i/46].init(500,20+i,3);
     v2[i/46].setColor(COLOR("yellow"));
     v2[i/46].setFill(true);
    }

for (int i=0;i<=460;i+=46)
    {v3[i/46].init(980,20+i,3);
     v3[i/46].setColor(COLOR("yellow"));
     v3[i/46].setFill(true);
    }


Circle pd(500,250,6);
pd.setColor(COLOR("white"));
pd.setFill(true);

wait(0.1);

Ghost g1(255,0,0);
Ghost g2(0,255,0);


XEvent event;



while(true)
{


            if(checkEvent(event) && keyPressEvent(event))
            {
            //char c;
            dd=c;
            c = charFromEvent(event);
            //c=dd;
            pacMove(c,dx,dy);
            }

            wait(0.02);

            g1.ghost_random(fx,fy);

            g2.ghost_random(fx1,fy1);


            if(c1.getY()>=480 && dy>0){c=dd;pacMove(c,dx,dy);}
            else if (c1.getY()<=20 && dy<0){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=980 && dx>0){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=20 && dx<0) {c=dd;pacMove(c,dx,dy);}







         if((c1.getY()>=19 && c1.getY()<=21 && c1.getX()<=21 && c1.getX()>=19 && dy<0) ||
             (c1.getY()>=19 && c1.getY()<=21 && c1.getX()<=21 && c1.getX()>=19 && dx<0)){continue;}

         else if((c1.getY()>=19 && c1.getY()<=21 && c1.getX()<=981 && c1.getX()>=979 && dy<0) ||
             (c1.getY()>=19 && c1.getY()<=21 && c1.getX()<=981 && c1.getX()>=979 && dx>0)){continue;}

         else if((c1.getY()>=19 && c1.getY()<=21 && c1.getX()<=21 && c1.getX()>=19 && dy<0) ||
             (c1.getY()>=19 && c1.getY()<=21 && c1.getX()<=21 && c1.getX()>=19 && dx<0)){continue;}

         else if((c1.getY()>=479 && c1.getY()<=481 && c1.getX()<=21 && c1.getX()>=19 && dy>0) ||
             (c1.getY()>=479 && c1.getY()<=481 && c1.getX()<=21 && c1.getX()>=19 && dx<0)){continue;}

         else if((c1.getY()>=479 && c1.getY()<=481 && c1.getX()<=981 && c1.getX()>=979 && dy<0) ||
             (c1.getY()>=479 && c1.getY()<=481 && c1.getX()<=981 && c1.getX()>=979 && dx<0)){continue;}

         else if((c1.getY()>=249 && c1.getY()<=251 && c1.getX()<=21 && c1.getX()>=19 && dx<0)){continue;}

         else if((c1.getY()>=19 && c1.getY()<=21 && c1.getX()<=551 && c1.getX()>=549 && dy<0)){continue;}

         else if((c1.getY()>=249 && c1.getY()<=251 && c1.getX()<=981 && c1.getX()>=979 && dx>0)){continue;}

         else if((c1.getY()>=479 && c1.getY()<=481 && c1.getX()<=551 && c1.getX()>=549 && dy>0)){continue;}





            //top left
            if(c1.getY()>=19 && c1.getY()<=21 && dy>0 && 21<c1.getX() && c1.getX()<499){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=249 && c1.getY()<=251 && dy<0 && 21<c1.getX() && c1.getX()<499){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=19 && c1.getX()<=21 && dx>0 && 21<c1.getY() && c1.getY()<249){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=499 && c1.getX()<=501 && dx<0 && 21<c1.getY() && c1.getY()<249){c=dd;pacMove(c,dx,dy);}

            //top right
            if(c1.getY()>=19 && c1.getY()<=21 && dy>0 && 501<c1.getX() && c1.getX()<979){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=249 && c1.getY()<=251  && dy<0 && 501<c1.getX() && c1.getX()<979){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=499 && c1.getX()<=501 && dx>0 && 21<c1.getY() && c1.getY()<249){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=979 && c1.getX()<=981 && dx<0 && 21<c1.getY() && c1.getY()<249){c=dd;pacMove(c,dx,dy);}

            //bottom left
            if(c1.getY()>=249 && c1.getY()<=251 && dy>0 && 21<c1.getX() && c1.getX()<499){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=479 && c1.getY()<=481 && dy<0 && 21<c1.getX() && c1.getX()<499){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=19 && c1.getX()<=21 && dx>0 && 251<c1.getY() && c1.getY()<479){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=499 && c1.getX()<=501 && dx<0 && 251<c1.getY() && c1.getY()<479){c=dd;pacMove(c,dx,dy);}

            //bottom right
            if(c1.getY()>=249 && c1.getY()<=251 && dy>0 && 501<c1.getX() && c1.getX()<979){c=dd;pacMove(c,dx,dy);}
            else if(c1.getY()<=479 && c1.getY()<=481 && dy<0 && 501<c1.getX() && c1.getX()<979){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()>=499  && c1.getX()<=501 && dx>0 && 251<c1.getY() && c1.getY()<479){c=dd;pacMove(c,dx,dy);}
            else if(c1.getX()<=979 && c1.getX()<=981 && dx<0 && 251<c1.getY() && c1.getY()<479){c=dd;pacMove(c,dx,dy);}

            //Pacdots
            for(int i=0;i<=960;i+=40)
                {if (c1.getX()<=23+i && c1.getX()>=17+i && c1.getY()<=23 && c1.getY()>=17) {h1[i/40].hide();}
                    }

            for(int i=0;i<=960;i+=40)
                {if (c1.getX()<=23+i && c1.getX()>=17+i && c1.getY()<=253 && c1.getY()>=247) {h2[i/40].hide();}
                    }

            for(int i=0;i<=960;i+=40)
                {if (c1.getX()<=23+i && c1.getX()>=17+i && c1.getY()<=483 && c1.getY()>=477) {h3[i/40].hide();}
                    }

            for(int i=0;i<=460;i+=46)
                {if (c1.getX()<=23 && c1.getX()>=17 && c1.getY()<=23+i && c1.getY()>=17+i) {v1[i/46].hide();}
                    }

            for(int i=0;i<=460;i+=46)
                {if (c1.getX()<=503 && c1.getX()>=97 && c1.getY()<=23+i && c1.getY()>=17+i) {v2[i/46].hide();}
                    }

            for(int i=0;i<=460;i+=46)
                {if (c1.getX()<=983 && c1.getX()>=977 && c1.getY()<=23+i && c1.getY()>=17+i) {v3[i/46].hide();}
                    }

            //power dot eating
            if(c1.getX()<=501 && c1.getX()>=499 && c1.getY()<=251 && c1.getY()>=249)
            {
                pd.hide();
                counter=1;
            }

            //Thru Channel
            if (c1.getX()<=981 && c1.getX()>=979 && c1.getY()<=251 && c1.getY()>=249 && dx>0){c1.moveTo(20,250);continue;}
            else if (c1.getX()<=21 && c1.getX()>=19 && c1.getY()<=251 && c1.getY()>=249 && dx<0){c1.moveTo(980,250);continue;}

            if (c1.getX()<=501 && c1.getX()>=499 && c1.getY()<=21 && c1.getY()>=19 && dy<0){c1.moveTo(500,480);continue;}
            else if (c1.getX()<=501 && c1.getX()>=499 && c1.getY()<=481 && c1.getY()>=479 && dy>0){c1.moveTo(500,20);continue;}


            c1.move(dx,dy);

            //power dot time constraint.
            if (counter==1 && kill>0 && kill<=500 )

              {
                 kill+=1;

                 g1.ghostKill(c1);
                 g2.ghostKill(c1);
              }

            else {if (g1.ghostCapture(c1,life,shift)){break;}
                    else{
                        if (shift==1)
                        {shift=0;c1.moveTo(500,20);}
                        }

                if (g2.ghostCapture(c1,life,shift)){break;}
                    else{
                        if (shift==1)
                        {shift=0;c1.moveTo(500,20);}
                        }
                 }

    wait(0.01);
}

wait(3);
}
}
