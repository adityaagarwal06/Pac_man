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

Rectangle r4(260,135,460,210);
r4.setColor(COLOR("green"));
Rectangle r1(740,135,460,210);
r1.setColor(COLOR("green"));
Rectangle r2(260,365,460,210);
r2.setColor(COLOR("green"));
Rectangle r3(740,365,460,210);
r3.setColor(COLOR("green"));



Circle c1(500,250,10);

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

            c1.move(dx,dy);
            wait(0.005);
}
}
