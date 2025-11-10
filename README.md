# Sistema De Cadastro 📜

🎯 Objetivo

Criar um sistema em C que simule um cadastro e autenticação de usuários, armazenando os dados em arquivo (como um backend simples de login).

**Requisitos** 

Menu principal

O programa deve exibir um menu com as opções:

1 - Cadastrar usuário
2 - Fazer login
3 - Listar usuários (apenas admin)
4 - Sair

**Cadastro**

O usuário informa:

Nome de usuário (sem espaços)

**Senha**

Os dados devem ser armazenados em um arquivo chamado usuarios.txt.

Cada linha do arquivo deve conter:

nome senha tipo


Onde tipo pode ser "admin" ou "comum" (o primeiro usuário cadastrado automaticamente será admin).

**Login**

O programa pede nome e senha.

Se houver correspondência no arquivo, exibe:

Login bem-sucedido! Bem-vindo, <nome>.


Caso contrário:

Usuário ou senha incorretos.


**Listar usuários**

Apenas o usuário admin logado pode listar todos os usuários cadastrados.

Mostrar algo como:

Usuários cadastrados:
- gabriel (admin)
- joao (comum)
- maria (comum)


**Persistência**

Todos os cadastros devem ser salvos de modo que, ao encerrar o programa e rodar novamente, os dados permaneçam.

**Extras**

Criptografar a senha de forma simples (por exemplo, somando +1 no código ASCII de cada caractere).

Validar se o usuário já existe antes de cadastrar.

Limpar a tela a cada ação (usando system("cls") no Windows ou system("clear") no Linux).

🧠 **O que esse desafio me testa**

Manipulação de arquivos (fopen, fprintf, fscanf)

Estruturas (struct, arrays)

Controle de fluxo (menus e loops)

Lógica de autenticação

Organização de código (funções bem separadas)
