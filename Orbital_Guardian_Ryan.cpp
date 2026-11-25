#include <stdio.h>
#include <stdlib.h>

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
    estacao->modulos[2] = (Subsistema){3, "Manobra e Propulsao", 70, 3, 10, 0};
    estacao->modulos[3] = (Subsistema){4, "Nucleo do Reator", 90, 5, 25, 0};
}

void painel_exibicao(EstacaoEspacial *e) {

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

void tela_inicial(){
printf("+===========================================================================+\n");
printf("|    .          *               .        ___________________________________|\n");
printf("|          +                     .      /  [=====]       |   |    |   |     |\n");
printf("|   .                                  /_________________|___|____|___|_____|\n");
printf("|                 *                   |   ________________________________  |\n");
printf("|        .                            |  |  |                          | o  |\n");
printf("|                     .               |  |  |       Aethelgard         |    |\n");
printf("|             /|                      |  |  |                          | [] |\n");
printf("|     ---===>| |    .    _ _ _ _ _ _  |  |  |                          |    |\n");
printf("|             \\|                      |  |__|__________________________| o  |\n");
printf("|   _.._                 *            |_____________________________________|\n");
printf("|  /    \\       .                      \\____________________________________|\n");
printf("| /      \\               +                     ||                 ||        |\n");
printf("+---------------------------------------------------------------------------+\n");
printf("| ___  ___  ___ ___ _____  _   _      ___ _   _  _   ___  ___ ___  _   _  _ |\n");
printf("|/ _ \\| _ \\| _ )_ _|  |   /_\\ | |_    / __| | | |/_\\ | _ \\|   \\_ _| /_\\ | \\||\n");
printf("|\\___/|_|_\\|___/___|  |  /_/ \\|___|   \\___|\\___//_/ \\|_|_\\|___/___/_/ \\|_|\\||\n");
printf("|                                                                           |\n");
printf("|               SIMULADOR DE TELEMETRIA E CONTROLE DE MISSAO                |\n");
printf("+===========================================================================+\n");
}

void exibir_derrota(void){
    printf("\n");
    printf("                                                                                                                                              .-.\n");
    printf("                                                                                                                                         .-\n");
    printf("                                                                                                                                        ..\n");
    printf("                                                                   .--====oooooooooooooo====--.                                       .-.\n");
    printf("                                                             .=oooooooooooooooooooooooooooooooo=ooo=-                     ..         ..\n");
    printf("                                                         .=oo==--ooooooooooooooooooooooooo==-..--=======-.                ..        ..\n");
    printf("                                                     .-==oo=-==oooooooooooooooooooo=====--==o==-====ooooooo=.             ..       -.\n");
    printf("                                                  --==ooo==oooooooooooooooooooooo=======ooooo=-------===oo=oo==.          -      .-.\n");
    printf("                                                ..-=oooo==oooooooooooooooooooooooo=.====oooooo=-.------=oo=-==oo=.      .-      .-.\n");
    printf("                                             .-==--===--------=====ooooooooo==---..===--=oooooo-...----=o==.-=oooo-.. ..       --\n");
    printf("                                           .-=====----==========-------...----=====--..=ooooooo=--..---=o=-.--=o=oo----..    .--      ..\n");
    printf("                                          -======---==============================----==-.-oooooooo=--====-..-=o==o=---=-   .-.      -.\n");
    printf("                                        .---==----=====================-========-..----====-.-=ooooooooo---.-----===--==o- --.      .\n");
    printf("                                       .==--.......................---=======-...--..-=======---=oooooo=-..----.-=o---==..--      ..\n");
    printf("                                      .....---...             ....----.......------..===========.=ooooo--..---...-=----.-=..     -.\n");
    printf("                                      ...   ....             ........    .----.  .--======---===.-ooooo=. .     .=-.-..-=-.==  ..\n");
    printf("                                     .. ....        .-----..................   ..--...---=---===--=oo=-..   ...-==.-..--.-=o- -.\n");
    printf("                                       -......    .=ooooooooooooooo===--. ......... ..-....-=====-.-==--  ..--.==...-=-.-==..-.\n");
    printf("                                      -......     -ooooooooooooooooooooo-..............  .--...-====-.===.. .-==....-- =o= -- -\n");
    printf("                                     --....-.    .=oo#ooooooooooooooooo=......-...........   .-..--=-=-.==oooo=.....-.==-.-. ==.\n");
    printf("                                    .=--...      .=o#oo###oooo=o#######o=-.................... ..-..-===-.--.....--...-... -ooo-\n");
    printf("                                    -=--...     -o##ooooo######ooooooooooo-......................  ...-===---.-====-...--.=oo=--\n");
    printf("                                   .==..==...  =o.      =oooooooo=         .--.... ....  ....... ... .. .--.=oooooooo=...=o==.--\n");
    printf("                                   -==--=- .  .-.        ----=oo=.        .....-......-=-...... .... -.   -ooooooo=====.=oo=-..-.\n");
    printf("                                   -==--=- . . --        .oo#====        ........-=..==-....... ....-- -.-oo--o=------.-.==.----. ..\n");
    printf("                                   ===----.. . .=.      -=o#o=o=-.      ...     .ooo-.- ...... .....- -..ooooo-.------.  -.-.---.  ..\n");
    printf("                                   ======-.. . -o.    .. .o#-oo=.-              -#oo= -.....   ... --.- ==-==-.------... ..-----    ..\n");
    printf("                                   ======-.. ..==.    .    ==oooo-.             ##oo-.==--===......-..-.oo-...-----...--...----=     ..\n");
    printf("                                   .====== -  =##o==o-.     oooo==oo=-.       -##=oo=.-======.....-= -.-ooo=..----...--- --==.==     ..\n");
    printf("                                   -.=====... =ooo==oo.      =oo#######oo######==o##oo==-. .......-= -.-oooo=.=-...----- =..-==      ..\n");
    printf("                                   .-.-==-..  -oooo===        oo###o=.-oooo=o######oooooooooo-....-- .--=--==.....----- .=oo=.      .-\n");
    printf("                                    ==- . .    -==o===   -    o####oooooooooo=ooooooo=. ....   .......--=----. .------  =oo= ..    ..\n");
    printf("                                    .==..          .o#o=oo=-=o#####o#oooo=--==-ooo=.      --   .....- --.-----...---. .=-..    . ...\n");
    printf("                                     -=...         -o##oo##########o#oo-..-      .==-   .=-   ... -=..-. .----------.-=...   .-...\n");
    printf("                                     -...        -=oo#o##o##=#o=###o=====.      ==-=====-  ....--..-..---.....--..-=o=.. ..    .\n");
    printf("                                       -.   .     .--=-=o=o===========---.       o=====......--..--..-------....===--=o=.      ..\n");
    printf("                                        .......   -=o#oo##-##.##-o===-o===      -o==. ... ---..--.-------------=o=-...=-      .-\n");
    printf("                                      -  .......  ...--=o=-oo-=o.=---...==.    -o. .. .---..----=-....-----.---=o-.. .-.....-.\n");
    printf("                                      .- . .....   .=-o-o-oo=#o=o===-=----=o=-==  .---..-==---==--.. ..----.---=o=---.\n");
    printf("                                       -=...  ...  -=====o--=--=-===ooooooo-...---..-==-.-======-.   ...----.=oooo=.. .\n");
    printf("                                     -...==..-=.   .=ooooooo-oo=oooo=-. .--=-. .===- -ooooooooo=-.  ..-----.=oo=- ....\n");
    printf("                                    .-- ---===-...-----..........------...--===-.-=o===----==o==--.---===-.==-. ....\n");
    printf("                                    .--..o===----=====------------===oo==----.-=oo=..---......-oo=-=oo=---........\n");
    printf("                                     ---.=o==ooo=====--....----=ooo=====o==--.=oo-.-.---. ..--.-=ooo=.-- .. ..\n");
    printf("                                      --- =oo=..-===ooooooooooooooooooo==ooo=-=o= -.--.----. .-.=oo-. .. ...\n");
    printf("                                       ...-=- ...................-=oo=-=ooooo==o= ..-.-----........ .....    .\n");
    printf("                                           -.........................--=ooooo==oo-..-- ..............      .\n");
    printf("                                             . ...........-.......... -======ooooo=  ---. .-. ....   .. ..\n");
    printf("                                               .........................=o=-.=ooo===-      ..       ..\n");
    printf("                                                ............... . ........--............           ..\n");
    printf("                                                   ...........................-..                ..\n");
    printf("                                                            ...........             .-..      ...\n");

printf("\n");

}

void exibir_relatorio(EstacaoEspacial *e){
    int indice_maior = 0;
    int indice_menor = 0;

    for (int i = 0; i < MAX_SUBSISTEMAS; i++) {
        if  (e->modulos[i].integridade > e->modulos[indice_maior].integridade) {
            indice_maior = i;
        }

        if (e->modulos[i].integridade < e->modulos[indice_menor].integridade){
            indice_menor = i;
        }
    }

    printf("\n======================RELATORIO ESTATISTICO==========================\n");
    printf("Subsistema mais integro: %s (%d%%)\n",
    e->modulos[indice_maior].nome,
    e->modulos[indice_maior].integridade);

    printf("Subsistema mais degradado: %s (%d%%)\n",
    e->modulos[indice_menor].nome,
    e->modulos[indice_menor].integridade);

    printf("Oxigenio final: %d%%\n", e->oxigenio_tripulacao);

    printf("Moral final: %d%%\n", e->moral_tripulacao);

}

int main(void) {
    EstacaoEspacial estacao;
    inicializar_estacao(&estacao);

    tela_inicial();
    printf("Pressione qualquer tecla para continuar...");
    getchar();
    printf("\n");

    int reator_reparado_c3_c4 = 0;
    

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

            if (scanf("%d", &opcao) != 1) {
                        printf("Entrada invalida.\n");

                        while (getchar() != '\n');
                        continue;
                    }

            printf("\n");
            
            switch(opcao){

                case 1:{
                    int id_selecionado; 
                    int energia = 0;
                    int novo_saldo = 0;

                    printf("Digite o id do modulo: ");
                    
                    if (scanf("%d", &id_selecionado) != 1) {
                        printf("Entrada invalida.\n");

                        while (getchar() != '\n');
                        continue;
                    }

                    if(id_selecionado >= 1 && id_selecionado <= MAX_SUBSISTEMAS){
                        printf("Digite a quantidade de energia a adicionar o retirar: ");
                        
                        if (scanf("%d", &energia) != 1) {
                            while (getchar() != '\n');
                            printf("Entrada invalida.\n");
                            break;
                        }

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
                    
                    if(scanf("%d", &id_selecionado) != 1){
                        while (getchar() != '\n');
                        printf("Entrada invalida.\n");
                        break;
                    }

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

                    //condicao dos eventos ciclo 4
                    if(indice == 3 && (estacao.ciclo_atual == 3 || estacao.ciclo_atual == 4)){
                        reator_reparado_c3_c4 = 1;
                    }

                    break;
                }
                case 3: {
                    int encontrou = 0;

                    for(int i = 0; i < MAX_SUBSISTEMAS; i++) {
                        if(estacao.modulos[i].integridade < 50){
                            encontrou = 1;
                            printf("Alerta no seguinte modulo:\n");
                            printf("ID:%d NOME:%s\n",
                                estacao.modulos[i].id,
                                estacao.modulos[i].nome);
                            printf("\n");
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

        int novo_oxigenio = estacao.oxigenio_tripulacao;

        if(estacao.modulos[0].integridade == 0){
            novo_oxigenio -= 50;
            printf("O Suporte de Vida colapsou! Niveis criticos de O2!\n");
        }else if(estacao.modulos[0].integridade < 50){
            novo_oxigenio -= 20;
        }

        if(novo_oxigenio < 0){
            novo_oxigenio = 0;
        }

        if(novo_oxigenio > 100){
            novo_oxigenio = 100;
        }

        estacao.oxigenio_tripulacao = novo_oxigenio;


        //evento ciclo 2
        if(estacao.ciclo_atual == 2 && estacao.modulos[1].energia_alocada < 5){
            int nova_integridade = 0;

            nova_integridade = estacao.modulos[1].integridade - 30;
            if(nova_integridade <= 0){
                nova_integridade = 0;
            }

            estacao.modulos[1].integridade = nova_integridade;
        }

        //evento ciclo 4
        if(estacao.ciclo_atual == 4){
            if(reator_reparado_c3_c4 == 0){
                estacao.modulos[3].integridade = estacao.modulos[3].integridade / 2;
            }
        }

        //Game Over
        if(estacao.oxigenio_tripulacao == 0){
            exibir_derrota();
            printf("%100s\n", "FALHA NOS SINAIS VITAIS DA TRIPULACAO. A ESTACAO TRANSFORMOU EM UM MAUSOLEU DE METAL.");
            exibir_relatorio(&estacao);
            break;
        }

        if(estacao.modulos[3].integridade == 0){
            exibir_derrota();
            printf("%100s\n", "GAME OVER! EXPLOSAO CATASTROFICA DE FISSAO DO NUCLEO.");
            exibir_relatorio(&estacao);
            break;
        }

        //verifica se 2 ou mais modulos colapsaram para o game over

        estacao.alertas_criticos = 0;
        int modulos_colapsados = 0;

        for(int i = 0; i < MAX_SUBSISTEMAS; i++) {
            if(estacao.modulos[i].integridade < 50) {
                estacao.alertas_criticos++;

            }

            if(estacao.modulos[i].integridade == 0) {
                modulos_colapsados++;
            }
        }

        if(modulos_colapsados >= 2){
            exibir_derrota();
            printf("GAME OVER! DOIS OU MAIS MODULOS COLAPSARAM.\n");
            exibir_relatorio(&estacao);
            break;
        }

        estacao.energia_livre_banco += 5;

        //relatorio apos derrota ou vitoria

        if(estacao.ciclo_atual == 5) {
            int todos_acima_20 = 1;

            for (int i = 0; i < MAX_SUBSISTEMAS; i++) {
                if (estacao.modulos[i].integridade <= 20){
                    todos_acima_20 = 0;
                }
            }

            if(estacao.oxigenio_tripulacao > 0 && todos_acima_20 == 1) {
                printf("\nRESGATE EFETUADO COM SUCESSO!\n");
            }else {
                exibir_derrota();
                printf("\nGAME OVER - MISSAO FRACASSADA\n");
            }
            exibir_relatorio(&estacao);

        }


        estacao.ciclo_atual++;
    }

    system("pause");
    return 0;
}