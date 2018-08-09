#include <allegro.h>
#include "inicia.h"


int main()
{
    inicia_allegro(600,500);
    inicia_audio(70,70);
    install_mouse();

    int com=0;
    int cod=0;
    int mario=0;
    int fifa=0;



    BITMAP *buffer = create_bitmap(600,500);
    BITMAP *fondo1 = load_bitmap("Menuprincipal.bmp",NULL);
    BITMAP *fondo2 = load_bitmap("Comenzar.bmp",NULL);
    BITMAP *fondo3 = load_bitmap("Salir.bmp",NULL);
    BITMAP *cursor = load_bitmap("cursor.bmp",NULL);
    //SAMPLE *salir = load_wav("Perdio.wav");
    SAMPLE *comenzar = load_wav("Salto.wav");
    BITMAP *play1 = load_bitmap("cual es tu juego/seleccion.bmp",NULL);
    BITMAP *play2 = load_bitmap("cual es tu juego/seleccion_mario.bmp",NULL);
    BITMAP *play3 = load_bitmap("cual es tu juego/seleccion_cod.bmp",NULL);
    BITMAP *play4 = load_bitmap("cual es tu juego/seleccion_fifa.bmp",NULL);
    BITMAP *playsalir = load_bitmap("cual es tu juego/seleccion_salir.bmp",NULL);
    BITMAP *juego_1 = load_bitmap("Juegos/Cod_frases.bmp",NULL);
    BITMAP *juego_2 = load_bitmap("Juegos/Mario_frases.bmp",NULL);
    BITMAP *juego_3 = load_bitmap("Juegos/Fifa_frases.bmp",NULL);
    BITMAP *salir_fifa = load_bitmap("Juegos/Fifa_salir.bmp",NULL);
    BITMAP *salir_mario = load_bitmap("Juegos/Mario_salir.bmp",NULL);
    BITMAP *salir_cod = load_bitmap("Juegos/Cod_salir.bmp",NULL);


    //MIDI *musicafondo = load_midi("musica.mid");


    bool salida = false;

    while (!salida){

        if (mouse_x > 325 && mouse_x<555 && mouse_y >125 && mouse_y<185 && com==0){//cuando el mause esta en la opcon comenzar

            blit(fondo2,buffer,0,0,0,0,600,500);


            if (mouse_b & 1){//1 es click izquierdo y 2 el derecho

                    play_sample(comenzar,250,100,1000,0);//suena la moneda al dar click
                    com=1;

                    }//cierro el if del click

                    //salida=true;

        }//cierro cuando esta en comenzar.

        else if (com==1){ //entra a la seleccion del juego favorito

                 if (mouse_x > 235 && mouse_x<510 && mouse_y >187 && mouse_y<235){

                    blit(play3,buffer,0,0,0,0,600,500); //call duty

                    if (mouse_b & 1){

                    play_sample(comenzar,250,100,1000,0);//suena la moneda al dar click
                    com=4;

                    }

                    }

                        else if (mouse_x > 36 && mouse_x<195 && mouse_y >268 && mouse_y<367){

                            blit(play2,buffer,0,0,0,0,600,500);//mario seleccion
                            if (mouse_b & 1){

                            play_sample(comenzar,250,100,1000,0);//suena la moneda al dar click
                            mario=1;
                            com=2;


                        }

                        }

                            else if (mouse_x > 234 && mouse_x<505 && mouse_y >305 && mouse_y<368){

                                blit(play4,buffer,0,0,0,0,600,500); //fifa seleccion
                                if (mouse_b & 1){

                                play_sample(comenzar,250,100,1000,0);//suena la moneda al dar click
                                fifa=1;
                                com=3;

                            }

                            }

                            else if (mouse_x > 534 && mouse_x<588 && mouse_y >440 && mouse_y<488){

                                    blit(playsalir,buffer,0,0,0,0,600,500);

                                if (mouse_b & 1){//1 es click izquierdo y 2 el derecho
                                salida=true;
                                }
                            }

                    else

                    blit(play1,buffer,0,0,0,0,600,500);
                    masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
                    blit(buffer,screen,0,0,0,0,600,500);

                }//cierro con llave de com=1

        else if(com==2){

                blit(juego_2,buffer,0,0,0,0,600,500); //mario

                if (mouse_x > 534 && mouse_x<588 && mouse_y >440 && mouse_y<488){

                                    blit(salir_mario,buffer,0,0,0,0,600,500);

                                if (mouse_b & 1){//1 es click izquierdo y 2 el derecho
                                salida=true;
                                }
                            }

        }

         else if(com==3){ //fifa

                blit(juego_3,buffer,0,0,0,0,600,500);

                if (mouse_x > 534 && mouse_x<588 && mouse_y >440 && mouse_y<488){

                                    blit(salir_fifa,buffer,0,0,0,0,600,500);

                                if (mouse_b & 1){//1 es click izquierdo y 2 el derecho
                                salida=true;
                                }
                            }

        }

        else if(com==4){ //cod

                blit(juego_1,buffer,0,0,0,0,600,500);

                if (mouse_x > 534 && mouse_x<588 && mouse_y >440 && mouse_y<488){

                                    blit(salir_cod,buffer,0,0,0,0,600,500);

                                if (mouse_b & 1){//1 es click izquierdo y 2 el derecho
                                salida=true;
                                }
                            }

        }

         /*else if (cod==1){

            blit(juego_1,buffer,0,0,0,0,600,500);
            masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
            blit(buffer,screen,0,0,0,0,600,500);

        }*/


        else if(mouse_x > 328 && mouse_x<553 && mouse_y>230 && mouse_y <295 && com==0){

        blit(fondo3,buffer,0,0,0,0,600,500);

        //play_sample(salir,100,150,1000,0);

        if (mouse_b & 1){//1 es click izquierdo y 2 el derecho
                    salida=true;
        }
    } else if (com==0)
        blit(fondo1,buffer,0,0,0,0,600,500);
        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
        blit(buffer,screen,0,0,0,0,600,500);
        //play_midi(musicafondo,1);



    }//fin de bool
    //clear_to_color(buffer, 0x999999);


    destroy_bitmap(buffer);

    return 0;
}
END_OF_MAIN();
