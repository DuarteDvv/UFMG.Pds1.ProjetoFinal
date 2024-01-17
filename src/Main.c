#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>


struct Coordenada{
    int x;
    int y;
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
struct Ruas {
    bool paviment;

    void pavimento(int a);
};

void Ruas::pavimento(int a){
    if(a == 1){
        this->paviment = true;
    }
    else{
        this->paviment = false;
    }
}

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

struct Restaurantes{
    int x;
    int y;
    char nome[100];
    char custo[100];
    int velocidade;


    int distancia(int x, int y, Ruas city[23][39]);

};

int Restaurantes::distancia(int x, int y, Ruas city[23][39]){
    int zambs = 0,contador = 0, marcador = 0;
    Coordenada ruaatual, novarua;
    x--;
    y--;

    bool verificados[23][39];
    for(int i = 0; i < 23; i++){
        for(int j = 0; j < 39; j++){
            verificados[i][j] = false;
        }
    }

    int vizvert[] = {0, 0, -1, 1};
    int vizhor[] = {-1, 1, 0, 0};

    Coordenada fila[23 * 39];
    int frente = 0;
    int tras = 1;

    verificados[y][x] = true;
    fila[0].x = x;
    fila[0].y = y;

    if(x == this->x && y == this->y){
        return 0;
    }
   

    while (frente != tras){
       
        ruaatual = fila[frente];

        int atualX = ruaatual.x;
        int atualY = ruaatual.y;
       

        for (int i = 0; i < 4; i++){
            novarua.x = atualX + vizhor[i]; // coluna
            novarua.y = atualY + vizvert[i]; // linha


           

            if (novarua.x < 39 && novarua.x >= 0 && novarua.y < 23 && novarua.y >= 0){ // se está dentro da cidade
                if (city[novarua.y][novarua.x].paviment && !verificados[novarua.y][novarua.x]){ // se é pavimentada e não foi verificada


                    verificados[novarua.y][novarua.x] = true;
                    fila[tras].x = novarua.x;
                    fila[tras].y = novarua.y;
                    tras++;
                    contador++;


                    if (novarua.y == this->y && novarua.x == this->x){
                        return zambs + 1;
                    }
                }
            }
        }

        if(frente == marcador){
            zambs++;
            marcador = frente + contador;
            contador = 0;
            
        }

        frente++;
    }
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main(){
    int x,y,z;
    int atualx, atualy;
    int limite, preferencia;
    char nome[100], custo[100];
    Restaurantes lista[23];
   
    Ruas cidade[23][39];
    Restaurantes Rest[23];

    FILE* ruastxt = fopen("ruas.txt", "r");

    if(ruastxt == NULL){
        printf("Problema no arquivo ruas.txt");
    }

    while(!feof(ruastxt)){
        fscanf(ruastxt, "%i", &x);
        fscanf(ruastxt, "%i", &y);
        fscanf(ruastxt, "%i", &z);
        cidade[y-1][x-1].pavimento(z);
    }


    fclose(ruastxt);


    FILE* restaurantestxt = fopen("restaurantes.txt", "r");

    if(restaurantestxt== NULL){
        printf("Problema no arquivo restaurantes.txt");
    }

    for(int k = 0;!feof(restaurantestxt); k++){

        fscanf(restaurantestxt, "%i", &x);
        fscanf(restaurantestxt,"%i", &y);
        fscanf(restaurantestxt, "%s", &Rest[k].nome);
        fscanf(restaurantestxt,"%s", &Rest[k].custo);
        fscanf(restaurantestxt,"%i", &z);
        Rest[k].x =  x-1; Rest[k].y = y-1; //y é linha
        Rest[k].velocidade = z;
    }

    fclose(restaurantestxt);

    

    cidade[0][0].paviment = true;
    cidade[0][1].paviment = false;

    printf("Digite a cordenada 0 < X < 40 e 0 < Y < 24 de sua casa ->\n");

    scanf("%i", &atualx);
    scanf("%i", &atualy);

    if(cidade[atualy-1][atualx-1].paviment == false){
        while(cidade[atualy-1][atualx-1].paviment == false ){

            printf("Essa coordenada nao esta pavimentada ou esta fora da cidade\n");
            printf("digite outra ->\n");
            scanf("%i %i", &atualx, &atualy);
        }
    }

    printf("Prefere restaurantes caros ou baratos ? \ndigite 1 para caros e 0 para baratos -> \n");

    scanf("%i", &preferencia);
    while(preferencia != 0 && preferencia != 1){
        printf("escolha uma opcao valida\n");
        scanf("%i", &preferencia);  
    }


    int k = 0;
    for (int i = 0; i < 23; i++){
        if (preferencia == 1){
            if(strcmp(Rest[i].custo, "Caro") == 0){
                lista[k] = Rest[i];
                k++;
            }
        }
         if (preferencia == 0){
            if(strcmp(Rest[i].custo, "Barato") == 0){
                lista[k] = Rest[i];
                k++;
            }
        }
    }


    for(int inicio = 0 ;inicio < k ;inicio++){ //organizador de menor para maior
        for(int verificador = inicio + 1; verificador < k;verificador++){
            if(((lista[verificador].distancia(atualx,atualy,cidade)/1.0) / lista[verificador].velocidade) < ((lista[inicio].distancia(atualx,atualy,cidade)/1.0) / lista[inicio].velocidade)){
                Restaurantes memory = lista[inicio];
                lista[inicio] = lista[verificador];
                lista[verificador] = memory;
            }
        }
    }

    printf("Qual o maximo de tempo que pretende esperar ?\n");
    scanf("%i", &limite);

    printf("Segue a lista ordenada dos restaurantes com menor tempo de entrega ao maior ->\n\n");

    for(int i = 0; i<k;i++){
        printf("%s -- %f min\n\n", lista[i].nome, ((lista[i].distancia(atualx,atualy,cidade)/1.0) / lista[i].velocidade)); 
    }

    printf("Segue os restaurantes que respeitam seu limite e preferencia:\n\n");
    for(int i = 0; i<k;i++){
        if((lista[i].distancia(atualx,atualy,cidade) / lista[i].velocidade) <= limite){
            printf("%s\n", lista[i].nome);

        }
    }

}
