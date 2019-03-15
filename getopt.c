int percorre_argv(int argc, char**argv, char opcao[2]){
	int i;
	for (i=0; i<argc; i++){
		if (strcmp(argv[i],opcao) == 0){
			break;
		}									
	}
	return i+1;
}

FILE* arquivo(int argc, char**argv, int i, char opcao[2]){
	FILE *arquivo = fopen(argv[i], "r");
	if (arquivo == NULL){
		printf("Erro ao abrir o arquivo da opcao %s\n", opcao);
		exit (-1);
	}
	return arquivo;
}

int main (int argc, char** argv){

	node_category_t data_category, *root_category=NULL, *aux_categ=NULL;
	node_product_t data_product, *aux_product=NULL;
	FILE *put=NULL, *get=NULL, *del=NULL, *contain=NULL, *rank=NULL, *flooor=NULL, *ceiling=NULL, *sequencia=NULL;
	char opcao, leitor[9], leitor2[8], separador; 
	int i, j; //variaveis para percorrer vetores, também utilizada para pegar valores.

	while ((opcao = getopt(argc, argv,"p:g:d:c:R:F:C:S:\n")) != -1) {
		switch (opcao){
			case 'p':			
				put = arquivo(argc, argv, percorre_argv(argc, argv, "-p"), "-p");
			break;
			case 'g':
				get = arquivo(argc, argv, percorre_argv(argc, argv, "-g"), "-g" );
			break;
			case 'd':
				del = arquivo(argc, argv, percorre_argv(argc, argv, "-d"), "-d");
			break;
			case 'c':	
				contain = arquivo(argc, argv, percorre_argv(argc, argv, "-c"), "-c");					
			break;
			case 'R':
				rank = arquivo(argc, argv, percorre_argv(argc, argv, "-R"), "-R");
			break;
			case 'F':
				flooor = arquivo(argc, argv, percorre_argv(argc, argv, "-F"), "-F");
			break;	
			case 'C':
				ceiling = arquivo(argc, argv, percorre_argv(argc, argv, "-C"), "-C");
			break;
			case 'S':
				sequencia = arquivo(argc, argv, percorre_argv(argc, argv, "-S"), "-S");
			break;
			default: 
				printf("Opcao invalida para abertura de arquivo %c\n", opcao);
				exit (-1);
			break;
		}				
	}
