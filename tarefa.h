



#ifndef TAREFA_H
#define TAREFA_H
void ledVermelho();
void ledAmarelo();

void verificarInput();
void botaoDiminuir(int *unidade,int *dezena);
void botaoAumentar(int *unidade,int *dezena);
void mostraDisplay(int unidade,int dezena);
void display();



void modificar_temp();
void PWM1_value(int motor, int resistencia);
void valor_res_motor(unsigned int temp);
int  map(int x, int in_min, int in_max, int out_min, int out_max);


#endif