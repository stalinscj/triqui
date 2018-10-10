# include <stdio.h>
# include <cstdlib>
# include <time.h>
# include <windows.h>
# include <conio.h>
# include <stdlib.h>


#define F 3
#define C 7


int pt1=0;
int pt2=0;
int el=F*C;
char op;

void gotoxy(int x, int y) 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int limpiart (char tablero[F][C]) 
{
	int i,j;
		
	for (i=0;i<F;i++) 
		  {
			for (j=0;j<C;j++)
				{
					tablero[i][j]=' ';
					//printf("tablero vacio: %c", tablero[i][j]);
		            //getchar ();
						
				}
		  }
	return 0;
}

void clreol( ) 
{
    COORD coord;
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle
    (STD_OUTPUT_HANDLE), &info);
    coord.X = info.dwCursorPosition.X;
    coord.Y = info.dwCursorPosition.Y;
    FillConsoleOutputCharacter (GetStdHandle
    (STD_OUTPUT_HANDLE), ' ',
    info.dwSize.X - info.dwCursorPosition.X * 
    info.dwCursorPosition.Y, coord, &written);
    gotoxy (info.dwCursorPosition.X + 1, 
    info.dwCursorPosition.Y + 1);
}

void borramepan ()
{
	for (int i=12;i<24;i++)
	{
	gotoxy(0,i); clreol();
    }
	
}

int limpiartaux (char tableroaux[F][C]) 
{
	int i,j;
		
	for (i=0;i<F;i++) 
		  {
			for (j=0;j<C;j++)
				{
					tableroaux[i][j]=' ';
				//	printf("tableroaux vacio: %c", tableroaux[i][j]);
		        //    getchar ();
						
				}
		  }
	return 0;
}

int rtfh (char tablero[F][C],char op) 
{
	int i,j,p1,p2;
	char tableroaux[F][C];
	limpiartaux(tableroaux);
	p1=0;
	p2=0;	
	for (i=0;i<F;i++) 
		  {
			for (j=0;j<C;j++)
				{
					if (((tablero[i][j]==tablero[i][j+1])&&(tablero[i][j]==tablero[i][j+2]))&&(j<=4))
					{
                        if (tableroaux[i][j]==' ')			             
						{
								tableroaux[i][j]=tablero[i][j];
								tableroaux[i][j+1]=tablero[i][j+1];
								tableroaux[i][j+2]=tablero[i][j+2];
								if (tablero[i][j]=='O')
								{
									p1=p1+1;
								}
								else
								{
									p2=p2+1;
								}
								
						}
					}
					
					//printf("\nestas recorriendo el tablero en forma horizontal: %c", tablero[i][j]);
		            //getchar ();
		            //printf("estas recorriendo el tablero en forma horizontal: %c", tablero[i+1][j+1]);
		            //getchar ();
		            //printf("estas recorriendo el tablero en forma horizontal: %c", tablero[+2][j+2]);
		            //getchar ();
						
				}
		  }
	pt1=pt1+p1;
	pt2=pt2+p2;
	
	gotoxy(0,8); clreol();
	gotoxy(0,8);
	if (el==0)
	{
	   printf("Puntos horizontales de J1: %d",p1);
	   if (op==2)
	   {
	      printf("           Puntos horizontales de J2: %d\n",p2);
	      getchar ();
	   }
	   else
	   {
			printf("           Puntos horizontales de la com: %d\n",p2);
	   }
    }
	
	
	return 0;
}

int rtfv (char tablero[F][C],char op) 
{
	int i,j,p1,p2;
	char tableroaux[F][C];
	limpiartaux(tableroaux);
	p1=0;
	p2=0;	
	for (j=0;j<C;j++) 
		  {
			for (i=0;i<F;i++)
				{
					if (((tablero[i][j] == tablero[i+1][j])&&(tablero[i+1][j] == tablero[i+2][j]))&&(i==0))
					{
						if (tableroaux[i][j]==' ')			             
						{
								tableroaux[i][j]=tablero[i][j];
								tableroaux[i+1][j]=tablero[i+1][j];
								tableroaux[i+2][j]=tablero[i+2][j];
								if (tableroaux[i][j]=='O')
								{
									p1=p1+1;
								}
								else
								{
									p2=p2+1;
								}
						}
					}
					
					//printf("\nestas recorriendo el tablero en forma vertical: %c", tablero[i][j]);
		            //getchar ();
						
				}
		  }
	pt1=pt1+p1;
	pt2=pt2+p2;	  
	
	if(el==0)
	{
		printf("\nPuntos verticales de J1: %d",p1);
	   if (op==2)
	   {
	      printf("             Puntos verticales de J2: %d\n",p2);
	      getchar ();
	   }
	   else
	   {
			printf("             Puntos verticales de la com: %d\n",p2);
	        
	   }
    }
	//printf(" puntos totales: %d",pt);
	
	return 0;
}

int rtdp (char tablero[F][C],char op)
{
	int i,j,d,e,lc,p1,p2;
	char tableroaux[F][C];
	limpiartaux(tableroaux);
	p1=0;
	p2=0;
		
	lc=C;
	e=C;
	while (e>F-1)
	{
		d=lc-e;
		for (i=0;i<F;i++) 
		{
			for (j=0;j<C;j++)
			  	{
						if (((tablero[i][j+d]==tablero[i+1][j+d+1])&&(tablero[i][j+d]==tablero[i+2][j+d+2]))&&(i==j))
						{
							if (tableroaux[i][j+d]==' ')			             
						    {
								tableroaux[i][j+d]=tablero[i][j+d];
								tableroaux[i+1][j+d+1]=tablero[i+1][j+d+1];
								tableroaux[i+2][j+d+2]=tablero[i+2][j+d+2];
								if (tableroaux[i][j+d]=='O')
								{
									p1=p1+1;
								}
								else
								{
									p2=p2+1;
								}
						    }
						}
						
						
						//printf("\nesta es la diagonal principal: %c", tablero[i][j+d]);
		                //getchar ();
				    		
				}
		}
		e=e-1;	   
	}
	pt1=pt1+p1;
	pt2=pt2+p2;
	
	
	if(el==0)
	{
	  printf("\nPuntos diagonal principal de J1: %d",p1);
	   if (op==2)
	   {
	      printf("     Puntos diagonal principal de J2: %d\n",p2);
	      
	   }
	   else
	   {
			printf("     Puntos diagonal principal de la com: %d\n",p2);
	        
	   }
    }
	//printf(" puntos totales: %d",pt);
	
	return 0;
}

int rtds (char tablero[F][C],char op)
{
	int i,j,ds,p1,p2;
	char tableroaux[F][C];
	limpiartaux(tableroaux);
	p1=0;
	p2=0;
	
	ds=F-1;	
	while (ds<=C-1)
	{
		for (i=0;i<F;i++) 
		{
			for (j=0;j<C;j++)
			  	{
					if (i+j==ds)
					{
						if(((tablero[i][j]==tablero[i+1][j-1])&&(tablero[i][j]==tablero[i+2][j-2]))&&(i==0))
						{
							if (tableroaux[i][j]==' ')			             
						    {
								tableroaux[i][j]=tablero[i][j];
								tableroaux[i+1][j-1]=tablero[i+1][j-1];
								tableroaux[i+2][j-2]=tablero[i-2][j+2];
								if (tableroaux[i][j]=='O')
								{
									p1=p1+1;
								}
								else
								{
									p2=p2+1;
								}
						    }
						}
						
						
					    //printf("\nesta es la diagonal secundaria: %c", tablero[i][j]);
		                //getchar ();
					}
						
				}
				
		}
	ds=ds+1;
    }
    pt1=pt1+p1;
    pt2=pt2+p2;
	
	if(el==0)
	{
	   if (op==2)
	   {
			printf("\nPuntos diagonal secundaria de J1: %d",p1);
	        printf("    Puntos diagonal secundaria de J2: %d\n",p2);
	        printf("\n\nPuntos totales de J1: %d\n",pt1);
	        printf("\nPuntos totales de J2: %d\n",pt2);
	        if (pt1 > pt2)
	        {
				gotoxy(27,22);
				printf("Ha ganado el Jugador 1.");
			
		    }
		    if (pt2 > pt1)
	        {
				gotoxy(27,22);
				printf("Ha ganado la Computadora.");
			
		    }
		    if (pt1 == pt2)
	        {
				gotoxy(27,22);
				printf("Es un empate.");
			
		    }
		    
	        getchar ();
	        getchar ();
	   }
	   else
	   {
			printf("\nPuntos diagonal secundaria de J1: %d",p1);
	        printf("    Puntos diagonal secundaria de la com: %d\n",p2);
	        printf("\n\nPuntos totales de J1: %d\n",pt1);
	        printf("\nPuntos totales de la com: %d\n",pt2);
	        
	        if (pt1 > pt2)
	        {
				gotoxy(27,22);
				printf("Ha ganado el Jugador 1.");
			
		    }
		    if (pt2 > pt1)
	        {
			    gotoxy(27,22);
				printf("Ha ganado la Computadora.");
			
		    }
		    if (pt1 == pt2)
	        {
				gotoxy(27,22);
				printf("Es un empate.");
			
		    }
		    
	        getchar ();
	        getchar ();
	        
	   }
    }
	
    return 0;
}

bool posllena (char tablero[F][C],int x , int y)
{
	if (tablero[y][x]!=' ')
	    {
			gotoxy(0,9);
			printf("\nEsa posicion esta ocupada introduzca otra. \n");
			return true;
			
		}
	else 
	return false;
}

int jugador1 (char tablero [F][C])
{
	int x,y,i=0;
	char f1,tecla;
	bool jugada = false;
	f1='O';
	
	gotoxy(0,8);
	printf("J1 pulse la letra donde quire poner su ficha: ");
	
	while(!jugada && i<20 )
	{
	  if(kbhit()==1)
	  {
	    tecla = getch();
	     
	    switch(tecla)
	    {
	       case 'a':
			 x=0; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'b':
			 x=0; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'c':
			 x=0; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'd':
			 x=1; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	        if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
		   case 'e':
			 x=1; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
		   case 'f':
			 x=1; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
		   case 'g':
			 x=2; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break; 
	       case 'h':
			 x=2; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'i':
			 x=2; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'j':
			 x=3; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'k':
			 x=3; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'l':
			 x=3; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'm':
			 x=4; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'n':
			 x=4; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'o':
			 x=4; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'p':
			 x=5; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'q':
			 x=5; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'r':
			 x=5; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 's':
			 x=6; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 't':
			 x=6; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'u':
			 x=6; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       default: printf("Jugada no valida");
	    }
	  
	  
	  }
	  i=i+1;
	  Sleep (1000);
	  borramepan ();
	  gotoxy(0,12);
	  printf("Segundos transcurridos: %d",i);
    }
    
	if (jugada)
	{
		tablero[y][x]=f1;
		gotoxy(x*4+27,2*y+1);
		printf("O");
		borramepan ();
		el=el-1;
    }
    
	
	return 0;
}
int jugador2 (char tablero [F][C])
{
	int x,y,i=0;
	char f2,tecla;
	bool jugada = false;
	f2='X';
	
	gotoxy(0,8);
	printf("J2 pulse la letra donde quire poner su ficha: ");
	
	while(!jugada && i<=20 )
	{
	  if(kbhit()==1)
	  {
	    tecla = getch();
	     
	    switch(tecla)
	    {
	       case 'a':
			 x=0; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'b':
			 x=0; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'c':
			 x=0; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'd':
			 x=1; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	        if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
		   case 'e':
			 x=1; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
		   case 'f':
			 x=1; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
		   case 'g':
			 x=2; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break; 
	       case 'h':
			 x=2; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'i':
			 x=2; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'j':
			 x=3; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'k':
			 x=3; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'l':
			 x=3; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'm':
			 x=4; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'n':
			 x=4; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'o':
			 x=4; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'p':
			 x=5; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'q':
			 x=5; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'r':
			 x=5; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 's':
			 x=6; y=0;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 't':
			 x=6; y=1;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       case 'u':
			 x=6; y=2;
	         printf("\n\njugaras en la posicion x: %d y: %d\n",x,y);
	         if (!posllena(tablero,x,y)) 
			 {
					jugada=true;
					gotoxy(0,10); clreol();
			 }
	         break;
	       default: printf("Jugada no valida");
	    }
	  
	  
	  }
	  i=i+1;
	  Sleep (1000);
	  borramepan ();
	  gotoxy(0,12);
	  printf("Segundos transcurridos: %d",i);
    }
    
	if (jugada)
	{
		tablero[y][x]=f2;
		gotoxy(x*4+27,2*y+1);
		printf("X");
		borramepan ();
		el=el-1;
    }
    
	
	return 0;
}


int com (char tablero[F][C])
{
	int x,y;
	srand(time(NULL));
	
	do
    {	
	  x=(rand()%7);
	  y=(rand()%3);
	  if (tablero[y][x]==' ')
	  {
	    tablero[y][x]='X';
	    gotoxy(x*4+27,2*y+1);
	    printf("X");
	    el=el-1;
	    gotoxy(0,16);
	    break;
	  }
	} while (tablero[y][x]!=' ');
}

int rtt(char tablero[F][C],char op)
{
	int pj1,pj2,i;
	
    i=0;
    do{
	
	rtfh(tablero,op);
    rtfv(tablero,op);
	rtdp(tablero,op);
    rtds(tablero,op);
	pt1=pj1;
	pt2=pj2;
	pt1=0;
	pt2=0;
	i=i+1;
	} while (i<1);
	
	return 0;
}

int dibujo (int x, int y)
{
	int i=97;
	for(int y=0;y<8;y=y+2)
	{
		for (int x=25;x<54;x=x++)
		{
			gotoxy(x,y);
			printf("%c",196);
		}
	}
	
	for(int x=25;x<54;x=x+4)
	{
		for (int y=1;y<7;y=y+2)
		{
			gotoxy(x,y);
		    printf("%c",179);
		    
		}
	}
    
	return 0;
}

int instrucciones (int x, int y)
{
	int i=97;
	for(int y=0;y<8;y=y+2)
	{
		for (int x=25;x<54;x=x++)
		{
			gotoxy(x,y);
			printf("%c",196);
		}
	}
	
	for(int x=25;x<54;x=x+4)
	{
		for (int y=1;y<7;y=y+2)
		{
			gotoxy(x,y);
		    printf("%c",179);
		    if (x<50)
			{
				gotoxy(x+2,y);
				printf("%c",i);
				i++;
		    }
		    
		}
	}
	
	 i=97;
	for(int y=11;y<19;y=y+2)
	{
		for (int x=25;x<54;x=x++)
		{
			gotoxy(x,y);
			printf("%c",196);
		}
	}
	
	for(int x=25;x<54;x=x+4)
	{
		for (int y=12;y<18;y=y+2)
		{
			gotoxy(x,y);
		    printf("%c",179);
		    if (x<50)
			{
				gotoxy(x+2,y);
				printf("%c",i);
				i++;
		    }
		    
		}
	}
	
	gotoxy(0,7); 
	printf("Las posiciones en el tablero estan representadas por letras, las cuales siguen\n");
	printf("la secuencia del abecedario en forma vertical. De modo que bastara con pulsar\n");
	printf("la letra en la cual quiere colocar su ficha. Por ejemplo: Si pulsa la letra (h)\n");
	printf("su ficha se colocara en la casilla donde estaba la letra (h)");
	gotoxy(35,14);
	printf("O");
	gotoxy(0,18);
	printf("Observe como su ficha se ha colocado en la casilla donde estaba la letra (h).\n");
	printf("Dispone de 20 seg para pensar y ejecutar una jugada valida, si pasan 20 seg\n");
	printf("y no se ha realizado una jugada valida, el turno pasara al siguiente jugador.\n");
	printf("El juego terminara cuando el tablero este lleno y ganara aquel jugador con\n");
	printf("mayor cantidad de tres en raya.");
	
    
    getchar();
    getchar();
	return 0;
}

int leyendaisq (int x, int y)
{
	int i=97;
	for(int y=0;y<8;y=y+2)
	{
		for (int x=0;x<15;x=x++)
		{
			gotoxy(x,y);
			printf("%c",196);
		}
	}
	
	for(int x=0;x<15;x=x+2)
	{
		for (int y=1;y<7;y=y+2)
		{
			gotoxy(x,y);
		    printf("%c",179);
		    if (x<14)
			{
				gotoxy(x+1,y);
				printf("%c",i);
				i++;
		    }
		    
		}
	}
	
	return 0;
}

int leyendader (int x, int y)
{
	int i=97;
	for(int y=0;y<8;y=y+2)
	{
		for (int x=64;x<79;x=x++)
		{
			gotoxy(x,y);
			printf("%c",196);
		}
	}
	
	for(int x=64;x<79;x=x+2)
	{
		for (int y=1;y<7;y=y+2)
		{
			gotoxy(x,y);
		    printf("%c",179);
		    if (x<78)
			{
				gotoxy(x+1,y);
				printf("%c",i);
				i++;
		    }
		    
		}
	}
	return 0;
}
int menu (char &op,char tablero [F][C])
{		
	system("cls");
	do
	{
 	    gotoxy(19,0);
 	    printf("BIENVENIDOS A UN JUEGO QUE SE PARECE A TRIKI \n");
		printf("\nPulse 1 para jugar vs computadora \n");
	    printf("\nPulse 2 para jugar vs un amigo \n");
	    printf("\nPulse 3 para ver la instrucciones \n");
	    printf("\npulse 4 para salir \n");
		printf("\nIngrese una opcion: ");
	    scanf("%c",&op);
	    
	    if (((op!='1')&&(op!='2'))&&(op!='3'&&op!='4'))
        {
			printf("\nLa opcion ingresada no es valida");
			getchar();
			getchar();
		}
	    system("cls");
		
	    }while((op!='1'&&op!='2')&&(op!='3'&&op!='4'));
	
	
	return 0;
}



int main () 
{
    
	char tablero[F][C];
    int x,y;
	
		
	do
	{
	limpiart(tablero);
	limpiartaux(tablero);
	menu(op,tablero);
	if (op!='3')
	{
	leyendaisq(x,y);
	leyendader(x,y);
    }
	
	dibujo(x,y);	
	switch (op)
	    {
		    case '1':  el=F*C;
				       tablero[0][5]='X';
		               gotoxy(47,1);
	                   printf("X");
		               dibujo(x,y);
		               gotoxy(0,8);
					   printf("La com ha jugado en la posicion 0 5");
         	           el=el-1;
         	           
	                   do
                       {
						   jugador1(tablero);
						   if (el==0) break;
		                   com(tablero);
		                   
	                   }while (el>0);
	                   rtt(tablero,op);
	    	break;
		
		    case '2':  el=F*C;
				       jugador1(tablero);
			           do
	                   {
						   jugador2(tablero);
						   if (el==0) break;
	                       jugador1(tablero);
		
	                   }while (el>0);
	                   rtt(tablero,op);
		    break;
		    
		    case '3':  instrucciones(x,y);
		
		    case '4':  break;
		              
	    }
	    }while (op!='4');

	
	return 0;
}
