#include<maze.h>
//#include"maze1.h"
//#include"maze1.cpp"
#include<simplecpp>
#include"mazecall.h"
//#include<conio.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<iostream>
#include"abcd.h"
//#include<stdlib.h>
#include<ctime>

using namespace std;


int main()
{
    //bool game;
    ALLEGRO_DISPLAY *dis;
    //int f=0;
    cout<<sum(5,5)<<endl<<endl;
    if(!al_init())
        al_show_native_message_box(NULL,NULL,NULL,"ASDF",NULL,NULL);
    dis=al_create_display(800,600);
    al_set_window_position(dis,270,80);
    al_set_window_title(dis,"pacman menu");
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    ALLEGRO_COLOR eblue=al_map_rgb(44,117,255);
    ALLEGRO_COLOR pc=eblue;
    al_flip_display();
    ALLEGRO_FONT *font=al_load_font("Orbitron Black.ttf",30,NULL);
    ALLEGRO_FONT *fon=al_load_font("Orbitron Black.ttf",15,NULL);
    al_install_mouse();
    begin:
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_text(font,eblue,400,70,ALLEGRO_ALIGN_CENTER,"PACMAN");
        //al_rest(2.0);
        //al_draw_text(fon,eblue,400,70,ALLEGRO_ALIGN_CENTER,"PAC_MAN");
        al_draw_text(fon,eblue,400,170,ALLEGRO_ALIGN_CENTER,"PLAY");
        al_draw_text(fon,eblue,400,220,ALLEGRO_ALIGN_CENTER,"HELP");
        al_draw_text(fon,eblue,400,270,ALLEGRO_ALIGN_CENTER,"ABOUT");
        al_draw_text(fon,eblue,400,320,ALLEGRO_ALIGN_CENTER,"EXIT");

        al_draw_rectangle(350,165,450,187,eblue,1.0);
        al_draw_rectangle(350,215,450,237,eblue,1.0);
        al_draw_rectangle(350,265,450,287,eblue,1.0);
        al_draw_rectangle(350,315,450,337,eblue,1.0);
        al_flip_display();

        bool don=false;
        int x=10,y=10;//movespeed=5;


        ALLEGRO_TIMER *timer=al_create_timer(1.0/60.0);
        ALLEGRO_EVENT_QUEUE *event_queue=al_create_event_queue();
        al_register_event_source(event_queue,al_get_timer_event_source(timer));
        al_register_event_source(event_queue,al_get_display_event_source(dis));
        al_register_event_source(event_queue,al_get_mouse_event_source());

        al_start_timer(timer);

        bool a=false;
        while(!don)
        {
            checked:
                cout<<"jumped";
                ALLEGRO_EVENT events;

                //f+=1;
                al_wait_for_event(event_queue,&events);

                if(events.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
                    don=true;
                else if(events.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                {
                    x=events.mouse.x;
                    y=events.mouse.y;
                    goto check;
                }
        }

                /*al_flip_display();
                al_clear_to_color(al_map_rgb(0,0,0));*/

                check:
                    {
                        if(x>350&&x<450)
                        {
                            if(y>315&&y<337)
                            {
                                don=true;
                            }
                            else if(y>165&&y<187)
                            {
                                pac();
                                if(false)
                                    goto begin;
                                al_clear_to_color(al_map_rgb(0,0,0));
                                al_flip_display();
                                al_rest(2.0f);
                                cout<<1;
                            }
                            else if(y>215&&y<237)
                            {
                                al_clear_to_color(al_map_rgb(0,0,0));
                                al_flip_display();
                                al_draw_text(fon,eblue,100,70,ALLEGRO_ALIGN_LEFT,"pacman needs to collect all the pac-dots(yellow)");
                                al_draw_text(fon,eblue,100,95,ALLEGRO_ALIGN_LEFT,"while doing this it needs to protect itself from ghosts(moving)");
                                al_draw_text(fon,eblue,100,120,ALLEGRO_ALIGN_LEFT,"use 'w','a','s' and 'd' to navigate");
                                al_draw_text(fon,eblue,100,145,ALLEGRO_ALIGN_LEFT,"w-upwards");
                                al_draw_text(fon,eblue,100,170,ALLEGRO_ALIGN_LEFT,"a-left");
                                al_draw_text(fon,eblue,100,195,ALLEGRO_ALIGN_LEFT,"s-downwards");
                                al_draw_text(fon,eblue,100,220,ALLEGRO_ALIGN_LEFT,"d-right");
                                al_draw_text(font ,eblue,400,300,ALLEGRO_ALIGN_CENTER,"BACK");
                                al_flip_display();
                                while(!a)
                                {
                                    ALLEGRO_EVENT event;

                                    al_wait_for_event(event_queue,&event);

                                    if(event.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
                                        a=true;
                                    else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                                    {
                                        x=event.mouse.x;
                                        y=event.mouse.y;
                                        if(x>300&&x<500)
                                            if(y>285&&y<315)
                                                goto begin;
                                    }
                                }

                                cout<<2;
                            }
                            else if(x>265&&y<287)
                            {
                                al_clear_to_color(al_map_rgb(0,0,0));
                                al_flip_display();
                                al_draw_text(fon,eblue,100,70,ALLEGRO_ALIGN_LEFT,"a");
                                al_draw_text(fon,eblue,100,95,ALLEGRO_ALIGN_LEFT,"b");
                                al_draw_text(fon,eblue,100,120,ALLEGRO_ALIGN_LEFT,"c");
                                al_draw_text(fon,eblue,100,145,ALLEGRO_ALIGN_LEFT,"d");
                                al_draw_text(fon,eblue,100,170,ALLEGRO_ALIGN_LEFT,"a");
                                al_draw_text(fon,eblue,100,195,ALLEGRO_ALIGN_LEFT,"s");
                                al_draw_text(fon,eblue,100,220,ALLEGRO_ALIGN_LEFT,"d");
                                al_draw_text(font,eblue,400,300,ALLEGRO_ALIGN_CENTER,"BACK");
                                al_flip_display();
                                while(!a)
                                {
                                    ALLEGRO_EVENT event;

                                    al_wait_for_event(event_queue,&event);

                                    if(event.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
                                        a=true;
                                    else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                                    {
                                        x=event.mouse.x;
                                        y=event.mouse.y;
                                        if(x>300&&x<500)
                                            if(y>285&&y<315)
                                                goto begin;
                                    }
                                }

                                cout<<3;
                            }
                        }
                            else
                            {
                               //pacman();
                                goto checked;
                            }
                        }
                        // check2:
                            al_destroy_font(font);
                            al_destroy_font(fon);
                            al_destroy_display(dis);
                            //al_destroy_timer(timer);
                            //al_destroy_event_queue(event_queue);
                            cout<<endl<<y;
                            return 0;
}


