//****************************************************************************
//                              NOME PROJETO
//****************************************************************************
//Compilador CCS PCWH Ver 4.104

#include <16F877.h>              //include do 16F628
#include <string.h>
#include <16f8x_registradores.h>//MAPEAMENTO DE MEÓRIA DOS REGISTRADORES
                                                    

//****************************************************************************
//                    CONFIGURAÇÕES DO COMPILADOR
//****************************************************************************

#use fast_io(a)                  //modo de entrada e saida de dados que
#use fast_io(b)                  //o compilador nao configura o tris

#use delay(clock=20000000)        //clock usual
#fuses HS,NOWDT,NOLVP,PUT,NOPROTECT

//#rom 0x2100={0b00010010,0x00}    //programa os primeiros dois endereços da eeprom
                                 

//****************************************************************************
//                                BIOS
//****************************************************************************
//****************************  ENTRADAS  ************************************
#define  botao       PIN_B0

//*****************************  SAÍDAS  *************************************
#define  sinal       port_a,2

//****************************************************************************
//                        CONSTANTES E VARIÁVEIS
//****************************************************************************
#define  debouce     10
#define alarme_off_flag alarme_status,1

int   w_temp;
int   status_temp;
int   count;


//***************************************************************************
//                               DRIVES
//***************************************************************************
//#include <usart.h>



//****************************************************************************
//                       Rotinas da interrupcao
//****************************************************************************
//#inline                     //descomentar se for usar o in_line
void trata_serial(){

}

//****************************************************************************
//                           INTERRUPÇÕES
//****************************************************************************
#int_rda
void interrupcao(){
   disable_interrupts(int_rda);
   trata_serial();
   enable_interrupts(int_rda);
}

//****************************************************************************
//                             Sub-rotinas
//****************************************************************************
trata_tecla(){    

}


//****************************************************************************
//                          Rotina Principal
//****************************************************************************

void main(){
//********************** CONFIGURAÇÕES INICIAIS *****************************
      setup_timer_0(rtcc_internal); //clock interno
      setup_timer_1(t1_internal|t1_div_by_8); 
      setup_wdt(wdt_288ms);
      port_b_pullups(false);    //sem pull-up

//    Configuração do tris
//    Bit porta: 76543210
      tris_a = 0b00000000;
      tris_b = 0b00000000;
      tris_c = 0b00000000;
      tris_d = 0b00000000;
      tris_e = 0b00000000;
      
      enable_interrupts(global);
      enable_interrupts(int_rda);
      
      
//******************** INICIALIZAÇÃO DE VARIÁVEIS ***************************
      count = 0;
      
//****************************************************************************
//                             INICIO DO LOOP
//****************************************************************************
      while(1){  
      restart_wdt();
      
      }
//********************************* FIM **************************************
}


















































