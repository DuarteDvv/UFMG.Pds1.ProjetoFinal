# ProjetoFinal_PDS1
(Sem POO/ whithout OO)<br>
(Maps)
Remembering that this code was developed a long time ago (when I was learning C) and has several flaws, it is not modularized and treated, in addition to being something very simple and can be improved.
The only thing I want to highlight in this work is my adaptation of the BFS or Breadth-First Search algorithm to find the shortest path between houses and restaurants.
Not only did I have to know how to use it, but how to adapt it to the problem.

This project is about solving a problem with the following statement:

Consider a city, represented as a matrix. In the city there are restaurants and streets.
Streets are represented by coordinates (x, y) indicating whether the coordinate is
paved (1) or not (0). Consider that if two adjacent coordinates are
paved, then the section between these coordinates is paved. The file “streets.txt”
provides information about paved and unpaved sections (x, y,
paved). All restaurants are accessible via the streets, meaning there is always
a possible path between a paved place and a restaurant. Furthermore, there is always
only one possible path.
Restaurants can be cheap/expensive, and each restaurant has a delivery person. O
Delivery man makes deliveries with his motorcycle, and the speed of the motorcycle is specified. O
file “restaurants.txt” has this information (x, y, name, cost, speed).
The unit of distance measurement is called “zambs”. The distance between two coordinates
adjacent in the matrix corresponds to a “zambs”. The speeds of the motorcycles are given in
zambs/minute.
You must enter (via keyboard) the coordinates of your home. Note that your home must
be in a paved section of the city.
  1. Calculate the distance in “zambs” from your home to all restaurants.
  2. Read (from the keyboard) the cost preference (expensive or cheap), and return an arrangement with
  restaurants in order of delivery speed.
  3. Read (from the keyboard) the cost preference (expensive or cheap) and the maximum time
  you want to wait (minutes), and return an arrangement with the restaurants that
  respect the waiting time restriction.

Lembrando que esse código foi desenvolvido a muito tempo (Quando estava aprendendo C) e possui varias falhas, não esta modularizado e tratado, além de ser algo bem simples e que pode ser melhorado.
A unica coisa que quero destacar nesse trabalho é minha adaptação do algortimo BFS ou Busca em largura para encontrar o menor caminho entre casa-restaurantes.
Não apenas tive saber usar como adaptar ao problema.

Esse projeto se trata da resolução de um problema com o seguinte enunciado:

Considere uma cidade, representada como uma matriz. Na cidade há restaurantes e ruas.
As ruas são representadas por coordenadas (x, y) indicando se a coordenada é
pavimentada (1) ou não (0). Considere que se duas coordenadas adjacentes forem
pavimentadas, então o trecho entre essas coordenadas é pavimentado. O arquivo “ruas.txt”
fornece a informação sobre os trechos pavimentados e não-pavimentados (x, y,
pavimentado). Todos os restaurantes são acessíveis através das ruas, ou seja, há sempre
um caminho possível entre um local pavimentado e um restaurante. Mais ainda, há sempre
apenas um caminho possível.
Os restaurantes podem ser baratos/caros, e cada restaurante possui um entregador. O
entregador realiza entregas com sua moto, e a velocidade da moto é especificada. O
arquivo “restaurantes.txt” possui essa informação (x, y, nome, custo, velocidade).
A unidade de medida de distância é chamada “zambs”. A distância entre duas coordenadas
adjacentes na matriz corresponde a um “zambs”. As velocidades das motos são dadas em
zambs/minuto.
Você deve informar (via teclado) as coordenadas de sua casa. Note que sua casa deve
estar em um trecho pavimentado da cidade.
  1. Calcule a distância em “zambs” de sua casa a todos os restaurantes. 
  2. Leia (do teclado) a preferência de custo (caro ou barato), e retorne um arranjo com
  os restaurantes em ordem de rapidez de entrega.
  3. Leia (do teclado) a preferência de custo (caro ou barato) e o tempo máximo que
  voce quer esperar (minutos), e retorne um arranjo com os restaurantes que
  respeitem a restrição de tempo de espera.

