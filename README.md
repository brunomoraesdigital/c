# Operacoes com datas em javascript

Este projeto foi desenvolvido para praticar e aprender manipulação de datas em JavaScript. Ele contém funções que permitem selecionar, incrementar e decrementar datas, exibindo informações úteis no DOM, como o dia da semana, a quantidade de dias no mês e se o ano selecionado é bissexto.


<a href="https://brunomoraesdigital.github.io/operacoes-com-datas-em-javascript/" target="_blank" rel="noopener noreferrer">Ver Demonstração</a>


## Funcionalidades
- Manipulação de Entrada de Data:
  - Obtém uma data inserida pelo usuário, converte-a em um objeto e a processa.
- Modificação de Data:
  - Funções para incrementar e decrementar a data selecionada, com verificações lógicas para o fim/início de meses e anos.
- Cálculo de Ano Bissexto:
  - Função que determina se um ano é bissexto.
- Cálculo do Dia da Semana:
  - Calcula o dia da semana de qualquer data usando um algoritmo específico.
- Conversão de Nome do Mês:
  - Converte o número do mês para o seu nome correspondente (ex: 1 → Janeiro).
- Atualização do DOM:

  - Exibe dinamicamente informações como o dia da semana, a quantidade de dias no mês selecionado e se o ano é bissexto.
    
## Como Funciona
1. Seleção de Data:

O usuário seleciona uma data através de um campo de input.

2. Pressionar Carregar

As informações serão carregadas com base na data escolhida.

4. Incrementar/Decrementar Data:

Ao clicar nos botões, a data pode ser aumentada ou diminuída, ajustando automaticamente o mês e o ano quando necessário.

4. Exibir Resultados:

Informações como o dia da semana da data selecionada, a quantidade de dias no mês e se o ano é bissexto são mostradas na página.

## Funções

- recebeData(): Obtém e processa a data a partir do campo de input.
- diminuiData(): Diminui a data selecionada em um dia, ajustando automaticamente o mês e o ano.
- aumentaData(): Aumenta a data selecionada em um dia, também ajustando o mês e o ano conforme necessário.
- verificaSeAnoBissexto(ano): Verifica se o ano fornecido é bissexto.
- verificaQuantidadeDiasMes(mes, ano): Retorna a quantidade de dias no mês informado, considerando anos bissextos.
- verificaDiaSemanaQualquerData(dia, mes, ano): Calcula o dia da semana de uma data específica e retorna uma string indicando o dia.
- converteNomeMes(mes): Converte o número do mês para o seu nome correspondente.
- mostrarResultados(data): Atualiza o DOM com as informações da data processada.

## Problemas Observados a Serem Resolvidos

- [ ] Implementar atualização do DOM ao digitar ou selecionar uma nova data.
  
## Instalação
Clone o repositório e abra o arquivo HTML no seu navegador:

```bash
git clone https://github.com/seu-usuario/seu-repositorio.git
```
## Como Usar
1. Insira uma data no campo de input.
2. Pressione Carregar para mostrar as informações.
3. Use os botões para incrementar ou decrementar a data.
4. Veja os resultados diretamente na página.

## Licença

Este projeto está licenciado sob a Licença MIT.

![Bruno Moraes Digital](https://visitor-badge.laobi.icu/badge?page_id=xxxxx.visitor-badge) ![Última atualização README](https://img.shields.io/github/last-commit/brunomoraesdigital/xxxxx?path=README.md) [![License: AGPL-3.0](https://img.shields.io/badge/License-AGPL_3.0-blue.svg)](LICENSE)
