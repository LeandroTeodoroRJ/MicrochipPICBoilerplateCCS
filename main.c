//****************************************************************************
//                              NOME PROJETO
//****************************************************************************
//Compilador CCS PCWH Ver 4.104

#include <16F628.h>              //include do 16F628
#include <string.h>
#include <16f628_registradores.h>//MAPEAMENTO DE ME�RIA DOS REGISTRADORES
                                                    

//****************************************************************************
//                    CONFIGURA��ES DO COMPILADOR
//****************************************************************************

#use fast_io(a)                  //modo de entrada e saida de dados que
#use fast_io(b)                  //o compilador nao configura o tris

#use delay(clock=4000000)        //clock usual
#fuses XT,WDT,NOLVP,PUT,PROTECT

//#rom 0x2100={0b00010010,0x00}    //programa os primeiros dois endere�os da eeprom
                                 

//****************************************************************************
//                                BIOS
//****************************************************************************
//****************************  ENTRADAS  ************************************
#define  botao       PIN_B0

//*****************************  SA�DAS  *************************************
#define  sinal       port_a,2

//****************************************************************************
//                        CONSTANTES E VARI�VEIS
//****************************************************************************
#define  debouce     10
#define alarme_off_flag alarme_status,1

int   w_temp;
int   status_temp;
int count;

//****************************************************************************
//                       Rotinas da interrupcao
//****************************************************************************
//#inline                     //descomentar se for usar o in_line



//****************************************************************************
//                           INTERRUP��ES
//****************************************************************************
#int_global
void interrupcao(){
restart_wdt();
disable_interrupts(global);
#asm
movwf w_temp
swapf status,w
movwf status_temp
#endasm


//***************************************************************************
//                          FIM DA INTERRUPCAO
//***************************************************************************
enable_interrupts(global);
#asm
swapf status_temp,w
movwf status
swapf w_temp,f
swapf w_temp,w
#endasm
}

//***************************************************************************
//                               DRIVES
//***************************************************************************
//#include <usart.h>



//****************************************************************************
//                             Sub-rotinas
//****************************************************************************
trata_tecla(){    

}


//****************************************************************************
//                          Rotina Principal
//****************************************************************************

void main(){
//********************** CONFIGURA��ES INICIAIS *****************************
      setup_timer_0(rtcc_internal); //clock interno, prescaler 1:2
      setup_timer_1(t1_internal|t1_div_by_8); 
      setup_wdt(wdt_288ms);
      disable_interrupts(global);
      bit_set(option_reg,7);    //sem pull-up

//    Configura��o do tris
//    Bit porta: 76543210
      tris_a = 0b00011000;
      tris_b = 0b00011111;
//******************** INICIALIZA��O DE VARI�VEIS ***************************
      count = 0;
      
//****************************************************************************
//                             INICIO DO LOOP
//****************************************************************************
      while(1){  
      restart_wdt();
      
      }
//********************************* FIM **************************************
}


















































