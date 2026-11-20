#include <stdio.h>

#define MAX_SUBSISTEMAS 4
#define MAX_NOME 30

typedef struct {
    int id;
    char nome[MAX_NOME];
    int integridade;
    int energia_alocada;
    int taxa_degradacao;
    int reparado_neste_ciclo;
} Subsistema;

typedef struct {
    int ciclo_atual;
    int energia_livre_banco;
    int oxigenio_tripulacao;
    int moral_tripulacao;
    int alertas_criticos;
    Subsistema modulos[MAX_SUBSISTEMAS];
} EstacaoEspacial;

void inicializar_estacao(EstacaoEspacial *estacao) {
    estacao->ciclo_atual = 1;
    estacao->energia_livre_banco = 15;
    estacao->oxigenio_tripulacao = 100;
    estacao->moral_tripulacao = 80;


    //modulos
    estacao->modulos[0] = (Subsistema){1, "Suporte de vida (O2)", 85, 3, 15, 0};
    estacao->modulos[1] = (Subsistema){2, "Escudo Defletor", 60, 4, 20, 0};
    estacao->modulos[2] = (Subsistema){3, "Manobra de Propulsao", 70, 3, 10, 0};
    estacao->modulos[3] = (Subsistema){4, "Nucleo do Reator", 90, 5, 25, 0};
}

void painel_exibicao(EstacaoEspacial *e) {
    const char *status;

    

    printf("\t\t=============================PAINEl DE TELEMETRIA [ CICLO %d/5 ]=============================\n", e->ciclo_atual);
    printf("\t\tSTATUS GERAL: Oxigenio da tripulacao: [ %d ] | Bateria Disponivel: [ %d un ] \n", e->oxigenio_tripulacao, e->energia_livre_banco);
    printf("\t\t----------------------------------------------------------------------------------------------\n");
        printf("\t\t%-3s %-30s %10s %16s  %-5s\n",
            "ID", "SUBSISTEMA", "INTEGRIDADE", "ENERGIA ALOCADA", "STATUS");
    for(int i = 0; i < MAX_SUBSISTEMAS; i++) {
        const char *status;
        Subsistema *s = &e->modulos[i];

        if(s->integridade >=90) {
            status = "ESTAVEL";
        }else if (s->integridade >=70){
            status = "OPERACIONAL";
        }else {
            status = "ALERTA";
        }

        printf("\t\t[%-d] %-30s %-12d %-16d %-10s\n",
            s->id, s->nome, s->integridade, s->energia_alocada, status);

    }

}

int main(void) {
    EstacaoEspacial estacao;
    inicializar_estacao(&estacao);
    

    while (estacao.ciclo_atual <= 5){
        painel_exibicao(&estacao);

        for(int i = 0; i < MAX_SUBSISTEMAS; i++){
            estacao.modulos[i].reparado_neste_ciclo = 0;
        }

        int opcao;

        do{
            printf("\n");
            printf("ACOES DISPONIVEIS:\n");
            printf("1 - Transferir energia para subsistema\n");
            printf("2 - Enviar engenheiro para reparo de emergencia\n");
            printf("3 - Rodar diagnostico avancado\n");
            printf("4 - Encerrar ciclo orbital\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            printf("\n");
            
            switch(opcao){

                case 1:{
                    int id_selecionado; 
                    int energia = 0;
                    int novo_saldo = 0;

                    printf("Digite o id do modulo: ");
                    scanf("%d", &id_selecionado);

                    if(id_selecionado >= 1 && id_selecionado <= MAX_SUBSISTEMAS){
                        printf("Digite a quantidade de energia a adicionar o retirar: ");
                        scanf("%d", &energia);
                        int indice = id_selecionado - 1;
                        int nova_energia = estacao.modulos[indice].energia_alocada + energia;
                        novo_saldo = estacao.energia_livre_banco - energia;

                        if(nova_energia >= 0 && nova_energia <= 10 && novo_saldo >= 0){
                            estacao.modulos[indice].energia_alocada = nova_energia;
                            estacao.energia_livre_banco = novo_saldo;
                        }else {
                            printf("Nao e possivel adicionar ou remover esta quantidade de energia.");
                        }

                    }else {
                        printf("Id invalido!");
                    }


                    break;
                }

                case 2:{
                    int id_selecionado;
                    int indice;
                    int nova_integridade = 0;
                    int reparo_feito = 0;
                    
                    for(int i = 0; i < MAX_SUBSISTEMAS; i++){
                        if(estacao.modulos[i].reparado_neste_ciclo == 1){
                        reparo_feito = 1;
                        break;
                    }

                    }
                    if(reparo_feito == 1) {
                        printf("Reparo ja feito neste ciclo!");
                        break;
                    }
                    

                    printf("Selecione o modulo para reparar: ");
                    scanf("%d", &id_selecionado);

                    if(id_selecionado < 1 || id_selecionado > MAX_SUBSISTEMAS){
                        printf("Id selecionado nao existe!");
                        break;
                    }
                    
                    indice = id_selecionado - 1;

                    if(estacao.modulos[indice].integridade == 100){
                        printf("A integridade ja esta no maximo");
                        break;
                    }else {
                        nova_integridade = estacao.modulos[indice].integridade + 25;
                    }

                    if(nova_integridade > 100) {
                        nova_integridade = 100;
                    }

                    estacao.modulos[indice].integridade = nova_integridade;
                    estacao.modulos[indice].reparado_neste_ciclo = 1;

                    break;
                }
                case 3:{
                    int encontrou = 0;

                    for(int i = 0; i < MAX_SUBSISTEMAS; i++) {
                        if(estacao.modulos[i].integridade < 50){
                            encontrou = 1;
                            printf("ID:%d NOME:%s\n",
                                estacao.modulos[i].id,
                                estacao.modulos[i].nome);
                        }
                    }

                    if (encontrou == 0) {
                        printf("TODOS OS SISTEMAS DENTRO DA MARGEM OPERACIONAL!\n");
                    }
                    break;
                }

                case 4:
                    printf("Encerrando ciclo orbital\n");
                    break;

                default:
                    printf("Opcao invalida");
                    break;
            }

            printf("\n");
        }while (opcao != 4);

        for(int i = 0; i < MAX_SUBSISTEMAS; i++){

            int perda_integriade = estacao.modulos[i].taxa_degradacao - estacao.modulos[i].energia_alocada * 2;

            if(perda_integriade < 0){
                perda_integriade = 0;
            }
            int nova_integridade = estacao.modulos[i].integridade - perda_integriade;

            if(nova_integridade < 0){
                nova_integridade = 0;
            }

            estacao.modulos[i].integridade = nova_integridade;
        } 

        if(estacao.modulos[0].integridade == 0){
            estacao.oxigenio_tripulacao -= 50;
        }else if(estacao.modulos[0].integridade < 50){
            estacao.oxigenio_tripulacao -= 20;
        }

        if(estacao.oxigenio_tripulacao < 0){
            estacao.oxigenio_tripulacao = 0;
        }
        

        estacao.ciclo_atual++;
    }
}