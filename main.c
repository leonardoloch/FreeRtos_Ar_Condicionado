/*
Leonardo Loch da Silva
Engenharia de Computação - UFSC
*/

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "tarefa.h"
#include "init.h"


#define true 1




//xSemaphoreHandle controle_1, controle_2;

/*
Funcao principal - coloca o kernel em execucao e cria as tarefas
*/
xSemaphoreHandle semMotor, semInput;

xQueueHandle  mensagens,channel_temp;
int main(void)
{
  DDRB = 0b00111000;
  DDRD = 0xFC;
  
  DDRC=0x4F;//DISPLAY
	
  
  //-----------Create Semaphore
  semInput = xSemaphoreCreateCounting(1, 1);
  semMotor = xSemaphoreCreateCounting(1, 0); 
   
  //-----------Inicializando PWM 
  set_pwm();
  
  channel_temp = xQueueCreate (10,sizeof(int ));
  mensagens = xQueueCreate (10,sizeof( int ));
  
  //-----------Task Create
  xTaskCreate( display, (signed char*)"display", configMINIMAL_STACK_SIZE, NULL, 4, NULL );
  
  xTaskCreate( modificar_temp, (signed char*)"modificar_temp", configMINIMAL_STACK_SIZE, NULL, 4, NULL );
  xTaskCreate( verificarInput, (signed char*)"verificarInput", configMINIMAL_STACK_SIZE, NULL, 4, NULL );

  //-----------Dispecher
  vTaskStartScheduler();
 
}