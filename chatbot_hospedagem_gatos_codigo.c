#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Necessário para imprimir acentos (ç, ã, é) no terminal

int main(void) {
    // 1. Muda o terminal do Windows para UTF-8 de forma invisível (> nul)
    system("chcp 65001 > nul");
    // 2. Alinha a linguagem C com a codificação UTF-8 do VS Code
    setlocale(LC_ALL, ".UTF8");
    // ====================================================================

    // Declaração das variáveis de controle de fluxo e análise condicional
    int opcao;
    int dias;

    // Cabeçalho de apresentação do sistema
    printf("====================================================\n");
    printf("===    ATENDIMENTO VIRTUAL - HOSPEDAGEM FELINA   ===\n");
    printf("====================================================\n\n");

    // Saudação inicial e propósito básico do programa
    printf("Olá! Seja muito bem-vindo(a) ao nosso atendimento.\n");
    printf("Sou o assistente virtual da Hospedagem e estou aqui para\n");
    printf("ajudar a organizar a estadia do seu gatinho, apresentar\n");
    printf("nossos planos e tirar todas as suas dúvidas!\n\n");

    // Laço de repetição principal para manter o menu interativo ativo
    do {
        printf("\n=== MENU DE OPÇÕES ===\n");
        printf("1. Ver valores e planos de hospedagem\n");
        printf("2. Dúvidas frequentes (Alimentação, caixinha de areia, etc.)\n");
        printf("3. Falar com um cuidador humano\n");
        printf("0. Encerrar atendimento\n");
        printf("\nDigite a opção desejada: ");

        // Captura da escolha do usuário
        scanf("%d", &opcao);

        // Estrutura switch para avaliar e tratar a opção escolhida
        switch (opcao) {
            case 1:
                printf("\n[BOT] Trabalhamos com diárias a partir de R$ 60,00 e descontos progressivos!\n");
                printf("Para simular o valor, digite quantos dias seu gatinho ficará conosco: ");
                scanf("%d", &dias);

                // Estrutura aninhada (if / else if / else) para cálculo analítico do pacote
                if (dias <= 0) {
                    printf("\n[ERRO] Quantidade de dias inválida! Informe um valor inteiro maior que zero.\n");
                } else if (dias <= 5) {
                    printf("[BOT] Plano Curta Estadia: Valor total de R$ %.2f (R$ 60,00/dia).\n", dias * 60.0);
                } else if (dias <= 14) {
                    printf("[BOT] Plano Estadia Média (10%% de desconto): Valor total de R$ %.2f (R$ 54,00/dia).\n", dias * 54.0);
                } else {
                    printf("[BOT] Plano Longa Estadia (20%% de desconto): Valor total de R$ %.2f (R$ 48,00/dia).\n", dias * 48.0);
                }
                break;

            case 2:
                printf("\n[BOT] === DÚVIDAS FREQUENTES ===\n");
                printf("- Alimentação: Mantemos a rotina e a ração habitual do seu felino.\n");
                printf("- Higiene: As caixinhas de areia são higienizadas continuamente.\n");
                printf("- Segurança: Espaço 100%% telado, climatizado e com enriquecimento ambiental.\n");
                break;

            case 3:
                printf("\n[BOT] Transferindo seu atendimento para um cuidador humano...\n");
                printf("[BOT] Em instantes continuaremos a conversa diretamente pelo WhatsApp!\n");
                break;

            case 0:
                printf("\n[BOT] Preparando o encerramento seguro do atendimento...\n");
                break;

            // Tratamento de dados incorretos ou opções fora do escopo válido
            default:
                printf("\n[ERRO] Opção inválida! O código digitado não existe no sistema.\n");
                printf("[BOT] Por favor, escolha e digite apenas um número válido entre 0 e 3.\n");
                break;
        }

    } while (opcao != 0);

    // Mensagem explícita de despedida e finalização cortês do sistema fora do laço
    printf("\n====================================================\n");
    printf("Obrigado por utilizar o Atendimento Virtual da Hospedagem Felina!\n");
    printf("Sessão finalizada com sucesso. Um ronrom e até logo!\n");
    printf("====================================================\n");

    return 0;
}