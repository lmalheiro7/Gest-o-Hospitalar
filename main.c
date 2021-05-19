#include <stdio.h>
#include <stdlib.h>
#include<conio.h> // Use getch
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc

//Declaracao de funcoes
void inserirMedico(void);
void editarMedico(void);
void pesquisarMedico(void);
void eliminarMedico(void);
void inserirPaciente(void);
void editarPaciente(void);
void pesquisarPaciente(void);
void eliminarPaciente(void);
void ecraLogin(void);
void menuMedico(void);
void menuAdmin(void);
void criarCredenciasMedico(void);


//Structs

typedef struct{
int ano;
short mes;
short dia;
short hora;
int minutos;
} Data;
struct Paciente{

    int numeroInterno;
    char nomeCompleto[100];
    int idade;
    char sexo[20];
    char localidade[50];
    int telefone;
    char problemaSaude[100];
    char problemaCovid;
    char receita[300];
    Data primeiraConsulta;
    Data ultimaConsulta;
    Data proximaConsulta;
    char situacaoClinica[300];
    char nomeMedico[100];
    char nomeEspecialidadeMedica[100];
};
struct Medico{
    int numeroInterno;
    char nomeCompleto[100];
    int idade;
    char nomeEspecialidade[100];
    int anosExperiencia;
    char localidade[100];
    int telefone;
    double salario;
    char horarioTrabalho[100];
};

//Declaraçao structs
struct Medico m;
struct Paciente p;

int main()
{
    //inserirMedico();
    //editarMedico();
    //pesquisarMedico();
    //eliminarMedico();
    //inserirPaciente();
    //editarPaciente();
    //pesquisarPaciente();
    //eliminarPaciente();
    //ecraLogin();
    //menuMedico();
    //menuAdmin();
     ecraLogin();
     //criarCredenciasMedico();


    //ESTAO REGISTADOS 1 UTILIZADOR POR DEFENIÇAO
    //USERNAME:   Admin
    //PASSWORD:   123q



}
//Funcoes desenvolvidas:
void ecraLogin(void){


    int j = 3;
    int flag = 0;
    char username[20];
    char password[20];
    char username2[20];
    char password2[20];




    // Utilizador Guardados no Sistema
    char username1[20] ="admin";
    char password1[20] ="admin";





    do
    {
        printf("\n***********Introduz o utilizador e password***********\n");
        printf("\n\tUtilizador: ");
        fflush(stdin);
        gets(username);
        printf("\n\tPassword: ");
        fflush(stdin);
        gets(password);

        if(strcmp(username,username1) == 0 && strcmp(password,password1) ==0 )// se admin
        {
            printf("\n\n________...Login ADMIN foi efetuado com sucesso...________");
            getch();
            menuAdmin();
            break;

        }
        else // se medico ou utilizador nao registado
        {
            system("cls");
            FILE *fpr;

            fpr = fopen("CredenciaisMedicos.txt","r"); //open file in reading mode

            while(fscanf(fpr,"%[^;];%[^\n]\n",username2,password2) != EOF )
            {

                if(strcmp(username2,username) == 0 && strcmp(password2,password) == 0 )
                {
                    printf("\n\n________...Login MEDICO foi efetuado com sucesso...________");
                    getch();
                    menuMedico();
                    flag = 1;
                    break;


                }

            }
            if(strcmp(username2,username) != 0 && strcmp(password2,password) != 0) //Caso as credenciais estejam erradas
            {
                printf("\n\n________...PASSWORD ou UTILIZADOR INCORRETO (TENTE NOVAMENTE (Possui mais %i tentativas))...________",j-1);
                j--;
                getch(); // pausa ate clicar em alguma tecla
                system("CLS");



            }

            fclose(fpr);
            printf("%i",flag);

        }



    }while(j != 0 && flag == 0);

    if(j==0)
        {
           printf("\n\n________...LIMITE TENTATIVAS ATINGIDO !!!! (O PROGRAMA IRA ENCERRAR)...________");
           getch();

        }


}

void criarCredenciasMedico(void){

    system("cls");

    FILE *pont_arq; // criação de variavel para arquivo
	char nome_utilizador[20]; //variavel do tipo string
	char password[20];
	pont_arq = fopen("CredenciaisMedicos.txt", "a"); //Criaçao do ficheiro de texto

	//Testar se o programa foi criado
	if(pont_arq == NULL) {
		printf("Dados Inválidos, por favor tente novamente");

	}
	else{
		printf("Introduza o nome de utilizador: ");
		scanf("%s", nome_utilizador);

		printf("Introduza a sua palavra-passe: ");
		scanf("%s", password);

		//USAR O FPRINTF PARA GUARDAR DA STRING NO ARQUIVO
		fprintf(pont_arq, "%s;%s\n", nome_utilizador, password);
		//USAR O FCLOSE PARA FECHAR O ARQUIVO
		fclose(pont_arq);

		printf("Dados gravados com sucesso!");
		}

}


void menuMedico(void){

    system("cls");
	int escolha;

    printf("*************************MENU MEDICO*************************\n\n");
    printf("Pfv escolha uma das seguintes opcoes:");
    printf("\n\t 1. Inserir um novo paciente");
    printf("\n\t 2. Editar dados de um paciente");
    printf("\n\t 3. Procurar todos os dados de um paciente");
    printf("\n\t 4. Eliminar registos de um paciente");
    printf("\n\t 5. Sair do menu\n\n\t");

    scanf("%i", &escolha);


    switch(escolha)
    {
        case 1:
            inserirPaciente();
            getch();//espera que seja inserido uma tecla
            menuMedico();
            break;
        case 2:
            editarPaciente();
            getch();
            menuMedico();
            break;
        case 3:
            pesquisarPaciente();
            getch();
            menuMedico();
            break;
        case 4:
            eliminarPaciente();
            getch();
            menuMedico();
            break;
        case 5:
            system("cls");
            printf("\n\t O programa ira encerrar!!!");
            getch();
            break;
        default:
            printf("\n\t Opcao invalida!!! Pfv insira uma das opcoes indicadas!!");
            getch();
            menuMedico();


    } //fim do switch
}


void menuAdmin(void){

    system("cls");
	int escolha;

    printf("*************************MENU ADMIN*************************\n\n");
    printf("Pfv escolha uma das seguintes opcoes:");
    printf("\n\t 1. Inserir um novo medico");
    printf("\n\t 2. Editar dados de um medico");
    printf("\n\t 3. Procurar registo de um medico");
    printf("\n\t 4. Eliminar registos de um medico");
    printf("\n\t 5. Criar credenciais de acesso para medicos");
    printf("\n\t 6. Sair do menu\n\n\t");

    scanf("%i", &escolha);


    switch(escolha)
    {
        case 1:
            inserirMedico();
            getch();//espera que seja inserido uma tecla
            menuAdmin();
            break;
        case 2:
            editarMedico();
            getch();
            menuAdmin();
            break;
        case 3:
            pesquisarMedico();
            getch();
            menuAdmin();
            break;
        case 4:
            eliminarMedico();
            getch();
            menuAdmin();
            break;
        case 5:
            criarCredenciasMedico();
            getch();
            menuAdmin();
            break;
        case 6:
            system("cls");
            printf("\n\t O programa ira encerrar!!!");
            getch();
            break;
        default:
            printf("\n\t Opcao invalida!!! Pfv insira uma das opcoes indicadas!!");
            getch();
            menuAdmin();


    } //fim do switch


}



void inserirMedico(void){

    system("cls");

    FILE *fpr;//file pointer
	fpr = fopen("Medicos.dat","a");//open file in write mode

    printf("\n Insira o numero Interno: ");
	scanf("%i",&m.numeroInterno);

	printf("\n Insira o nome completo: ");
	fflush(stdin); //Limpa o buffer do stdin antes de ler
	gets(m.nomeCompleto);

	printf("\n Insira a idade: ");
	fflush(stdin);
	scanf("%i",&m.idade);

	printf("\n Insira o nome da especialidade: ");
    fflush(stdin); // clean keyboard buffer
	gets(m.nomeEspecialidade);

	printf("\n Insira os anos de experiencia: ");
	scanf("%i",&m.anosExperiencia);

	printf("\n Insira a localidade: ");
	fflush(stdin);
	gets(m.localidade);

	printf("\n Insira o telefone: ");
	scanf("%i",&m.telefone);

	printf("\n Insira o salario: ");
	scanf("%lf",&m.salario);

	printf("\n Insira o horario de trabalho: ");
	fflush(stdin);
	gets(m.horarioTrabalho);

    fprintf(fpr,"%i;%s;%i;%s;%i;%s;%i;%lf;%s\n",m.numeroInterno,m.nomeCompleto,m.idade,m.nomeEspecialidade
            ,m.anosExperiencia,m.localidade,m.telefone,m.salario, m.horarioTrabalho); //Guarda em ficheiro as informacoes inseridas
    printf("\n\n\t Registo efetuado com sucesso");

	fclose(fpr);
}


void editarMedico(void){

    char nome[100];
    int numero;
    int existe = 0;
    char tecla;

    system("cls");

    FILE *fpr,*fpr1;//file pointer's
	fpr1 = fopen("MedicosFicheiroTemporario.dat","w+");//open file in write/update mode  //http://www.cplusplus.com/reference/cstdio/fopen/
	fpr = fopen("Medicos.dat","r"); //open file in reading mode

	if(fpr==NULL){

        printf("Nao existem dados gravados");
        //main menu
        //meter break
	}

	printf("Insira o nome do medico que deseja editar: ");
	fflush(stdin);
	gets(nome);
	printf("Insira o numero do medico que deseja editar: ");
	scanf("%i",&numero);

    if(fpr1==NULL){

        printf("\n Ficheiro não pode ser aberto");
    }



    //Le todos os registos que estao no ficheiro medicos.dat
    while(fscanf(fpr,"%i;%[^;];%i;%[^;];%i;%[^;];%i;%lf;%[^\n]",&m.numeroInterno,m.nomeCompleto,&m.idade,m.nomeEspecialidade,&m.anosExperiencia,m.localidade,&m.telefone,&m.salario, m.horarioTrabalho) != EOF ) //EOF End OF FILE
	{
        //verifica se o registo que estiver a ler é do medico que desja editar
	    if(strcmp(m.nomeCompleto,nome ) == 0 && m.numeroInterno == numero)
            {
                // se verdade a varivel existe passa a valor 1 e é feito o print do medico e pedidos os novos valores
                existe = 1;
                printf("Funcionario encontrado\n");

                printf("Numero: %i\nNome: %s\nIdade: %i\nEspecialidade: %s\nExperiencia: %i\nLocalidade: %s\nTelefone: %i\nSalario: %lf\nHorario: %s\n********\n",
                           m.numeroInterno,m.nomeCompleto,m.idade,m.nomeEspecialidade,m.anosExperiencia,m.localidade,m.telefone,m.salario, m.horarioTrabalho);

                printf("\n Insira o numero Interno: ");
                scanf("%i",&m.numeroInterno);

                printf("\n Insira o nome completo: ");
                fflush(stdin);
                gets(m.nomeCompleto);

                printf("\n Insira a idade: ");
                scanf("%i",&m.idade);

                printf("\n Insira o nome da especialidade: ");
                fflush(stdin); // clean keyboard buffer
                gets(m.nomeEspecialidade);

                printf("\n Insira os anos de experiencia: ");
                scanf("%i",&m.anosExperiencia);

                printf("\n Insira a localidade: ");
                fflush(stdin);
                gets(m.localidade);

                printf("\n Insira o telefone: ");
                scanf("%i",&m.telefone);

                printf("\n Insira o salario: ");
                scanf("%lf",&m.salario);

                printf("\n Insira o horario de trabalho: ");
                fflush(stdin);
                gets(m.horarioTrabalho);

                printf("\n Pressione a tecla 's' para fazer update do Funcionario : ");
                tecla = getche();

                if(tecla == 's' || tecla == 'S')
                    {
                        // as novas informaçoes editas são guardadas no ficheiro MedicosFicheiroTemporario.dat
                        fprintf(fpr1,"%i;%s;%i;%s;%i;%s;%i;%lf;%s\n",m.numeroInterno,m.nomeCompleto,m.idade,m.nomeEspecialidade,m.anosExperiencia,m.localidade,m.telefone,m.salario, m.horarioTrabalho);



                        printf("\n\n\t\t\t Funcionario Atualizado Com Sucesso...");

                    }
            }

            else
                {
                    // os medicos que estavam guardados no ficheiro medicos.dat são agora inseridos no ficheiro MedicosFicheiroTemporario.dat
                    fprintf(fpr1,"%i;%s;%i;%s;%i;%s;%i;%lf;%s\n",m.numeroInterno,m.nomeCompleto,m.idade,m.nomeEspecialidade,m.anosExperiencia,m.localidade,m.telefone,m.salario, m.horarioTrabalho);
                }
	}
    //caso o medico n seja encontrado é imprimida essa informaçao
	if(!existe) printf("\n\t\tFuncionario nao encontrado...");

	fclose(fpr1);
	fclose(fpr);

	//removemos o ficheiro antigo Medicos.dat e renomeamos o novo ficheiro MedicosFicheiroTemporario.dat com o nome do original
	remove("Medicos.dat");
	rename("MedicosFicheiroTemporario.dat","Medicos.dat");

}

void pesquisarMedico(void){

    char nome[100];
    int numero;


    system("cls");
    FILE *fpr;

    fpr = fopen("Medicos.dat","r"); //open file in reading mode

    printf("Insira o nome do medico que deseja procurar: ");
	fflush(stdin);
	gets(nome);
	printf("Insira o numero do medico que deseja procurar: ");
	scanf("%i",&numero);
	system("cls");


	while(fscanf(fpr,"%i;%[^;];%i;%[^;];%i;%[^;];%i;%lf;%[^\n]",&m.numeroInterno,m.nomeCompleto,&m.idade,m.nomeEspecialidade
            ,&m.anosExperiencia,m.localidade,&m.telefone,&m.salario, m.horarioTrabalho) != EOF )
            {
                if(m.numeroInterno== numero && strcmp(m.nomeCompleto,nome)==0)
                {
                    printf("Numero: %i\nNome: %s\nIdade: %i\nEspecialidade: %s\nExperiencia: %i\nLocalidade: %s\nTelefone: %i\nSalario: %lf\nHorario: %s\n********\n",
                       m.numeroInterno,m.nomeCompleto,m.idade,m.nomeEspecialidade,m.anosExperiencia,m.localidade,m.telefone,m.salario, m.horarioTrabalho);
                    break;
                }

            }
            if(m.numeroInterno != numero || strcmp(m.nomeCompleto,nome)!= 0 )
                {
                    printf("Medico nao encontrado no sistema pf verifique se inseriu corretamente o numero e nome!!!");
                    getch();
                    pesquisarMedico();
                }



    fclose(fpr);



}

void eliminarMedico(void){

    char nome[100];
    int numero;
    int existe = 0;
    char tecla;

    system("cls");

    FILE *fpr,*fpr1;//file pointer's
	fpr1 = fopen("MedicosFicheiroTemporario.dat","w+");//open file in write/update mode  //http://www.cplusplus.com/reference/cstdio/fopen/
	fpr = fopen("Medicos.dat","r"); //open file in reading mode

	if(fpr==NULL){

        printf("Nao existem dados gravados");
        //main menu
        //meter break
	}

	printf("Insira o nome do medico que deseja ELIMINAR: ");
	fflush(stdin);
	gets(nome);
	printf("Insira o numero do medico que deseja ELIMINAR: ");
	scanf("%i",&numero);

    if(fpr1==NULL){

        printf("\n Ficheiro não pode ser aberto");
    }





    while(fscanf(fpr,"%i;%[^;]\n;%i;%[^;]\n;%i;%[^;]\n;%i;%lf;%[^\n]",&m.numeroInterno,m.nomeCompleto,&m.idade,m.nomeEspecialidade,&m.anosExperiencia,m.localidade,&m.telefone,&m.salario, m.horarioTrabalho) != EOF ) //EOF End OF FILE
	{

	    if(strcmp(m.nomeCompleto,nome ) == 0 && m.numeroInterno == numero)
            {
                 printf("Numero: %i\nNome: %s\nIdade: %i\nEspecialidade: %s\nExperiencia: %i\nLocalidade: %s\nTelefone: %i\nSalario: %lf\nHorario: %s\n********\n",m.numeroInterno,m.nomeCompleto,m.idade,m.nomeEspecialidade,m.anosExperiencia,m.localidade,m.telefone,m.salario, m.horarioTrabalho);
                 printf("Tem a certeza que pretende eliminar ? [S/N]\n");
                 tecla = getch();
                  if(tecla == 's' || tecla == 'S')
                    {
                        existe = 1;

                    }
                  else if(tecla == 'n' || tecla == 'N')
                    {
                        break;
                    }
                  else
                    {
                        printf("\nTecla INCORRETA");
                        break;

                    }


            }
            else
                {
                    fprintf(fpr1,"%i;%s;%i;%s;%i;%s;%i;%lf;%s\n",m.numeroInterno,m.nomeCompleto,m.idade,m.nomeEspecialidade,m.anosExperiencia,m.localidade,m.telefone,m.salario, m.horarioTrabalho);

                }
	}


	if(existe==0)
        {
            printf("\n\t\tFuncionario nao encontrado ou nao eliminado...");
        }
    else
    {
        fclose(fpr1);
        fclose(fpr);
        remove("Medicos.dat");
        rename("MedicosFicheiroTemporario.dat","Medicos.dat");
        printf("\n\n\t\t\t Record deleted successfully :) ");

    }

    fclose(fpr1);
    fclose(fpr);
    remove("MedicosFicheiroTemporario.dat");

}

void inserirPaciente(void){
	
	int covid;
	char tecla;
     system("cls");

    FILE *fpr;//file pointer
	fpr = fopen("Pacientes.dat","a");//open file in write mode

    printf("\n Insira o numero Interno: ");
	scanf("%i",&p.numeroInterno);

	printf("\n Insira o nome completo: ");
	fflush(stdin); //Limpa o buffer do stdin antes de ler
	gets(p.nomeCompleto);

	printf("\n Insira a idade: ");
	scanf("%i",&p.idade);

	printf("\n Insira o sexo [Feminino/Masculino]: ");
	fflush(stdin); //Limpa o buffer do stdin antes de ler
	gets(p.sexo);

	printf("\n Insira a localidade: ");
	fflush(stdin);
	gets(p.localidade);

	printf("\n Insira o telefone: ");
	scanf("%i",&p.telefone);


	printf("\n Insira o problema de saude: ");
	fflush(stdin);
	gets(p.problemaSaude);

            
	printf("\n Insira a data da primeira consulta: ");
	printf("\n \t Insira o DIA: ");
	scanf("%hi",&p.primeiraConsulta.dia);
	printf("\t Insira o MES: ");
	scanf("%hi",&p.primeiraConsulta.mes);
	printf("\t Insira o ANO: ");
	scanf("%i",&p.primeiraConsulta.ano);
	printf("\t Insira o HORA: ");
	scanf("%hi",&p.primeiraConsulta.hora);
	printf("\t Insira o MINUTO: ");
	scanf("%i",&p.primeiraConsulta.minutos);

	printf("\n Insira a data da ultima consulta: ");
	printf("\n \t Insira o DIA: ");
	scanf("%hi",&p.ultimaConsulta.dia);
	printf("\t Insira o MES: ");
	scanf("%hi",&p.ultimaConsulta.mes);
	printf("\t Insira o ANO: ");
	scanf("%i",&p.ultimaConsulta.ano);
	printf("\t Insira o HORA: ");
	scanf("%hi",&p.ultimaConsulta.hora);
	printf("\t Insira o MINUTO: ");
	scanf("%i",&p.ultimaConsulta.minutos);

	printf("\n Insira a data da proxima consulta: ");
	printf("\n \t Insira o DIA: ");
	scanf("%hi",&p.proximaConsulta.dia);
	printf("\t Insira o MES: ");
	scanf("%hi",&p.proximaConsulta.mes);
	printf("\t Insira o ANO: ");
	scanf("%i",&p.proximaConsulta.ano);
	printf("\t Insira o HORA: ");
	scanf("%hi",&p.proximaConsulta.hora);
	printf("\t Insira o MINUTO: ");
	scanf("%i",&p.proximaConsulta.minutos);

	printf("\n Insira a situacao clinica: ");
	fflush(stdin);
	gets(p.situacaoClinica);

	printf("\n Insira o nome do medico: ");
	fflush(stdin);
	gets(p.nomeMedico);

	printf("\n Insira o nome da especialidade medica: ");
	fflush(stdin);
	gets(p.nomeEspecialidadeMedica);
	
	printf("\n Este paciente testou recentemente positivo para covid-19?(clique tecla 'p' para POSITIVO ou tecla 'f' para NEGATIVO): ");
	fflush(stdin);
	tecla = getche();
	scanf("%i", &p.problemaCovid);

        if(tecla == 'p' || tecla == 'P')
            {
            	covid = 1;
            }
        if(tecla == 'f' || tecla == 'F')
            {
            	covid = 0;
            }
    
	printf("\n Insira a receita(se possivel separada por pontos e virgulas): ");
	fflush(stdin);
	gets(p.receita);

	    fprintf(fpr,"%i;%s;%i;%s;%s;%i;%s;%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%s;%s;%s;Covid-19:%i;Receita Medica:%s\n"
            ,p.numeroInterno,p.nomeCompleto,p.idade,p.sexo,p.localidade,p.telefone,p.problemaSaude,
            p.primeiraConsulta.dia,p.primeiraConsulta.mes,p.primeiraConsulta.ano,p.primeiraConsulta.hora,p.primeiraConsulta.minutos,
            p.ultimaConsulta.dia,p.ultimaConsulta.mes,p.ultimaConsulta.ano,p.ultimaConsulta.hora,p.ultimaConsulta.minutos,
            p.proximaConsulta.dia,p.proximaConsulta.mes,p.proximaConsulta.ano,p.proximaConsulta.hora,p.proximaConsulta.minutos,
            p.situacaoClinica,p.nomeMedico,p.nomeEspecialidadeMedica, p.problemaCovid, p.receita);
    fclose(fpr);
	printf("\n\n\t Registo efetuado com sucesso");
	printf("\n O paciente %s deu entrada no hospital com %s. O paciente tem %i testes positivos com covid-19. \n Alem disso o paciente deve ter em atencao a seguinte receita: %s " , p.nomeCompleto, p.problemaSaude, covid, p.receita);
}

void editarPaciente(void){

    char nome[100];
    int numero;
    int existe = 0;
    char tecla;


    system("cls");

    FILE *fpr,*fpr1;//file pointer's
	fpr1 = fopen("PacientesFicheiroTemporario.dat","w+");//open file in write/update mode  //http://www.cplusplus.com/reference/cstdio/fopen/
	fpr = fopen("Pacientes.dat","r"); //open file in reading mode

	if(fpr==NULL){

        printf("Nao existem dados gravados");
        //main menu
        //meter break
	}

	printf("Insira o nome do paciente que deseja editar: ");
	fflush(stdin);
	gets(nome);
	printf("Insira o numero do paciente que deseja editar: ");
	scanf("%i",&numero);

    if(fpr1==NULL){

        printf("\n Ficheiro não pode ser aberto");
    }




    while(fscanf(fpr,"%i;%[^;];%i;%[^;];%[^;];%i;%[^;];%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%[^;];%[^;];%[^\n]"
            ,&p.numeroInterno,p.nomeCompleto,&p.idade,p.sexo,p.localidade,&p.telefone,p.problemaSaude,
            &p.primeiraConsulta.dia,&p.primeiraConsulta.mes,&p.primeiraConsulta.ano,&p.primeiraConsulta.hora,&p.primeiraConsulta.minutos,
            &p.ultimaConsulta.dia,&p.ultimaConsulta.mes,&p.ultimaConsulta.ano,&p.ultimaConsulta.hora,&p.ultimaConsulta.minutos,
            &p.proximaConsulta.dia,&p.proximaConsulta.mes,&p.proximaConsulta.ano,&p.proximaConsulta.hora,&p.proximaConsulta.minutos,
            p.situacaoClinica,p.nomeMedico,p.nomeEspecialidadeMedica) != EOF ) //EOF End OF FILE

	{


	    if(strcmp(p.nomeCompleto,nome ) == 0 && p.numeroInterno == numero)
            {
                existe = 1;
                printf("Funcionario encontrado\n");

                printf("Numero: %i\nNome: %s\nIdade: %i\nSexo: %s\nLocalidade: %s\nTelefone: %i\nProblemaSaude: %s\nDiaPrimeiraConslt: %hi\nMesPrimeiraConslt: %hi\nAnoPrimeiraConslt: %i\nHoraPrimeiraConslt: %hi\nMinutoPrimeiraConslt: %i\nDiaUltmConsult: %hi\nMesUltmConsult: %hi\nAnoUltmConsult: %i\nHoraUltmConsult: %hi\nMinutUltmConsult: %i\nDiaProximaConslt: %hi\nMesProximaConslt: %hi\nAnoProximaConslt: %i\nHoraProximaConslt: %hi\nMinutProximaConslt: %i\nSituacaoClinica: %s\nMedico: %s\nEspecialidadeMedica: %s\n********\n",
                        p.numeroInterno,p.nomeCompleto,p.idade,p.sexo,p.localidade,p.telefone,p.problemaSaude,
                        p.primeiraConsulta.dia,p.primeiraConsulta.mes,p.primeiraConsulta.ano,p.primeiraConsulta.hora,p.primeiraConsulta.minutos,
                        p.ultimaConsulta.dia,p.ultimaConsulta.mes,p.ultimaConsulta.ano,p.ultimaConsulta.hora,p.ultimaConsulta.minutos,
                        p.proximaConsulta.dia,p.proximaConsulta.mes,p.proximaConsulta.ano,p.proximaConsulta.hora,p.proximaConsulta.minutos,
                        p.situacaoClinica,p.nomeMedico,p.nomeEspecialidadeMedica);

                printf("\n Insira o numero Interno: ");
                scanf("%i",&p.numeroInterno);

                printf("\n Insira o nome completo: ");
                fflush(stdin); //Limpa o buffer do stdin antes de ler
                gets(p.nomeCompleto);

                printf("\n Insira a idade: ");
                scanf("%i",&p.idade);

                printf("\n Insira o sexo [Feminino/Masculino]: ");
                fflush(stdin); //Limpa o buffer do stdin antes de ler
                gets(p.sexo);

                printf("\n Insira a localidade: ");
                fflush(stdin);
                gets(p.localidade);

                printf("\n Insira o telefone: ");
                scanf("%i",&p.telefone);

                printf("\n Insira o problema de saude: ");
                fflush(stdin);
                gets(p.problemaSaude);

                printf("\n Insira a data da primeira consulta: ");
                printf("\n \t Insira o DIA: ");
                scanf("%hi",&p.primeiraConsulta.dia);
                printf("\t Insira o MES: ");
                scanf("%hi",&p.primeiraConsulta.mes);
                printf("\t Insira o ANO: ");
                scanf("%i",&p.primeiraConsulta.ano);
                printf("\t Insira o HORA: ");
                scanf("%hi",&p.primeiraConsulta.hora);
                printf("\t Insira o MINUTO: ");
                scanf("%i",&p.primeiraConsulta.minutos);

                printf("\n Insira a data da ultima consulta: ");
                printf("\n \t Insira o DIA: ");
                scanf("%hi",&p.ultimaConsulta.dia);
                printf("\t Insira o MES: ");
                scanf("%hi",&p.ultimaConsulta.mes);
                printf("\t Insira o ANO: ");
                scanf("%i",&p.ultimaConsulta.ano);
                printf("\t Insira o HORA: ");
                scanf("%hi",&p.ultimaConsulta.hora);
                printf("\t Insira o MINUTO: ");
                scanf("%i",&p.ultimaConsulta.minutos);

                printf("\n Insira a data da proxima consulta: ");
                printf("\n \t Insira o DIA: ");
                scanf("%hi",&p.proximaConsulta.dia);
                printf("\t Insira o MES: ");
                scanf("%hi",&p.proximaConsulta.mes);
                printf("\t Insira o ANO: ");
                scanf("%i",&p.proximaConsulta.ano);
                printf("\t Insira o HORA: ");
                scanf("%hi",&p.proximaConsulta.hora);
                printf("\t Insira o MINUTO: ");
                scanf("%i",&p.proximaConsulta.minutos);

                printf("\n Insira a situacao clinica: ");
                fflush(stdin);
                gets(p.situacaoClinica);

                printf("\n Insira o nome do medico: ");
                fflush(stdin);
                gets(p.nomeMedico);

                printf("\n Insira o nome da especialidade medica: ");
                fflush(stdin);
                gets(p.nomeEspecialidadeMedica);

                printf("\n Pressione a tecla 's' para fazer update do Funcionario : ");
                tecla = getche();

                if(tecla == 's' || tecla == 'S')
                    {

                        fprintf(fpr1,"%i;%s;%i;%s;%s;%i;%s;%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%s;%s;%s\n"
                        ,p.numeroInterno,p.nomeCompleto,p.idade,p.sexo,p.localidade,p.telefone,p.problemaSaude,
                        p.primeiraConsulta.dia,p.primeiraConsulta.mes,p.primeiraConsulta.ano,p.primeiraConsulta.hora,p.primeiraConsulta.minutos,
                        p.ultimaConsulta.dia,p.ultimaConsulta.mes,p.ultimaConsulta.ano,p.ultimaConsulta.hora,p.ultimaConsulta.minutos,
                        p.proximaConsulta.dia,p.proximaConsulta.mes,p.proximaConsulta.ano,p.proximaConsulta.hora,p.proximaConsulta.minutos,
                        p.situacaoClinica,p.nomeMedico,p.nomeEspecialidadeMedica);



                        printf("\n\n\t\t\t Funcionario Atualizado Com Sucesso...");

                    }
            }

            else
                {

                    fprintf(fpr1,"%i;%s;%i;%s;%s;%i;%s;%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%s;%s;%s\n"
                    ,p.numeroInterno,p.nomeCompleto,p.idade,p.sexo,p.localidade,p.telefone,p.problemaSaude,
                     p.primeiraConsulta.dia,p.primeiraConsulta.mes,p.primeiraConsulta.ano,p.primeiraConsulta.hora,p.primeiraConsulta.minutos,
                     p.ultimaConsulta.dia,p.ultimaConsulta.mes,p.ultimaConsulta.ano,p.ultimaConsulta.hora,p.ultimaConsulta.minutos,
                     p.proximaConsulta.dia,p.proximaConsulta.mes,p.proximaConsulta.ano,p.proximaConsulta.hora,p.proximaConsulta.minutos,
                     p.situacaoClinica,p.nomeMedico,p.nomeEspecialidadeMedica);
                }
	}

	if(!existe) printf("\n\t\tPaciente nao encontrado...");


	fclose(fpr1);
	fclose(fpr);
	remove("Pacientes.dat");
	rename("PacientesFicheiroTemporario.dat","Pacientes.dat");


}

void pesquisarPaciente(void){

    char nome[100];
    int numero;


    system("cls");
    FILE *fpr;

    fpr = fopen("Pacientes.dat","r"); //open file in reading mode

    printf("Insira o nome do paciente que deseja procurar: ");
	fflush(stdin);
	gets(nome);
	printf("Insira o numero do paciente que deseja procurar: ");
	scanf("%i",&numero);
	system("cls");


	while(fscanf(fpr,"%i;%[^;];%i;%[^;];%[^;];%i;%[^;];%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%[^;];%[^;];%[^\n]"
            ,&p.numeroInterno,p.nomeCompleto,&p.idade,p.sexo,p.localidade,&p.telefone,p.problemaSaude,
            &p.primeiraConsulta.dia,&p.primeiraConsulta.mes,&p.primeiraConsulta.ano,&p.primeiraConsulta.hora,&p.primeiraConsulta.minutos,
            &p.ultimaConsulta.dia,&p.ultimaConsulta.mes,&p.ultimaConsulta.ano,&p.ultimaConsulta.hora,&p.ultimaConsulta.minutos,
            &p.proximaConsulta.dia,&p.proximaConsulta.mes,&p.proximaConsulta.ano,&p.proximaConsulta.hora,&p.proximaConsulta.minutos,
            p.situacaoClinica,p.nomeMedico,p.nomeEspecialidadeMedica) != EOF )
            {

                if(p.numeroInterno== numero && strcmp(p.nomeCompleto,nome)==0)
                {
                    printf("Numero: %i\nNome: %s\nIdade: %i\nSexo: %s\nLocalidade: %s\nTelefone: %i\nProblemaSaude: %s\n\nDiaPrimeiraConslt: %hi\nMesPrimeiraConslt: %hi\nAnoPrimeiraConslt: %i\nHoraPrimeiraConslt: %hi\nMinutoPrimeiraConslt: %i\n\nDiaUltmConsult: %hi\nMesUltmConsult: %hi\nAnoUltmConsult: %i\nHoraUltmConsult: %hi\nMinutUltmConsult: %i\n\nDiaProximaConslt: %hi\nMesProximaConslt: %hi\nAnoProximaConslt: %i\nHoraProximaConslt: %hi\nMinutProximaConslt: %i\n\nSituacaoClinica: %s\nMedico: %s\nEspecialidadeMedica: %s\n********\n",
                    p.numeroInterno,p.nomeCompleto,p.idade,p.sexo,p.localidade,p.telefone,p.problemaSaude,
                    p.primeiraConsulta.dia,p.primeiraConsulta.mes,p.primeiraConsulta.ano,p.primeiraConsulta.hora,p.primeiraConsulta.minutos,
                    p.ultimaConsulta.dia,p.ultimaConsulta.mes,p.ultimaConsulta.ano,p.ultimaConsulta.hora,p.ultimaConsulta.minutos,
                    p.proximaConsulta.dia,p.proximaConsulta.mes,p.proximaConsulta.ano,p.proximaConsulta.hora,p.proximaConsulta.minutos,
                    p.situacaoClinica,p.nomeMedico,p.nomeEspecialidadeMedica);
                    break;
                }

            }
            if(p.numeroInterno != numero || strcmp(p.nomeCompleto,nome)!= 0 )
                {
                    printf("Paciente nao encontrado no sistema pf verifique se inseriu corretamente o numero e nome!!!");
                }



    fclose(fpr);


}

void eliminarPaciente(void){


    char nome[100];
    int numero;
    int existe = 0;
    char tecla;

    system("cls");

    FILE *fpr,*fpr1;//file pointer's
	fpr1 = fopen("PacientesFicheiroTemporario.dat","w+");//open file in write/update mode  //http://www.cplusplus.com/reference/cstdio/fopen/
	fpr = fopen("Pacientes.dat","r"); //open file in reading mode

	if(fpr==NULL){

        printf("Nao existem dados gravados");
        //main menu
        //meter break
	}
	

	printf("Insira o nome do paciente que deseja ELIMINAR: ");
	fflush(stdin);
	gets(nome);
	printf("Insira o numero do paciente que deseja ELIMINAR: ");
	scanf("%i",&numero);

    if(fpr1==NULL){

        printf("\n Ficheiro não pode ser aberto");
    }




    while(fscanf(fpr,"%i;%[^;];%i;%[^;];%[^;];%i;%[^;];%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%[^;];%[^;];%[^\n]"
            ,&p.numeroInterno,p.nomeCompleto,&p.idade,p.sexo,p.localidade,&p.telefone,p.problemaSaude,
            &p.primeiraConsulta.dia,&p.primeiraConsulta.mes,&p.primeiraConsulta.ano,&p.primeiraConsulta.hora,&p.primeiraConsulta.minutos,
            &p.ultimaConsulta.dia,&p.ultimaConsulta.mes,&p.ultimaConsulta.ano,&p.ultimaConsulta.hora,&p.ultimaConsulta.minutos,
            &p.proximaConsulta.dia,&p.proximaConsulta.mes,&p.proximaConsulta.ano,&p.proximaConsulta.hora,&p.proximaConsulta.minutos,
            p.situacaoClinica,p.nomeMedico,p.nomeEspecialidadeMedica) != EOF ) //EOF End OF FILE
	{

	    if(strcmp(p.nomeCompleto,nome ) == 0 && p.numeroInterno == numero)
            {
                    printf("Numero: %i\nNome: %s\nIdade: %i\nSexo: %s\nLocalidade: %s\nTelefone: %i\nProblemaSaude: %s\n\nDiaPrimeiraConslt: %hi\nMesPrimeiraConslt: %hi\nAnoPrimeiraConslt: %i\nHoraPrimeiraConslt: %hi\nMinutoPrimeiraConslt: %i\n\nDiaUltmConsult: %hi\nMesUltmConsult: %hi\nAnoUltmConsult: %i\nHoraUltmConsult: %hi\nMinutUltmConsult: %i\n\nDiaProximaConslt: %hi\nMesProximaConslt: %hi\nAnoProximaConslt: %i\nHoraProximaConslt: %hi\nMinutProximaConslt: %i\n\nSituacaoClinica: %s\nMedico: %s\nEspecialidadeMedica: %s\n********\n",
                    p.numeroInterno,p.nomeCompleto,p.idade,p.sexo,p.localidade,p.telefone,p.problemaSaude,
                    p.primeiraConsulta.dia,p.primeiraConsulta.mes,p.primeiraConsulta.ano,p.primeiraConsulta.hora,p.primeiraConsulta.minutos,
                    p.ultimaConsulta.dia,p.ultimaConsulta.mes,p.ultimaConsulta.ano,p.ultimaConsulta.hora,p.ultimaConsulta.minutos,
                    p.proximaConsulta.dia,p.proximaConsulta.mes,p.proximaConsulta.ano,p.proximaConsulta.hora,p.proximaConsulta.minutos,
                    p.situacaoClinica,p.nomeMedico,p.nomeEspecialidadeMedica);
                 printf("Tem a certeza que pretende eliminar ? [S/N]\n");
                 tecla = getch();
                  if(tecla == 's' || tecla == 'S')
                    {
                        existe = 1;

                    }
                  else if(tecla == 'n' || tecla == 'N')
                    {
                        break;
                    }
                  else
                    {
                        printf("\nTecla INCORRETA");
                        break;

                    }



            }
            else
                {
                    fprintf(fpr1,"%i;%s;%i;%s;%s;%i;%s;%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%hi;%hi;%i;%hi;%i;%s;%s;%s\n"
                    ,p.numeroInterno,p.nomeCompleto,p.idade,p.sexo,p.localidade,p.telefone,p.problemaSaude,
                    p.primeiraConsulta.dia,p.primeiraConsulta.mes,p.primeiraConsulta.ano,p.primeiraConsulta.hora,p.primeiraConsulta.minutos,
                    p.ultimaConsulta.dia,p.ultimaConsulta.mes,p.ultimaConsulta.ano,p.ultimaConsulta.hora,p.ultimaConsulta.minutos,
                    p.proximaConsulta.dia,p.proximaConsulta.mes,p.proximaConsulta.ano,p.proximaConsulta.hora,p.proximaConsulta.minutos,
                    p.situacaoClinica,p.nomeMedico,p.nomeEspecialidadeMedica);

                }
	}

	if(existe==0)
        {
            printf("\n\t\tPaciente nao encontrado ou nao eliminado...");
        }
    else
    {
        fclose(fpr1);
        fclose(fpr);
        remove("Pacientes.dat");
        rename("PacientesFicheiroTemporario.dat","Pacientes.dat");
        printf("\n\n\t\t\t Record deleted successfully :) ");

    }

    fclose(fpr1);
    fclose(fpr);
    remove("PacientesFicheiroTemporario.dat");



}
