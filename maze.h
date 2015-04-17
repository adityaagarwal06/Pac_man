#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED

#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<conio.h>
#include<math.h>
#include<string>
//#include<allegro5/allegro_audio.h>
//time *t;
using namespace std;

//namespace medium_maze:
  //  {

    //}

const float width=800;
const float height=600;

bool capture(int x,int y,int x1,int y1)
{
    if(abs(x-x1)<=20&&abs(y-y1)<=20)
        return true;
    else
        return false;
}

void gmove(int &x1,int &y1,int &f1)
    {
        int x=1,moves=1;
        if((x1==50&&(y1==50||y1==150||y1==250||y1==295||y1==430))||
          (x1==315&&(y1==50||y1==150))||
          (x1==580&&(y1==50||y1==150||y1==250||y1==295||y1==430)))
       {
        //  srand(time(NULL));
        x=rand()%4+1;
        //cout<<x<<endl;
        //cout<<x1<<endl<<y1;
        if(x==1)
        {
            //if(y1<=429)
            {
                f1=1;
                //y1+=moves;
            }
        }
        else if(x==2)
        {
            //if(y1>=51)
            {
                f1=2;
                //y1-=moves;
            }
        }
        else if(x==3)
        {
            //if(x1>=51)
            {
                f1=3;
                //x1-=moves;
            }
        }
        else if(x==4)
        {
            //if(x1<=579)
            {
                f1=4;
                //x1+=moves;
            }
        }
       }

        if(f1==1)
        {
            if(y1>=50&&y1<=429&&(x1==50||x1==580||(x1==315&&y1<150&&y1>=50)||(x1==205&&y1<295&&y1>=250)||(x1==425&&y1<295&&y1>=250)))
            y1+=moves;
        }
        else if(f1==2)
        {
            if(y1>=51&&y1<=430&&(x1==50||x1==580||(x1==315&&y1<150&&y1>=50)||(x1==205&&y1<295&&y1>=250)||(x1==425&&y1<295&&y1>=250)))
            y1-=moves;
        }
        else if(f1==3)
        {
            //cout<<endl<<endl;
            if(x1>=51&&x1<=580&&(y1==50||y1==150||y1==250||y1==295||y1==430))
            x1-=moves;
        }
        else if(f1==4)
        {
            if(x1>=50&&x1<=579&&(y1==50||y1==150||y1==250||y1==295||y1==430))
            x1+=moves;
        }
    }


void pac()
{

//    srand(time(0));
    ALLEGRO_DISPLAY *display;
    float c=60,d=60,e=0,f=4,ff=0,dd=0;
    int f1=2;
    int score=0;
    int counter=3;
    if(!al_init())
        al_show_native_message_box(NULL,NULL,NULL,"COULD NOT",NULL,NULL);

    display=al_create_display(800,600);
    al_set_window_position(display,270,80);
    al_set_window_title(display,"pacman");
    if(!display)
        al_show_native_message_box(NULL,"SAMPLE","COULD NOT DISPLAY",NULL,NULL,NULL);

    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_mouse();
    al_install_keyboard();
    //ALLEGRO_TIMER *timer=al_create_timer(1.0/3.0);
    ALLEGRO_COLOR eblue=al_map_rgb(44,117,255);
    ALLEGRO_COLOR yellow=al_map_rgb(255,255,0);
    ALLEGRO_BITMAP *p=al_load_bitmap("Untitled1.png");
    ALLEGRO_BITMAP *g1=al_load_bitmap("ghost.png");
    ALLEGRO_EVENT_QUEUE *equeue=al_create_event_queue();
    al_register_event_source(equeue,al_get_keyboard_event_source());
    //al_register_event_source(equeue,al_get_timer_event_source(timer));
    int x=50,y=50,x1=580,y1=70;
    int p_1=50,q_1=50,p_2=50,q_2=50,p_3=50,q_3=50,p_4=50,q_4=50,p_5=50,q_5=50;
    int p1=50,q1=580,p2=50,q2=580,p3=50,q3=580,p4=50,q4=580,p5=50,q5=580;
    int movespeed=1;
    bool done=false;
    ALLEGRO_FONT *font=al_load_font("Orbitron Black.ttf",24,NULL);
    al_draw_text(font,eblue,325,270,ALLEGRO_ALIGN_CENTER,"pac-man");


    //al_start_timer(timer);
    while(!done)
    {
        //al_start_timer(timer);

        e=0;
        al_draw_rectangle(225,270,425,295,eblue,2.0);
    al_draw_rectangle(50,50,600,450,eblue,2.0);
    al_draw_rectangle(70,70,315,150,eblue,2.0);
    al_draw_rectangle(335,70,580,150,eblue,2.0);
    al_draw_rectangle(70,170,580,250,eblue,2.0);
    al_draw_rectangle(70,270,205,295,eblue,2.0);
    al_draw_rectangle(445,270,580,295,eblue,2.0);
    al_draw_rectangle(70,315,580,430,eblue,2.0);
    c=80;
    d=60;
    ;
    /*if(f==1)
    {
        if()
    }
    else if(f==2)
    else if(f==3)*/
    /*if(f==4)
    {
        if(y==50)
            if(x>p1)
               {
                 p1=c+20;
                 c+=20;
               }

    }*/

    while(c<q1)
    {

        if(y==50)
           {if(f==4)
        {   if(p_1==50)
            if(x+10>p1)
            p1=x+10  ;

            }
            if(f==3)
                if(q_1==50)
                if(x<q1)
                q1=x;
            }

            while(p1>c)
            c=c+20;

        if(c<590)
        al_draw_filled_circle(c,d,2,al_map_rgb(255,255,0));

        c=c+20;
        e+=1;
    }
    c=80;
    /*while(d<=450)
    {
        al_draw_filled_circle(c,d,2,al_map_rgb(255,255,0));
        d=d+20;
        e+=1;
    }*/
    d=440;
    while(c<=q5)
    {
        if(y==430)
           {if(f==4)
        {   if(p_5==50)
            if(x+10>p5)
            p5=x+10  ;

            }
            if(f==3)
                if(q_5==50)
                if(x<q5)
                q5=x;
            }

            while(p5>c)
            c=c+20;

        al_draw_filled_circle(c,d,2,al_map_rgb(255,255,0));
        c=c+20;
        e+=1;
    }
    d=60;
    c=590;
    /*while(d<=450)
    {
        al_draw_filled_circle(c,d,2,al_map_rgb(255,255,0));
        d=d+20;
        e+=1;
    }*/
    d=160;
    c=80;
    while(c<=q2)
    {
        if(y==150)
           {if(f==4)
        {   if(p_2==50)
            if(x+10>p2)
            p2=x+10  ;

            }
            if(f==3)
                if(q_2==50)
                if(x<q2)
                q2=x;
            }

            while(p2>c)
            c=c+20;

        al_draw_filled_circle(c,d,2,al_map_rgb(255,255,0));
        c=c+20;
        e+=1;
    }
    c=80;
    d=260;
    while(c<=q3)
    {
        if(y==250)
           {if(f==4)
        {   if(p_3==50)
            if(x+10>p3)
            p3=x+10  ;

            }
            if(f==3)
                if(q_3==50)
                if(x<q3)
                q3=x;
            }

            while(p3>c)
            c=c+20;
        if(c<=590)
        al_draw_filled_circle(c,d,2,al_map_rgb(255,255,0));
        c=c+20;
        e+=1;
        //cout<<"aditya";
    }
    c=80;
    d=305;
    while(c<q4)
    {
        if(y==295)
           {if(f==4)
        {   if(p_4==50)
            if(x+10>p4)
            p4=x+10  ;

            }
            if(f==3)
                if(q_4==50)
                if(x<q4)
                q4=x;
            }

            while(p4>c)
            c=c+20;
        if(c<=590)
        al_draw_filled_circle(c,d,2,al_map_rgb(255,255,0));
        c=c+20;
        e+=1;
    }
    c=325;
    d=80;
    //cout<<ff;
    /*while(d<=140)
    {
        al_draw_filled_circle(c,d,2,al_map_rgb(255,255,0));
        d=d+20;
        e+=1;
    }*/
    //al_draw_filled_circle(215,282.5,2,al_map_rgb(255,255,0));
    //al_draw_filled_circle(435,282.5,2,al_map_rgb(255,255,0));
    //e+=2;
    score=(179-e)*10;

    al_flip_display();
        //al_destroy_bitmap(p);
        al_draw_bitmap(p,x,y,NULL);
        al_draw_bitmap(g1,x1,y1,NULL);
        al_flip_display();
            //al_rest(5.0);
        gmove(x1,y1,f1);
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout,0.05);
        ALLEGRO_EVENT event;
        //get_event=al_wait_for_event_until(equeue,&event,&timeout);
        //if(get_event)
        //{
        if(al_wait_for_event_until(equeue,&event,&timeout)) {
        if(event.type==ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(event.keyboard.keycode)
            {
            case ALLEGRO_KEY_DOWN:
              {
                dd=1;
               //if(y<=429)
               }
                break;
            case ALLEGRO_KEY_UP:
                {
                    dd=2;
                    /*if(y>=51)
                {   f=2;
                    y-=movespeed;}*/}
                break;
            case ALLEGRO_KEY_LEFT:
                {
                    dd=3;
                    /*if(x>=51)
                {   f=3;
                    x-=movespeed;}*/}
                break;
            case ALLEGRO_KEY_RIGHT:
                {
                    dd=4;
                    /*if(x<=578)
                {
                    f=4;
                    x+=movespeed;}*/}
                break;
            default:done=true;
            }

        }
        }
        else
        {
            if(dd==1)
            {
                if(y<=429)
                {
                    if(x==50||x==580||(x==315&&y<150&&y>=50)||(x==205&&y<295&&y>=250)||(x==425&&y<295&&y>=250))
                    {
                               f=1;
                                y+=movespeed;
                                dd=0;

                    }
                }
            }
            else if(dd==2)
            {
                if(y>=51)
                {
                    if(x==50||x==580||(x==315&&y>50&&y<=150)||(x==205&&y>250&&y<=295)||(x==425&&y>250&&y<=295))
                    {
                               f=2;
                                y-=movespeed;
                                dd=0;
                    }
                }
            }
            else if(dd==3)
            {
                if(x>=51)
                {
                    if(y==50||y==150||y==250||y==295||y==430)
                    {
                               f=3;
                                x-=movespeed;
                                dd=0;
                                if(x>=576&&x<=580)
                                   {
                                        if(y==50)
                                        q_1=50;
                                        if(y==150)
                                            q_2=50;
                                        if(y==250)
                                            q_3=50;
                                        if(y==295)
                                            q_4=50;
                                        if(y==430)
                                            q_5=50;
                                   }

                                else
                                    {q_1=0;q_2=0;q_3=0;q_4=0;q_5=0;}
                    }
                }
            }
            else if(dd==4)
            {
                if(x<=579)
                {
                    if(y==50||y==150||y==250||y==295||y==430)
                    {
                               f=4;
                                x+=movespeed;
                                dd=0;
                                if(x>=50&&x<=54)
                                    {
                                        if(y==50)
                                            p_1=50;
                                        if(y==150)
                                            p_2=50;
                                        if(y==250)
                                            p_3=50;
                                        if(y==295)
                                            p_4=50;
                                        if(y==430)
                                            p_5=50;
                                    }
                                else
                                    {
                                        p_1=0;p_2=0;p_3=0;p_4=0;p_5=0;
                                    }
                    }
                }
            }
         //   cout<<"else";
            //done=true;

            {

            if(f==4)
                {
                    if(x<=579)
                    x+=movespeed;
                }
            else if(f==3)
                {
                    if(x>=51)
                    x-=movespeed;
                }
            else if((x==50||x==580||(x==315&&y>50&&y<=150)||(x==205&&y>250&&y<=295)||(x==425&&y>250&&y<=295))&&f==2)
                {
                    if(y>=51)
                    y-=movespeed;
                }
            else if(f==1)
                {
                    if((x==50||x==580||(x==315&&y<150&&y>=50)||(x==205&&y<295&&y>=250)||(x==425&&y<295&&y>=250))&&y<=429)
                    y+=movespeed;
                }
            else
            {
                al_rest(2.0); done=true;
            }
            }
        }

      ff+=1;

      al_clear_to_color(al_map_rgb(0,0,0));
        //cout<<"adi";
        if(capture(x,y,x1,y1))
        {
            x=50,y=50,x1=580,y1=70;
            counter-=1;
            f=4;
            f1=2;
            al_clear_to_color(al_map_rgb(0,0,0));
            if(counter==0)
            {al_draw_text(font,eblue,325,270,ALLEGRO_ALIGN_CENTER,"GAME OVER");
            al_flip_display();
            al_rest(1.0);
            done=true;}
        }
    }




    al_flip_display();

    al_rest(1.0);
    al_destroy_event_queue(equeue);
    al_destroy_font(font);
    //al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_bitmap(g1);
    al_destroy_bitmap(p);
    cout<<"\n"<<e;
    //cout<<endl<<x1<<endl<<y1;
    //char ccc=getch();
    //cout<<ccc;
    //return 0;
}




#endif // MAZE_H_INCLUDED
