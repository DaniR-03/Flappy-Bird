//så nü har sättet att rita upp och displaya en vit pixel ändrats, istället för att skapa en icon så gör de här två funktionerna att man kan sätta in ett x och y värde för att säga vart
man vill att en pixel ska vara på skärmen. 

Exempel:
 
  draw_pixel(0,0);      --> Ritar en pixel på plats (0,0) vit.
  
!!! TYVÄRR ÄR X OCH Y PÅ FEL PLATS SÅ DET ÄR EGENTLIGEN FÖRST Y VÄRDET OCH SEN X VÄRDET (Y,X) jag kan fixa det lite senare. 
void draw_pixel(int x int y);
Ritar en pixel på punkten (x,y) vit. (y,x)!!!

Den här ritar en ifylld kvadrat med hjälp av dina koordinater

Exempel:
  
  draw_quad(0,0,0,5);   --> Ritar pixlar på alla platset mellan (0,0) och (0,5) vita, alltså en linje. (5 pixlar lång)

  draw_quad(0,0,5,5);   --> Ritar pixlar på alla platset mellan (0,0) och (5,5) vita, alltså en vit rektangel/kvadrat.
  
!!! TYVÄRR SAMMA SOM PÅ DRAW_PIXEL DE ÄR OMVÄNDA Y1,X1,Y2,X2. 
void draw_quad(int x1, int y2, int x2, int y2);
Ritar pixlarna inom två punkter (x1,y1) och (x2,y2) vita. (Y1,X1) (Y2,X2).

 
Skärmen går 32 rader ner och 128 rader åt höger. --> För nu så är det att det första värdet kan gå upp till 32 och andra 128 när det egentligen tvärt om 

Om man vill rita en punkt längst till vänster på skärmen i mitten väljer man draw_pixel(15, 0). 


Lite confusing men men jag fixar


