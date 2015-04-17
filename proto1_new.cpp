#include<simplecpp>

void pacMove(char c,int &dx,int &dy)
{

    switch(c){
            case 'a':dx=-3;dy=0; break;
            case 'w':dx=0;dy=-3; break;
            case 'd':dx=3;dy=0; break;
            case 's':dx=0;dy=3; break;

        }

}

main_program{
int dx=0,dy=0;
//Write your code here
initCanvas("PACMAN",1000,500);
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



Circle c1(500,480,10);
c1.setColor(COLOR("yellow"));
c1.setFill(true);

Circle h1[25],h2[25],h3[25],v1[25],v2[25],v3[25];

for(int i=0;i<=960;i=i+40)
    {h1[i/40].init(20+i,20,3);
     h1[i/40].setColor(COLOR("blue"));
     h1[i/40].setFill(true);
    }

for (int i=0;i<=960;i+=40)
    {h2[i/40].init(20+i,250,3);
     h2[i/40].setColor(COLOR("blue"));
     h2[i/40].setFill(true);
    }

for (int i=0;i<=960;i+=40)
    {h3[i/40].init(20+i,480,3);
     h3[i/40].setColor(COLOR("blue"));
     h3[i/40].setFill(true);
    }

for (int i=0;i<=460;i+=46)
    {v1[i/46].init(20,20+i,3);
     v1[i/46].setColor(COLOR("blue"));
     v1[i/46].setFill(true);
    }

for (int i=0;i<=460;i+=46)
    {v2[i/46].init(500,20+i,3);
     v2[i/46].setColor(COLOR("blue"));
     v2[i/46].setFill(true);
    }

for (int i=0;i<=460;i+=46)
    {v3[i/46].init(980,20+i,3);
     v3[i/46].setColor(COLOR("blue"));
     v3[i/46].setFill(true);
    }


wait(0.1);

XEvent event;
while(true)
{

            if(checkEvent(event) && keyPressEvent(event))
            {
            char c = charFromEvent(event);
            pacMove(c,dx,dy);
            }
            if(c1.getY()>=480 && dy>0){continue;}
            else if (c1.getY()<=20 && dy<0){continue;}
            else if(c1.getX()>=980 && dx>0){continue;}
            else if(c1.getX()<=20 && dx<0) {continue;}

            //top left
            if(c1.getY()>=17 && dy>0 && 20<c1.getX() && c1.getX()<500){continue;}
            else if(c1.getY()<=250 && dy<0 && 20<c1.getX() && c1.getX()<500){continue;}
            else if(c1.getX()>=20 && dx>0 && 20<c1.getY() && c1.getY()<250){continue;}
            else if(c1.getX()<=500 && dx<0 && 20<c1.getY() && c1.getY()<250){continue;}

            //top right
            if(c1.getY()>=17 && dy>0 && 500<c1.getX() && c1.getX()<980){continue;}
            else if(c1.getY()<=250 && dy<0 && 500<c1.getX() && c1.getX()<980){continue;}
            else if(c1.getX()>=500 && dx>0 && 20<c1.getY() && c1.getY()<250){continue;}
            else if(c1.getX()<=980 && dx<0 && 20<c1.getY() && c1.getY()<250){continue;}

            //bottom left
            if(c1.getY()>=250 && dy>0 && 20<c1.getX() && c1.getX()<500){continue;}
            else if(c1.getY()<=483 && dy<0 && 20<c1.getX() && c1.getX()<500){continue;}
            else if(c1.getX()>=20 && dx>0 && 250<c1.getY() && c1.getY()<480){continue;}
            else if(c1.getX()<=500 && dx<0 && 250<c1.getY() && c1.getY()<480){continue;}

            //bottom right
            if(c1.getY()>=250 && dy>0 && 500<c1.getX() && c1.getX()<980){continue;}
            else if(c1.getY()<=483 && dy<0 && 500<c1.getX() && c1.getX()<980){continue;}
            else if(c1.getX()>=500 && dx>0 && 250<c1.getY() && c1.getY()<480){continue;}
            else if(c1.getX()<=980 && dx<0 && 250<c1.getY() && c1.getY()<480){continue;}

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

            //Thru Channel
            if (c1.getX()<=983 && c1.getX()>=977 && c1.getY()<=253 && c1.getY()>=247 && dx>0){c1.moveTo(20,250);continue;}
            else if (c1.getX()<=23 && c1.getX()>=17 && c1.getY()<=253 && c1.getY()>=247 && dx<0){c1.moveTo(980,250);continue;}

            if (c1.getX()<=503 && c1.getX()>=497 && c1.getY()<=23 && c1.getY()>=17 && dy<0){c1.moveTo(500,480);continue;}
            else if (c1.getX()<=503 && c1.getX()>=497 && c1.getY()<=483 && c1.getY()>=477 && dy>0){c1.moveTo(500,20);continue;}




            c1.move(dx,dy);
            wait(0.005);
}
}
